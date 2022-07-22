#include <stdio.h>

double test_strtof(char *str, char **endptr)
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
    char* arr = "365.25 7.0";
    char* pend, *pend2;

    float f1 = test_strtof(arr, &pend);
    printf ("f1: %f\n", f1);

    float f2 = test_strtof(pend, &pend2);
    printf("f2: %f\n", f2);

    return 0;
}