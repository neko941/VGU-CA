#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Question 1
int** createMatrix(int m, int n){
    int **M = (int**)malloc(m * sizeof(int*));
    for(int i=0; i<m; i++)
        *(M + i) = (int*)malloc(n * sizeof(int));

    printf("Enter matrix: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            scanf("%d", *(M+i)+j);
    }
    puts("");
    return M;
}

void printMatrix(int **M, int m, int n){
    for(int i=0; i<m; i++){
        (i==0)? printf("[ ") : printf("  ");
        for(int j=0; j<n; j++)
            printf("%d ", *(*(M+i)+j));
        if(i==m-1)
            printf("]");
        puts("");
    }
    puts("");
}

int** multiplyMatrix(int **M, int **v, int m, int n, int p){
    int **result = (int**)malloc(m * sizeof(int*));
    for(int i=0; i<m; i++)
        *(result + i) = (int*)malloc(p * sizeof(int));

    printf("M = \n");
    printMatrix(M, m, n);

    printf("v = \n");
    printMatrix(v, n, p);

    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            *(*(result+i)+j) = 0;
            for(int k=0; k<n; k++)
                *(*(result+i)+j) = *(*(result+i)+j) + (*(*(M+i)+k)) * (*(*(v+k)+j));
        }
    }
    return result;
}

// Question 2
int** initMatrix(int m, int n){
    int **M = (int**)malloc(m * sizeof(int*));
    srand((unsigned)time(NULL));
    for(int i=0; i<m; i++)
        *(M + i) = (int*)malloc(n * sizeof(int));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            *(*(M+i)+j) = rand() % 10; // < 10 -> 0, 1, 2, 3, 4 .. 9
    }
    puts("");
    return M;
}

void getStat(int **M, int m, int n){
    int _max = INT_MIN, _min = INT_MAX, _sum = 0;
    float _avg = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            _max = (*(*(M+i)+j)<_max)? _max : *(*(M+i)+j); // if
            _min = (*(*(M+i)+j)>_min)? _min : *(*(M+i)+j);
            _sum = _sum + *(*(M+i)+j);
        }
    }
    _avg = (float)_sum / (m * n);
    printf("Max = %d\nMin = %d\nAvg = %f\n", _max, _min, _avg);
}

void check(int **M, int x, int m, int n){
    short flag = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(*(*(M+i)+j)==x){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    // 0 -> False; != 0 -> True
    if(flag)
        printf("True :)");
    else
        printf("False :(");
}

int main()
{
    // Question 1:
//    int m, n, p;
//    printf("Enter the size of the matrices: ");
//    scanf("%d %d %d", &m, &n,&p);
//
//    int **M = createMatrix(m, n);
//    int **v = createMatrix(n, p);
//
//    int **result = multiplyMatrix(M, v, m, n, p);
//    printf("Result = \n");
//    printMatrix(result, m, p);

    // Question 2:
    int m, n;
    printf("Enter the size of the matrix: ");
    scanf("%d %d", &m, &n);

    int **M = initMatrix(m, n);
    printf("Matrix A = \n");
    printMatrix(M, m, n);
//    getStat(M, m, n);

    puts("");
    int x;
    printf("Enter the number: \n");
    scanf("%d", &x);
    check(M, x, m, n);
    return 0;
}
