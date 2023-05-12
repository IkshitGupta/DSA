// #include <stdio.h>
// int main()
// {
//     int r1, r2, c1, c2;
//     int m1[100], m2[100], m3[100];
//     printf("Rows in 1\n");
//     scanf("%d", &r1);
//     printf("Columns in 1\n");
//     scanf("%d", &c1);
//     printf("Rows in 2\n");
//     scanf("%d", &r2);
//     printf("Column in 2\n");
//     scanf("%d", &c2);

//     if (c1 != r2)
//     {
//         printf("Na wohi\n");
//     }
//     else
//     {
//         int k = 0;
//         printf("For Matrix 1\n");
//         for (int i = 0; i < r1; i++)
//         {
//             for (int j = 0; j < c1; j++)
//             {
//                 printf("Entry no. %d in row %d\n", j + 1, i + 1 );
//                 scanf("%d", &m1[k]);
//                 ++k;
//             }
//         }
//         k = 0;
//         printf("For Matrix 2\n");
//         for (int i = 0; i < r2; i++)
//         {
//             for (int j = 0; j < c2; j++)
//             {
//                 printf("Entry no. %d in row %d\n", j + 1, i + 1 );
//                 scanf("%d", &m2[k]);
//                 ++k;
//             }
//         }
//         int e = 0;
//         int g = 0;
//         for (int i = 0; i < r1*c1; i+=c1)
//         {
//             for (int j = 0; j < c2; j++)
//             {
//                 for (int k = 0; k < c1; k++)
//                 {
//                     g += m1[k+i]*m2[j+c2*k];
//                 }
//                 m3[e] = g;
//                 g = 0;
//                 ++e;
//             }
//         }
//         k = 0;
//         for (int i = 0; i < r1; i++)
//         {
//             do{
//                 printf("%d ", m3[k]);
//                 ++k;
//             }while(k%c2 != 0);
//             printf("\n");   
//         }   
//     }   
//     return 0;
// }

#include <stdio.h>
void getArr(int a[100][100], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
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
    int a[100][100];
    int b[100][100];
    int g[100][100];
    int m, n, o, p;
    scanf("%d%d%d%d", &m, &n, &o, &p);
    getArr(a, m, n);
    getArr(b, o, p);
    if (n!=o) return 0;
    int val = 0;
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < p; k++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += a[i][j] * b[j][k];
            }
            g[val][k] = sum;
        }
        val++;   
    }
    printArr(g, m, p);   
    return 0;
}