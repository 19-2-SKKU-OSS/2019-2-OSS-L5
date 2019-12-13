#include <cstdio>

#define MAX_SIZE 1000
#define MAX_NUM 10000

int main(){
    int len, A[MAX_SIZE+1], B[MAX_SIZE+1], count[MAX_NUM+1], countSum[MAX_NUM+1];
    int i;

    scanf("%d", &len); // length should be under MAX_SIZE

    for(i=0; i<= len; i++){
        count[i]=0; // initialize count array to 0
    }

    for(i=1; i<=N; i++){
        scanf("%d", &A[i]); // number input to array A should be under MAX_NUM

        count[A[i]]++; // count how many times the number appear
    }

    // make sum
    countSum[0] = count[0];
    for(i=1; i<= MAX_NUM; i++){
        countSum[i]=countSum[i-1]+count[i];
    }

    // array A from back
    for(i=N; i>=1; i--){
        B[countSum[A[i]]]=A[i];
        countSum[A[i]]--;
    }

    //print sorted array B
    for(i=1; i<=N; i++){ 
        printf("%d", B[i]);
    }
}
