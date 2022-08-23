/*
Name: Debprasad Kundu
Roll No.: cs2102
Date:8th January, 2022
Programme Description: Takes an ASCII string as a command-line argument and expands the non-numeric characters 
that are preceded by a numeric character within it. An expansion of a character increases the occurrence of it 
by one.The preceding numeric character will denote the number of times it has to be expanded.Hence, not all the 
characters will necessarily get expanded.The numeric characters used for expanding the succeeding non-numeric 
characters disappear in the resulting string, while the rest of the numeric characters remain.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Print(char a[], int n){
    int i = 0, j, x;
    while (i < n){
        if (0 == isdigit(a[i]))
            printf("%c", a[i++]);
        else{
            while (0 != isdigit(a[i])){
                if ((0 != isdigit(a[i + 1])) || (n == (i + 1)))
                    printf("%c", a[i]);
                x = a[i] - 48;
                i++;
            }
            if (0 == isdigit(a[i])){
                for (j = 0; j <= x; j++)
                    printf("%c", a[i]);
                i++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int n;
    char *a;
    if (argc == 1)
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    if (argc >= 2){
        a = (char *)malloc(20);
        if (argc > 1)
            a = argv[1];
        n = strlen(a);
        Print(a, n);
    }
    return 0;
}