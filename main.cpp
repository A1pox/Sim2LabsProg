#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    bool* sieve = new bool[n + 1];
    for(int i = 0; i <= n; i++) sieve[i] = true;
    if(n >= 0) sieve[0] = false;
    if(n >= 1) sieve[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(sieve[i]){
            for(int j = i * i; j <= n; j += i){
                sieve[j] = false;
            }
        }
    }
    cout << "Prime numbers: ";
    for(int i = 2; i <= n; i++){
        if(sieve[i]) cout << i << " ";
    }
    delete[] sieve;
    return 0;
}
