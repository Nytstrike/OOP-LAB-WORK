#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

class Shape {
protected:
    double x, y;
    std::string color;
    double borderThickness;

public:
    Shape(double x = 0, double y = 0, std::string color = "black", double borderThickness = 1.0)
        : x(x), y(y), color(color), borderThickness(borderThickness) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, std::string color, double borderThickness, double radius)
        : Shape(x, y, color, borderThickness), radius(radius) {}

    void draw() override {
        std::cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius 
                  << ", color " << color << ", and border thickness " << borderThickness << ".\n";
    }

    double calculateArea() override {
        return PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double x, double y, std::string color, double borderThickness, double width, double height)
        : Shape(x, y, color, borderThickness), width(width), height(height) {}

    void draw() override {
        std::cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width 
                  << " and height " << height << ", color " << color << ", and border thickness " 
                  << borderThickness << ".\n";
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double x, double y, std::string color, double borderThickness, double side1, double side2, double side3)
        : Shape(x, y, color, borderThickness), side1(side1), side2(side2), side3(side3) {}

    void draw() override {
        std::cout << "Drawing Triangle at (" << x << ", " << y << ") with sides " << side1 << ", " 
                  << side2 << ", and " << side3 << ", color " << color << ", and border thickness " 
                  << borderThickness << ".\n";
    }

    double calculateArea() override {
        double s = (side1 + side2 + side3) / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(0, 0, "magneta", 6, 9);
    Rectangle rectangle(1, 1, "crimson", 1, 4, 6);
    Triangle triangle(2, 2, "Cream", 1, 7, 7, 5);

    Shape* shapes[] = { &circle, &rectangle, &triangle };

    for (Shape* shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->calculateArea() << std::endl;
        std::cout << "Perimeter: " << shape->calculatePerimeter() << std::endl;
    }

    return 0;
}
