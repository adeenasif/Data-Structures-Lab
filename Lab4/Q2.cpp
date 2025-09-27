#include<iostream>
using namespace std;

// Sorts the array using Selection Sort
void selectionSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // loop thru entire array
        int minIndex = i; // stores index of element to sort
        for (int j = i + 1; j < n; j++) {  // loop from next index of the element
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // update minindex with the index of smaller element
            }
        }
        // swap elements
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Implements Interpolation Search to find the target in the sorted array.
int interpolationSearch(int arr[], int n, int x) {
    // find indexes of two corners
    int low = 0, high = (n - 1);  // low index is 0 and high index is array size -1
    // array is sorted, an element present in array must be in range defined by corner
    while (low <= high && x >= arr[low] && x <= arr[high]) {  // search val x lies within the range arr[low] to arr[high]
        if (low == high) { // if search space has only one element left
            if (arr[low] == x) {
                return low;  // element found
            }
            return -1;  // element not found
        }

        // estimate the position
        int pos = low + ((x-arr[low]) * (high - low)) / ((arr[high]) - (arr[low]));

        if (arr[pos] == x) { // check if estimated position has x 
            // move left to find the first occurrence if there are duplicates
            while (pos > low && arr[pos - 1] == x) {
                pos--;
            }
            return pos;
        } else if (arr[pos] < x) { // if x is larger, x is in upper part, ignore left half
            low = pos + 1;
        } else { // if x is smaller, x is in the lower part, ignore right half
            high = pos - 1;
        }
    }
    return -1;
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

    selectionSort(arr, size);  // sorts the array
    
    cout << "Sorted Array: " << endl;
    printArray(arr, size); // prints array after sorting elemenets

    cout << "Enter a number to search in array: ";
    cin >> searchVal;  // stores value to be searched

    int x = interpolationSearch(arr, size, searchVal);  // calls function to search
    if (x == -1) {  // checks whether the val is found or not
        cout << "Value not found" << endl;  // value not found
    } else {
        cout << "Value found at index: " << x << endl; // value found
    }
    return 0;
}