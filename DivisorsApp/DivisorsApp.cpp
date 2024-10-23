#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm> 
#include "..\DivisorsLib\Divisors.h"
#include "..\benchmark\benchmark.h"

std::vector<unsigned long long> divisors(unsigned long long number) {
    std::vector<unsigned long long> result;
    if (number < 1) return result;

    result.reserve(100); 
    unsigned long long sqrt_n = static_cast<unsigned long long>(std::sqrt(number));

    for (unsigned long long i = 1; i <= sqrt_n; ++i) {
        if (number % i == 0) {
            result.push_back(i);
            if (i != number / i) {
                result.push_back(number / i);
            }
        }
    }

    std::sort(result.begin(), result.end()); 
    return result;
}

int main() {
    unsigned long long number = 0ULL;
    std::ios::sync_with_stdio(false); 

    do {
        std::cout << "Number: ";
        std::cin >> number;

        Benchmark<std::chrono::milliseconds> benchmark;

        std::vector<unsigned long long> result = divisors(number);

        auto t = benchmark.elapsed();

        std::cout << "\n" << number << " divisors (" << result.size() << ", ";
        std::cout << t / 1000 << "." << std::setw(3) << std::setfill('0') << t % 1000 << std::setfill(' ');
        std::cout << "s):\n";

        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0)
                std::cout << ",";
            std::cout << result[i];
        }
        std::cout << "\n";

    } while (number > 0);
}
