#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Voyageur {
    char nom[50];
    char prenom[50];
    char email[100];
    struct Voyageur* suivant;
} Voyageur;
char ch[10][130]={"Aval voyages","Thapsus voyages","sky travel voyages","Liberta voyages","Safar voyages","Tunisian sky voyages"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();
void name_number(int booking,char numstr[100]);
void reserver();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void annuler();
Voyageur* creerCompteVoyageur() {
    Voyageur* nouveauVoyageur = (Voyageur*)malloc(sizeof(Voyageur));
    if (nouveauVoyageur == NULL) {
        printf("Erreur : Impossible d'allouer la mémoire pour le nouveau voyageur\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez votre nom : ");
    scanf("%s", nouveauVoyageur->nom);

    printf("Entrez votre prénom : ");
    scanf("%s", nouveauVoyageur->prenom);

    printf("Entrez votre e-mail : ");
    scanf("%s", nouveauVoyageur->email);

    nouveauVoyageur->suivant = NULL;

    return nouveauVoyageur;
}
int main()
{
	
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
   printf("====================================== BIENVENUE AU SYSTEME DE RESERVATION DE BUS ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Afficher la liste des bus\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Reserver des billets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Annuler la reservation\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Tableau d'etat du bus\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Quitter\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEntrez votre choix:: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();
        break;
    case 2:
        reserver();
        break;
    case 3:
        annuler();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tMerci d'utiliser ce systeme\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");

    getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== SYSTÈME DE RÉSERVATION DE BUS ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void reserver()
{
    Voyageur* listeVoyageurs = NULL;
    Voyageur* nouveauVoyageur = creerCompteVoyageur();

    nouveauVoyageur->suivant = listeVoyageurs;
    listeVoyageurs = nouveauVoyageur;

    printf("Votre compte voyageur a été créé avec succès !\n");

    int i=0;
    char numstr[100];
system("cls");
printf("=========================================== SYSTÈME DE RÉSERVATION DE BUS ============================================\n\n\n");
bus();
printf("Enter the Bus number:--->");
scanf("%d",&trno);
system("cls");
printf("=========================================== SYSTÈME DE RÉSERVATION DE BUS ============================================\n\n\n");
printf("Votre numéro de bus est %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covertion le numero en chaine
if(seat1 <= 0)
{
 printf("il n'y a pas des places vides' ");
}else
{
printf("\n\n\n\t\t\t\tles sieges disponibles:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tThe montant total de reservation  %d",200*booking);
itoa(seat1, str1, 10);

if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//ouverture de fichier pour ecrire le prenom dans le fichier
   b = fopen(tempstr2,"a");//ouverture de fichier pour ecrire le numero dans le fichier
for(i=0; i<booking; i++)//pour entrer le nom et le numero de siege du persone
{
    printf("||||||||||||||||||||Entrer les details du ticket num %d||||||||||||||||||||\n\n\n",i+1);
      printf("\t\t\t\tEntrer le numero de siege:--->");
      scanf("%d",&number);
      printf("\t\t\t\t Entrer le prenom de person:--->");
      scanf("%s",name[number-1]);
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)//mettre le numero dans le tableau
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//ecrire le prenom dans le fichier 
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)//mettre le numero dans le tableau
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//ecrire le prenom dans le fichier
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("|||||||||||||||||||||||||||||||||||||||| BUS RESERVATION SYSTEM ||||||||||||||||||||||||||||||||||||||||\n\n\n");
    int i,trno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("||||||||||||||||||||||||||||||||||||||||BUS RESERVATION SYSTEM ||||||||||||||||||||||||||||||||||||||||\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide","Vide ","Vide ","Vide ","Vide ","Vide ","Vide ","Vide "};
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void annuler()
{
 int siege_num,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Entrez le numéro de bus:---->");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("Entrez le numéro de siege:--->");
 scanf("%d",&siege_num);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == siege_num)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != siege_num&& num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == siege_num && num1[j] != 0)
             {
                 strcpy(name[j],"VIDE");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
 printf("\t\t\t\t ton argent est retourne a vous \t\t\t\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}


