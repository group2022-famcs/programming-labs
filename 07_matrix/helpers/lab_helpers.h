//
// Created by Dmitriy V. Baranov on 17.09.2021.
//

#ifndef LAB7__LAB_HELPERS_H_
#define LAB7__LAB_HELPERS_H_

#include <cassert>
#include <string>
#include <vector>

#define assertm(exp, msg) assert(((void)msg, exp))
// NOLINTBEGIN
#include "./stb_image.h"
#include "./stb_image_write.h"
// NOLINTEND

std::vector<std::vector<int>> loadGrayscaleImage(const std::string& filename);
void writeGrayscaleImage(const std::vector<std::vector<int>>& image, const std::string& filename);

#endif // LAB7__LAB_HELPERS_H_
