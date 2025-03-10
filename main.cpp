#include <iostream>
using namespace std;
int main(){
    int rows = 9;
    int** table = new int*[rows];
    for(int i = 0; i < rows; i++){
        table[i] = new int[i+1];
        for(int j = 0; j < i+1; j++){
            table[i][j] = (i+1) * (j+1);
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < i+1; j++){
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i = 0; i < rows; i++){
        delete[] table[i];
    }
    delete[] table;
    return 0;
}
