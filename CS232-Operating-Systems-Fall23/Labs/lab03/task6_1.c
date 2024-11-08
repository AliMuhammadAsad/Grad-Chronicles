#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int my_strlen(char str[]){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

void my_strcpy(char s1[], char s2[]){
    int count = 0;
    while(s1[count] != '\0'){
        s2[count] = s1[count];
        count++;
    }
    s2[count] = '\0';
}

int my_strcmp(char s1[], char s2[]){
    int count = 0;
    while(s1[count] != '\0' || s2[count] != '\0'){
        if(s1[count] < s2[count]){
            return -1;
        }
        else if(s1[count] > s2[count]){
            return 1;
        }
        count++;
    }
    return 0;
}

int main(int argc, char* argv[]){
    char s1[6] = "Hello"; char s2[6] = "Hello";

    printf("------------------- Lengths of strings using my own strlen function -------------------\n");
    printf("First String = %s, Length of First String = %d \n", s1, my_strlen(s1)); printf("Second String = %s, Length of Second String = %d \n\n", s2, my_strlen(s2)); 
    
    printf("------------------- String comparison using my own strcmp function -------------------\n");
    printf("Comparing S1 and S2 with mystrcmp = %d \n", my_strcmp(s1, s2)); printf("Comparing using builtin strcmp = %d \n\n", strcmp(s1, s2));

    printf("------------------- String copy using my own strcpy function -------------------\n");
    char s3[20] = "BLAH BLAH BLAHHH"; char s4[20];
    my_strcpy(s3, s4);
    printf("String3 = %s, String4 (copied) = %s \n", s3, s4);

    return 0;
}