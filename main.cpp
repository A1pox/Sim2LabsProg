#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sortDescending(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){
        int maxIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int linearSearch(int arr[], int n, int target, int &iterations) {
    iterations = 0;
    for(int i = 0; i < n; i++){
        iterations++;
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int target, int &iterations) {
    int low = 0, high = n - 1;
    iterations = 0;
    while(low <= high) {
        iterations++;
        int mid = low + (high - low) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void processArray(int n) {
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000; // random numbers from 0 to 999
    }
    sortDescending(arr, n);
    cout << "\nArray of size " << n << " (sorted descending):\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\nEnter element to search: ";
    int target;
    cin >> target;
    int linIter = 0, binIter = 0;
    int linIndex = linearSearch(arr, n, target, linIter);
    int binIndex = binarySearch(arr, n, target, binIter);
    cout << "\nLinear search: ";
    if(linIndex != -1)
        cout << "Element found at index " << linIndex;
    else
        cout << "Element not found";
    cout << " (iterations: " << linIter << ")";
    cout << "\nBinary search: ";
    if(binIndex != -1)
        cout << "Element found at index " << binIndex;
    else
        cout << "Element not found";
    cout << " (iterations: " << binIter << ")\n";
    delete[] arr;
}

int main(){
    srand(time(0));
    processArray(100);
    processArray(1000);
    return 0;
}
