// Write a program to create a file, 
// read its content code will be written in it, 
// count the number of tokens in the program. 
// run the code, get the output, show it and store it in file and close file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MMAX = -INT_MAX
#define MAX = INT_MAX

int main(){
    FILE* ptr;
    FILE* fptr;
    char ch;
    char str[100];
    int tokens=0;
    char *keywords[] = {"int", "float", "char", "string", "bool", "printf", "scanf", "const", "return"};
    char *special_chars[] = {"(", ")", "{", "}", "[", "]", ";", ","};
    ptr = fopen("code.txt", "r");

    while (fscanf(ptr, "%s", str) != EOF) {
        printf("%s\n", str);

        // Check if the token is a keyword
        for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
            if (strcmp(str, keywords[i]) == 0) {
                tokens++;
                break;
            }
        }

        // Check if the token is a special character
        for (int i = 0; i < sizeof(special_chars) / sizeof(special_chars[0]); i++) {
            if (strcmp(str, special_chars[i]) == 0) {
                tokens++;
                break;
            }
        }

        // Check if the token is a valid identifier (variable name)
        if (isalpha(str[0]) || str[0] == '_') {
            int is_valid = 1;
            for (int i = 1; str[i] != '\0'; i++) {
                if (!isalnum(str[i]) && str[i] != '_') {
                    is_valid = 0;
                    break;
                }
            }
            if (is_valid) {
                tokens++;
            }
        }

        // Check if the token is a number
        int is_number = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isdigit(str[i])) {
                is_number = 0;
                break;
            }
        }
        if (is_number) {
            tokens++;
        }
    }   

    printf("No of tokens are : %d " , tokens);
    fclose(ptr);

    fptr = fopen("output.txt", "w");
    fprintf(fptr , "No of tokens : %d" , tokens);
    fclose(fptr);
    return 0;
}