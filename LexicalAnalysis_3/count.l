%{
#include <stdio.h>

int char_count = 0;
int word_count = 0;
int line_count = 0;
%}

%%

[^ \t\n]          { char_count++; }    // Count each character
[ \t]+            { word_count++; }    // Count each word separator (space or tab)
\n                { line_count++; word_count++; } // Count each newline

%%

int yywrap(){
return 1;
}

int main()
{
    yylex();
    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);
    return 0;
}
