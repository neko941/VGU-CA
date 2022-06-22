 # Chapter 3
## 3.1
Calculate (123 * 321 + 123) and print the result
```c
#include <stdio.h>

main ()
{
  printf("123 * 321 + 123 = %d\n",123 * 321 + 123);
}
```
## 3.2
Print a box only using puts  
Example
```
************
*          *
*          *
*          *
*          *
*          *
************
```
Answer:
```c
#include <stdio.h>

int main()
{
    puts("************");
    puts("*          *");
    puts("*          *");
    puts("*          *");
    puts("*          *");
    puts("*          *");
    puts("************");
}
```
## 3.3
Calculate the perimeter and area of a rectangle with height = 7 (inches) and width = 5 (inches)  
Output:
```
Perimeter = 24 (inches)
Area = 35 (square inches)
```
```c
#include <stdio.h>

int main() {
	int height = 7;
	int width = 5;

	printf("Perimeter = %d (inches)\n", 2*(height + width));
	printf("Area = %d (square inches)\n", height * width);
}
```

# Chapter 4
## 4.1
Print this text
```
Are you going to Scarborough Fair?
Parsley, sage, rosemary, and thyme
Remember me to one who lives there
She once was a true love of mine
```
Answer:
```c
#include <stdio.h>

int main()
{
    puts("Are you going to Scarborough Fair?");
    puts("Parsley, sage, rosemary, and thyme");
    puts("Remember me to one who lives there");
    puts("She once was a true love of mine");
}
```
## 4.2
Print this without using any variable:  
D:\\[00] Upload\\[00] Error\\[PCCG-01351] \"Shingeki no Kyojin\" Original Soundtrack [24bit/48kHz].rar
```c
#include <stdio.h>

int main()
{
    printf("D:\\[00] Upload\\[00] Error\\[PCCG-01351] \"Shingeki no Kyojin\" Original Soundtrack [24bit/48kHz].rar");
}
```
## 4.3 
Print this table only using printf:
```
┌──┬────┐
├──┼────┤
│  │    │
└──┴────┘
```
Hint:
```
printf("%c", 196);
```
Answer:
```c
#include <stdio.h>

int main()
{
    printf("%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 194, 196, 196, 196, 196, 191);
    printf("%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 197, 196, 196, 196, 196, 180);
    printf("%c  %c    %c\n", 179, 179, 179);
    printf("%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 193, 196, 196, 196, 196, 217);
}
```

