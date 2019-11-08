#include <range/v3/algorithm.hpp>
#include <range/v3/core.hpp>
#include <range/v3/view/iota.hpp>

#include <iostream>

template <int N, typename TFunction>
void repeat_n(TFunction f) {
    ranges::for_each(ranges::view::iota(1, N), [f](int i) {
        f(i);
    });
}

int main() {
    repeat_n<10>([](int i) {
        std::cout << "Hello, World - " << i << '\n';
    });
}
