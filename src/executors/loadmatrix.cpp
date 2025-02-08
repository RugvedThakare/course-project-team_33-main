#include "global.h"

// Syntactic Parsing for LOAD MATRIX
bool syntacticParseLOADMATRIX() {
    logger.log("syntacticParseLOADMATRIX");

    if (tokenizedQuery.size() != 3) {
        cout << "SYNTAX ERROR: Expected format: LOAD MATRIX <matrix_name>" << endl;
        return false;
    }

    parsedQuery.queryType = LOAD_MATRIX;
    parsedQuery.matrixName1 = tokenizedQuery[2];

    return true;
}

// Semantic Parsing for LOAD MATRIX
bool semanticParseLOADMATRIX() {
    logger.log("semanticParseLOADMATRIX");

    // Check if matrix already exists
    if (matrixCatalogue.isMatrix(parsedQuery.matrixName1)) {
        cout << "SEMANTIC ERROR: Matrix " << parsedQuery.matrixName1 << " already exists." << endl;
        return false;
    }

    return true;
}

// Execution for LOAD MATRIX
void executeLOADMATRIX() {
    logger.log("executeLOADMATRIX");

    Matrix *matrix = new Matrix(parsedQuery.matrixName1);
    matrix->loadFromFile();
    matrixCatalogue.insertMatrix(matrix);

    cout << "Successfully loaded matrix " << parsedQuery.matrixName1 << "." << endl;
}
