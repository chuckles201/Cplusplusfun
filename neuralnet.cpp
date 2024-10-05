// Including libraries
# include <vector>
# include <cmath>
# include <iostream>
# include <random> // for distributions
# include <cassert>
# include <string> // for strings
# include <iomanip> // rounding


using namespace std;

// *Note: bad to use global variables to much, since multiple functions modify them


// Function to create a random matrix given shape
vector<vector<float>> getRandomMatrix(mt19937& gen, int s1, int s2) {
    // initializing 2d weight matrix and distr. creator
    normal_distribution<float> d(0.0,1.0); // mean,std.
    vector<vector<float>> matrix(s1,vector<float>(s2)); // creating 2d matrix

    // generating random vals for each row and col.
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = d(gen); // dist w/ random object
        }
    }
    return matrix;
}

// function to multiply two matrices
vector<vector<float>> matrixMultiply(vector<vector<float>>m1,vector<vector<float>>m2) {
    // outside shape (dim 0) rows, inside is cols (dim1)
    int shape1[2];
    int shape2[2];
    shape1[0] = m1.size();
    shape1[1] = m1[0].size();
    shape2[0] = m2.size();
    shape2[1] = m2[0].size();

    // check dimensions are ok
    //assert(shape1[1] == shape2[0]);

    // initializing resulting matrix
    vector<vector<float>> result(shape1[0],vector<float>(shape2[1]));

    for (int i = 0; i < shape1[0]; i++) { // row
        for (int j = 0; j < shape2[1]; j++) { // col
            // dot product of ith row m1, jth col m2
            result[i][j] = 0;
            for (int k = 0; k < shape1[1]; k++) {
                result[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }

    return result;

}


// simple print-matrix functionality
void printMatrix(vector<vector<float>> matrix) {
    int s1, s2;
    s1 = matrix.size();
    s2 = matrix[0].size();
    cout << "Matrix Size (" << s1 << "," << s2 << ")" << endl;

    // printing 'top' of matrix: 2 for each, 1 more for extra
    cout << " ";
    for (int i = 0; i < (s2*7 -1); i++) {
        cout << "-"; // for top of matrix
    }
    cout << endl;

    // printing each element
    for (int i = 0; i < s1; i++) {
        cout << "|"; // begin gate
        for (int j = 0; j < s2; j++) {
            float el = matrix[i][j];
            if (el > 0) {
                cout << " ";
            }
            cout << fixed << setprecision(3) << el;
            cout << "|";
        }
        cout << endl;
    }

    // bottom of matrix
    cout << " ";
    for (int i = 0; i < (s2*7-1); i++) {
        cout << "-"; // for bottom of matrix
    }

}

// class for RELU non-linearity and backprop
class Relu {
    public: //available to outside entities
        vector<vector<int>>matrix;
        vector<int> shape;

        Relu(vector<vector<int>> matrixin) {
            matrix = matrixin;
            shape[0] = matrix.size();
            shape[1] = matrix[0].size();
        }

}; // add after defining a class


int main() {
    random_device r1; // creating random instance
    mt19937 r2(r1()); // another instance with double randomness

    // shape of matrix
    const int s1[2] = {3,5};
    const int s2[2] = {3,3};

    // creating matrices
    vector<vector<float>> m1 = getRandomMatrix(r2,s1[0],s1[1]); // layer 1
    vector<vector<float>> m2 = getRandomMatrix(r2,s2[0],s2[1]); // 2nd layer
    vector<vector<float>> m2 = getRandomMatrix(r2,s2[0],s2[1]); // 3rd layer


    // multiplying matrices
    vector<vector<float>> result = matrixMultiply(m1,m2);

    // printing result
    printMatrix(result);



    return 0;
}