#ifndef MATRIX_CATALOGUE_H
#define MATRIX_CATALOGUE_H

#include "matrix.h"
#include <unordered_map>
#include <string>

class MatrixCatalogue {
private:
    std::unordered_map<std::string, Matrix*> matrixMap;

public:
    // Insert matrix into catalogue
    void insertMatrix(Matrix* matrix);

    // Check if matrix exists
    bool isMatrix(const std::string& matrixName);

    // Get matrix by name
    Matrix* getMatrix(const std::string& matrixName);

    // Delete matrix by name
    void deleteMatrix(const std::string& matrixName);

    ~MatrixCatalogue();
};

extern MatrixCatalogue matrixCatalogue;

#endif // MATRIX_CATALOGUE_H
