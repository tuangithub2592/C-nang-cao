#include <stdio.h>

char *del(char *str, const char *delim)
{
    static int len = 0;
    while(*(str+len) != '\0'){
        len++;
    }

    for(int i=0; i<len; i++){
        for(int j=0; *(delim+j) != '\0';j++){
            if(*(str+i) == *(delim+j)){
                *(str+i) = *(delim);
                break;
            }
        }
    }

    for(int i=0; i<len; i++){
        while(*(str+i) == *(delim) && *(str+i+1) == *(delim)){
            for(int j=i; j<len; j++){
                *(str+j) = *(str+j+1);
            }
            len--;
        }
    }
    *(str+len) = *delim;

    return str;
}

char *test_strtok(char *str, const char *delim)
{
    static char *token;
    int lens = 0;
    if(str != NULL){
        str = del(str, delim);
        token = str;
    }
    while(*(token+lens) != '\0'){
        lens++;
    }
    for(int i = 0;;i++){
        if(*(token+i+1) == '\0' && i == lens){
            return 0;
        }
        char *newStr;
        for(int j = 0;;j++){
            if(*(delim+j) == '\0'){
                break;
            }
            if(*(token+i) == *(delim+j) || *(token+i) == '\0'){
                newStr = token;
                *(token+i) = '\0';
                token = token+i+1;
                return newStr;
            }
        }
    }
}

int main()
{
    char str[] = "nguyen////////     viet/tuan-    lop,12a2.......abcd";
    const char c[] = ",-/. ";

    char *token = test_strtok(str, c);

    while(token != NULL){
        printf("%s\n", token);
        token = test_strtok(NULL, c);
    }
    return 0;
}