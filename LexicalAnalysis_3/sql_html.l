%{
#include <stdio.h>
%}

%%

"<".*">"       { printf("HTML tag found: %s", yytext); }
"SELECT"|"FROM"|"WHERE"|"INSERT"|"UPDATE"|"DELETE"|"CREATE"|"DROP"|"ALTER"|"JOIN"|"UNION" { printf("SQL tag found: %s\n", yytext); }
                 
%%

int yywrap()
{
return 1;
}

int main(int argc, char **argv)
{
    yylex();
    return 0;
}
