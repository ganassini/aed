int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int* array = (int*)malloc(sizeof(int));
    int** returnArray = (int**)malloc(sizeof(int*) * numRows);
    int j;

    for (int i = 0; i < numRows; i++) {
        j = 1;

        if ( i == 0 ) {
            array[0] = 1;
            returnArray[0] = array;
            continue;
        }

        if ( i == 1 ) {
            array = (int*)realloc(array, sizeof(int)*2);
            returnArray = (int**)realloc(returnArray, sizeof(int*)*2);
            array[0] = 1;
            array[1] = 1;
            returnArray[1] = array;
            continue;
        }

        array = (int*)realloc(array, sizeof(int)*2);
        array[0] = 1;

        while ( j < i ) {
            array[j] = returnArray[i-1][j] + returnArray[i-1][j + 1];
            j++;
        }

        array[j+1] = 1;
    }

    return returnArray;
}
