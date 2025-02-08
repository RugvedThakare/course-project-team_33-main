#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix {
public:
    std::string matrixName;
    int rowCount, columnCount;
    std::vector<std::vector<int>> data;

    // Constructor
    Matrix(std::string name);

    // Helper Functions
    void loadFromFile();
    void exportToFile();
    void printMatrix();
    void rotate();
    void updateData(const std::vector<std::vector<int>>& newData);

    int getElement(int row, int col) const;
    void setElement(int row, int col, int value);

    ~Matrix();
};

#endif // MATRIX_H
