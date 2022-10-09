#!/usr/bin/env python3

import os
import re

from git import Repo, NoSuchPathError, InvalidGitRepositoryError, PushInfo

REMOTE_NAME = 'origin'


def infer_task_name_from_directory(dir):
    return os.path.basename(os.path.realpath(dir))


def uncommitted_changes(repo, task_name):
    return [
        item.a_path for item in repo.index.diff(None)
        if item.a_path.startswith(f'{task_name}/')]


def github_repo_title(remote):
    return re.match(r'(^git@github\.com:)(.+)(\.git$)', next(remote.urls)).group(2)


def push_task(remote, task_name):
    branch_name = f'submit/{task_name}'
    status = remote.push(f'HEAD:{branch_name}', force=True)

    unprocessed_flags = status[0].flags
    if unprocessed_flags & PushInfo.UP_TO_DATE:
        print(f'Your code for task "{task_name}" has already been submitted.')

        unprocessed_flags &= ~PushInfo.UP_TO_DATE
    elif unprocessed_flags & PushInfo.FAST_FORWARD or unprocessed_flags & PushInfo.FORCED_UPDATE:
        all_prs_url = f'https://github.com/{github_repo_title(remote)}/pulls'
        print(
            f'Task "{task_name}" resubmitted.\nYou can find your pull-request here:\n * \'{all_prs_url}\'')

        unprocessed_flags &= ~PushInfo.FAST_FORWARD
        unprocessed_flags &= ~PushInfo.FORCED_UPDATE
    elif unprocessed_flags & PushInfo.NEW_HEAD or unprocessed_flags & PushInfo.NEW_TAG:
        new_pr_url = f'https://github.com/{github_repo_title(remote)}/compare/master...{branch_name}'
        print(f'Task "{task_name}" submitted for the first time.\n' +
              f'Please visit the link below and open a pull-request:\n * \'{new_pr_url}\'')

        unprocessed_flags &= ~PushInfo.NEW_HEAD
        unprocessed_flags &= ~PushInfo.NEW_TAG

    if unprocessed_flags != 0:
        raise RuntimeError(
            f'Failed to push task "{task_name}": {status[0].flags} {unprocessed_flags} {status[0].summary}')


def main(cwd):
    try:
        task_name = infer_task_name_from_directory(cwd)
        repo = Repo(os.path.dirname(cwd))
    except (NoSuchPathError, InvalidGitRepositoryError) as e:
        print('Failed to open your git repository.\n' +
              'Please check you run submit.py inside a task directory.')
        exit(1)

    uncommitted_files = uncommitted_changes(repo, task_name)
    if uncommitted_files:
        print('There are uncommitted changes:\n' +
              "\n".join(f' * {file}' for file in uncommitted_files) +
              '\nPlease either commit or stash them.')
        exit(2)

    try:
        remote = repo.remote(REMOTE_NAME)
    except ValueError:
        print(f'Remote "{REMOTE_NAME}" does not exist.\n' +
              'Please create it according to the course tutorial.')
        exit(3)

    try:
        push_task(remote, task_name)
    except RuntimeError as e:
        print(e)
        exit(4)


if __name__ == '__main__':
    main(os.getcwd())
