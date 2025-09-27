#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of students (rows): ";
    cin >> rows;
    cout << "Enter number of subjects (cols): ";
    cin >> cols;

    int** studentArray = new int*[rows];
    for (int i = 0; i < rows; i++) {
        studentArray[i] = new int[cols];
    }

    cout << "Enter marks for all students: " << endl;
    for (int i = 0; i < rows; i++) {  // loop to take user input for marks
        for (int j = 0; j < cols; j++) {
            cin >> studentArray[i][j];
        }
    }

    cout << endl;
    int total[rows] = {0};
    for (int i = 0; i < rows; i++) {  // loop to ca;lculate total marks        
        for (int j = 0; j < cols; j++) {
            total[i] += studentArray[i][j];
        }
        cout << "Total Marks of Student [" << i << "]: " << total[i] << endl;
    }
cout << endl;
    for (int i = 0; i < cols; i++) {  // loop to calc average
        int totalMarks = 0;  // resets the total to 0
        int avgMarks = 0;  // resets the average to 0
        for (int j = 0; j < rows; j++) {
            totalMarks += studentArray[j][i];
        }
        avgMarks = totalMarks/rows;
        cout << "Average Marks of Subject [" << i << "]: " << avgMarks << endl;;
    }

    int max = 0;
    for (int i = 0; i < rows; i++) {  // loop to find the highest marks
        if (total[i] > max) {
            max = total[i];
        }
    }
    cout << "\nHighest Total Marks: " << max;

    for (int i = 0; i < rows; i++) {
        delete[] studentArray[i];
    }
    delete[] studentArray;

    return 0;
}
Q2.cpp
Displaying Q2.cpp.Next 
Lab 02
Abdullah Yaqoob
•
Aug 25
10 points
Due Aug 26, 1:30 AM
Task 2
Class comments
