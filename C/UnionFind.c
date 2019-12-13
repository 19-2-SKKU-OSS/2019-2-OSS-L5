#include<stdio.h>
#Define MAX_SIZE 100

int root[MAX_SIZE];

for (int i = 0; i < MAX_SIZE; i++)
    parent[i] = i;

int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return find(root[x]);
    }
}

void union(int x, int y){

    x = find(x);
    y = find(y);

    root[y] = x;
}
