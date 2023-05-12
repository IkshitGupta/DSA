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
int main()
{
    int a;
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        int b;
        scanf("%d", &b);
        arr[i] = b;
    }
    // char str1[] = "ha";
    // char str2[] = "ha";
    // if (strcmp(str1, str2) == 0)
    // {
    //     printf("success");
    // }
    

    for (int j = 0; j < (sizeof(arr))/sizeof(int) ; j++)
    {
        // bool c = true;
        while (true)
        {
            arr[j]++;
            // printf("%d\n", arr[j]);
            // if (arr[j] <= 10)
            // {
            //     printf("11\n");
            //     break;
            // }
            char str[20];
            char str2[20];
            sprintf(str, "%d", arr[j]);
            strcpy(str2, str);
            strre(str2);
            // printf("%s\n", str);
            // printf("%s\n", str2);
            
            // printf("%s\n", str);
            // char *str2 = strrev(str);
            // strrev(str);
            // printf("%s\n",str2);
            // strrev(str);
            // printf("%s\n", str);
            if (strcmp(str, str2) == 0)
            {
                printf("%d\n", arr[j]);
                break;
            }

        }
        
    }
       
    return 0;
}