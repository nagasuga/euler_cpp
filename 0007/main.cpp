// 10001st prime
//
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?

#include <iostream>
#include <vector>

std::vector<int> sieveOfEratosthenes(int max) {
    std::vector<int> primes;
    for(int i=2; i < max; i++) {
        bool notPrime = false;
        for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            if(i % *it == 0) {
                //std::cout << "skip " << *it << std::endl;
                notPrime = true;
                break;
            }
        }

        if(!notPrime) {
            //std::cout << "add " << i << std::endl;
            primes.push_back(i);
        }
    }
    return primes;
}


int getNthPrime(int n) {
    /* Returns the n-th prime number. */
    std::vector<int> primes;
    int counter = 2;
    while(true) {
        bool notPrime = false;
        for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            if(counter % *it == 0) {
                //std::cout << "skip " << *it << std::endl;
                notPrime = true;
                break;
            }
        }

        if(!notPrime) {
            primes.push_back(counter);
            if(primes.size() == n) {
                return counter;
            }
        }
        counter++;
    }
}


int main() {
    int max = 1000000;

    //std::vector<int> res = sieveOfEratosthenes(max);
    //for(std::vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
    //    std::cout << *it << std::endl;
    //}

    //for(std::vector<int>::size_type i = 0; i != res.size(); i++) {
    //    if(i + 1 == 10001)
    //        std::cout << i + 1 << ": " << res[i] << std::endl;
    //}

    std::cout << getNthPrime(10001) << std::endl;
    exit(0);
}
