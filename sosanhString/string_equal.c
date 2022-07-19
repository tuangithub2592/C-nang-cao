#include <stdio.h>

int stringEqual(char s1[], char s2[])
{
    int len_s1 = 0, len_s2 = 0;

    while (s1[len_s1] != '\0')
        len_s1++;
    while (s2[len_s2] != '\0')
        len_s2++;

    if(len_s1 != len_s2)
        return 0;
    else{
        for(int i = 0; i < len_s1; i++){
            if(s1[i] != s2[i])
                return 0;
        }
        return 1;
    }
}

int main()
{
    char str1[] = "tuanviet";
    char str2[] = "tuanviet123";
    char str3[] = "tuanviet";

    if(stringEqual(str1, str3))
        printf("2 chuoi giong nhau\n");
    else 
        printf("2 chuoi khac nhau\n");
    
    return 0;
}