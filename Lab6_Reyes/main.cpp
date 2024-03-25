#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;    // using namespace std to avoid writing std:: in front of cout, cin, etc.

const int max_size = 100;   // set a constant for the max size of the matrix to 100

// create a function to read matrix data from a file. This function takes in a matrix, size, and filename.
void readMatrixFile(int matrix[max_size][max_size], int &size, const string &filename) {
    // opens the file and reads the data from the file into the matrix array
    ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        // loop through the size of the matrix to assign every matrix location in the NxN matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (file.eof()) {
                    break;
                }
                file >> matrix[i][j];
            }
        }
        // once the data is read, close the file
        file.close();
        // if the file does not open, print an error message
    } else {
        cerr << "Unable to access file. Please re-check input data" << endl;
    }
}

// creates a function to print the matrix data
void printMatrix(const int matrix[max_size][max_size], int size) {
    // loops through the matrix and prints the data of each location in a formatted manner
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        // prints a new line after each row
        cout << endl;
    }
}

// creates a function to add two matrices together
void addMatrices(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int result[max_size][max_size], int size) {
    // loops through the matrices and adds the values of the same index together
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // assigns the sum of the two matrices to the result matrix
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// creates a function to multiply two matrices together
void multiplyMatrices(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int result[max_size][max_size], int size) {
    // loops through the matrices and multiplies the values of the same index together
    // similar concept to adding matrices, but with multiplication
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // initializes the result matrix to 0 before multiplying
            result[i][j] = 0;
            // loops through the matrices and multiplies the values together and stores the result in the result matrix
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// creates a function to subtract two matrices
void subtractMatrices(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int result[max_size][max_size], int size) {
    // loops through the matrices and subtracts the values of the same index
    // once again, similar to adding matrices, but with subtraction
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // assigns the difference of the two matrices to the result matrix
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// creates a function to update a specific element in the matrix based on the parameters given from main
void updateMatrixElement(int matrix[max_size][max_size], int size, int row, int column, int newValue) {
    // check if the row and column values are within the matrix size
    if (row >= 0 && row < size && column >= 0 && column < size) {
        // assigns the new value to the specified location in the matrix
        matrix[row][column] = newValue;
    } else {
        // if the row or column values are invalid, print an error message
        cerr << "Invalid row or column value." << endl;
    }
}

// creates a function to find the maximum value in the matrix
void getMaxValue(const int matrix[max_size][max_size], int size) {
    // sets the max value to the first element in the matrix
    int max = matrix[0][0];
    // loops through the matrix and compares each value to the current max value
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // checks if the current value is greater than the max value and updates the max value if true
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    // prints the max value of the matrix
    cout << "Max value of the first matrix: " << max << endl;
}

// creates a function to transpose the matrix
void transposeMatrix(const int matrix[max_size][max_size], int size) {
    // creates a new matrix to store the transposed values
    int transposed[max_size][max_size];
    // loops through the matrix and assigns the transposed values to the new matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    // prints the transposed matrix
    printMatrix(transposed, size);
}


// sets the main function to run the program
int main() {
    // declares the size and matrices to store the data
    int size;
    int matrixA[max_size][max_size];
    int matrixB[max_size][max_size];
    int result[max_size][max_size];

    // reads the matrix data from the input file assuming it has the name "matrix_input.txt"
    readMatrixFile(matrixA, size, "matrix_input.txt");

    // creates a new matrix B by adding 1 to each element of matrix A
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixB[i][j] = matrixA[i][j] + 1;
        }
    }

    // prints the lab number and the section of the assignment
    cout << "Lab #6: IDE, Complied Programs (C++ Programming)" << endl;
    cout << "\n1. & 2. Read values and print matrices from an input file" << endl;

    //prints the matrices A and B
    cout << "Matrix A:" << endl;
    printMatrix(matrixA, size);
    cout << "Matrix B:" << endl;
    printMatrix(matrixB, size);

    // prints the sum of the matrices A and B
    cout << "\n3. Add two matrices" << endl;
    cout << "Matrix Sum (A + B):" << endl;
    addMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    // prints the product of the matrices A and B
    cout << "\n4. Multiply two matrices" << endl;
    cout << "Matrix Product (A * B):" << endl;
    multiplyMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    // prints the difference of the matrices A and B
    cout << "\n5. Subtract two matrices" << endl;
    cout << "Matrix Difference (A - B):" << endl;
    subtractMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    // updates an element in the matrix A and prints the updated matrix
    cout << "\n6. Update an element in a matrix" << endl;
    cout << "Matrix A after updating element at (1, 1):" << endl;
    updateMatrixElement(matrixA, size, 1, 1, 100);
    printMatrix(matrixA, size);

    // prints the maximum value in the matrix A
    cout << "\n7. Get the maximum value in a matrix" << endl;
    getMaxValue(matrixA, size);

    // prints the transposed matrix A
    cout << "\n8. Transpose a matrix" << endl;
    cout << "Transposed Matrix A:" << endl;
    transposeMatrix(matrixA, size);

    // returns 0 to end the program
    return 0;
}