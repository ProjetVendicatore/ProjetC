#include "prototypes.h"

int read_level(char* level_number)
{
    int line = rand() % 6;
    FILE *fp;
    int c;
    int n = 0;
    char name [250] = "";
    strcat(name,"level/");
    strcat(name,level_number);
    strcat(name,".txt");

    fp = fopen(name,"r");
    if(fp == NULL)
    {
        perror("Error in opening file");
        return(-1);
    }
    while(!feof(fp))
    {
    c = fgetc(fp);
    printf("%c", c);

    switch(c)
        {   case 'a':create_ennemi(create_vector(0,350),1);
        break;
            case 'b':create_ennemi(create_vector(0,450),2);
        break;
        }
    };

    fclose(fp);
    return(0);
}
