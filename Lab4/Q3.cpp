#include<iostream>
using namespace std;

void printArray(int *arr, int n) { // function to print elements of array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Perform Bubble Sort on a given array to sort it in ascending order.
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {  // outside loop for entire array
        for (int j = 0; j < n-1; j++) {  // inside loop for comparasions of each element
            if (arr[j] > arr[j+1]) {  // checks if the value is greater then in its next element
                int temp = arr[j];  // a temp var to hold the element
                arr[j] = arr[j+1]; // element updated with the val of next index
                arr[j+1] = temp;  // the next index now holds the previous index val (which was stored in temp)
            }
        }
    }
}

// Implement Linear Search to find the first occurrence of a target element in the sorted array.
int linearSearch(int *arr, int n, int val) {
    for (int i = 0; i < n; i++) {  // loop thru entire array
        if (arr[i] == val) { //  checks if search value is found
            return i;  //  Returns the index of the target if found
        }
    }
    return -1;  // return -1 if not found
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

    bubbleSort(arr, size);  // sorts the array

    cout << "\nSorted array: " << endl;
    printArray(arr, size);  // prints the sorted array

    cout << "\nEnter a number to search in array: ";
    cin >> searchVal;  // stores value to be searched

    int x = linearSearch(arr, size, searchVal);  // calls function to search on sorted array
    if (x == -1) {  // checks whether the val is found or not
        cout << "Value not found" << endl;  // value not found
    } else {
        cout << "Value found at index: " << x << endl; // value found
    }

    delete[] arr; // free dynamically allocated memory of array
    return 0;
}