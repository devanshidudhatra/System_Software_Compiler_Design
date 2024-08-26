%{
int lineno=1;
%}

line .*\n
%%
{line} {printf("%5d   %s" , lineno++ , yytext);}
%%

int yywrap() {
    return 1;
}

int main()
{
yylex();
return 0;
}