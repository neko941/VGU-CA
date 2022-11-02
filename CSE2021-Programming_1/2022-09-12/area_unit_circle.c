#include <stdio.h>
#include <math.h>

double get_y(double x){
    return sqrt(1 - pow(x, 2));
}

int main(){
    double delta = .000001;
    double r = 0;

    for (double x = -1; x < 1; x+= delta){
        r += get_y(x) * delta;
    }
    
    printf("%f", r*2);
}