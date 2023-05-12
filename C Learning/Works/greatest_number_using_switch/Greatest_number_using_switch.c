#include <stdio.h>
int n1 = 10;
int n2 = 5;
int main(int argc, char const *argv[])
{

    // greatest number

    switch ((int)(n1 > n2))
    {
    case 0:
        printf("%d is the largest\n", n2);
        break;
    
    default:
        printf("%d is the largest\n", n1);
        break;
    }

    return 0;

}
