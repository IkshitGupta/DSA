#include <stdio.h>
#include <math.h>
int x1, x2, y3, y2;
float dis(int x1, int y3, int x2, int y2){
    // printf("in dis\n");
    return sqrt(pow(x2-x1, 2)+pow(y2-y3, 2));
}
float area (float (*ptr)(int, int, int, int)) {
    // printf("in area\n");
    return 3.14*pow(ptr(x1, y3, x2, y2), 2);
}
int main()
{
    // int x1, x2, y3, y2;
    scanf("%d", &x1);
    scanf("%d", &y3);
    scanf("%d", &x2);
    scanf("%d", &y2);
    float (*ptr) (int, int, int, int);
    ptr = &dis;
    printf("%f\n", area(dis));
    return 0;
}