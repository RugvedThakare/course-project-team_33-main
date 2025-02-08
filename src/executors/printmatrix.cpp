#include "global.h"

// Syntactic Parsing for PRINT MATRIX
bool syntacticParsePRINTMATRIX() {
    logger.log("syntacticParsePRINTMATRIX");

    if (tokenizedQuery.size() != 2) {
        cout << "SYNTAX ERROR: Expected format: PRINT MATRIX <matrix_name>" << endl;
        return false;
    }

    parsedQuery.queryType = PRINT_MATRIX;
    parsedQuery.matrixName1 = tokenizedQuery[1];

    return true;
}

// Semantic Parsing for PRINT MATRIX
bool semanticParsePRINTMATRIX() {
    logger.log("semanticParsePRINTMATRIX");

    if (!matrixCatalogue.isMatrix(parsedQuery.matrixName1)) {
        cout << "SEMANTIC ERROR: Matrix " << parsedQuery.matrixName1 << " does not exist." << endl;
        return false;
    }

    return true;
}

// Execution for PRINT MATRIX
void executePRINTMATRIX() {
    logger.log("executePRINTMATRIX");

    Matrix *matrix = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    matrix->printMatrix();
}
