#include <stdio.h>
#include <stdlib.h>
#define EPS 0.0001
#define F(x) (x * x - 10)

double half_div(double a,double b);

double chord(double a,double b);

double derivative(double x);

double derivative_2(double x);

double newton(double a,double b);

int main()
{
    printf("%f\n",half_div(0,5));
    printf("%f\n",chord(0,5));
    printf("%f\n",newton(0,5));

    return 0;
}

double half_div(double a,double b)
{
    double c = (a + b) / 2.0;

    while(abs(F(c)) > EPS){
        if(F(c) < 0)
            a = c;
        else
            b = c;

        c = (a + b) / 2.0;
    }

    return c;
}

double chord(double a,double b)
{
    double c = (a * F(b) - b * F(a)) / (F(b) - F(a));

    while(abs(F(c)) > EPS){
        if(F(a) * F(c) < 0 && F(b) * F(c) < 0)
            return -1.0;
        
        if(F(a) * F(c) > 0 && F(b) * F(c) > 0)
            return -1.0;

        if(F(a) * F(c) < 0)
            b = c;
        else
            a = c;
        
        c = (a * F(b) - b * F(a)) / (F(b) - F(a));
    }

    return c;
}

double derivative(double x)
{
    return 2.0 * x;
}

double derivative_2(double x)
{
    return 2.0;
}

double newton(double a,double b)
{
    if(F(a) * derivative_2(a) > 0 && F(b) * derivative_2(b) > 0)
        return -1.0;

    double c;

    if(F(a) * derivative_2(a) > 0)
        c = a;
    else
        c = b;
    
    while(abs(F(c)) > EPS)
        c = c - (F(c) / derivative(c)); 
    
    return c;
}