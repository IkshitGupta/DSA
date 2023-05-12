#include <stdio.h>
int main()
{
    int mid = 4;
    int count = 0;
    int ini = 5;
    int a =0;
    for (int i = 0; i < ini && i >=0;)
    {
        for (int j = 0; j < 2*mid + 1; j++)
        {
            printf("%d ", count);
            if (count < i && j < mid)
            {
                count += 1;
            }
            if (j>= 2*mid+1-i-1 && count != 0)
            {
                count -= 1;
            }   
        }
        printf("\n");
        if (a == 0)
        {
            i += 1;
        }   
        if (i == mid+1)
        {
            ini = 4;
            i = 4;
            a = 1;
        }
        if (a == 1)
        {
            i -= 1;
        }
    }
    return 0;
}