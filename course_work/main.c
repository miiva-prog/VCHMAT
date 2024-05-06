#include <stdio.h>
#include <math.h>
#define H 0.0188
#define K 0.042
#define EPS 0.01
#define RO 0.952
#define B 0.999
#define aE 0.999
#define aI 0.999
#define Y 0
#define C 1
#define e0 99
#define r0 24
#define n0 3000000

double DS(double s,double e,double i,double r,double d);

double DE(double s,double e,double i,double r,double d);

double DI(double s,double e,double i,double r,double d);

double DR(double s,double e,double i,double r,double d);

double DD(double s,double e,double i,double r,double d);

void euler(double a,double b,double h,double *S,double *E,double *I,double *R,double *D);

int main()
{
    double e = e0,i = 0.0,r = r0,d = 0.0,s = n0 - i - e - r - d;
    double a,b,h,d1 = d,delta = 0.0;

    printf("(a - b) ->");
    scanf("%lf %lf",&a,&b);
    printf("h ->");
    scanf("%lf",&h);
    euler(a,b,h,&s,&e,&i,&r,&d);

    while(delta > EPS){
        h = h / 2.0;
        e = e0;
        r = r0;
        i = d = 0.0;
        s = n0 - i - e - r - d;

        euler(a,b,h,&s,&e,&i,&r,&d);

        delta = fabs(d - d1);
        d1 = d;
    }

    printf("S ->%f | E ->%f | I ->%f | R ->%f | D ->%f | N ->%f\n",s,e,i,r,d,s + e + i + r + d);

    return 0;
}

double DS(double s,double e,double i,double r,double d)
{
    double N = s + e + i + r + d;

    return -C * (aI * s * i + aE * s * e) / N + Y * r;
}

double DE(double s,double e,double i,double r,double d)
{
    double N = s + e + i + r + d;

    return C * (aI * s * i + aE * s * e) / N - (K + RO) * e;
}

double DI(double s,double e,double i,double r,double d)
{
    return K * e - B * i - H * i + 0 * (s + r + d);
}

double DR(double s,double e,double i,double r,double d)
{
    return B * i + RO * e - Y * r + 0 * (s + d);
}

double DD(double s,double e,double i,double r,double d)
{
    return H * i + 0 * (s + e + r + d);
}

void euler(double a,double b,double h,double *S,double *E,double *I,double *R,double *D)
{
    double s,e,i,r,d;
    double s2,e2,i2,r2,d2;

    for(;a <= b;a += h){
        s = *S + h * DS(*S,*E,*I,*R,*D);
        e = *E + h * DE(*S,*E,*I,*R,*D);
        i = *I + h * DI(*S,*E,*I,*R,*D);
        r = *R + h * DR(*S,*E,*I,*R,*D);
        d = *D + h * DD(*S,*E,*I,*R,*D);
        s2 = *S + h / 2 * (DS(*S,*E,*I,*R,*D) + DS(s,e,i,r,d));
        e2 = *E + h / 2 * (DE(*S,*E,*I,*R,*D) + DE(s,e,i,r,d));
        i2 = *I + h / 2 * (DI(*S,*E,*I,*R,*D) + DI(s,e,i,r,d));
        r2 = *R + h / 2 * (DR(*S,*E,*I,*R,*D) + DR(s,e,i,r,d));
        d2 = *D + h / 2 * (DD(*S,*E,*I,*R,*D) + DD(s,e,i,r,d));
        *S = s;
        *E = e;
        *I = i;
        *R = r;
        *D = d;
    }

    *S = s2;
    *E = e2;
    *I = i2;
    *R = r2;
    *D = d2;
}