# Chapter 5
## 5.1
Check whether 23 is divisible by 4
```c
#include <stdio.h>

int main()
{
    int result = 23 % 4;
    if(result == 0)
    {
        printf("23 is divisible by 4");
    }
    else
    {
        printf("23 is not divisible by 4");
    }
}
```
## 5.2
Print These Number:
```
short int si1 = -32768, si2 = 32767;
unsigned short int usi = 65535;
unsigned int ui = 4294967295;
int i1 = -2147483648, i2 = 2147483647;
long int li1 = -2147483648, li2 = 2147483647;
unsigned long int uli = 4294967295;
long long int lli1 = -9223372036854775807, lli2 = 9223372036854775807;
unsigned long long int ulli = 18446744073709551615;
```
Output:
```
Range of short int: -32768 → 32767
Range of unsigned short int: 0 → 65535
Range of unsigned int: 0 → 4294967295
Range of int: -2147483648 → 2147483647
Range of long int: -2147483648 → 2147483647
Range of unsigned long int: 0 → 4294967295
Range of long long int: -9223372036854775809 → 9223372036854775807
Range of unsigned long long int: 0 → 18446744073709551615
```
Answer:
```c
#include <stdio.h>
#include <limits.h>

int main()
{
    short int si1 = SHRT_MIN, si2 = SHRT_MAX;
    unsigned short int usi = USHRT_MAX;
    unsigned int ui = UINT_MAX;
    int i1 = INT_MIN, i2 = INT_MAX;
    long int li1 = LONG_MIN, li2 = LONG_MAX;
    unsigned long int uli = ULONG_MAX;
    long long int lli1 = LLONG_MIN, lli2 = LLONG_MAX;
    unsigned long long int ulli = ULLONG_MAX;

    printf("Range of short int: %hd %c %hd\n", si1 , 26, si2);
    printf("Range of unsigned short int: 0 %c %hu\n", 26, usi);
    printf("Range of unsigned int: 0 %c %u\n", 26, ui);
    printf("Range of int: %d %c %d\n", i1, 26, i2);
    printf("Range of long int: %ld %c %ld\n", li1, 26, li2);
    printf("Range of unsigned long int: 0 %c %lu\n", 26, uli);
    printf("Range of long long int: %lld %c %lld\n", lli1, 26, lli2);
    printf("Range of unsigned long long int: 0 %c %llu\n", 26, ulli);
}

```
## 5.3
Print These Number "Nicely":
```
int i1 = -2039407152;
int i2 = 2039407151;
```
Output:
```
-2 039 407 152
2 039 407 151
```
Answer:
```c
#include <stdio.h>

void print_with_space(int num)
{
    int temp = 0;
    int scale = 1;
    if (num < 0)
    {
        printf("-");
        num = -num;
    }

    while (num >= 1000)
    {
        temp = temp + scale * (num % 1000);
        num /= 1000;
        scale *= 1000;
    }

    printf("%d", num);

    while (scale != 1)
    {
        scale /= 1000;
        num = temp / scale;
        temp = temp % scale;
        printf(" %03lld", num);
    }

    puts("");
}

int main()
{
    int i1 = -2039407152;
    int i2 = 2039407151;

    print_with_space(i1);
    print_with_space(i2);
}

```

# Chapter 6
## 6.1
Create an array with const int type, and then try to change the value inside the array. What is the error?
Answer:
```
error: assignment of read-only location 'array[0]'
```
## 6.2
Gwt raidus from user adn calculate the perimeter and area of a circle  
Example:
```
Input: 6
Output: 
	Perimeter = 37.699112 (inches)
	Area = 113.097336 (square inches)
``` 
Answer:
```c
#include <stdio.h>
#include <math.h>

int main()
{
    int radius;

    printf("radius = ");
    scanf("%d", &radius);

    printf("Perimeter = %f (inches)\n", 2 * M_PI * radius);
    printf("Area = %f (square inches)\n", M_PI * radius * radius);\
}
```
# Chapter 14
## 14.1
Using struct to store and compute sum of (1 meter and 50 centimeters; 1 meter and 51 centimeters):  
Output:
```
3 meter(s) and 1 centimeter(s)
```
Answer:
```c
struct height
{
  int meters;
  int centimeters;
};

struct height sum(struct height a, struct height b)
{
  struct height temp;
  temp.centimeters = a.centimeters + b.centimeters;
  temp.meters = a.meters + b.meters;

  if (temp.centimeters >= 100)
  {
      temp.centimeters -= 100;
      temp.meters += 1;
  }

  return temp;
}

int main()
{
  struct height h1 = {1, 50};
  struct height h2 = {1, 51};

  struct height a = sum(h1, h2);

  printf("%d meter(s) and %d centimeter(s)\n", a.meters, a.centimeters);
}

```
## 14.2
Using struct to store data. 
This struct has 2 variables: 
 + Composer
 + Metadata  

Metadata is also a struct which has 3 variables:
 + Title
 + Catalog Number
 + Number of Tracks
