#include <stdio.h>
int main()
{
    int d1, m1, y1, d2, m2, y2, week_day, y_diff;
    int days = 0;
    int ext_days = 0;
    scanf("%d/%d/%d", &d1,&m1,&y1);
    scanf("%d/%d/%d", &d2,&m2,&y2);
    // scanf("%d", &week_day);
    if (m1 == 11)
    {
        if ((y1%4 == 0) && (y1%100 != 0))
        {
            days += 30 - d1 + 30;
        }
        else if (y1%400 == 0)
        {
            days += 30 - d1 + 30;
        }
        else
        {
            days += 29 - d1 + 30;
        }
    }
    else
    {
        switch ((int) (m1 <= 6))
        {
        case 1:
            days += 31 - d1 + (6-m1)*31 + 5*30;
            if ((y1%4 == 0) && (y1%100 != 0))
            {
                days += 30;
            }
            else if (y1%400 == 0)
            {
                days += 30;
            }
            else
            {
                days += 29;
            }
            break;
        case 0:
            days += 30 - d1 + (12-m1)*30;
            if (m1 < 11)
            {
                if ((y1%4 == 0) && (y1%100 != 0))
                {
                }
                else if (y1%400 == 0)
                {
                }
                else
                {
                    days -= 1;
                }
            }
            break;
        default:
            break;
        }
    }
    
    if (m2 == 11)
    {
        if ((y2%4 == 0) && (y2%100 != 0))
        {
            ext_days += 30 - d2 + 30;
        }
        else if (y2%400 == 0)
        {
            ext_days += 30 - d2 + 30;
        }
        else
        {
            ext_days += 29 - d2 + 30;
        }
    }
    else
    {
        switch ((int) (m2 <= 6))
        {
        case 1:
            ext_days += 31 - d2 + (6-m2)*31 + 5*30;
            if ((y2%4 == 0) && (y2%100 != 0))
            {
                ext_days += 30;
            }
            else if (y2%400 == 0)
            {
                ext_days += 30;
            }
            else
            {
                ext_days += 29;
            }
            break;
        case 0:
            ext_days += 30 - d2 + (12-m2)*30;
            if (m2 < 11)
            {
                if ((y2%4 == 0) && (y2%100 != 0))
                {
                }
                else if (y2%400 == 0)
                {
                }
                else
                {
                    ext_days -= 1;
                }
            }
            break;
        default:
            break;
        }
    }
    
    y_diff = y2 - y1;
    int leap;
    // int leap = y2/4 - (y1)/4 - (y2)/100 + (y1)/100 + y2/400 -(y1)/400 ;
    if ((y1%4==0) & (y1%100 != 0))
    {
        leap = y2/4 - (y1-1)/4 - y2/100 + (y1-1)/100 + y2/400 -(y1-1)/400;
    }
    else if (y1%400 == 0)
    {
        leap = y2/4 - (y1-1)/4 - y2/100 + (y1-1)/100 + y2/400 -(y1-1)/400 ;
    }
    else
    {
        /* code */
    }
    
    // int leap = y_diff/4 - y_diff/100 + y_diff/400;
    // printf("%d\n", days + ext_days);
    // printf("%d\n", days - ext_days);
    days += ((y_diff - leap)*365 + leap*366);
    // if ((y1%4 != 0) && (y2 %4 != 0))
    // {
    //     printf("%d\n", days - ext_days);   
    // }
    // else
    // {
    //     printf("%d\n", days - ext_days + 1);   
    // }
    printf("%d\n", days - ext_days);   
    
    

    // int new_y = (days-leap*366)/365 + leap;
    // int left_days = days - leap*366 - (new_y-leap)*365;
    // int new_m = (12 - m1 + m2)%12;

    // printf("%d\n", new_m);
    return 0;
}