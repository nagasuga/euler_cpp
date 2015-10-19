// Summation of primes
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.


#include <iostream>
#include <math.h>
#include <vector>


bool isPrime(unsigned long long num) {
    if(num == 2 || num == 3)
        return true;

    if(num % 2 == 0)
        return false;

    for(int i = 3; i < sqrt(num) + 1; i += 2) {
        if(num % i == 0)
            return false;
    }
    return true;
}


std::vector<int> getPrimes(int num) {
    std::vector<int> primes;
    for(int i = 2; i <= num; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

long sumOfPrimes(long num) {
    std::vector<int> primes = getPrimes(num);

    long sum = 0;
    for(int i = 2; i < num; i++) {
        if(isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    std::cout << sumOfPrimes(2000000) << std::endl;
    exit(0);
}
