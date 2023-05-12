#include <stdio.h>
int findmax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
void printArr(int a[100][100], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int entry;
            scanf("%d", &entry);
            a[i][j] = entry;
        }
    }
    // triangular for n = m
    // int flag = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (a[i][j] != 0) {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 1){
    //         printf("NO");
    //         break;
    //     }
    // }
    // if (flag == 0) printf("YES");

        int max = findmax(n, m);
    int temp;
    for (int i = 0; i < max - 1; i++)
    {
        for (int j = i + 1; j < max; j++)
        {
            int c = a[i][j], d = a[j][i];
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    temp = n;
    n = m;
    m = temp;
    printArr(a, n, m);
    return 0;
}