/* 삽입정렬*/
#include <iostream>
using namespace std;

void printArray(int arr[], int N);
void printArrayLinear(int arr[], int N);
void selectionSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int N) {
    for (int i = 1; i < N; i++) {
        int card = arr[i];
        int j = i - 1;
        printArrayLinear(arr, N);

        while (j >= 0 && arr[j] > card) {
            arr[j + 1] = arr[j];
            arr[j] = card;
            j--;
        }
        printArrayLinear(arr, N);
    }
}
void printArrayLinear(int arr[], int N) {
    for (int i = 0; i < N; i++) {
    }
}
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }
}
int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, N);
    printArray(arr, N);
    return 0;
}