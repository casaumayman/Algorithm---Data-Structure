#include <stdio.h>
#include <string.h>
int main(){
    char number[203];
    gets(number);
    int sum = 0;
    for (int i=1 ; i < strlen(number); i++) sum += number[i] - '0';
    if (number[0] != '-') sum += number[0] - '0';
    printf("%d", sum);
    return 0;
}
