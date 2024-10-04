// Including relevant libraries
# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

// Matrix multiplication:
/*
Ask user for input, verify that the dimensions are proper,
and multiply the matrices!



*/


// Matmul: ith, jth element is <ith row mat1, jth col mat 2>
// Function intiatied w/ (), takes parameters
vector<vector<float>> matrixMultiplication(vector<vector<float>> mat1, vector<vector<float>> mat2) {
    // getting shape of both matrices
    int shape1[2], shape2[2];
    shape1[0] = mat1.size(); // rows
    shape2[0] = mat2.size();

    shape1[1] = mat1[0].size(); // cols
    shape2[1] = mat2[0].size();

    // preforming matmul --> (m1,n2)
    vector<vector<float>> mulResult(shape1[0],vector<float>(shape2[1]));
    for(int i = 0; i < shape1[0]; i++) { // row elements
        for(int j = 0; j < shape2[1]; j++) {
            // dot product! --> going through jth col of 2nd, ith row of 1st
            mulResult[i][j] = 0;
            for(int k = 0; k < shape1[1]; k++) {
                mulResult[i][j] += mat1[i][k] * mat2[k][j];
                cout << "*** ind:" << i << j << "*** result:" << mulResult[i][j] << endl;
            }

        }
    }

    // returning the resulting value!
    return mulResult;


}

int main() { // function to execute code

    // shape of matrix 1
    int m1,n1;

    // shape of 2nd matrix
    int m2,n2;

    cout << "Matrix Shape: " << endl;;
    cin >> m1>>n1>>m2>>n2;;

    // m,n matrices
    vector<vector<float>> matrix1(m1,vector<float>(n1));
    vector<vector<float>> matrix2(m2,vector<float>(n2));
    vector<vector<float>> result(m1,vector<float>(n2)); // stores result (m1,n2)

    // for = initial, condition, change: creating matrices
    for(int i = 0; i < m1; i++) { // each row
        for (int j = 0; j < n1; j++) { // each col
            cout << "Enter matrix 1 position " << i << "," << j << " :";
            cin >> matrix1[i][j]; // putting in positipn

        }
    }

    // entering second mat values
    for(int i = 0; i < m2; i++) { // each row
        for (int j = 0; j < n2; j++) { // each col
            cout << "Enter matrix 2 position (" << i << "," << j << ") :";
            cin >> matrix2[i][j]; // putting in positipn

        }
    }

    result = matrixMultiplication(matrix1,matrix2);

    // printing result
    for (int i = 0; i < m1; i++) {
        cout << "row: " << i << endl;
        for (int j = 0; j < n2; j++) {
            cout << "Col: "  << j << ", val: " << result[i][j] << endl;
        }
    }

    return 0;

}