#include "fibonacci.h"

void fillInFibonacciNumbers(int result[], int length) {
    if (length > 0) {
        result[0] = 0;
    } 
    if (length > 1) {
        result[1] = 1;
    }
    if (length > 2) {
        for (int i = 2; i < length; ++i) {
            result[i] = result[i - 1] + result[i - 2];
        }
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << '\n';
    }
}

void createFibonacci() {
    cout << "Hvor mange tall i rekken? ";
    int length;
    cin >> length;
    int *result = new int[length] {};
    fillInFibonacciNumbers(result, length);
    printArray(result, length);
}