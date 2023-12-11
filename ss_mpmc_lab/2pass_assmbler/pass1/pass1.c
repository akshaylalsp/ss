#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    char opcode[10], operand[10], label[10], code[10], mnemonic[10];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtbl.txt", "w");
    fp4 = fopen("out.txt", "w");
    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }
    while (strcmp(opcode, "END") != 0)
    {
        fprintf(fp4, "%d\t", locctr);
        if (strcmp(label, "**") != 0)
        {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }
        fscanf(fp2, "%s\t%s", code, mnemonic);
        while (strcmp(code, "END") != 0)
        {
            if (strcmp(opcode, code) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }
        if (strcmp(opcode, "WORD") == 0)
        {
            locctr += 3;
        }
        else if (strcmp(opcode, "RESW") == 0)
        {
            locctr += (3 * (atoi(operand)));
        }
        else if (strcmp(opcode, "RESB") == 0)
        {
            locctr += (atoi(operand));
        }
        else if (strcmp(opcode, "BYTE") == 0)
        {
            ++locctr;
        }
        fprintf(fp4, "%s\t%s\t%s\t\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    length = locctr - start;
    printf("The length of the code : %d\n", length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}

/*
INPUT.TXT
** START 2000
** LDA FIVE
** STA ALPHA
** LDCH CHARZ
** STCH C1
ALPHA RESW 2
FIVE WORD 5
CHARZ BYTE C'Z'
C1 RESB 1
** END **


OPTAB.TXT
START *
LDA 03
STA 0f
LDCH 53
STCH 57
END *


OUT.TXT
** START 2000
2000 ** LDA FIVE
2003 ** STA ALPHA
2006 ** LDCH CHARZ
2009 ** STCH C1
2012 ALPHA RESW 2
2018 FIVE WORD 5
2021 CHARZ BYTE C'Z'
2022 C1 RESB 1
2023 ** END **


SYMTAB.TXT
ALPHA 2012
FIVE 2018
CHARZ 2021
C1 2022

*/