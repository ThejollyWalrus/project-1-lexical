%{
#include "SymbolTable.c"
int chars = 0;
int words = 0;
int lines = 0;
int errors = 0;
int para = 0;
int brac = 0;
field* symTable;

%}

%%

iint|intt|innt {words++; errors++; printf("%6s : ERROR AT LINE: %i, CHAR: %i ... 'int' incorrect\n", yytext, lines, chars);}
;;|;;;|;;;; {chars++; errors++; printf("%6s : ERROR AT LINE: %i, CHAR: %i ... Too many: ';' \n", yytext, lines, chars);}



"("|")" {para++;chars++;printf("%6s : PARENTHESE\n", yytext);}
"{"|"}" {brac++;chars++;printf("%6s : BRACE\n", yytext);}
"="|"+"|"-"|"*"|"^"|"/" {chars++;printf("%6s : OPERATOR\n", yytext);}
">"|"<"|"=<"|"=>"|"=="|"<="|">=" {chars++;printf("%6s : BOOL OPERATOR\n", yytext);}
";" {chars++;printf("%6s : SEMI-COLON\n", yytext);}
":" {chars++;printf("%6s : COLON\n", yytext);}
test|write|main {words++; chars += strlen(yytext);printf("%6s : FUNCTION\n", yytext);}
int|return {words++; chars += strlen(yytext);printf("%6s : KEYWORD\n", yytext);}
Int|iNt|inT|INt|InT|INt|INT {words++; errors++; chars += strlen(yytext);printf("%6s : ERROR in line %i: At least one letter is capatilized incorrectly. Try int\n", yytext, lines);}
Test|tEst|teSt|tesT|TEst|TeSt|TesT|tESt|tEsT|teST|TESt|TeST|TEsT|tEST {words++; errors++; chars += strlen(yytext);printf("%6s : ERROR in line %i: At least one letter is capatilized incorrectly. Try test\n", yytext, lines);}
[a-zA-Z]+ {words++; chars += strlen(yytext);printf("%6s : IDENTIFIER\n",yytext);}
\n {chars++; lines++;}
. {chars++;}

%%

int main(int argc, char **argv)
{

initSymtable(symTable, 5);

display(symTable);

printf("Token    Type\n");
printf("_____________\n");


if(argc > 1){
          if(!(yyin = fopen(argv[1],"r"))){
             perror(argv[1]);
             return(1);
          }
        }
        yylex();
if (para % 2 != 0)
	printf(" Error : Missing/Extra Parenthese\n");
if (brac % 2 != 0)
	printf(" Error : Missing/Extra Brace\n");
printf("Lines: %8d\nWords: %8d\nChars: %8d\nErrors: %7d\n", lines,words, chars, errors);

}