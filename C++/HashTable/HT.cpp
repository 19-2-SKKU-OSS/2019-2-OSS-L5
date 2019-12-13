#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

void savePairs(int arr[], int n, int k, FILE *fpw)
{
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
 
		int cha = k - arr[i];
		if (map.find(cha) != map.end()) {
			int count = map[cha];
			for (int j = 0; j < count; j++){
				fprintf(fpw, "%d, %d\n", cha, arr[i]);
			}
		}
		map[arr[i]]++;
	}
}

int main()
{
	for (int j = 0; j < 5;j++) {
		char inputarr[20];
		char outputarr[20];
		printf("write input file name: ");
		scanf("%s", inputarr);
		printf("write output file name: ");
		scanf("%s", outputarr);

		FILE *fpr;
		FILE *fpw;
		fpr = fopen(inputarr, "r");
		fpw = fopen(outputarr, "w");

		char txt;
		int num;
		int k; 
		int t = 0; 

		while (1) {
			if (t == 0) {
				fscanf(fpr, "%c %d\n", &txt, &k);
				t++;
			}
			else {
				fscanf(fpr, "%d\n", &num);
				t++;
			}
			if (feof(fpr)) break;
		}

		rewind(fpr);
		t--;

		fscanf(fpr, "%c %d\n", &txt, &k);
		int *arr = (int *)malloc(sizeof(int)*t);
		int n = 0;

		while (1) {
			fscanf(fpr, "%d\n", &num);
			arr[n] = num;
			n++;
			if (feof(fpr)) break;
		}

		savePairs(arr, n, k, fpw);

		fclose(fpr);
		fclose(fpw);
	}
	
	return 0;
}
