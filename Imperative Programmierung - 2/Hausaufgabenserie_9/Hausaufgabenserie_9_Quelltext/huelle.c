#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, m;

    printf("Enter dimensions\nn = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    bool arr[n][m];

    // get input array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    // calculate result array
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(arr[i][k] == true){
                for(int j = 0; j < n; j++){
                    if(arr[k][j] == true)
                        arr[i][j] = true;   
                }
            }
        }
    }

    // print result
    printf("Reflexive transitive Huelle:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}