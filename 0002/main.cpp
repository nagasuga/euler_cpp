// Even Fibonacci numbers
// 
// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.


#include <iostream>

#define FOUR_MILLION 4000000

int sumFibonacci(int max) {
    int num1 = 1;
    int num2 = 2;
    int temp;
    int sum = 0;
    while(num2 < max) {
        if(num2 % 2 == 0)
            sum += num2;

        temp = num2;
        num2 += num1;
        num1 = temp;
    }
    return sum;
}

int main() {
    std::cout << sumFibonacci(FOUR_MILLION) << std::endl;
    exit(0);
}
