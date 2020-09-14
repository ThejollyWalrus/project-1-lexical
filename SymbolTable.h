//SymbolTable.h
#include <stdlib.h>
// fields structure
typedef struct fields{
    char* name;
    int   kind;
    int   type;
    char* value;
    int   parameters; 
    int   scope;
} field;

int symlength;

// symbol table functions 

void initSymtable(field* symtable, int size);
field* allocate(int index, field* symtable);
// char* 	lookup(char* token, field* symtable);
void insert( char* token, int index, field* symtable);
// void delete(char* token, int* symtable);
// void update(char* token, char* value, field* symtable);
 void display(field* symtable);

void destorySymtable(field* symtable);
