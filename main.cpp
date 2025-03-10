#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    double *a = new double[n];
    double **b = new double*[n];
    srand(time(0));
    for(int i = 0; i < n; i++){
        a[i] = (rand() % 201 - 100) + (rand() % 100 / 100.0);
        b[i] = &a[i];
    }
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\nSorted array: ";
    sort(b, b + n, [](double* p1, double* p2) { return *p1 < *p2; });
    for(int i = 0; i < n; i++){
        cout << *b[i] << " ";
    }
    delete[] a;
    delete[] b;
    return 0;
}
