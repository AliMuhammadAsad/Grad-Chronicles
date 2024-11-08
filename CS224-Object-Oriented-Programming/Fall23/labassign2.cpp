/*
Create a base class Shape. Each Shape has a 2D location (Point). There are three inherited classes from Shape: Circle, Square and Triangle. Each Circle has a radius
member variable. Provide appropriate constructors, accessor and mutator functions for it. Square has a size member variable that represents its size. Provide
appropriate constructors, accessor and mutator functions for it. Triangle has two member variables: base and height. Provide appropriate constructors, accessor and
mutator functions. There are two pure virtual functions in the Shape class. The first function intersects is declared as follows:
virtual bool intersects(const Point& point)=0;
This function returns true if the given point intersects a given Shape. The second function getArea returns the area of the given Shape. It is declared as follows:
virtual float getArea()=0;
This function returns the area of the given shape. Note that for calculating the area of triangle, you can use the formula ½ * base * height, for Circle the area can be calculated using PI*r2 and for square its size*size. Inherit three classes from the Shape class, Circle, Square, Triangle and implement the intersects and getArea functions in all of them. Provide appropriate default, two parameters, copy constructor and assignment operator in Shape class. For all other classes, provide an appropriate constructor depending on the additional member variables that are needed to be assigned. Overload the stream insertion operator to
output the details about the Shape that is for parent class Shape, you should output
Shape [x: {x pos}, y: {y pos}]
For child classes only output additional attributes stored for each class for e.g. for Circle lets In main, create a vector of Shape objects dynamically and populate it with an object of each child class that is Circle, Square, Triangle. Then polymorphically call the intersect function using the Shape pointer.
*/

#include<bits/stdc++.h>
using namespace std;
const float PI = 3.1415936;

class Point{
    public:
    float x, y;
    Point(float x = 0.0, float y = 0.0) : x(x), y(y){}
};

class Shape{
    protected:
    Point location;

    public:
    Shape(float x = 0.0, float y = 0.0) : location(x, y){}
    // Shape(const Shape& other) : location(other.location){}

    Shape& operator=(const Shape& other){
        if(this != &other){
            location = other.location;
        }
        return *this;
    }

    virtual bool intersects(const Point& point) = 0;
    virtual float getArea() const = 0;
    virtual string getType() const = 0;

    friend ostream& operator << (ostream& os, const Shape& shape);
};

ostream& operator<<(ostream& os, const Shape& shape){
    os << "Shape [x: " << shape.location.x << ", y: " << shape.location.y << "]";
    return os;
}

class Circle: public Shape{
    float radius;

    public:
    Circle(float x = 0.0, float y = 0.0, float radius = 0.0) : Shape(x, y), radius(radius){}

    bool intersects(const Point& point){
        float dx = point.x - location.x, dy = point.y - location.y;
        return sqrt(dx * dx + dy * dy) <= radius;
    }

    float getArea() const{
        return PI * radius * radius;
    }

    string getType() const{
        return "Circle";
    }

    friend ostream& operator << (ostream& os, const Circle& circle){
        os << static_cast<const Shape&>(circle);
        os << ", Radius: " << circle.radius;
        return os;
    }
};

class Square: public Shape{
    float size;
    
    public:
    Square(float x = 0.0, float y = 0.0, float size = 0.0) : Shape(x, y), size(size){}

    bool intersects(const Point& point) override {
        return abs(point.x - location.x) <= size / 2 && abs(point.y - location.y) <= size / 2;
    }

    float getArea() const{
        return size * size;
    }

    string getType() const{
        return "Square";
    }

    friend ostream& operator << (ostream& os, const Square& square){
        os << static_cast<const Shape&>(square);
        os << ", Size: " << square.size;
        return os;
    }
};

class Triangle: public Shape{
    float base, height;

    public:
    Triangle(float x = 0.0, float y = 0.0, float base = 0.0, float height = 0.0) : Shape(x, y), base(base), height(height){}

    bool intersects(const Point& point) override {
        // Vertices of the triangle
        Point leftBase(location.x - base / 2, location.y);    // Left vertex of base
        Point rightBase(location.x + base / 2, location.y);   // Right vertex of base
        Point apex(location.x, location.y + height);          // Apex of the triangle

        // Point-in-triangle test
        auto sign = [](const Point& p1, const Point& p2, const Point& p3) {
            return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
        };

        bool b1, b2, b3;
        b1 = sign(point, leftBase, rightBase) < 0.0f;
        b2 = sign(point, rightBase, apex) < 0.0f;
        b3 = sign(point, apex, leftBase) < 0.0f;

        return ((b1 == b2) && (b2 == b3));
    }

    float getArea() const{
        return 0.5 * base * height;
    }

    string getType() const{
        return "Triangle";
    }

    friend ostream& operator << (ostream& os, const Triangle& triangle){
        os << static_cast<const Shape&>(triangle);
        os << ", Base: " << triangle.base << ", Height: " << triangle.height;
        return os;
    }
};

int main(){
    vector<Shape*> shapes;

    shapes.push_back(new Circle(1.0, 1.0, 2.0));
    shapes.push_back(new Square(3.0, 3.0, 4.0));
    shapes.push_back(new Triangle(0, 0, 3.0, 4.0));
    // shapes.push_back(new Circle(1.0, 1.0, 1.0));
    // shapes.push_back(new Square(2.0, 2.0, 2.0));
    // shapes.push_back(new Triangle(3.0, 3.0, 3.0, 3.0));

    Point testPoint(2, 2);

    for(const auto& shape : shapes){
        cout << shape->getType() << ": " << endl;
        cout << (shape->intersects(testPoint) ? "Intersects " : "Does not intersect ");
        cout << "with point (" << testPoint.x << ", " << testPoint.y << ")" << endl;
        cout << "Area: " << shape->getArea() << endl << endl;
    }

    return 0;
}