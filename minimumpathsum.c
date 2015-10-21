//
//  https://www.codeeval.com/open_challenges/72/
//  minimumpathsum
//
//  Created by Stephan Warren on 1/6/15.
//  Copyright (c) 2015 Stephan Warren. All rights reserved.
//
/*
 
 MINIMUM PATH SUM
 CHALLENGE DESCRIPTION:
 
 You are given an n*n matrix of integers. You can move only right and down. Calculate the minimal path sum from the top left to the bottom right
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. The first line will have the value of n(the size of the square matrix). This will be followed by n rows of the matrix. (Integers in these rows will be comma delimited). After the n rows, the pattern repeats. E.g.
 
 2
 4,6
 2,8
 3
 1,2,3
 4,5,6
 7,8,9
 OUTPUT SAMPLE:
 
 Print out the minimum path sum for each matrix. E.g.
 
 14
 21
 
 
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE *file = fopen(argv[1], "r");
    short dim;
    int ** grid;
    
    while(fscanf(file, "%hd", &dim) && !feof(file)) {
        grid = (int **) malloc(sizeof(int *) * dim);
        for(short r = 0; r < dim ; r++) {
            grid[r] = (int *) malloc(sizeof(int) * dim);
        }
        for(short r = 0; r < dim; r++) {
            for(short c = 0; c < dim; c++) {
                fscanf(file, "%d,", &grid[r][c]);
//                printf("%d ", grid[r][c]);
            }
//            printf("\n");
        }
    
//        printf("\n");
        
        short diagcnt = 2 * dim - 2;
        for(short diag = diagcnt - 1; diag >= 0; diag--) {
            for(short cell = 0; cell <= diag; cell++) {
                short r = cell;
                short c = diag - cell;
                if((r < dim) && (c < dim)) {
                    int bottom = (r + 1 < dim) ? grid[r + 1][c] : 0x7fffffff;
                    int right = (c + 1 < dim) ? grid[r][c + 1] : 0x7fffffff;
                    if(bottom < right)
                        grid[r][c] += bottom;
                    else
                        grid[r][c] += right;
                    
                }
                
            }
        }
        
//        for(short r = 0; r < dim; r++) {
//            for(short c = 0; c < dim; c++) {
//                printf("%d ", grid[r][c]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//        printf("\n");
// 

        printf("%d\n", grid[0][0]);
    
        for(short r = 0; r < dim ; r++) {
            free(grid[r]);
        }
        free(grid);
    }
    
    
    return 0;
}
