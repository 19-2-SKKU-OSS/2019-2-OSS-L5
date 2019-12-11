#include <stdio.h>
#include <stdlib.h>

#define weight 50
#define item 50

int value[item] = { 0 };
int weights[weight] = { 0 };

int* Fractional_KNAPSACK( int v, int w, int W ){
	int load = 0, i = 0;
	int* sack = (int *)malloc(sizeof(int)*item);

	while( load <= W && I < item ){
		if( W - load >= weights[i] ){
			sack[i] = weights[i];
			load = weights[i];
		}
		else{
			sack[i] =( W - load ) / weights[i];
			load = ( W - load ) / weights[i];
		}

		i++:
	}
	return sack;
}
