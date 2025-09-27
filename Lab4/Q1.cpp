#include<iostream>
using namespace std;

// First, sort the list using Insertion Sort.
void insertionSort (int arr[], int n) {
    for (int i = 1; i < n; i++) {  // assumes that first element is sorted
        int key = arr[i];  // key stores the element that needs to be sorted
        int j = i - 1 ;  // prev index

        while(j >= 0 && arr[j] > key) {  // loops till it does not reach start of array & till the current array element is greater then key
            arr[j+1] = arr[j];  // shifts the values until the right position is found for key
            j--;  // to compare with prev value
        }
        arr[j+1] = key;  // place key on correct position
    }
}

// implement Binary Search on the sorted list to find the target.
int binarySearch(int *arr, int n, int val) {
    int LB = 0;  // the initial lower index (start of array)
    int UB = n-1;  // the inital upper index (end of array)
    while (UB >= LB) {  // loop until array elements are over (lower index = upper index)
        int mid = (LB+UB) / 2;  // finds the middle index

        if (val == arr[mid]) { // value is equal to the value mid is pointing at
            return mid;  // value found
        } else if (val < arr[mid]) { // value is less then the value mid is pointing at
            UB = mid-1;  // update upper bound to the index before the current mid
        } else {  // value is greater then the value mid is pointing at
            LB = mid+1;  // update lower bound to the index after the current mid
        }
    }
    return -1; // is target value is not found
}

// function to print elements of array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size, searchVal;
    cout << "Enter size of array: ";
    cin >> size;  // number of elements in array

    int *arr = new int[size];  // declaration of array

    cout << "\nEnter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];  //  storing elements in array
    }
    printArray(arr, size);  // prints the original array

    insertionSort(arr, size);  // sorts the array
    
    cout << "Sorted Array: " << endl;
    printArray(arr, size); // prints array after sorting elemenets

    cout << "Enter a number to search in array: ";
    cin >> searchVal;  // stores value to be searched

    int x = binarySearch(arr, size, searchVal);  // calls function to search
    if (x == -1) {  // checks whether the val is found or not
        cout << "Value not found" << endl;  // value not found
    } else {
        cout << "Value found at index: " << x << endl; // value found
    }
    return 0;
}