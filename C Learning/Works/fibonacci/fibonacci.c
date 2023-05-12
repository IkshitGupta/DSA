#include <stdio.h>
int a, i, c;

int fibo(int a){

    if (a==1) 
    {
        return 0;
    }
    if (a==2)
    {
        return 1;
    }
    
    return (fibo(a-1) + fibo(a-2));
    
}

int fiboprint(int a){
            for (i = 1; i <= a; i++)
            {
                c = fibo(i);
                printf("%d\n", c);
             
            }
            
}


int main(int argc, char const *argv[])
{ 
    int a;

    printf("how many numbers in series\n");
    scanf("%d", &a);
    fiboprint(a);

    return 0;
}

// int a, i, b, c, d;
// int fiboitr(int a){
//     b = 0;
//     c = 1;
//     for (i = 1; i <= a; i++)
//     {
//         printf("%d\n", b);
//         d = c;
//         c = b + c;
//         b = d;

//         /*
//         or c = b + c
//         b = c - b 
//         */

//     }
    
// }
// int main(int argc, char const *argv[])
// {
//     printf("how many numbers in series\n");
//     scanf("%d", &a);
//     fiboitr(a);
    
//     return 0;
// }
