#include <iostream>
#include <cassert> // This is a C standard library header file called <assert.h>
                   // The C++ version of this C header file is called <cassert>

int main() {
    
    ////////////////////////////////////////////////////////////
    // 1. assert()
    ////////////////////////////////////////////////////////////
    //
    // If you've noticed, you've been trying to pass programs that use the 
    // assert() macro that can be used to "assert" that a condition is correct, 
    // or abort a program
    //
    // assert() macros are extremely useful for testing! In fact, they are 
    // optimized such that if you provide the NDEBUG macro flag, they will be 
    // optimized out of a program. So, you can compile your program in a "DEBUG" 
    // or a "RELEASE" mode -- one for debugging and testing, the other one for 
    // official release.
    //
    // This is how many companies do software engineering -- they will often 
    // alpha and beta-test their products with many assert() and test cases, and 
    // then optimize them out upon release.

    // The assert() macro is simple -- it either passes if the condition inside 
    // resolves to true, or aborts the program if it resolves to 0 or false.
    //
    // Therefore, here are three examples, where the final ones fails.
    //
    // Note that assert() also reports the file and line that it failed on! 
    // Convenient!
    assert(1 + 1 == 2);
    assert("The sky is blue");
    assert(1 / 2 == 1);
}
