// given coordinates and centre of two circles, to find center and coordinate of minimum circle to enclose both circle

#include <stdio.h>
#include <math.h>
int main(void)
{
    double a, b, c, d, r1, r2;
    scanf("%lf%lf", &a, &b);
    scanf("%lf%lf", &c, &d);
    scanf("%lf", &r1);
    scanf("%lf", &r2);
    // double x = (d-b)/(c-a);
    // double y = atan(x);
    // printf("%lf, %lf\n", ((a+c+(r1-r2)*cos(y))/2), (b+d+(r1-r2)*sin(y))/2);
    printf("%lf\n", (d+r1+r2)/2);
    double D = sqrt(pow((a-c),2)+pow((b-d),2));
    double k = (r2-r1+D)/(r1-r2+D);
    printf("%lf %lf", (k*c+a)/(k+1), (k*d+b)/(k+1));

    return 0;
}