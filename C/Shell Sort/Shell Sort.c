# include <stdio.h>
# define MAX_SIZE 10

void insertionsort(int list[], int first, int last, int gap){
  int i, j, key;

  for(i=first+gap; i<=last; i=i+gap){
    key = list[i];

    for(j=i-gap; j>=first && list[j]>key; j=j-gap){
      list[j+gap] = list[j];
    }

    list[j+gap] = key;
  }
}


void shell_sort(int list[], int n){
  int i, gap;

  for(gap=n/2; gap>0; gap=gap/2){
    if((gap%2) == 0)(
      gap++; 
    )

    for(i=0; i<gap; i++){
      insertionsort(list, i, n-1, gap);
    }
  }
}

void main(){
  int i;
  int n = MAX_SIZE;
  int lt[n] = {6,5,3,7,1,2,4};

  shell_sort(lt, n);

  for(i=0; i<n; i++){
    printf("%d\n", lt[i]);
  }
}
