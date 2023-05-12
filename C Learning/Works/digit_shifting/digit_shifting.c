// to shift digits in a given number

// METHOD 1

#include <stdio.h>
int main(void) 
{
    int a;
    scanf("%d", &a);

    int ones = a%10;         // OR
    int tens =(a%100)/10;      //  (a/10)%10
    int hundreds = (a%1000)/100;    // (a/100)%10
    int thousands = a/1000;      // (a/1000)%10 continues aur end me 0;        // while (n != 0) {  // sum of digits
                                                                                // sum = sum + (n % 10);
                                                                                // n = n / 10;

    printf("%d%d%d%d\n", ones, thousands, hundreds, tens);
    printf("%d%d%d%d\n", tens, ones, thousands, hundreds);
    printf("%d%d%d%d\n", hundreds, tens, ones, thousands);
    printf("%d%d%d%d", thousands ,hundreds, tens, ones);

    return 0;
}

// METHOD 2

// #include <stdio.h>
// int main(void)
// {
//     char a[5];
//     int temp;
//     scanf("%s", &a);
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             temp = a[j+1];
//             a[j+1] = a[0];
//             a[0] = temp;
//         }
            
//         for (int k = 0; k < 4; k++)
//         {
//             printf("%c", a[k]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// METHOD 3

// #include <stdio.h>
// int main(void)
// {
//     char inp[5];
//     int a = 7, b = 3;
//     scanf("%s", &inp);
//     char xyz[9];

//     for (int j = 0; j < 4; j++)
//     {
//         xyz[4+j] = inp[j];
//     }
    
//     for (int i = 0; i < 4; i++)
//     {
//         xyz[b] = xyz[a];
//         --a;
//         for (int k = b; k <= a; k++)
//         {
//             printf("%c", xyz[k]);
//         }
//         --b;
//         printf("\n");    
//     }
    
//     return 0;
// }