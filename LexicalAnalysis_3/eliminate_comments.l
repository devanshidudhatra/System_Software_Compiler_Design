%{
#include<stdio.h>
FILE *file;
FILE *comments;
%}

%%
"/*"(.|\n)*?"*/"   { fprintf(comments, "%s", yytext); }  // Capture multi-line comments, non-greedy matching
"//".*             {fprintf(comments, "%s", yytext);}  // Capture single-line comments
[^/]+              { fprintf(file, "%s", yytext); }      // Capture non-comment text
.|\n               { fprintf(file, "%s", yytext); }      // Capture any other characters including newlines
%%

int yywrap() {
    return 1;
}

int main() {
    file = fopen("input.c", "w");
    comments = fopen("comment.txt", "w");
    yylex();
    fclose(file);
    fclose(comments);
    return 0;
}

