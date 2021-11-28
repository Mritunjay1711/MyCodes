#include<stdio.h>
#include<string.h> 

char *reverse(char *str);

int main(){
    char str[]="Akshat";
    printf("The reversed string is: %s", reverse(str));
    return 0;
}

char *reverse(char *str){
    static char result[20];
    int length=strlen(str);
    int i=0;
    while(i<length){
        result[i]=str[length-i-1];
        i++;
    }
    return result;
}