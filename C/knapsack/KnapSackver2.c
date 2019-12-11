#include <stdio.h>
#include <stdlib.h>

#define weight 50
#define item 50

int value[item] = { 0 };
int weights[weight] = { 0 };

int* Fractional_KNAPSACK( int v, int w, int W ){
	int load = 0, i = 0;
	int* sack = (int *)malloc(sizeof(int)*item);
	int tmp_weight;

	while( load <= W && i < item ){
		if( W - load >= weights[i] ){
			sack[i] = weights[i];
			load = weights[i];
		}
		else{
			tmp_weight = ( W - load ) / weights[i];
			sack[i] = tmp_weight;
			load = tmp_weight;
		}

		i++:
	}
	return sack;
}
