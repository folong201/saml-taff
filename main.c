// FOLONG EMERSON 20U2998
#include <stdio.h>
#include <stdlib.h>
#include"pile.h"
#include"fonction.h"


int main()
		{
		    char i;
		    char x[50];
		    pile *tete=NULL;
		    tete=(pile*)malloc(sizeof(pile));

		    scanf("%s",&x);
		    for(i=0; i<50;i++)
		    {
		        if(x[i]=='[' || x[i]=='{' || x[i]=='(')
		            {
		                enpiler(tete,x[i]);
		            }
		        if(x[i]==']' || x[i]=='}' || x[i]==')')
		            {
		                depiler(tete);
		            }
		    }
		    //fre(tete);
		   // printf("pour l`expression %s \t ",x);
		   if(verification(tete)==2)
		   {
		   	puts("expression correct");
		   }
		   else
		   puts("expression incorrect");
		    return 0;
	}
