#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./lab_helpers.h"

std::vector<std::vector<int>> loadGrayscaleImage(const std::string& filename) {
    int width;
    int height;
    int bpp;
    uint8_t* image = stbi_load(filename.c_str(), &width, &height, &bpp, 1);
    assertm(image, "Can not read image. May be it is corrupted, invalid or simply not found");
    assertm(width > 0, "Image width should be positive");
    assertm(height > 0, "Image height should be positive");
    assertm(
        static_cast<long long>(width) * height <= 1e9,
        "Image total pixels number should not exceed 1 billion"
    );

    std::vector<std::vector<int>> imageVector(height, std::vector<int>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            imageVector[i][j] = image[i * width + j];
        }
    }
    stbi_image_free(image);
    return imageVector;
}

void writeGrayscaleImage(const std::vector<std::vector<int>>& image, const std::string& filename) {
    auto height = image.size();
    assertm(height > 0, "Image should have positive height");
    auto width = image.front().size();
    assertm(width > 0, "Image should have positive width");
    assertm(
        static_cast<long long>(width) * height <= 1e9,
        "Image total pixels number should not exceed 1 billion"
    );
    std::vector<uint8_t> imageVector(height * width);
    for (size_t i = 0; i < imageVector.size(); ++i) {
        imageVector[i] = image[i / width][i % width];
    }
    stbi_write_jpg(
        filename.c_str(), static_cast<int>(width), static_cast<int>(height), 1, imageVector.data(),
        100
    );
}

std::vector<std::vector<std::vector<int>>> loadRgbImage(const std::string& filename) {
    int width;
    int height;
    int bpp;
    uint8_t* image = stbi_load(filename.c_str(), &width, &height, &bpp, 3);
    assertm(image, "Can not read image. May be it is corrupted, invalid or simply not found");
    assertm(width > 0, "Image width should be positive");
    assertm(height > 0, "Image height should be positive");
    assertm(bpp == 3, "Image should have exactly 3 channels");
    assertm(
        static_cast<long long>(width) * height <= 1e9,
        "Image total pixels number should not exceed 1 billion"
    );

    std::vector<std::vector<std::vector<int>>> imageVector(
        height, std::vector<std::vector<int>>(width, std::vector<int>(3))
    );
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < 3; ++k) {
                imageVector[i][j][k] = image[width * 3 * i + 3 * j + k];
            }
        }
    }
    stbi_image_free(image);
    return imageVector;
}

void writeRgbImage(
    const std::vector<std::vector<std::vector<int>>>& image, const std::string& filename
) {
    auto height = image.size();
    assertm(height, "Image should have non-zero height");
    auto width = image.front().size();
    assertm(width, "Image should have non-zero width");
    assertm(image.front().front().size(), "Image should have exactly 3 channels");

    std::vector<uint8_t> imageVector(height * width * 3, 0);
    for (size_t i = 0; i < imageVector.size(); ++i) {
        auto row = i / 3 / width;
        auto offset = i - row * 3 * width;
        imageVector[i] += image[row][offset / 3][offset % 3];
    }
    stbi_write_jpg(
        filename.c_str(), static_cast<int>(width), static_cast<int>(height), 3, imageVector.data(),
        100
    );
}
