#include <stdio.h>
#include <string.h>
int isPalin(const char *p, int x)
{
    int y = x / 2;
    while (y != 0)
    {
        if (*(p + strlen(p) - x) != *(p + x - 1))
            return 0;
        --y;
        --x;
    }
    return 1;
}
int main()
{
    char a[] = "lplpl";
    int ans = 0;
    int l = 1;
    for (int i = 0; i < strlen(a); i++)
    {
        char p[strlen(a) + 1];
        int index = 0;
        p[index] = a[i];
        index++;
        for (int j = i + 1; j < strlen(a); j++)
        {
            p[index] = a[j];
            p[index + 1] = '\0';
            index++;
            if (strlen(p) > l)
            {
                if (isPalin(p, strlen(p)))
                {
                    l = strlen(p);
                    ans = i;
                }
            }
        }
    }
    printf("%d\n", ans);
    printf("%d", l);

    return 0;
}