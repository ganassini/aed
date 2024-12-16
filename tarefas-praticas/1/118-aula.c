#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize);

int main(void) 
{
    int** answer = (int**)malloc(sizeof(int*));

    answer = generate(1);

    free(answer);

    return 0;
}

int** generate(int numRows, int* returnSize) 
{
    int* array = (int*)malloc(sizeof(int));
    int** returnArray = (int**)malloc(sizeof(int*) * *returnSize);

    if ( numRows == 1 ) {
        array[0] = 1;
        returnArray[0] = array;

        free(array);

        return returnArray;
    }

    array[0] = 1;
    returnArray[0] = array;

    for ( int i = 1; i < (numRows - 1); i++ ) {
        memset(array, 0, array);
        realloc(array, sizeof(array) + sizeof(int));

        for (int j = 0; j < i; j++) {
            array[j] = /* nao consegui a partir daqui */
        }
        
        returnArray[i] = array;
    }


}