/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matrixColSize[0]; 
    int transposedColSize = matrixSize;
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    int** transposedMatrix = (int**)malloc((*returnSize) * sizeof(int*));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = transposedColSize;
        transposedMatrix[i] = (int*)malloc(transposedColSize * sizeof(int));
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    return transposedMatrix;
}
