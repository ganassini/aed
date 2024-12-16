int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** returnArray = (int**)malloc(numRows * sizeof(int*));
	int i, j;

    for ( i = 0; i < numRows; i++ ) {
        returnArray[i] = (int*)malloc((i + 1) * sizeof(int));

        returnArray[i][0] = 1;

		for ( j = 1; j < i; j++ ) {

			returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
		}
        
		returnArray[i][i] = 1;
    }

    return returnArray;
}

