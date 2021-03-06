#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "X()" << '\n'; }
    X(const X &) { std::cout << "X(const X &)" << '\n'; }
    X &operator=(const X &) {
        std::cout << "X &operator=(const X &)" << '\n';
        return *this;
    }
    ~X() { std::cout << "~X()" << '\n'; }
};

void F(const X &rx, X x) {
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main() {

    X *px = new X;

    F(*px, *px);

    delete px;

    return 0;
}
