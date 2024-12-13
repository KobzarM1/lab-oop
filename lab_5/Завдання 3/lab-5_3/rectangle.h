#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
public:
    Rectangle(int width, int height);
    ~Rectangle();

    Rectangle operator+(const Rectangle& other) const;
    Rectangle operator-(const Rectangle& other) const;
    Rectangle operator*(int factor) const;
    Rectangle operator/(int divisor) const;
    bool operator==(const Rectangle& other) const;
    bool operator!=(const Rectangle& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

private:
    int width;
    int height;
};

#endif // RECTANGLE_H
