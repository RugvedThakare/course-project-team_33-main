#include "matrix.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm> // For std::min

using namespace std;

// Constructor
Matrix::Matrix(string name) : matrixName(name), rowCount(0), columnCount(0) {}

// Load matrix from CSV
void Matrix::loadFromFile() {
    string filePath = "data/" + matrixName + ".csv";
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "ERROR: Unable to load matrix from " << filePath << endl;
        return;
    }

    data.clear();
    string line;

    while (getline(file, line)) {
        vector<int> row;
        int num;
        size_t pos = 0;

        while ((pos = line.find(",")) != string::npos) {
            num = stoi(line.substr(0, pos));
            row.push_back(num);
            line.erase(0, pos + 1);
        }
        row.push_back(stoi(line)); // Last element
        data.push_back(row);
    }

    rowCount = data.size();
    columnCount = rowCount > 0 ? data[0].size() : 0;

    file.close();
}

// Export matrix to CSV
void Matrix::exportToFile() {
    string filePath = "data/" + matrixName + ".csv";
    ofstream file(filePath);

    if (!file.is_open()) {
        cout << "ERROR: Unable to export matrix to " << filePath << endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1)
                file << ",";
        }
        file << endl;
    }

    file.close();
}

// Print matrix (first 20x20 only)
void Matrix::printMatrix() {
    int limitRow = min(20, rowCount);
    int limitCol = min(20, columnCount);

    for (int i = 0; i < limitRow; i++) {
        for (int j = 0; j < limitCol; j++) {
            cout << setw(5) << data[i][j];
        }
        cout << endl;
    }
}

// Rotate matrix by 90 degrees clockwise
void Matrix::rotate() {
    vector<vector<int>> rotated(columnCount, vector<int>(rowCount));
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            rotated[j][rowCount - i - 1] = data[i][j];
        }
    }
    data = rotated;
    swap(rowCount, columnCount);
}

// Update matrix with new data
void Matrix::updateData(const vector<vector<int>>& newData) {
    data = newData;
    rowCount = data.size();
    columnCount = rowCount > 0 ? data[0].size() : 0;
}

// Get element at specific row, col
int Matrix::getElement(int row, int col) const {
    if (row < 0 || row >= rowCount || col < 0 || col >= columnCount) {
        cout << "ERROR: Invalid row or column index." << endl;
        return -1;
    }
    return data[row][col];
}

// Set element at specific row, col
void Matrix::setElement(int row, int col, int value) {
    if (row < 0 || row >= rowCount || col < 0 || col >= columnCount) {
        cout << "ERROR: Invalid row or column index." << endl;
        return;
    }
    data[row][col] = value;
}

// Destructor
Matrix::~Matrix() {}
