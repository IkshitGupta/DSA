/*
0
*
**
***
****
1
****
***
**
*
*/

#include <stdio.h>
int a, b, i, j;
int main(int argc, char const *argv[])
{
    printf("Type 0 or 1\n");
    scanf("%d", &a);
    printf("How many rows?\n");
    scanf("%d", &b);

    
    if (a == 0)
    {
        for (i = 1; i <= b; i++)
        {
            for (j = 0; j < i; j++)
            {
                // printf("*");
                printf("%c", '*');
            }
            printf("\n");
        }
        
    }

    else if (a == 1)
    {
        for (i = b; i >= 1; i--)
        {
            for (j = 0; j < i; j++)
            {
                // printf("*");
                printf("%c", '*');
            }
            printf("\n");
        }
      

    }

    return 0;
}