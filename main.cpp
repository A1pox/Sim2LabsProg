#include <iostream>
#include <cmath>
using namespace std;
bool computeProbabilities(int n, int m, double& pd, double& pm) {
    if(n <= 0 || m < 0 || m > n) return false;
    double p = 0.45, q = 1 - p;
    double comb = tgamma(n + 1) / (tgamma(m + 1) * tgamma(n - m + 1));
    pd = comb * pow(p, m) * pow(q, n - m);
    pm = comb * pow(q, m) * pow(p, n - m);
    return true;
}
int main(){
    int n, m;
    cout << "Enter number of children (n): ";
    cin >> n;
    cout << "Enter required number (m): ";
    cin >> m;
    double probabilityGirls, probabilityBoys;
    if(computeProbabilities(n, m, probabilityGirls, probabilityBoys)) {
        cout << "Probability of exactly " << m << " girls: " << probabilityGirls << "\n";
        cout << "Probability of exactly " << m << " boys: " << probabilityBoys << "\n";
    } else {
        cout << "Error: invalid input data." << "\n";
    }
    return 0;
}
