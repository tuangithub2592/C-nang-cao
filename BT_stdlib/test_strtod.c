#include <stdio.h>

double test_strtod(char* str, char** endptr)
{
    double val = 0;
    double f = 1;
    int i=0;
    while(*(str+i) == ' ') i++;
    while(*(str+i) >= '0' && *(str+i) <= '9'){
        val = val*10 + (*(str+i) - '0'); 
        i++;
    }
    if(*(str+i) == '.'){
        i++;
        while(*(str+i) >= '0' && *(str+i) <= '9'){
            f /= 10;
            val = val + (*(str+i) - '0')*f;
            i++;
        }
    }
    *endptr = (str+i);
    return val;
}

int main()
{
    char* s = "a123.4 tuan";
    char* s1 = "    123.4 atuan";
    char* ptr;
    char* ptr1;

    double test = test_strtod(s, &ptr);
    printf("Test1:\ngia tri: %lf\n", test);
    printf("chuoi: %s\n", ptr);

    double test1 = test_strtod(s1, &ptr1);
    printf("Test2\ngia tri: %lf\n", test1);
    printf("chuoi: %s\n", ptr1);

    return 0;
}