%{
#include <stdio.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* { printf("Token: %s, Length: %d\n", yytext, yyleng); }
[0-9]+                { printf("Token: %s, Length: %d\n", yytext, yyleng); }
[ \t\n]+              { /* Ignore whitespace */ }
.                     { printf("Token: %s, Length: %d\n", yytext, yyleng); }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
