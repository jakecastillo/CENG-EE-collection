#include <iostream>

#include "Point2D.hpp"
#include "Person.hpp"
#include "point_in_polygon.hpp"

int main() {
    // To simplify the lab, we're not going to use dynamic allocation.
    unsigned num_points = 0;
    Person points[100];
    // In the future, we would want to use a std::vector<Person> here instead.

    // The main I/O loop.
    bool done = false;
    while (!done) {
        // The input prompt
        std::cout << "============================================================" << std::endl;
        std::cout << "person:   Add a new person" << std::endl;
        std::cout << "find:     Determine if the last person is within the polygon" << std::endl;
        std::cout << "          formed by the others" << std::endl;
        std::cout << "clear:    Clear all points" << std::endl;
        std::cout << "quit:     Quit the program" << std::endl;
        std::cout << "============================================================" << std::endl;

        // The string object to read the next command
        std::string s; 

        // Read in the next word (that is, until a space/newline) into the string
        std::cin >> s;

        // This adds a new person
        if (s == "person") {
            // Cannot have more than 100 people.
            if (num_points >= 100) {
                std::cout << "Cannot add more than 100 people" << std::endl;
                continue;
            }
            // Else, parse in the name, x-coord, and y-coord
            std::cout << "name(no spaces) x y: ";
            float x, y;
            std::string s;
            std::cin >> s >> x >> y;
    
            // Add the Person to the array
            points[num_points] = Person(s, x, y);
            num_points++;

            // Print a response
            std::cout << "Added point #" << num_points << std::endl;

        }
        // Determines whether the last person is in the polygon formed by the
        // points of the prior people.
        else if (s == "find") {
            // The minimum number of points for a 2D-polygon is 3, so we must have
            // at least 4 points input so far.
            if (num_points < 4) {
                std::cout << "Must have at least 3 people to form in a polygon and "
                    "1 person to find inside of the polygon" << std::endl;
                continue;
            }
            // Print out the points first.
            for (int i = 0; i < num_points; ++i) {
                std::cout << "Point #" << i+1 << ": "
                    << "(" << points[i].get_name()
                    << "," << points[i].get_location().get_x()
                    << "," << points[i].get_location().get_y() << ")" << std::endl;
            }
            // Determine whether the person lies inside the polygon.
            bool is_inside = pnpoly(num_points-1, &points[0], points[num_points-1]);

            // Print the result.
            if (is_inside) {
                std::cout << points[num_points-1].get_name() << " is within the polygon." << std::endl;
            } else {
                std::cout << points[num_points-1].get_name() << " is outside the polygon." << std::endl;
            }
        }
        // Since Person allocates no memory, we don't need to free anything.
        // So it's safe if we just reset the count to 0 and overwrite memory
        // as needed.
        else if (s == "clear") {
            num_points = 0;
        }
        // Set the loop termination flag.
        else if (s == "quit") {
            done = true;
        }
        // Always clear the input string before the next iteration of the loop!
        s.clear();
    }
}


