#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void passone(){

    int locctr, length, start;
    char label[10],opcode[10],operand[10],mnemonic[10],code[10];

    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","w");
    fp4 = fopen("intermediate.txt","w");
    fp5 = fopen("length.txt","w");


    printf("\nim here 1");


    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0){

        printf("\nim here at checking for start");

        start = atoi(operand);
        locctr = start;
        fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    else{
        locctr = 0;
    }



    while(strcmp(opcode,"END")!=0){

        fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

        printf("\nim here at inner while ");

        if(strcmp(label,"**")!=0){
            fprintf(fp3,"%s\t%d\n",label,locctr);
        }

        fscanf(fp2,"%s\t%s",code,mnemonic);

        while(strcmp(code,"END")!=0){
            if(strcmp(opcode,code)==0){
                locctr += 3;
                break;
            }
            fscanf(fp2,"%s\t%s",code,mnemonic);
        }

        if(strcmp(opcode,"BYTE")==0){
            locctr += 1;
        }
        else if(strcmp(opcode,"WORD")==0){
            locctr += 3;
        }
        else if(strcmp(opcode,"RESB")==0){
            locctr += atoi(operand);
        }
        else if(strcmp(opcode,"RESW")==0){
            locctr += atoi(operand) * 3;
        }
        
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    length = locctr - start;
    printf("length is %d",length);
    fprintf(fp5,"%d",length);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

}

void main(){
    passone();
}
