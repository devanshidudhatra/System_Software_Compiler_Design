%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}
%}

%%

[a-zA-Z0-9]+ {
    
    if (is_palindrome(yytext)) {
        printf("Palindrome: %s\n", yytext);
    } else {
        printf("Not a palindrome: %s\n", yytext);
    }
}

[ \t\n]+    ;  // Ignore whitespace

.           ;  // Ignore any other character

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
