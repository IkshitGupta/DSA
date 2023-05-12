#include <stdio.h>
#include <string.h>
int countDigit(long long n){
    static int count;
    if (n == 0) return 1;
    count ++;
    n/=10;
    countDigit(n);
    return count;
}
int sumDigits(long long n){
    static int sum;
    if (n == 0) return 0;
    sum += n%10;
    n /= 10;
    sumDigits(n);
    return sum;
}
int reverseStr(char arr[], int n){
    static int p;
    if (n - p == 0)  return 0;
    char temp;
    temp = arr[p];
    arr[p] = arr[n];
    arr[n] = temp;
    if (n - p == 1) return 0;
    ++p;
    reverseStr(arr, n - 1);
    return 0;
} 
int main()
{
    // printf("%d", countDigit(3473830789));
    // printf("%d", sumDigits(3473830789));
    // char str[] = "haohi";
    // reverseStr(str, strlen(str) - 1);
    // printf("%s", str);
    return 0;
}