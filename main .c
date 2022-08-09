#include <stdio.h>
#include <stdlib.h>
#define livre "livre.txt"       // pour l'affichage de la liste des livres
#define membre "membre.txt"     // pour l'affichage de la liste des membres
#define emprunt "emprunt.txt"   // pour l'affichage de la liste des emprunts

// Fonction pour définir le rôle de l'utilisateur
int main()
{
int choix_1;
printf("                                #######################################\n");
printf("                                #######################################\n");
printf("\n");
printf("                                Acceder au menu : \n");
printf("                                1...Administrateur\n ");
printf("                               2...Membre\n ");
printf("\n");
printf("                                #######################################\n");
printf("                                #######################################\n");
printf("\n");
printf("\n");

printf("Saisir le numero d une action : \n");
scanf("%d",&choix_1);
if (choix_1==1)
{
    menu_admin();
}
else if (choix_1==2)
{
    menu_membre();
}
else        //sécuriser la saisie
{
    printf("Erreur dans la saisie\n");
printf("\n");
printf("\n");
    main();
}
}

// fonction pour la modification de la bibliothèque en tant qu'administrateur
void menu_admin()
{
int choix_2;

printf("                                #######################################\n");
printf("                                ################ Menu #################\n");
printf("\n");
printf("                                1...Ajouter un Livre\n");
printf("                                2...Ajouter un Membre\n");
printf("                                3...Voire les livres disponibles\n");
printf("                                4...Voir la liste des membres\n");
printf("                                5...Voir la liste des livres empruntes \n");
printf("                                6...Quitter la bibliotheque\n");
printf("\n");
printf("                                #######################################\n");
printf("                                #######################################\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("Saisir le numero d une action : \n");
scanf("%d",&choix_2);
if (choix_2==1)
{
    addbook();
}
else if (choix_2==2)
{
    addmember();
}
else if (choix_2==3)
{
    livre_dispo();
}
else if (choix_2==4)
{
    liste_membre();
}
else if (choix_2==5)
{
    livre_emprunter();
}
else if (choix_2==6)
{
    fin();
}
else    //sécurisation de la saisie
{
    printf("Erreur dans la saisie\n");
printf("\n");
printf("\n");
    menu_admin();
}
}

// menu pour un membre souhaitant voir et emprunter des livres et voir les autres membres
void menu_membre()
{
int choix_3;
printf("                                #######################################\n");
printf("                                ################ Menu #################\n");
printf("\n");

printf("                                1...Voire les livres disponibles\n");
printf("                                2...Voir la liste des membres\n");
printf("                                3...Voir la liste des emprunts\n");
printf("                                4...Emprunter un livre\n");
printf("                                5...Depot de livre\n");
printf("                                6...Quitter la bibliotheque\n");
printf("\n");
printf("                                #######################################\n");
printf("                                #######################################\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("Saisir le numero d une action : \n");
scanf("%d",&choix_3);
if (choix_3==1)
{
    livre_dispo();
}
else if (choix_3==2)
{
    liste_membre();
}
else if (choix_3==3)
{
    livre_non_dispo ();
}
else if (choix_3==4)
{
    emprunt_livre();
}
else if (choix_3==5)
{
    restitution();
}
else if (choix_3==6)
{
    fin();
}
else    //sécurisation de la saisie
{
    printf("Erreur dans la saisie\n");
printf("\n");
printf("\n");
    menu_membre();
}
}





// fonction pour la saisie des livres
void addbook()
{

    char nom_a[50],titre[100],code[50];
    int nbr_ex;
    printf("Veuiller saisir les informations du livre\n");
    printf("Pour les espaces taper :  _  \n");
    printf("Titre du livre :\n");
    scanf("%s",&titre);
    printf("Pour les espaces taper :  _  \n");
    printf("Nom de l'auteur :\n");
    scanf("%s",&nom_a);
    printf("Code du livre :\n");
    scanf("%s",&code);
    printf("Nombre d'exemplaire :\n");
    scanf("%d",&nbr_ex);

    FILE *f = NULL ;  // ouvre le fichier si il le trouve (sinon erreur)
    f = fopen("livre.txt","a"); //ouvre le fichier texte  (commande a permet l'ajout de caractère)
     fprintf(f,"%s\n%s\n%s\n%d\n\n\n",titre,nom_a,code,nbr_ex); //fprintf permet l'écriture des données que l'on a saisie
    fclose(f);// ferme le fichier
    printf("\n");
    printf("\n");
    printf("\n");
    main();

}

void restitution ()
{
    char nom_a[50],titre[100],code[50];
    int nbr_ex;
    printf("Pour les espaces taper :  _  \n");
    printf("Titre du livre :\n");
    scanf("%s",&titre);
    printf("\n\nMerci du retour :D  \n\n\n");
    menu_membre();
}

// fonction pour saisir les membres
void addmember()
{
    char nom_m[50],prenom[50],adresse[100],metier[50],mail[50];
    printf("Saisir les informations du nouveau membre\n");
    printf("Nom du membre :\n");
    scanf("%s",&nom_m);
    printf("Prenom du membre :\n");
    scanf("%s",&prenom);
    printf("Pour les espaces taper :  _  \n");
    printf("Adresse du membre :\n");
    scanf("%s",&adresse);
    printf("Mail du membre :\n");
    scanf("%s",&mail);
    printf("Metier du membre :\n");
    scanf("%s",&metier);


    FILE *f = NULL ;// ouvre le fichier si il le trouve (sinon erreur)
    f = fopen("membre.txt","a");//ouvre le fichier texte  (commande a permet l'ajout de caractère)
    fprintf(f,"%s\n%s\n%s\n%s\n%s\n\n\n",nom_m,prenom,adresse,mail,metier);//fprintf permet l'écriture des données que l'on a saisie
    fclose(f);// ferme le fichier
    printf("\n");
    printf("\n");
    printf("\n");
    menu_admin();
}


//fonction pour afficher les livres de la bibliothèque
void livre_dispo()
{
  FILE *f_in;  // ouvre un fichier
  int c; // variable qui recevoit la valeur de retour de fgetc pour pouvoir détecter correctement la fin du fichier.

  if ((f_in = fopen(livre,"r")) == NULL)  // si le fichier livre n'est pas trouvé on affiche erreur
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",livre); // unité d'affichage des messages d'erreur
      return(EXIT_FAILURE);  // erreur dans la recherche du fichier
    }

  while ((c = fgetc(f_in)) != EOF)  // tant que la variable c n'est pas arrivé à la fin ne pas fermer le fichier (EOF= end of files = fin du fichier)
    {
      if (c == '0')// si la fin du fichier est égale à 0 enclenche la fermeture
        ungetc('.',f_in);//replace un caractère avec la fonction ungetc
      putchar(c); // transfère le caractère c et dans le if permettra d'indiquer la fin du fichier
    }
  fclose(f_in); // ferme le fichier
  return(EXIT_SUCCESS);
main();
}

//fonction pour afficher les membres de la bibliothèque
void liste_membre()
{
  FILE *f_in;  // ouvre un fichier
  int c; // variable qui recevoit la valeur de retour de fgetc pour pouvoir détecter correctement la fin du fichier.

  if ((f_in = fopen(membre,"r")) == NULL)  // si le fichier membre n'est pas trouvé on affiche erreur
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",membre); // unité d'affichage des messages d'erreur
      return(EXIT_FAILURE);  // erreur dans la recherche du fichier
    }

  while ((c = fgetc(f_in)) != EOF)  // tant que la variable c n'est pas arrivé à la fin ne pas fermer le fichier (EOF= end of files = fin du fichier)
    {
      if (c == '0') // si la fin du fichier est égale à 0 enclenche la fermeture
        ungetc('.',f_in);//replace un caractère avec la fonction ungetc
      putchar(c); // transfère le caractère c et dans le if permettra d'indiquer la fin du fichier
    }
  fclose(f_in); // ferme le fichier
  return(EXIT_SUCCESS);
main();
}


