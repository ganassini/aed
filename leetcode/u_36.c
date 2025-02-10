bool checkBox(char **board, int i, int j) {
    int k,l,m,n,o,p;

    m = i + 3;
    n = j + 3;
    for (k = i; k < m; k++) {
        int *nums = (int*)malloc(sizeof(int) * 3);
        o = 0;

        for (l=j; l < n; l++) {
            if (board[k][l] != '.') {
                for (p = 0; p < o; p++) {
                    if (nums[p] == board[k][l]) {
                        free(nums);
                        return false;
                    }
                }
                nums[o] = board[k][l];
                o++;
            }
        }
        free(nums);
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int i,j,k,l,m,n;
    
    // check lines
    for (i=0; i < boardSize; i++) {
        int *nums = (int*)malloc(sizeof(int)*9);
        k = 0;

        for (j=0; j < *boardColSize; j++) {
            if (board[i][j] != '.') {
                for (l=0; l<k; l++) {
                    if (nums[l] == board[i][j]) {
                        free(nums);
                        return false;
                    }
                }
                nums[k] = board[i][j];
                k++;
            }
        }
        free(nums);
    }

    // check columns
    for (i=0; i< boardSize; i++) {
        int *nums = (int*)malloc(sizeof(int)*9);
        k = 0;

        for (j=0; j < *boardColSize; j++) {
            if (board[j][i] != '.') {
                for (l=0; l < k; l++) {
                    if (nums[l] == board[j][i]) {
                        free(nums);
                        return false;
                    }
                }
                nums[k] = board[j][i];
                k++;
            }
        }
        free(nums);
    }

    // check boxes
    for (m = 0; m < boardSize; m += 3) {
        for (n = 0; n < *boardColSize; n += 3) {
            if (!checkBox(board, m, n))
                return false;
        }
    }

    return true;
}
