#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    int i,j, address_int;
    char line[50], progname[10],staddr[10];
    fp = fopen("input.txt", "r");
    fscanf(fp, "%s", line);
    for (i = 2, j = 0; i < 8, j < 6; i++, j++)
        progname[j] = line[i];

    progname[j] = '\0';
    printf("name from obj. %s\n", progname);
    do
    {
        fscanf(fp, "%s", line);
        if (line[0] == 'T')
        {
            for (i = 2, j = 0; i < 8, j < 6; i++, j++)
                staddr[j] = line[i];
            staddr[j] = '\0';
            address_int = atoi(staddr);
            i = 12;
            while (line[i] != '$')
            {
                if (line[i] != '^')
                {
                    printf("00%x \t %c%c\n", address_int, line[i], line[i + 1]);
                    address_int++;
                    i = i + 2;
                }
                else
                    i++;
            }
        }
        else if (line[0] = 'E')
            break;
    } while (!feof(fp));

    fclose(fp);
}


/*
input.txt

H^00COPY^002000^000020
T^002000^12^002015^232012^502018^542019$
T^002015^06^000005^00000E$
E^002000

*/