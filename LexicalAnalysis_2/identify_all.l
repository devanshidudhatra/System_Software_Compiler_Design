%{
#include <stdio.h>

int n = 0;  
int other_chars = 0;  

%}

%%

"int"|"float" {n++; printf("\t Keywords : %s\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {n++; printf("\t Identifiers : %s\n", yytext);}
"<="|"=="|"="|"++"|"--"|"*"|"+" {n++; printf("\t Operators : %s\n", yytext);}
[(){}|,;] {n++; printf("\t Separators : %s\n", yytext);}
[0-9]*"."[0-9]+ {n++; printf("\t Float : %s\n", yytext);}
[0-9]+ {n++; printf("\t Integers : %s\n", yytext);}
. {other_chars++; printf("\t Other : %s\n", yytext);}

%%

int yywrap() {
    return 1;
}

int main()
{
    yylex();
    printf("\nTotal No. of tokens = %d\n", n);
    printf("Total No. of other characters = %d\n", other_chars);
    return 0;
}
