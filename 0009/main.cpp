// Special Pythagorean triplet
//
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <math.h>


bool isPythagorenTriplet(int a, int b, int c) {
    return (a * a) + (b * b) == (c * c);
}


int main() {
    int c = 400;
    int a;
    int b;
    bool isFound = false;
    do {
        for(b = c - 1; b > 1; b--) {
            a = 1000 - c - b;
            if(a >= b || a <= 1)
                break;

            if(isPythagorenTriplet(a, b, c)) {
                isFound = true;
                std::cout << a << ", " << b << ", " << c << " = " << a * b * c << std::endl;
            }
        }
        c++;
    } while(!isFound);
    exit(0);
}
