#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//let's consider that our function is sin(x)
//our task is to find an area of said function by numerically integrating it(using different methods/rules)

double left_rectan(double a, double b, int n)
{
    double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += sin(a + (b - a) / n * i) * ((b - a) / n); //counts sum using left-point rectangle method
        }
    return s;
}

double right_rectan(double a, double b, int n)
{
    double s = 0;
        for (int i = 1; i <= n; i++)
        {
            s += sin(a + (b - a) / n * i) * ((b - a) / n); //counts sum using right-point rectangle method
        }
    return s;
}

double middle_rectan(double a, double b, int n)
{
    double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += sin(a + (b - a) / n * i + (b - a) / (2 * n)) * ((b - a) / n); //counts sum using middle-point rectangle method
        }
    return s;
}

double trapez(double a, double b, int n)
{
    double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += (sin(a + (b - a) / n * i) + sin(a + (b - a) / n * (i + 1))) * ((b - a) / n) / 2; //counts sum using trapezoidal rule
        }
    return s;
}

double simpson(double a, double b, int n)
{
    double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += (sin(a + (b - a) / n * i) + sin(a + (b - a) / n * (i + 1)) + 4 * sin(a + (b - a) / n * i + (b - a) / (2 * n))) * ((b - a) / n) / 6; //counts sum using Simpson's rule
        }
    return s;
}

int main()
{
    int n, x;
    double a, b, s = 0, f;

    printf("Enter the values a,b,n>");
    scanf("%lf%lf%d", &a, &b, &n); 
    printf("\n Enter the number of any of the folowing methods/rules: \n 1 - left-point rectangle method \n 2 - right-point rectangle method \n 3 - middle-point rectangle method \n 4 - trapezoidal rule \n 5 - Simpson's rule \n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        f = left_rectan(a, b, n);
        break;
    case 2:
        f = right_rectan(a, b, n);
        break;
    case 3:
        f = middle_rectan(a, b, n);
        break;
    case 4:
        f = trapez(a, b, n);
        break;
    case 5:
        f = simpson(a, b, n);
        break;
    default:
        printf("Incorrect value, please try another");
    }
    printf("%lf", f); //printed result
    
}