// fonction pour afficher les livres non-disponibles
void livre_non_dispo ()
{
  FILE *f_in;  // ouvre un fichier
  int c; // variable qui recevoit la valeur de retour de fgetc pour pouvoir détecter correctement la fin du fichier.

  if ((f_in = fopen(emprunt,"r")) == NULL)  // si le fichier emprunt n'est pas trouvé on affiche erreur
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",emprunt); // unité d'affichage des messages d'erreur
      return(EXIT_FAILURE);  // erreur dans la recherche du fichier
    }

  while ((c = fgetc(f_in)) != EOF)  // tant que la variable c n'est pas arrivé à la fin ne pas fermer le fichier (EOF= end of files = fin du fichier)
    {
      if (c == '0')// si la fin du fichier est égale à 0 enclenche la fermeture
        ungetc('.',f_in);//replace un caractère avec la fonction ungetc
      putchar(c); // transfère le caractère c et dans le if permettra d'indiquer la fin du fichier
    }
  fclose(f_in); // ferme le fichier
  return(EXIT_SUCCESS);
}

//même fonction qu'avant mais pour l'admin cette fois-ci
void livre_emprunter ()
{
    FILE *f_in;  // ouvre un fichier
  int c; // variable qui recevoit la valeur de retour de fgetc pour pouvoir détecter correctement la fin du fichier.

  if ((f_in = fopen(emprunt,"r")) == NULL)  // si le fichier emprunt n'est pas trouvé on affiche erreur
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",emprunt); // unité d'affichage des messages d'erreur
      return(EXIT_FAILURE);  // erreur dans la recherche du fichier
    }

  while ((c = fgetc(f_in)) != EOF)  // tant que la variable c n'est pas arrivé à la fin ne pas fermer le fichier (EOF= end of files = fin du fichier)
    {
      if (c == '0')// si la fin du fichier est égale à 0 enclenche la fermeture
        ungetc('.',f_in);//replace un caractère avec la fonction ungetc
      putchar(c); // transfère le caractère c et dans le if permettra d'indiquer la fin du fichier
    }
  fclose(f_in); // ferme le fichier
  return(EXIT_SUCCESS);
  menu_admin();
}

