#include <stdio.h>
#include <string.h>
void parser(char string[]);
int main(int argc, char const *argv[])
{
    // char string[] = "<h1> this is a heading </h1>";
    // parser(string);
    printf("Give html line\n");
    char stringf[] = "";
    gets(stringf);
    parser(stringf);
    return 0;
}
void parser(char string[]){
    char string2[] = " ";
    char *string3 = strstr(string, string2);
    

    // printf("%s\n", string);
    // printf("%s\n", string2);
    // printf("%s\n", string3);
    char *stringn = strrev(strstr(strrev(string3), string2));
    // printf("%s\n", stringn);
    // char string5 [] = stringn[1];
    // puts(string5);
    int i;
    for (i = 0; i < strlen(stringn); i++)
    {
        if (stringn[i] != string2[0])
        {
            break;
        }
    }
    
    char *string4 = strchr(stringn, stringn[i]);
    // puts(string4);
    // puts(stringn);
    // puts(strrev(string4));
    strrev(string4);
    int j;
    for (j = 0; j < strlen(string4); j++)
    {
        if (string4[j] != string2[0])
        {
            break;
        }
    }

    char *string5 = strchr(string4, string4[j]);
    strrev(string5);
    // for (int i = 0; i < (strlen(stringn) - 1); i++)
    // {
    //     string4[i] = stringn[i+1];

    // }
    // char stringz[strlen(string4) + 1];
    // strcpy(stringz, string4);
    

    // printf("%c\n", string3[4]);
    // char string5[2] = "<";
    // printf("%c", string5[0]);

    // for (int i = 0; i < strlen(string3); i++)
    // {
    //     // char c = string3[i];
    //     if (string3[i] == string5[0])
    //     {
    //         break;
    //     }
        
    //     string4[i] = string3[i];

    // }
    // printf("%s\n", string4);
    // printf("%s\n", stringz);
    // puts(string4);
    puts(string5);
    // puts(stringz);
    // printf("%d", strlen(string4));
    
}