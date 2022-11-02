#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    // n is the length of the initial array
    int n;
    printf("Please enter the length n: ");
    scanf("%d", &n);

    // arr is the initial array, generated randomly
    int arr[n];
    srand(time(NULL));
    for(int i=0; i<n; i++){
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    puts("");

    // k is the length of the sub-array
    int k = 3;

    // sub[k] is the sub-array of length k
    int sub[k];
    printf("Please enter the sub-array: ");
    for(int i=0; i<k; i++)
        scanf("%d", &sub[i]);

    // find the position of sub-array in the initial array

    for(int i=0; i<n; i++)
        arr[i] = arr[i] * 2;
    int cost[n], diff, m = INFINITY;
        for(int i=0; i<n; i++){
            diff = 0;
            if(i<k-1)
                cost[i] = INFINITY;
            else{
                // i = ?????
                for(int j=0; j<k; j++)
                    diff += abs(sub[j]-arr[i+j-k+1]);
                cost[i] = diff;
                m = (cost[i]<m)? cost[i] : m;
            }
    }
    for(int i=0; i<n; i++){
        if(cost[i]==m)
            printf("The sub-array with the smallest cost is from %d to %d.\n", i-k+1, i);
    }




//    double cosine[n], t, a, b, m = 0;
//    for(int i=0; i<n; i++){
//        t = 0, a = 0, b = 0;
//        if(i<k-1)
//            cosine[i] = -1;
//        else{
//            for(int j=0; j<k; j++){
//                t += sub[j] * arr[i+j-k+1];
//                a += pow(arr[i+j-k+1], 2);
//                b += pow(sub[j], 2);
//            }
//            cosine[i] = t / (sqrt(a) * sqrt(b));
//            m = (cosine[i] > m)? cosine[i] : m;
//        }
//    }
//    for(int i=0; i<n; i++){
//        if(cosine[i]==m)
//            printf("The sub-array with largest similarity is from %d to %d.\n", i-k+1, i);
//    }
    return 0;
}
