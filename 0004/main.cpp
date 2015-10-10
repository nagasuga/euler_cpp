// Largest palindrome product
//
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>


bool isPalindrome(int num) {
    int digit;
    int revNum = 0;
    for(int i = num; i > 0; i /= 10) {
        digit = i % 10;
        revNum = (revNum * 10) + digit;
    }
    return num == revNum;
}

int largestPalindrome(int one, int two) {
    int max = 0;
    for(int i = two; i > 100; i--) {
        for(int j = one; j > 100; j--) {
            int num = j * i;
            if(isPalindrome(num) && num > max)
                max = num;
        }
        two--;
    }
    return max;
}

int main() {
    int one = 999;
    int two = 999;
    std::cout << largestPalindrome(one, two) << std::endl;
    exit(0);
}