Output:
```
Composer: Arai Ken
Catalog Number: VPCG-84988
Title: Kiseijuu Sei no Kakuritsu Original Soundtrack
Number of Tracks: 19
```
Answer:
```c
#include <stdio.h>

struct metadata
{
    char catalog[20];
    char title[100];
    int num_tracks;
};

struct info
{
    char composer[50];
    struct metadata data;
}album = {"Arai Ken", {"VPCG-84988", "Kiseijuu Sei no Kakuritsu Original Soundtrack", 19}};

int main()
{
    printf("Composer: %s\n", album.composer);
    printf("Catalog Number: %s\n", album.data.catalog);
    printf("Title: %s\n", album.data.title);
    printf("Number of Track: %d\n", album.data.num_tracks);
}
```
## 14.3
Find time difference using:
```
struct TIME
{
    int days;
    int hours;
    int minutes;
    int seconds;
};
```
Example
```
Input:
  Start: 9 days, 23 hours, 37 minutes, 58 seconds
  End: 14 days, 7 hours, 4 minutes, 27 seconds
Output:
  Time Difference: 4 days, 7 hours, 26 minutes, 29 seconds
```
Answer:
```c
#include <stdio.h>
#include <stdlib.h>

struct TIME
{
    int days;
    int hours;
    int minutes;
    int seconds;
};

struct TIME get_input(struct TIME time, char name[10])
{
    printf("%s.days = ", name);
    scanf("%d", &time.days);
    printf("%s.hours = ", name);
    scanf("%d", &time.hours);
    printf("%s.minutes = ", name);
    scanf("%d", &time.minutes);
    printf("%s.seconds = ", name);
    scanf("%d", &time.seconds);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return time;
}

void print_time(struct TIME time)
{
    printf("%d days, %d hours, %d minutes, %d seconds\n", time.days, time.hours, time.minutes, time.seconds);
}

struct TIME fix_format(struct TIME time)
{
    if(time.seconds >= 60)
    {
        time.seconds -= 60;
        time.minutes++;
    }

    if(time.minutes >= 60)
    {
        time.minutes -= 60;
        time.hours++;
    }

    if(time.hours >= 24)
    {
        time.hours -= 24;
        time.days++;
    }

    return time;
}

struct TIME calculate_diff(struct TIME start, struct TIME end)
{
    struct TIME temp;

    if(start.seconds > end.seconds)
    {
        end.seconds += 60;
        end.minutes--;
    }

    if(start.minutes > end.minutes)
    {
        end.minutes += 60;
        end.hours--;
    }

    if(start.hours > end.hours)
    {
        end.hours += 24;
        end.days--;
    }

    if(start.days > end.days)
    {
        printf("NANI KORE????");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        exit(0);
    }

    temp.days = end.days - start.days;
    temp.hours = end.hours - start.hours;
    temp.minutes = end.minutes - start.minutes;
    temp.seconds = end.seconds - start.seconds;

    temp = fix_format(temp);

    return temp;
}

int main()
{
    // declare variables
    struct TIME start;
    struct TIME end;
    struct TIME diff;

    // get input
    start = get_input(start, "start");
    end = get_input(end, "end");

    // check the input
    start = fix_format(start);
    end = fix_format(end);

    // calculate time difference
    diff = calculate_diff(start, end);

    // display data
    printf("Start: ");
    print_time(start);
    printf("End: ");
    print_time(end);
    printf("Time Difference: ");
    print_time(diff);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
```

