#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>

//declaration des fontions
void ajouter(char cle[], char signification[]);


typedef struct dictionnaire
{
	char cle[10];
	char valeur;
	struct dictionnaire *suivant;	
}dictionnaire;

//fontion de recherche dans un fichier
void rechercher(char find[])
{
	FILE *fich=NULL;
	char cle[15],signification[200];
	fich=fopen("dictionnaire.txt" ,"r");
	if (fich==NULL)
	{
		puts("echec d`ouverture");
	}

	else
	{
		while(fscanf(fich,"%s%s",&cle,&signification)!=EOF){// && *cle!=*find
			if (*cle==*find)
			{
				printf("%s\n",signification );
			}
		}
		if (*cle!=*find)
		{
			fclose(fich);
			printf("mot non trouver\n");
			puts("entrer la signification du mot");
			scanf("%s",signification);
			
			
			ajouter(find,signification);
		}
	}
	fclose(fich);
}
//fontion pour traduire le mots en une autre langue
void traduire(char mot[20])
{
	FILE*fich=NULL;
	char cle[20],traduction[30];
		fich=fopen("traduit.txt","r+");
		if (fich==NULL)
	{
		puts("echec d`ouverture");
	}

	else
	{
		while(fscanf(fich,"%s %s",cle,traduction)!=EOF){
			if (*cle==*mot)
			{
				printf("%s %s\n",cle,traduction );
			}
		}
		if (*cle!=*mot)
		{
			puts("le mot n`est pas dans le dictionnaire");
			puts("Veuillez entrer la traduction");
			scanf("%s",&traduction);
			fprintf(fich,"%s %s\n",mot,traduction);
	
			printf("mot ajouter dans le dictionnaire avec succees");

		}
	}
	fclose(fich);
}





int main(int argc, char const *argv[])
{
	int x;
	char cle[25],signification[200],mot[20],nada[10];
	dictionnaire pointeur;//=(dictionnaire*)malloc(sizeof(struct dictionnaire));
	puts("action");
	puts("Choisiser ce que vous vouler faire");
	puts("1-significations");
	puts("2-traduction");
	//petit essai de hachage
		/*scanf("%s",&nada);
		int inter=(int)*nada;
		printf("%d\n",inter );
		float second=(float)*nada;
		printf("%f",second);*/
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			puts("Entrer le mot a rechercher");
		scanf("%s",&cle);
		 rechercher(cle);
			break;
		case 2: 
		puts("Entrer le mot a traduire");
		scanf("%s",mot);
		traduire(mot);
			break;
		default:puts("erreur");
	}
	return 0;
}








void ajouter(char cle[], char signification[])
{
	FILE *fich=NULL;
	//char cle[15],signification[200];
	fich=fopen("dictionnaire.txt","a+");
	if (fich==NULL)
	{
		puts("echec d`ouverture du dictionnaire");
	}

	else
	{
		fprintf(fich,"%s %s\n",cle,signification);
	}
		printf("mot ajouter dans le dictionnaire avec succees");
	fclose(fich);
} 



void suprimer(char mot[])
{
	FILE *un=NULL;
	FILE *deux=NULL;
	char signification[200],cle[20];
	un=fopen("dictionnaire.txt","r+");
	deux=fopen("tmp.txt","w+");
	while(fscanf(un,"%s%s",cle,signification)!=EOF)
	{
		if (*cle!=*mot)
		{
			fprintf(deux,"%s %s\n",*cle,*signification);
		}
	}
	fclose(un);
	fclose(deux);
	remove("dictionnaire.txt");
	rename("tmp.txt","dictionnaire.txt");
}