#include <stdio.h>

double function(double x){
    return x * x;
}

double derivative(double x, double delta){
    return (function(x + delta) - function(x))/ delta;
}

double update(double x, double learning_rate, double derivative){
    return x - learning_rate*derivative;
}

int main(){
    double x = 3;
    double delta = 0.00001;
    double lr = 0.01;

    printf("x : %f\n", x);
    double deri = derivative(x, delta);
    printf("Derivative of x : %f\n", deri);
    double x_new = update(x, 0.1, deri);
    printf("New x : %f\n", x_new);
}