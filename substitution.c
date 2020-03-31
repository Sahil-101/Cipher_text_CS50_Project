#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char* argv[])
{
    if(argc<2)
    {
        printf("enter the key for getting ciphertext\n");
        return 1;
    }
    string str;
    int i,j,c,count=0;
    for(i=0; argv[1][i]!='\0'; i++)
    {
        count++;

    }
    if(count<26)
    {
        printf("Key must contain 26 letters count is %d", count);
        exit(1);
    }

    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            if(isalpha(argv[1][j]))
            {
                if(argv[1][i]==argv[1][j])
                {
                    printf("entered %c this char 2 times",argv[1][i]);
                    return 1;
                }
            }
            else
            {
                printf(" %c Invalid char in key\n",argv[1][j]);
                return 1;
            }
        }
    }
    str =get_string("plain text:");
    printf("ciphertext: ");
    for(i=0; i<argc-1; i++)
    {
        for(j=0; str[j]!='\0'; j++)
        {   if(isalpha(str[j]))
            {
                if(((int) str[j]) <= 90)
                {
                    c=((int) str[j]) - 65;
                    printf("%c",toupper(argv[1][c]));
                }
                if(((int) str[j])>90)
                {
                    c=((int) str[j])-97;
                    printf("%c",tolower(argv[1][c]));
                }
            }
            else
                {
                    printf("%c",str[j]);
                }
        }
        printf("\n");
    }
    return 0;
}