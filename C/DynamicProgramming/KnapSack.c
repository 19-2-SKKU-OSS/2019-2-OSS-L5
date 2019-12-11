#include <stdio.h>
#include <stdlib.h>
#define item 50
#define weight 50


int weights[weight] = { 0 };
int value[item] = { 0 };

int** 0_1_KNAPSAKC( int n, int W ){
	int **k = (int **)malloc(sizeof(int *)*n);
	for( int i = 0; i < n; i++ )
		k[i] = (int *)malloc(sizeof(int)*W);

	for( int i = 0; i < n; i++ )
		k[i][0] = 0;
	for( int j = 0; j < W; j++ )
		k[0][j-1] = 0;
	
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < W; j++){
			if( j < weights[i] )
				k[i][j] = k [i-1][j];
			k[i][j] = max( k[i-1][j], k[i-1][j-weights[i]] + value[i] );
		}
	}
				
	return k;
}

