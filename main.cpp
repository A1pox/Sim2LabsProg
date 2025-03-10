#include <iostream>

double power(double x, int n) {
    double result = 1.0;
    bool isNegative = (n < 0);

    if (isNegative) n = -n;

    for (int i = 0; i < n; ++i) {
        result *= x;
    }

    return isNegative ? 1.0 / result : result;
}

int main() {
    double x;
    int n;

    std::cout << "Enter base (x): ";
    std::cin >> x;
    std::cout << "Enter exponent (n): ";
    std::cin >> n;

    std::cout << "Result: " << power(x, n) << std::endl;
    return 0;
}
