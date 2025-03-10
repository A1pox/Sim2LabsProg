#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int m, k;
    cout << "Enter number of elements (m): ";
    cin >> m;
    cout << "Enter number of elements per row (k): ";
    cin >> k;
    if(k >= m){
        cout << "k must be less than m.";
        return 1;
    }
    int *A = new int[m];
    srand(time(0));
    for(int i = 0; i < m; i++){
        A[i] = rand() % 101 - 50;
    }
    int rows = (m + k - 1) / k;
    int **B = new int*[rows];
    for(int i = 0; i < rows; i++){
        B[i] = new int[k];
    }
    int index = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < k; j++){
            if(index < m)
                B[i][j] = A[index++];
            else
                B[i][j] = 0;
        }
    }
    cout << "Matrix B:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < k; j++){
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    delete[] A;
    for(int i = 0; i < rows; i++){
        delete[] B[i];
    }
    delete[] B;
    return 0;
}
