
//SymbolTable.c
#include <stdlib.h>
#include "SymbolTable.h"
#include "string.h"

//initalize symtable
void initSymtable(field* symtable, int size) { 
    symtable = (field*) calloc(size, sizeof(field));
} 
void destorySymtable(field* symtable){
    free(symtable);
}


field* allocate(int index, field* symtable){
    //make a new symtable bigger than the old 
    int symsize = sizeof(symtable)/sizeof(field);
    if (index >= symsize){
        // need to increase symtable size
        symtable = (field*) realloc(symtable, symsize*2);
    }
    symlength = 0;
    //symtable[index] = malloc(sizeof(field));
    return symtable;
}
/*
char* lookup(char* token, field* symtable){ 
    //check to see if token is in symtable
    for(int i = 0; i< sizeof(symtable)/sizeof(field); i++) {
        if(strcmp(token, symtable[i].name) == 0) {
            printf("Found %s in symtable\n", token);
            printf("scope is %s\n", symtable[i].scope);
            return token;
        }
        else {
            printf("token not found\n");
            return "tokenNotFound";
        }
    }
}
*/
void insert(char* token, int index, field* symtable){
    allocate(index, symtable);
    symtable[index].name = token;    
    printf("%s has been inserted into the symtable", token);
}

/*
void remove(char* token, field* symtable){
    int symsize = sizeof(symtable)/sizeof(field*);
    for(int i = 0; i< symsize; i++){
        if(strcmp(token, symtable[i].name) == 0){
            printf("%s has been deleted from the symtable", token);
            // symtable[i] = ; 
        }
        else{
            printf("token not found");
        }
    }
}

void update(char* token, char* value, field* symtable){
    int symsize = sizeof(symtable)/sizeof(field*);
    for(int i = 0; i< symsize; i++){
        if(token == symtable[i].name){
            symtable[i].value = value;
            printf("the value of token %s was updated to %s",token,value);
        }
        else{
            printf("token not found");
        }
    }
    printf("%s has been updated to %s in the voidble", token, value);
}
*/
void display(field* symtable){
    int symsize= sizeof(symtable)/sizeof(field);
    //printf("%10s|%10s|%10s|%10s|%10s|%10s\n", "NAME", "KIND", "TYPE", "VALUE", "PARAMETERS", "SCOPE");
    for (int i =0;i<symsize; i++){
        printf("%10s|%10i|%10i|%10s|%10i|%10i\n", 
                symtable[i].name, symtable[i].kind, 
                symtable[i].type, symtable[i].value, 
                symtable[i].parameters, symtable[i].scope);
    }
}


