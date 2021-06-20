//#include"fonction.h"
//fonctionpour compter le nobre d`occurence d`un not dans un text
int compte(char text[],char find[])
{
	int i,nb=0;
	//boucle qui parcour le texte
	for(i=0;i<strlen(text);i++)
	{
		if (text[i]==find[0])
		{
		    //appele de la fonction pour verifier si des expression suivants la premiere corespondes entre elle
			nb+=verif(text,find,i);

		}
	}
	return nb;
}


//fonction pour verifier si les expression suivant i concordents
int verif(char text[],char find[],int i)
{
	int k;
	// taille du mot rechercher
	int boum=strlen(find),re=0;
	for(k=0;k<strlen(find);k++)
	{
		if (text[i+k]==find[k])
		{
			re+=1;
		}
		else{
			re+=0;
		}
	}
	if (re==boum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
//fin de la fonction
}





//fontion pour comparer deux tableau afin de voir s`ils sont egaux
int compare_tableau()
{
	char tab[10];
	char x[10];
	scanf("%s",x);
	scanf("%s",tab);
	int i;
	for (i = 0; i < 10; ++i)
	{
		if (tab[i]!=x[i])
		{
			puts("elements diferents");
		}
	}
	return 1;
}


//fonction pour rechercher l`element qui differe dans deux tableau d`entier
int rechercher()
{
	char tab[10];
	char x[1];
	scanf("%s",x);
	scanf("%s",tab);
	int i;
	for ( i = 0; i < 10; ++i)
	{
		if (tab[i]==*x)
		{
			puts("element trouver");
		}
	}
	return 1;
}
