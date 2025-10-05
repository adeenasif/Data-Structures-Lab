#include<iostream>
using namespace std;

// determines if there is a subset whose sum is equal to the target
bool targetSum(int *arr, int n, int target){ 
    if (target == 0) return true;  //  subset found
    if (n == 0) return false;     // no elements left in array
    
    if (arr[n-1] > target) {  // skip if the element is greatr than target
        return targetSum(arr, n-1, target); 
    }   
    // first condition: creates sum using remaining n-1 elements
    // second condition: if more elements needed to find target
    return targetSum(arr, n-1, target) ||
            targetSum(arr, n-1,target-arr[n-1]);
}

int main() {
    // test cases
    int array[6] = {3, 34, 4, 12, 5, 2};  // array
    int target = 9; // target
    if (targetSum(array, 6, target)) {  // calls the function
        cout << "True" << endl;  // should return true
    } else {
        cout << "False" << endl; // if function returns false, no such subset
    }

    int array2[6] = {3, 34, 4, 12, 5, 2};  // array
    int target2 = 32; // target
    if (targetSum(array2, 6, target2)) {  // calls the function
        cout << "True" << endl;  // if funct returns true
    } else {
        cout << "False"; // should returns false, no such subset
    }
}
