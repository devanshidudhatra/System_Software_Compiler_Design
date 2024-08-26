/Example to count all instances of she and he, including the instance/

%{
int s=0;
%}

%%
she {s++;REJECT;}
he {s++;}
\n |
. ;
%%

int yywrap()
{
return 1;
}
int main(int argc, char *argv[])
{
extern FILE *yyin;
yyin=fopen(argv[1],"r");
yylex();
printf("No of occurence of he including in he in she = %d\n", s);
return 0;
}