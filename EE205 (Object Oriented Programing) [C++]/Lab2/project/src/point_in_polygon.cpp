// Always include the original .hpp that corresponds to the .cpp
#include "point_in_polygon.hpp"

// Here is the original C version from Stack Overflow.
// 
// Adapt it to use Person objects and a Person array
// instead of just pure x/y coordinates.
//
// Make the function match the types in the function
// declaration in "point_in_polygon.hpp"
//
// Remember -- the algorithm already essentially works!
//
// You just need to have it use our C++ object type now!
//
//int pnpoly(
//        int nvert,
//        float *vertx,
//       float *verty,
//       float testx,
//        float testy) {
//    int i, j, c = 0;
//    for (i = 0, j = nvert-1; i < nvert; j = i++) {
//        if (((verty[i]>testy) !=
//                    (verty[j]>testy)) && (testx <
//                        (vertx[j]-vertx[i]) *
//                        (testy-verty[i]) /
//                        (verty[j]-verty[i]) + vertx[i]) ) {
//            c = !c;
//        }
//    }
//    return c;
//}

bool pnpoly(std::size_t nvert, Person* location,Person Pers){
	int i, j, c = 0;
	float testx = Pers.get_location().get_x();
	float testy = Pers.get_location().get_y();

    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if (((location[i].get_location().get_y()>testy) !=
                    (location[j].get_location().get_y())>testy) && (testx <
                        (location[j].get_location().get_y()-location[i].get_location().get_x()) *
                        (testy-location[i].get_location().get_y()) /
                        (location[j].get_location().get_y()-location[i].get_location().get_y()) + location[i].get_location().get_x())) {
            c = !c;
        }
    }
    return c;
}

