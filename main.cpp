#include <iostream>
using namespace std;
void decToBinary(int n) {
    if(n > 1) decToBinary(n / 2);
    cout << n % 2;
}
int main(){
    int n;
    cin >> n;
    cout << "Binary representation: ";
    if(n == 0) cout << "0";
    else if(n < 0) {
        cout << "-";
        decToBinary(-n);
    } else {
        decToBinary(n);
    }
    return 0;
}
