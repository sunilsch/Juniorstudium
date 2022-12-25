#include <stdio.h>
#include <stdbool.h>

const long long runs = 1000;

int n, arr[10];

long long totalShuffles = 0;

/*
    swaps content from reference a to b
*/
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
    shuffles array with Fisher-Yates-Shuffle
*/
void shuffle(){
    for(int i = 0; i < n-2; i++){
        int j = i + (rand() % (n-i));
        swap(&arr[i], &arr[j]);
    }
}
/*
    returns if array is sorted
*/
bool isSorted(){
    for(int i = 0; i < n-1; i++) if(arr[i] > arr[i+1]) return false;
    return true;
}

/*
    sorts an array with shuffles
*/
void sort(){
    long long shuffles = 0;
    while(!isSorted()){
        shuffle();
        shuffles++;
    }
    totalShuffles += shuffles;
}

int main(){
    srand(time(NULL)); // set random seed
    printf("n = "); 
    scanf("%d", &n); // get input
    for(int r = 0; r < runs; r++){ // perform test runs
        for(int i = 0; i < n; i++) arr[i] = i+1; // fill array 
        shuffle(); // shuffle array
        sort(); // sort array
    }
    // output average number of shuffles
    printf("shuffles: %f", (((double)totalShuffles)/((double)runs)));
    return 0;
}