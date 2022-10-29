#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Exercise 1
double calculator(double a, double b, char op){
    if(op=='A')
        return (a + b);
    else if(op=='S')
        return (a - b);
    else if(op=='D')
        return (a / b);
    else if(op=='M')
        return (a * b);
    else{
        printf("No such operations\n");
        return 0;
    }
}

// Exercise 2
void cmpReverse(char str1[], char str2[]){
    int n = strlen(str1);
    for(int i=0; i<n; i++){
        if(str1[i]!=str2[n-1-i]){
            printf("No\n");
            return;
        }
        if(i==n-1)
            printf("Yes\n");
    }
}

// Exercise 3
void arrayStat(int arr[], int n){
    int maxArr = INT_MIN, minArr = INT_MAX, sumArr = 0; // maxArr = arr[0]
    for(int i=0; i<n; i++){
        maxArr = (maxArr>arr[i])? maxArr : arr[i];
        minArr = (minArr<arr[i])? minArr : arr[i];
        sumArr = sumArr + arr[i];
    }
    printf("max: %d, min: %d, avg: %.1f\n", maxArr, minArr, (float)sumArr/n);
}

// Exercise 4
void capDecap(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(str[i]>='a'&&str[i]<='z')
            str[i] = (char)(str[i] + 'A' - 'a');
        else if(str[i]>='A'&&str[i]<='Z')
            str[i] = (char)(str[i] + 'a' - 'A');
    }
    puts(str);
}

// Exercise 5
void quadraticEquation(float a, float b, float c){
    // a * x^2 + b * x + c -> delta -> x1, x2; x; 0 nghiệm
    if(a==0){
        printf("Not a quadratic equation");
        return;
    }
    float delta = pow(b, 2) - 4 * a * c;
    if(delta==0)
        printf("%.2f\n", -b/(2*a));
    else if(delta>0)
        printf("%.2f %.2f\n", (-b-sqrt(delta))/(2*a), (-b+sqrt(delta))/(2*a));
    else
        printf("No solution");

}

// Exercise 6
void hateThrees(int n){
    int i = 1;
    while(n>0){
        if(i%10!=3&&i%3!=0){
            printf("%d ", i);
            n = n - 1;
        }
        i = i + 1;
    }
    puts("");
}

// Exercise 7
void multiplyBy2(int arr[], int n){
    for(int i=0; i<n; i++){
        if(i%2==0)
            arr[i] = 2 * arr[i];
        printf("%d ", arr[i]);
    }
    puts("");
}

// Exercise 8
void findPosition(int x, int arr[3][3]){
    int flag = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j]==x){
                printf("(%d, %d)\n", i, j);
                flag++;
            }
        }
    }
    if(flag==0)
        printf("Not found\n");
}

// Exercise 9
void reverseArray(int arr[], int n){
    for(int i=0; i<n/2; i++){
        arr[i] = arr[i] + arr[n-i-1];
        arr[n-i-1] = arr[i] - arr[n-i-1];
        arr[i] = arr[i] - arr[n-i-1];
    }
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    puts("");
}

// Exercise 10
void countEven(int arr[], int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0)
            cnt = cnt + 1;
    }
    printf("Number of even number: %d\n", cnt);
}

// Exercise 11
void sumDigits(int n){
    int s = 0;
    while(n>0){
        s = s + n % 10;
        n = n / 10;
    }
    printf("Sum: %d\n", s);
}

// Exercise 12
void calculateArea(int arr[2][2]){
    int a = (arr[1][0]-arr[0][0])*(arr[1][1] - arr[0][1]);
    printf("Area: %d\n", a);
}

// Exercise 13
void compoundInterest(int p, int r, int t){
    float i = (float)p * pow((1 + (float)r/100), t);
    printf("Interest: %f\n", i);
}

// Exercise 14
void findWord(char word[], char str[]){
    int n = strlen(str), m = strlen(word);
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<m; j++){
            if(str[i+j]!=word[j])
                break;
            if(j==m-1){
                printf("%d\n", i);
                return;
            }
        }
    }
    printf("Not found\n");
}

// Exercise 15
void identityChecking(int arr[3][3]){
    int cnt = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j]==1){
                if(i==j)
                    cnt = cnt + 1;
                else{
                    printf("No\n");
                    return;
                }
            }
        }
    }
    if(cnt==3)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
//     Exercise 1:
//    double result;
//    result = calculator(4, 5, 'A');
//    printf("%.1f\n", result);
//
//    result = calculator(7, 2, 'S');
//    printf("%.1f\n", result);
//
//    result = calculator(9, 3, 'D');
//    printf("%.1f\n", result);
//
//    result = calculator(4, 2, 'M');
//    printf("%.1f\n", result);

    // Exercise 2:
//    cmpReverse("programming", "gnimmargorp");
//    cmpReverse("aaaabb", "aaaabb");
//    cmpReverse("AaBbCc", "cCbBaA");

    // Exercise 3:
//    int arr1[] = {1, 2, 3, 4, 5};
//    arrayStat(arr1, 5);
//
//    int arr2[] = {1};
//    arrayStat(arr2, 1);
//
//    int arr3[] = {8, 4, 8, 10};
//    arrayStat(arr3, 4);

    // Exercise 4:
//    char str1[] = "aaBBcc";
//    capDecap(str1);
//
//    char str2[] = "aAbBcC";
//    capDecap(str2);

    // Error
//    char *str = "aaBBcc";
//    capDecap(str);

    // Exercise 5:
//    quadraticEquation(1, -3, 2);
//    quadraticEquation(1, -4, 4);
//    quadraticEquation(1, 4, -4);
//    quadraticEquation(1, 1, 1);

    // Exercise 6:
//    hateThrees(5);
//    hateThrees(10);

    // Exercise 7:
//    int arr1[] = {1, 2, 3, 4, 5};
//    multiplyBy2(arr1, 5);
//
//    int arr2[] = {7, 9};
//    multiplyBy2(arr2, 2);

    // Exercise 8:
//    int arr1[3][3] = {{1, 2, 3}, {4, 5, 5}, {7, 8, 9}};
//    findPosition(5, arr1);
//
//    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
//    findPosition(7, arr2);

    // Exercise 9:
//    int arr1[] = {1, 2, 3, 4, 5};
//    reverseArray(arr1, 5);
//
//    int arr2[] = {1};
//    reverseArray(arr2, 1);

    // Exercise 10:
//    int arr1[] = {1, 2, 3, 4, 5};
//    countEven(arr1, 5);
//
//    int arr2[] = {1, 3, 5, 7, 9};
//    countEven(arr2, 5);
//
//    int arr3[] = {2, 4, 6, 8, 10};
//    countEven(arr3, 5);

    // Exercise 11:
//    sumDigits(123450);
//    sumDigits(246810);

    // Exercise 12:
//    int arr1[2][2] = {{1, 1}, {4, 4}};
//    calculateArea(arr1);
//
//    int arr2[2][2] = {{1, 2}, {3, 3}};
//    calculateArea(arr2);

    // Exercise 13:
//    compoundInterest(1000, 10, 5);
//    compoundInterest(1500, 7, 20);

    // Exercise 14:
//    findWord("khoa", "nguyenthieunangkhoa");
//    findWord("hello", "abcdhelloabcde");

    // Exercise 15:
    int arr1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    identityChecking(arr1);

    int arr2[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 0, 1}};
    identityChecking(arr2);

    return 0;
}
