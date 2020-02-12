#include "Point2D.hpp"
#include <cassert>

int main() {

    // Test: Default constructor == (0, 0)
    {
        Point2D p;
        assert(p.get_x() == 0);
        assert(p.get_y() == 0);
    }

    // Test: Constructor (x, y) == (x, y)
    {
        const float X_COORD = 1;
        const float Y_COORD = 2;
        Point2D p(X_COORD, Y_COORD);
        assert(p.get_x() == X_COORD);
        assert(p.get_y() == Y_COORD);
    }

    // Test: setting x/y components
    {
        Point2D p;
        p.set_x(123);
        p.set_y(456);
        assert(p.get_x() == 123);
        assert(p.get_y() == 456);
    }
}
