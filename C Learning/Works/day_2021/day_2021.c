#include <stdio.h>
int main()
{
    int d, m, days = 0;
    scanf("%d %d", &d, &m);
    switch (m)
    {
    case 1:
        days += 31-d;
        d = 0;
    case 2:
        days += 28 - d;
        d = 0;
    case 3:
        days += 31 -d;
        d = 0;
    case 4:
        days += 30-d;
        d = 0;
    case 5:
        days += 31 - d;
        d = 0;
    case 6:
        days += 30 -d;
        d = 0;
    case 7:
        days += 31-d;
        d = 0;
    case 8:
        days += 31 - d;
        d = 0;
    case 9:
        days += 30 -d;
        d = 0;
    case 10:
        days += 31-d;
        d = 0;
    case 11:
        days += 30 - d;
        d = 0;
    case 12:
        days += 31 -d;
        d = 0;
    default:
        break;
    }
    days = 365 - days;
    // printf("%d\n",days);
    switch (days%7)
    {
    case 0:
        printf("Thursday");
        break;
    case 1:
        printf("Friday");
        break;
    case 2:
        printf("Saturday");
        break;
    case 3:
        printf("Sunday");
        break;
    case 4:
        printf("Monday");
        break;
    case 5:
        printf("Tuesday");
        break;
    case 6:
        printf("Wednesday");
        break;
    default:
        break;
    }   
    return 0;
}