#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *strre(char *str)
{
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int b;
int main(void)
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &b);
        while (true)
        {
            b++;
            char str[1000002];
            char str2[1000002];
            sprintf(str, "%d", b);
            strcpy(str2, str);
            strre(str2);
            if (strcmp(str, str2) == 0)
            {
                printf("%d\n", b);
                break;
            }
        }
    }          
    return 0;
}