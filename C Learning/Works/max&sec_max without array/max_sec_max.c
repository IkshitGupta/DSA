#include <stdio.h>
int main()
{
    int n, input;
    scanf("%d", &n);
    int max = 0;
    int sec_max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (input > max)
        {
            sec_max = max;
            max = input;
        }
        if (input < max && input > sec_max)
        {
            sec_max = input;
        }
    }
    printf("%d\n", max);
    printf("%d\n", sec_max);   
    return 0;
}