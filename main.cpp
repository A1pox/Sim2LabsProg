#include <iostream>
#include <cmath>

using namespace std;

double taylorCos(double x, double eps) {
    double term = 1.0;
    double sum = term;
    int n = 1;

    while (fabs(term) >= eps) {
        term *= (-1) * x * x / (2 * n * (2 * n - 1));
        sum += term;
        n++;
    }

    return sum;
}

int main() {
    double x;
    cout << "Введите значение x (в радианах): ";
    cin >> x;

    double eps = 0.0001;
    double result = taylorCos(x, eps);
    double standard = cos(x);

    cout << "Ряд Тейлора: " << result << endl;
    cout << "Стандартный cos(x): " << standard << endl;

    return 0;
}