//fonction pour la liste des livres pour les membres
void livre_bibl ()
{
  FILE *f_in;  // ouvre un fichier
  int c; // variable qui recevoit la valeur de retour de fgetc pour pouvoir détecter correctement la fin du fichier.

  if ((f_in = fopen(livre,"r")) == NULL)  // si le fichier livre n'est pas trouvé on affiche erreur
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",livre); // unité d'affichage des messages d'erreur
      return(EXIT_FAILURE);  // erreur dans la recherche du fichier
    }

  while ((c = fgetc(f_in)) != EOF)  // tant que la variable c n'est pas arrivé à la fin ne pas fermer le fichier (EOF= end of files = fin du fichier)
    {
      if (c == '0')// si la fin du fichier est égale à 0 enclenche la fermeture
        ungetc('.',f_in);//replace un caractère avec la fonction ungetc
      putchar(c); // transfère le caractère c et dans le if permettra d'indiquer la fin du fichier
    }
  fclose(f_in); // ferme le fichier
  return(EXIT_SUCCESS);

}


// permet l'affichage ou non des livres de la bibliothèque et ceux non-disponible
void menu_emprunt ()
{
    printf("voici la liste des livres de la bibliotheque : \n");
    livre_bibl();
    printf("\n\nEt voici les livres deja empruntes : \n");
    livre_non_dispo ();

    printf("\n");
    printf("\n");
    printf("\n");
}

// fonction pour emprunter un livre
void emprunt_livre()
{

    char nom_a[50],titre[50],code[50];
    int choix_L;

    printf("souhaitez vous voir les livres disponibles? \n");  // donne le choix pour connaitre les livres disponibles
    printf("1=oui    2=non\n");
    scanf ("%d",&choix_L);
    if (choix_L==1)
    {
        menu_emprunt();
    }
    else
    {
        printf("quel livre souhaitez vous empruntez? \n");
    }
    printf("Titre du livre :\n");
    scanf("%s",&titre);
    printf("Nom de l'auteur :\n");
    scanf("%s",&nom_a);
    printf("code du livre :\n");
    scanf("%s",&code);

    FILE *f = NULL ;// ouvre le fichier si il le trouve (sinon erreur)
    f = fopen("emprunt.txt","a");//ouvre le fichier texte  (commande a permet l'ajout de caractère)
     fprintf(f,"%s\n%s\n%s\n_n\n",titre,nom_a,code);//fprintf permet l'écriture des données que l'on a saisie
    fclose(f);// ferme le fichier
    printf("\n");
    printf("\n");
    printf("\n");
    menu_membre();

}

void fin ()
{
        system("cls"); // la fonction cls vide la mémoire

}

