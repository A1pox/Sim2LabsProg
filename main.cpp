#include <iostream>
using namespace std;

void printNegatives(int arr[], int n) {
    if (n == 0) return;

    if (arr[0] < 0) {
        cout << arr[0] << " ";
    }
    printNegatives(arr + 1, n - 1);
}

void printPositives(int arr[], int n) {
    if (n == 0) return;

    if (arr[0] > 0) {
        cout << arr[0] << " ";
    }
    printPositives(arr + 1, n - 1);
}

void printAllNumbers(int arr[], int n) {
    printNegatives(arr, n);
    printPositives(arr, n);
}

int main() {
    int N = 0;
    int* arr = nullptr;

    cout << "Enter non-zero integers (enter 0 to stop): ";
    int num;
    while (true) {
        cin >> num;
        if (num == 0) break;

        if (arr == nullptr) {
            arr = new int[1];
            arr[0] = num;
            N = 1;
        } else {
            int* temp = new int[N + 1];
            for (int i = 0; i < N; ++i) {
                temp[i] = arr[i];
            }
            temp[N] = num;
            delete[] arr;
            arr = temp;
            N++;
        }
    }

    if (N > 0) {
        cout << "Negative numbers first, then positive numbers: ";
        printAllNumbers(arr, N);
    } else {
        cout << "No numbers entered.";
    }

    delete[] arr;
    return 0;
}
