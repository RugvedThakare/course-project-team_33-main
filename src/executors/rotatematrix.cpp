#include "global.h"

// Syntactic Parsing for ROTATE
bool syntacticParseROTATEMATRIX() {
    logger.log("syntacticParseROTATE");

    if (tokenizedQuery.size() != 2) {
        cout << "SYNTAX ERROR: Expected format: ROTATE <matrix_name>" << endl;
        return false;
    }

    parsedQuery.queryType = ROTATE_MATRIX;
    parsedQuery.matrixName1 = tokenizedQuery[1];

    return true;
}

// Semantic Parsing for ROTATE
bool semanticParseROTATEMATRIX() {
    logger.log("semanticParseROTATE");

    if (!matrixCatalogue.isMatrix(parsedQuery.matrixName1)) {
        cout << "SEMANTIC ERROR: Matrix " << parsedQuery.matrixName1 << " does not exist." << endl;
        return false;
    }

    return true;
}

// Execution for ROTATE
void executeROTATEMATRIX() {
    logger.log("executeROTATE");

    Matrix *matrix = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    matrix->rotate();

    cout << "Successfully rotated matrix " << parsedQuery.matrixName1 << " by 90 degrees clockwise." << endl;
}
