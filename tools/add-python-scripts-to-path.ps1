$PATH = [Environment]::GetEnvironmentVariable('PATH', [EnvironmentVariableTarget]::User)
$pythonScriptsPaths=(pip show pre-commit) -match 'Location' -replace 'Location: (.+)(site-packages)', '$1Scripts'
$PATH += ";" + $pythonScriptsPaths
[Environment]::SetEnvironmentVariable('PATH',$PATH, [EnvironmentVariableTarget]::User)
Read-Host -Prompt "Press Enter to exit"