# Chapter 15
## 15.1
Get a list of numbers from command line and calculate sum
Example:
```
  Input: 1 2 3
  Output: Sum = 6
```
Answer:
```c
#include <stdio.h>
#include <stdlib.h>

int i;

int main(int argc, char *argv[])
{
    int size = argc - 1;
    float sum;

    for (i = 0; i < size; i++)
    {
        sum += atof(argv[i + 1]);
    } 
    
    printf("Sum = %f", sum);
}
```
## 15.2
Get a list of numbers from command line and calculate Mean  
<img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_black&space;\huge&space;Mean&space;=&space;\frac{1}{N}\sum_{i=0}^{N}x_{i}" title="\huge Mean = \frac{1}{N}\sum_{i=0}^{N}x_{i}" />  
Example:
```
Input: 2 8 5 4 1 8
Output: 4.666667
```
Answer:
```
#include <stdio.h>
#include <stdlib.h>

int i;

int main(int argc, char *argv[])
{
    float sum;

    for (i = 0; i < argc - 1; i++)
    {
        sum += atof(argv[i + 1]);
    }

    printf("Mean = %f", sum / (argc - 1));
}
```
## 15.3
Get a list of numbers from command line and using the formula "Softmax function (stable)" to calculate:  
<img src="https://latex.codecogs.com/png.latex?\dpi{120}&space;\bg_black&space;\huge&space;m&space;=&space;max(x)" title="\huge m = max(x)" />  
<img src="https://latex.codecogs.com/png.latex?\dpi{120}&space;\bg_black&space;\huge&space;f(x_{i})&space;=&space;\frac{e^{(x_{i}-m)}}{\sum_{j}&space;e^{(x_{j}-m)}}" title="\huge f(x_{i}) = \frac{e^{(x_{i}-m)}}{\sum_{j} e^{(x_{j}-m)}}" />  
Example:
```
  Input:  1               2               3
  Output: 0.090031        0.244728        0.665241
```
Answer:
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i;

float max(float *X, int size)
{
    int result = X[0];
    for (i = 1; i < size; i++)
    {
        if (X[i] > result)
        {
            result = X[i];
        }
    }
    return result;
}

void stable_softmax(float *X, int size)
{
    double sum_exp;
    float exp[size];
    float maximum = max(X, size);

    for (i = 0; i < size; i++)
    {
        exp[i] = pow(M_E, X[i] - maximum);
        sum_exp += exp[i];
    }
    printf("\nResult:\n");
    for (i = 0; i < size; i++)
    {
        printf("%f\t", exp[i] / sum_exp);
    }
}

int main(int argc, char *argv[])
{
    int size = argc - 1;
    float arr[size];

    printf("Input:\n");
    for (i = 0; i < size; i++)
    {
        arr[i] = atof(argv[i + 1]);
        printf("%f\t", arr[i]);
    }
    stable_softmax(arr, size);
}
```

# Chapter 16
## 16.1
Using struct to store and compute sum of (1 meter and 50 centimeters; 1 meter and 51 centimeters) and using typedef for that struct  
Hint:
```
struct height
{
  int meters;
  int centimeters;
};

typedef struct height new_datatype;
```
Output:
```
3 meter(s) and 1 centimeter(s)
```
Answer:
```c
struct height
{
  int meters;
  int centimeters;
};

typedef struct height new_datatype;

new_datatype sum(new_datatype a, new_datatype b)
{
  new_datatype temp;
  temp.centimeters = a.centimeters + b.centimeters;
  temp.meters = a.meters + b.meters;

  if (temp.centimeters >= 100)
  {
      temp.centimeters -= 100;
      temp.meters += 1;
  }

  return temp;
}

int main()
{
  new_datatype h1 = {1, 50};
  new_datatype h2 = {1, 51};

  new_datatype a = sum(h1, h2);

  printf("%d meter(s) and %d centimeter(s)\n", a.meters, a.centimeters);
}
```
## 16.2
Using enumerate to store months in year 2000. Let user input a number (1-12) and then print numbers of days of that month  
Example:
```
Input: 2
Outputs: 29 days
```
Answer:
```c
#include <stdio.h>

int main()
{
    enum {_, January, February, March, April, May, June, July, August, September, October, November, December};
    int month;

    printf("Enter a month number, 1 - 12:\n>> ");
    scanf("%d",&month);

    if(month < 1 || month > 12)
    {
        puts("Invalid input");
    }
    else
    {
        switch(month)
        {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            puts("31 days");
            break;
        case February:
            puts("29 days");
            break;
        case April:
        case June:
        case September:
        case November:
            puts("30 days");
            break;
        };
    }
}
```
