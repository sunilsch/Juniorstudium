#include <stdio.h>

#define N 1000

int arr[N];

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *n, int *arr){
    // --> (bubble sort)
    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *n - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(&n, arr);
    for(int i = 0; i < n; i++) printf("%d : %d\n", i, arr[i]);
}