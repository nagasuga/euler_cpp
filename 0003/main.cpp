// Largest prime factor
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <vector>
#include <iostream>

std::vector<int> getPrimeFactors(long num) {
    std::vector<int> primeFactor;
    int divisor = 2;
    while(num > 1) {
        if(num % divisor == 0) {
            primeFactor.push_back(num);
            num = num / divisor;
        }
        divisor++;
    }
    return primeFactor;
}

int main() {
    long num = 600851475143;
    std::vector<int> primeFactor = getPrimeFactors(num);
    
    std::cout << primeFactor.back() << std::endl;
    exit(0);
}
