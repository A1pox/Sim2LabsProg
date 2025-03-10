#include <iostream>

using namespace std;

void printPositiveNumbers() {
    int num;
    cin >> num;

    if (num == 0)
        return;

    if (num > 0)
        cout << num << " ";

    printPositiveNumbers();
}

int main() {
    cout << "Enter numbers (end with 0): ";
    printPositiveNumbers();
    return 0;
}
