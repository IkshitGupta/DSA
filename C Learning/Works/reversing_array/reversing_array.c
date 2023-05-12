// without pointer
// #include <stdio.h>
// void arrrev(int arr[]);
// int main(int argc, char const *argv[])
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     printf("Before reversing -: ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     printf("After reversing -: ");
//     arrrev(arr);
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// void arrrev(int arr[]){
//     for (int i = 0; i < 2; i++)
//     {
//         int c = arr[i];
//         arr[i] = arr[4-i];
//         arr[4-i] = c;
//     }
// }

#include <stdio.h>
void arrrev(int *ptr, int size);
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("Before reversing -: ");
    for (int i = 0; i < (sizeof(arr) / 4); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("After reversing -: ");
    arrrev(arr, sizeof(arr));
    for (int i = 0; i < (sizeof(arr) / 4); i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
// do not use size of inside array
void arrrev(int *ptr, int size)
{
    for (int i = 0; i < size / 8; i++)
    {
        int c = *(ptr + i);
        *(ptr + i) = *(ptr + 4 - i);
        *(ptr + 4 - i) = c;
    }
}