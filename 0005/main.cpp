// Smallest multiple
//
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>


bool isDivisible(int num, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(num % i != 0)
            return false;
    }
    return true;
}

int main() {
    int start = 1;
    int end = 20;

    int num = end;
    while(true) {
        if(isDivisible(++num, start, end))
            break;
    }
    std::cout << num << std::endl;
    exit(0);
}
