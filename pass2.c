#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *f1,*f2,*f3,*f4,*f5;

    char opcode[10],label[10],operand[10],code[10],mnemonic[10]; 
    char optab_label[10],optab_value[10];
    char symtab_label[10],symtab_value[10];

    char start[10];

    int loc,length;

    f1 = fopen("input.txt","r");
    f2 = fopen("optab.txt","r");
    f3 = fopen("symtab.txt","r");
    f4 = fopen("length.txt","r");
    f5 = fopen("output.txt","w");

    fscanf(f1,"%S\t%s\t%s\t%s",loc,label,opcode,operand);
    printf(f5,"%S\t%s\t%s\t%s",loc,label,opcode,operand);

    fscanf(f4,"%s",length);

    if(strcmp(opcode,"START")==0){
        strcpy(start,operand);
        printf("H^%s^%s^%s\nT^%s",label,start,length,start);
    }
    fscanf(f1,"%S\t%s\t%s\t%s",loc,label,opcode,operand);
    while(strcmp(opcode,"END")!=0){

        fscanf(f2,"%s\t%s",optab_label,optab_value);
        while(!feof(f2)){
            
            if(strcmp(opcode,optab_label)==0){
                fscanf(f3,"%s\t%s",symtab_label,symtab_value);
                  while(!feof(f3)){
                    if(strcmp(label,symtab_label)==0){


                        break;
                    }
                    else{
                        fscanf(f3,"%s\t%s",symtab_label,symtab_value);
                    }
                }
            }
            else{
                fscanf(f2,"%s\t%s",optab_label,optab_value);
            }

            
        }
        if(strcmp(opcode,"BYTE") == 0 || strcmp(opcode,"WORD") == 0 ){
            if(strcmp(opcode,"BYTE")==0){

            }
            else{
                printf("%s",operand);
            }
    }
    fscanf(f1,"%S\t%s\t%s\t%s",loc,label,opcode,operand);

    }
    printf("E^%s",start);
    
}