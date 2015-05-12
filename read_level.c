#include "prototypes.h"

int read_level(char* level_number)
{
   FILE *fp;
   int c;
   int n = 0;
   char name [250] = "";
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
        {   case 'a': create_ennemi(20,create_position(200,200),type_2);
        break;
            case 'b':



        }
   };

   fclose(fp);
   return(0);
}
