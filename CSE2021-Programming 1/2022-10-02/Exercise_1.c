#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSet(int arr[], int arrSet[], int n){
    // first element of arr is guarantee not in arrSet
    arrSet[0] = arr[0];

    // m is the current length of set
    int m = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            // check if arr[i] has appeared in the set or not
            if(arr[i]==arrSet[j])
                break;
            else{
                if(j==m-1){
                    arrSet[m] = arr[i];
                    m++;
                }
            }
        }
    }
    // print out the array
    printf("Set: ");
    for(int i=0; i<m; i++)
        printf("%d ", arrSet[i]);
    puts("");
    return m;
}

void getProbability(int arr[], int arrSet[], int n, int m){
    // initialize an array with all elements = 0
    int arrCount[m];
    for(int i=0; i<m; i++)
        arrCount[i] = 0;

    // check whether arr[i] appears in arrSet[j]; if yes, count at j plus 1
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
             if(arr[i]==arrSet[j]){
                // if arr[i] appears in the set, count plus 1
                arrCount[j] = arrCount[j] + 1;
             }
        }
    }
    // print out the array
    printf("Count: ");
    for(int i=0; i<m; i++){
        if(arrCount>0)
            printf("%d ", arrCount[i]);
    }
    puts("");
}

int main(){
    // length of the array
    int n;
    scanf("%d", &n);
    srand(time(NULL));

    // initialize an array
    int arr[n];
    printf("Array: ");
    for(int i=0; i<n; i++){
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    puts("");

    // get set
    int arrSet[n];
    int m = getSet(arr, arrSet, n);

    // get count
    getProbability(arr, arrSet, n, m);
    return 0;
}
