#include "global.h"

// Syntactic Parsing for CROSSTRANSPOSE
bool syntacticParseCROSSTRANSPOSEMATRIX()
{
    logger.log("syntacticParseCROSSTRANSPOSE");

    if (tokenizedQuery.size() != 3)
    {
        cout << "SYNTAX ERROR: Expected format: CROSSTRANSPOSE <matrix1> <matrix2>" << endl;
        return false;
    }

    parsedQuery.queryType = CROSS_TRANSPOSE_MATRIX;
    parsedQuery.matrixName1 = tokenizedQuery[1];
    parsedQuery.matrixName2 = tokenizedQuery[2];

    return true;
}

// Semantic Parsing for CROSSTRANSPOSE
bool semanticParseCROSSTRANSPOSEMATRIX()
{
    logger.log("semanticParseCROSSTRANSPOSE");

    // Ensure both matrices exist in the catalogue
    if (!matrixCatalogue.isMatrix(parsedQuery.matrixName1) ||
        !matrixCatalogue.isMatrix(parsedQuery.matrixName2))
    {
        cout << "SEMANTIC ERROR: One or both matrices do not exist." << endl;
        return false;
    }

    // Check for dimension compatibility (square matrices)
    Matrix *matrix1 = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    Matrix *matrix2 = matrixCatalogue.getMatrix(parsedQuery.matrixName2);

    if (matrix1->rowCount != matrix1->columnCount ||
        matrix2->rowCount != matrix2->columnCount ||
        matrix1->rowCount != matrix2->rowCount)
    {
        cout << "SEMANTIC ERROR: Only square matrices of the same size are supported." << endl;
        return false;
    }

    return true;
}

// Execution for CROSSTRANSPOSE
void executeCROSSTRANSPOSEMATRIX()
{
    logger.log("executeCROSSTRANSPOSE");

    Matrix *matrix1 = matrixCatalogue.getMatrix(parsedQuery.matrixName1);
    Matrix *matrix2 = matrixCatalogue.getMatrix(parsedQuery.matrixName2);

    // Create transposes of both matrices
    vector<vector<int>> transpose1(matrix1->columnCount, vector<int>(matrix1->rowCount));
    vector<vector<int>> transpose2(matrix2->columnCount, vector<int>(matrix2->rowCount));

    // Perform transposition
    for (int i = 0; i < matrix1->rowCount; i++)
    {
        for (int j = 0; j < matrix1->columnCount; j++)
        {
            transpose1[j][i] = matrix1->getElement(i, j);
        }
    }

    for (int i = 0; i < matrix2->rowCount; i++)
    {
        for (int j = 0; j < matrix2->columnCount; j++)
        {
            transpose2[j][i] = matrix2->getElement(i, j);
        }
    }

    // Swap the matrix contents in-place
    matrix1->updateData(transpose2);
    matrix2->updateData(transpose1);

    cout << "Successfully swapped transposes of matrices " << parsedQuery.matrixName1
         << " and " << parsedQuery.matrixName2 << "." << endl;

    return;
}
