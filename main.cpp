#include <iostream>
using namespace std;
void resetBetweenMin(int arr[], int n) {
    int minVal = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < minVal)
            minVal = arr[i];
    }
    int first = -1, second = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == minVal){
            if(first == -1) first = i;
            else {
                second = i;
                break;
            }
        }
    }
    if(first != -1 && second != -1){
        int start = first < second ? first : second;
        int end = first < second ? second : first;
        for(int i = start + 1; i < end; i++){
            arr[i] = 0;
        }
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    resetBetweenMin(arr, n);
    cout << "Modified array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
