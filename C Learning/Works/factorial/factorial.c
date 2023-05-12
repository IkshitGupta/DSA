#include <stdio.h>
int fact(int num){
    if (num == 0)
    {
        return 1;
    }
    
    return (num * fact(num-1));
}

int main(int argc, char const *argv[]){
    int c, num;
    printf("Type Number!\n");
    scanf("%d", &num);
    c = fact(num);
    printf("%d",c);
    
    return 0;
}
