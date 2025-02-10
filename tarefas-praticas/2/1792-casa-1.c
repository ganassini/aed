#include <stdio.h>
#include <stdlib.h>

double maxAverageRatio(int** classes, int classesSize, int extraStudents);

int main(void)
{
	int values[4][2] = {
		{2,4},
		{3,9},
		{4,5},
		{2,10}
	};

	int** classes = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++) {
		classes[i] = (int*)malloc( 2 * sizeof(int));
		for (int j = 0; j < 2; j++) {
			classes[i][j] = values[i][j];
		}
	}

	printf("%lf\n", maxAverageRatio(classes, 4, 4));

	for (int i = 0; i < 4; i++) {
		free(classes[i]);
	}

	return 0;
}
double maxAverageRatio(int** classes, int classesSize, int extraStudents) {
    // | 2/4   | 3/9     | 4/5    | 2/10
    // | 0.1   |  0.0677 | 0.0333 | 0.072
    // | 3/5   | 3/9     | 4/5    | 2/10
    // | 0.066 | 0.0677  | 0.0333 | 0.072
    // | 3/5   | 3/9     | 4/5    | 3/11
    // | 0.066 | 0.0677  | 0.3333 | 0.25
    // | 3/5   | 4/10    | 4/5    | 3/11
    // | 0.066 | 0.0545  | 0.0333 | 0.25
    // | 4/6   | 4/10    | 4/5    | 3/11
    double biggest_c_pr, diff_c_pr, sum = 0;
    int biggest_c_pr_index;
    
	for ( int i = 0; i < extraStudents; i++ ) {
        biggest_c_pr_index = 0;
        biggest_c_pr = ((double)(classes[0][0] + 1) / (double)(classes[0][1] + 1)) - ((double)classes[0][0] / (double)classes[0][1]);

        for ( int j = 1; j < classesSize; j++ ) {
            diff_c_pr = ((double)(classes[j][0] + 1) / (double)(classes[j][1] + 1)) - ((double)classes[j][0] / (double)classes[j][1]);

            if ( diff_c_pr >= biggest_c_pr ) {
                if ( diff_c_pr == biggest_c_pr ) {
                    if ( classes[biggest_c_pr_index][1] > classes[j][1] )
                        biggest_c_pr_index = j;
                }
                if ( diff_c_pr > biggest_c_pr ) {
                    biggest_c_pr = diff_c_pr;
                    biggest_c_pr_index = j;
                }
            }
        }

        classes[biggest_c_pr_index][0] += 1;
        classes[biggest_c_pr_index][1] += 1;
    }

    for ( int i = 0; i < classesSize; i++ )
        sum += ((double)classes[i][0] / (double)classes[i][1]);

    return sum / (double)classesSize;
}
