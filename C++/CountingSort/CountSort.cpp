#include <cstdio>

#define MAX_SIZE 1000
#define MAX_NUM 10000

int main(){
    int len, A[MAX_SIZE+1], B[MAX_SIZE+1], count[MAX_NUM+1], countSum[MAX_NUM+1];
    int i;

    scanf("%d", &len); // length should be under MAX_SIZE 배열 길이는 MAX_SIZE 미만

    for(i=0; i<= len; i++){
        count[i]=0; // initialize count array to 0 갯수 세는 배열 0으로 초기화
    }

    for(i=1; i<=N; i++){
        scanf("%d", &A[i]); // number input to array A should be under MAX_NUM 배열 길이는 MAX_SIZE 미만
 
        count[A[i]]++; // count how many times the number appear 해당 값이 얼마나 많이 
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
