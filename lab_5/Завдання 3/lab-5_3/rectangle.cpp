#include "rectangle.h"
#include <algorithm>

Rectangle::Rectangle(int width, int height)
    : width(width), height(height)
{
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive integers.");
    }
}

Rectangle::~Rectangle() {}

Rectangle Rectangle::operator+(const Rectangle& other) const {
    int newWidth = std::max(width, other.width);
    int newHeight = std::max(height, other.height);
    return Rectangle(newWidth, newHeight);
}

Rectangle Rectangle::operator-(const Rectangle& other) const {
    int newWidth = std::max(1, width - other.width); // Мінімальна ширина 1
    int newHeight = std::max(1, height - other.height); // Мінімальна висота 1
    return Rectangle(newWidth, newHeight);
}

Rectangle Rectangle::operator*(int factor) const {
    return Rectangle(width * factor, height * factor);
}

Rectangle Rectangle::operator/(int divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return Rectangle(width / divisor, height / divisor);
}

bool Rectangle::operator==(const Rectangle& other) const {
    return width == other.width && height == other.height;
}

bool Rectangle::operator!=(const Rectangle& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle(width: " << rect.width << ", height: " << rect.height << ")";
    return os;
}
