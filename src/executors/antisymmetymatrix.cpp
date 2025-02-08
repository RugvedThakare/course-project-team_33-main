#include "global.h"

// Syntactic Parsing for CHECKANTISYM
bool syntacticParseCHECKANTISYM() {
    logger.log("syntacticParseCHECKANTISYM");

    if (tokenizedQuery.size() != 3) {
        cout << "SYNTAX ERROR: Expected format: CHECKANTISYM <matrix1> <matrix2>" << endl;
        return false;
    }

    parsedQuery.queryType = CHECK_ANTI_SYMMETRY;
    parsedQuery.matrixName1 = tokenizedQuery[1];
    parsedQuery.matrixName2 = tokenizedQuery[2];

    return true;
}

// Semantic Parsing for CHECKANTISYM
bool semanticParseCHECKANTISYM() {
    logger.log("semanticParseCHECKANTISYM");

    Matrix *matrix1 = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    Matrix *matrix2 = matrixCatalogue.getMatrix(parsedQuery.matrixName2);

    if (!matrixCatalogue.isMatrix(parsedQuery.matrixName1) ||
        !matrixCatalogue.isMatrix(parsedQuery.matrixName2)) {
        cout << "SEMANTIC ERROR: One or both matrices do not exist." << endl;
        return false;
    }

    if (matrix1->rowCount != matrix2->rowCount || matrix1->columnCount != matrix2->columnCount) {
        cout << "SEMANTIC ERROR: Matrices must have the same dimensions." << endl;
        return false;
    }

    return true;
}

// Execution for CHECKANTISYM
void executeCHECKANTISYM() {
    logger.log("executeCHECKANTISYM");

    Matrix *matrix1 = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    Matrix *matrix2 = matrixCatalogue.getMatrix(parsedQuery.matrixName2);

    bool antiSymmetric = true;

    for (int i = 0; i < matrix1->rowCount && antiSymmetric; i++) {
        for (int j = 0; j < matrix1->columnCount; j++) {
            if (matrix1->data[i][j] != -matrix2->data[j][i]) {
                antiSymmetric = false;
                break;
            }
        }
    }

    if (antiSymmetric)
        cout << "The matrices are anti-symmetric." << endl;
    else
        cout << "The matrices are not anti-symmetric." << endl;
}
