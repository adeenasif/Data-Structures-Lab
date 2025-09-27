// Task 3

#include<iostream>
using namespace std;

int main() {
    int rows;  // num of departments
    cout << "Enter the number of departments:";
    cin >> rows;

    int **uni = new int*[rows];  // 2d dynamic jagged array
    int *cols = new int[rows];  // num of students in each dept

    cout << "Enter number of students in each department:";
    for (int i = 0; i < rows; i++){
        cin >> cols[i];
        uni[i] = new int[cols[i]];  // allocating memory for each col in all rows
    }

    cout << "Enter marks for each student: " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols[i]; j++) {
            cin >> uni[i][j];
        }
    }

    // highest marks of each dept
    for (int i = 0; i < rows; i++) {
        int highest = uni[i][0];  // resets for eadch dept
        for (int j = 0; j < cols[i]; j++) {  // loop is for each row, then for each num of col in that row
            if(uni[i][j] > highest){  // comparing marks within departments 
                highest = uni[i][j];
            } 
        }
        cout << "Highest marks for department [" << i+1 << "]: " << highest << endl;
    }
    cout << endl;
    // lowest marks of each dept
    for (int i = 0; i < rows; i++) {
        int lowest = uni[i][0];  // resets for each dept
        for (int j = 0; j < cols[i]; j++) {
            if(uni[i][j] < lowest){  // comparing marks within departments 
                lowest = uni[i][j];
            } 
        }
        cout << "Lowest marks for department [" << i+1 << "]: " << lowest << endl;
    }
    cout << endl;
    // average marks of each dept
    for (int i = 0; i < rows; i++) {
        int total = 0, average = 0;
        for (int j = 0; j < cols[i]; j++) {
            total+= uni[i][j];
        }
        average = total/cols[i];
        cout << "Average marks for department [" << i+1 << "]: " << average << endl;
    }

    for (int i = 0; i < rows; i++) {  // frees all columns
        delete[] uni[i];
    }
    delete[] uni; // frees rows
    delete[] cols;  // fress the array of columns
    return 0;
}
