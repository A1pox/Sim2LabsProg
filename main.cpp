#include <iostream>
#include <cmath>
using namespace std;
int triangleProps(double a, double b, double c, double* perimeter, double* area) {
    if(a + b <= c || a + c <= b || b + c <= a)
        return 0;
    *perimeter = a + b + c;
    double s = *perimeter / 2;
    *area = sqrt(s * (s - a) * (s - b) * (s - c));
    return 1;
}
int main(){
    double a, b, c;
    cout << "Enter the sides of the triangle: ";
    cin >> a >> b >> c;
    double p, A;
    if(triangleProps(a, b, c, &p, &A))
        cout << "Perimeter: " << p << "\nArea: " << A;
    else
        cout << "Error: Triangle cannot exist with the given sides.";
    return 0;
}
