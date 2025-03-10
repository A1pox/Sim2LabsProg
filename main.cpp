#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    srand(time(0));
    int **A = new int*[m];
    for(int i = 0; i < m; i++){
        A[i] = new int[n];
    }
    cout << "\nMatrix A:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand() % 101 - 50;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    int **D = new int*[m+1];
    for(int i = 0; i < m+1; i++){
        D[i] = new int[n+1];
    }
    int totalSum = 0;
    for(int i = 0; i < m; i++){
        int rowSum = 0;
        for(int j = 0; j < n; j++){
            D[i][j] = A[i][j];
            rowSum += A[i][j];
        }
        D[i][n] = rowSum;
        totalSum += rowSum;
    }
    for(int j = 0; j < n; j++){
        int colSum = 0;
        for(int i = 0; i < m; i++){
            colSum += A[i][j];
        }
        D[m][j] = colSum;
    }
    D[m][n] = totalSum;
    cout << "\nMatrix D:" << endl;
    for(int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            cout << D[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i = 0; i < m; i++){
        delete[] A[i];
    }
    delete[] A;
    for(int i = 0; i < m+1; i++){
        delete[] D[i];
    }
    delete[] D;
    return 0;
}
