//For this problem, your goal is to sort an array of 0, 1 and 2’s but you must do this in
//place, in linear time and without any extra space (such as creating an extra array). This
//is called the Dutch national flag sorting problem. For example, if the input array is
//[2, 0, 0, 1, 2, 1] then your program should output [0, 0, 1, 1, 2, 2] and the algorithm should
//run in O(n) time.

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Dnf_sort(int arr[], int n) {
	int i = 0;
	int j = 0;
	int k = n-1;

	while (j <= k) {
		if (arr[j] < 49) {
			swap(&arr[i], &arr[j]);
			i++;
			j++;
		}
		else if (arr[j] > 49) {
			swap(&arr[j], &arr[k]);
			k--;
		}
		else {
			j++;
		}
	}
}

int main(){
	FILE *fpr;
	FILE *fpw;
	fpr = fopen("hw1_input.txt", "r");
	fpw = fopen("hw1_output.txt", "w");
	int n = 0;
	char txt;
	
	while (1) {
		fscanf(fpr, "%c", &txt);
		if (txt != '\n') n++;
		if (feof(fpr)) break;
	}
	n--;
	rewind(fpr);
	
	int *arr = (int *)malloc(sizeof(char)*n);


	int i = 0;
	while (1) {
		if (i==n) break;
		fscanf(fpr, "%c", &txt);
		if (txt != '\n') {
			arr[i] = txt;
			i++;
		}
		
	}

	
	Dnf_sort(arr, i);

	
	for (int k = 0; k < n; k++) {
		fprintf(fpw, "%c", arr[k]);
		if (k == n-1) {
			break;
		}
		else fprintf(fpw, "%c", '\n');
	}

	fclose(fpr);
	fclose(fpw);

	return 0;
	
}
