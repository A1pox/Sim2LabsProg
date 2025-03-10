#include <iostream>

std::string calculateEasterDate(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;

    if (f <= 26) {
        return "April " + std::to_string(4 + f);
    } else {
        return "May " + std::to_string(f - 26);
    }
}

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;
    std::cout << "Easter falls on: " << calculateEasterDate(year) << std::endl;
    return 0;
}
