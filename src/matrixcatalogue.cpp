#include "matrixCatalogue.h"
#include <iostream>

using namespace std;

MatrixCatalogue matrixCatalogue;

// Insert matrix
void MatrixCatalogue::insertMatrix(Matrix* matrix) {
    matrixMap[matrix->matrixName] = matrix;
}

// Check if matrix exists
bool MatrixCatalogue::isMatrix(const string& matrixName) {
    return matrixMap.find(matrixName) != matrixMap.end();
}

// Get matrix by name
Matrix* MatrixCatalogue::getMatrix(const string& matrixName) {
    if (isMatrix(matrixName)) {
        return matrixMap[matrixName];
    }
    cout << "ERROR: Matrix " << matrixName << " does not exist." << endl;
    return nullptr;
}

// Delete matrix by name
void MatrixCatalogue::deleteMatrix(const string& matrixName) {
    if (isMatrix(matrixName)) {
        delete matrixMap[matrixName];
        matrixMap.erase(matrixName);
    }
}

// Destructor to clean up all matrices
MatrixCatalogue::~MatrixCatalogue() {
    for (auto& entry : matrixMap) {
        delete entry.second;
    }
}
