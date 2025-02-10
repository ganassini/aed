double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    double biggest_c_pr, diff_c_pr, sum = 0;
    int biggest_c_pr_index;
	*classesColSize = 2;
    
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
