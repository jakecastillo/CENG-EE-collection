#include <iostream>
#include <cassert>
#include <cmath>

template <typename T>
class Point2D {
    T x;
    T y;
public:
    Point2D(T x_, T y_) :
        x(x_),
        y(y_) {}

    T get_x() const { return x; }
    T get_y() const { return y; }

    void set_x(T t) { x = t; }
    void set_y(T t) { y = t; }
};

Point2D<int> float_to_int(Point2D<float> p) {
    int x,y;
    x = p.get_x();
    y = p.get_y();
    return Point2D<int>(x,y);
}

int main() {
    // This is a 2D point with ints
    Point2D<int>    p1(1, 2);
    // This is a 2D point with floats
    Point2D<float>  p2(1.2345, 2.1233123);

    // Can you write a function to convert a float-based Point2D
    // to an int-based Point2D?
    Point2D<int>    converted_p2 = float_to_int(p2);

    // The function should truncate or always round down.
    assert(p1.get_x() == converted_p2.get_x() &&
           p1.get_y() == converted_p2.get_y() && 
           "Your conversion was implemented incorrectly. You should try "
           "casting up to float from int before comparison or by simply "
           "using the normal operator==.");

    std::cout << "SUCCESS" << std::endl;
}
