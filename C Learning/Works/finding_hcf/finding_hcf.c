#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a>=b)
    {
        int c = b;
        while (c<=b)
        {
            if ((a%c == 0) && (b%c == 0))
            {
                break;
            }
            --c;
        }
        printf("%d\n", c);
    }
    else    // iske jagah ek hi while banate aur if me a ko b se replace kar dete
    {
        int c = a;
        while (c<=a)
        {
            if ((a%c == 0) && (b%c == 0))
            {
                break;
            }
            --c;
        }
        printf("%d\n", c);
    }
    return 0;
}