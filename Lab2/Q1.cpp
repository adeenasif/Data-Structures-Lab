// TASK1

#include<iostream>
using namespace std;

// funtion to display matrix elements
void displayMatrix(int *matrix[], int r, int c) {
    cout << "\n--- Matrix Elements --- " <<endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int val = matrix[i][j];
                if ((i + j) % 2 == 1)  // odd index (sum of row+col odd)
                    val += 2;
                cout << val << " ";
        }
        cout << endl;
    }
}

// function that finds and prints transpose of given matrix
void transpose(int *matrix[], int r, int c) {
    cout << "\n--- Transposed Matrix (for original matrix) ---" << endl;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // creating 2d dynamic array
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int **matrix = new int*[rows];  // allocating memory for rows
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // allocating memory for columns
    }

    // Taking input in matrix
    cout << "Enter elements for the matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    displayMatrix(matrix, rows, cols); // to display original matrix
    transpose(matrix, rows, cols);  // to find the transpose of original matrix

    // resizing array
    int nRows, nCols;
    cout << "Enter new rows and columns to resize matrix: ";
    cin >> nRows >> nCols;
    if (nRows > rows && nCols > cols) {  // to increase the size of matrix
        int **newMatrix = new int*[nRows];
        for (int i = 0; i < nRows; i++) {
            newMatrix[i] = new int[nCols];
        }

        // transferring the data from old matrix to new matrix
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = 2; // entering 2 (by default / could be user input here) as the new element
                }
            }
        }
        displayMatrix(newMatrix, nRows, nCols);
        transpose(newMatrix, nRows, nCols);

        // memory Deallocation (deleting old matrix)
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        // reassigning values
        matrix = newMatrix;
        rows = nRows;
        cols = nCols;

    } else if (nRows < rows && nCols < cols) { // to truncate the matrix
        int **newMatrix = new int*[nRows];
        for (int i = 0; i < nRows; i++) {
            newMatrix[i] = new int[nCols];
        }

        // transferring the data from old matrix to new matrix
        // this truncates the matrix by just copying the data for new rows/cols
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        
        displayMatrix(newMatrix, nRows, nCols);
        transpose(newMatrix, nRows, nCols);

        // memory Deallocation (deleting old matrix)
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        // reassigning values
        matrix = newMatrix;
        rows = nRows;
        cols = nCols;
    } else {  // if the new rows/cols are same as the old ones
        cout << "New rows and cols must be different then old ones!!" << endl;\
        // memory Deallocation (even if new array is not created, free old matrix memory)
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    return 0;
}
