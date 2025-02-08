#include "global.h"

// Syntactic Parsing for EXPORT MATRIX
bool syntacticParseEXPORTMATRIX() {
    logger.log("syntacticParseEXPORTMATRIX");

    if (tokenizedQuery.size() != 2) {
        cout << "SYNTAX ERROR: Expected format: EXPORT MATRIX <matrix_name>" << endl;
        return false;
    }

    parsedQuery.queryType = EXPORT_MATRIX;
    parsedQuery.matrixName1 = tokenizedQuery[1];

    return true;
}

// Semantic Parsing for EXPORT MATRIX
bool semanticParseEXPORTMATRIX() {
    logger.log("semanticParseEXPORTMATRIX");

    if (!matrixCatalogue.isMatrix(parsedQuery.matrixName1)) {
        cout << "SEMANTIC ERROR: Matrix " << parsedQuery.matrixName1 << " does not exist." << endl;
        return false;
    }

    return true;
}

// Execution for EXPORT MATRIX
void executeEXPORTMATRIX() {
    logger.log("executeEXPORTMATRIX");

    Matrix *matrix = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    matrix->exportToFile();

    cout << "Successfully exported matrix " << parsedQuery.matrixName1 << "." << endl;
}
