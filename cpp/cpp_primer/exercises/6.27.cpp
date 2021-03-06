#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> lst) {
    int sum = 0;
    for(const auto& e : lst) {
        sum += e;
    }
    return sum;
}

int main() {
    std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
    return 0;
}
