/* LEX program to take a string "abcd" and prints the following output
abcd
abc
ab
a
*/

%{
%}

%%
a|ab|abc|abcd printf("%s\n", yytext); REJECT
.|\n
%%
int yywrap()
{
return 1;
}
int main(int argc, char *argv[])
{
extern FILE *yyin;
yyin = fopen(argv[1],"r");
yylex();
return 0;
}