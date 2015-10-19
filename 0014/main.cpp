// Longest Collatz sequence
//
// The following iterative sequence is defined for the set of positive integers:
//
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence:
//
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.

#include <iostream>
#include <vector>
#include <unordered_map>

const int MAX = 1000000;

long getLongestChain() {
    long longestNum;
    long longestCount = 0;

    std::unordered_map<long, long> chainByNum;
    std::unordered_map<long, long>::const_iterator found;
    for(int i = 1; i <= MAX; i++) {
        if(i % 10000 == 0)
            std::cout << "** " << i << std::endl;

        std::vector<long> chains;

        long num = i;
        chains.push_back(num);
        while(num != 1) {
            found = chainByNum.find(num);

            if(found != chainByNum.end()) {
                break;
            } else if(num % 2 == 0) {
                num = num / 2;
            } else {
                num = 3 * num + 1;
            }
            chains.push_back(num);
        }

        long total = chains.size();
        if(found != chainByNum.end()) {
            total += found->second - 1;
        }

        chainByNum.insert({i, total});
        if(longestCount < total) {
            longestNum = i;
            longestCount = total;
        }
    }

    //for(auto i : chainByNum) {
    //    std::cout << i.first << ": " << i.second << std::endl;
    //}

    return longestNum;
}

int main() {
    std::cout << getLongestChain() << std::endl;
    exit(0);
}
