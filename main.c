#include <stdio.h>
#include <stdlib.h>
#include <myconio.h>
#include <string.h>

struct contact *start, *pc, *end;
int first_contact = 0;

struct contact
{
    char nom[10];
    char prenom[10];
    int tel;
    char mail[30];
    struct contact *next;
};
int menu()
{
    int choix;
    printf("-===========-- Contact --===========-\n\n\t1- Ajouter contact\n\t2- Afficher contacts\n\t3- Rechercher contact\n\t4- Editer contact\n\t5- Quitter le programme\n\n-===================================-\n\n-> ");
    scanf("\n%d", &choix);
    return choix;
}
void back(struct contact *pc)
{
    int choix;
    printf("\n\n1-Menu principal\t2-Quitter le programme\n->");
    scanf("%d", &choix);
    if(choix==1)
    {
        system("cls");
        printf("\n\ntest : %s\t%s\t%d\t%s\n\n", pc->nom, pc->prenom, pc->tel, pc->mail);
        main();
    }
    else if(choix==2)
    {
        exit(0);
    }
    else
    {
        system("cls");
        printf("Veuillez choisir un choix parmis ceux proposes");
        Sleep(3000);
        system("cls");
        back(pc);
    }
}
void add_first(struct contact *start, struct contact *pc, struct contact *end)
{
    system("cls");
    printf("-===========-- Contact --===========-");
    start = (struct contact *)malloc(sizeof(struct contact));
    pc = start;
    fflush(stdin);
    printf("\n\nNom : ");
    gets(pc->nom);
    printf("\nPrenom : ");
    gets(pc->prenom);
    printf("\nTelephone : ");
    scanf("%d", &pc->tel);
    fflush(stdin);
    printf("\nMail : ");
    gets(pc->mail);
    end = pc;
    pc->next = NULL;
    printf("\n\n-===================================-");

    printf("\n\ntest : %s\t%s\t%d\t%s", pc->nom, pc->prenom, pc->tel, pc->mail);

    back(pc);
}
void add(struct contact *pc, struct contact *end)
{
    system("cls");
    printf("-===========-- Contact --===========-");
    pc = (struct contact *)malloc(sizeof(struct contact));
    fflush(stdin);
    printf("\n\nNom : ");
    gets(pc->nom);
    printf("\nPrenom : ");
    gets(pc->prenom);
    printf("\nTelephone : ");
    scanf("%d", &pc->tel);
    fflush(stdin);
    printf("\nMail : ");
    gets(pc->mail);
    end = pc;
    pc->next = NULL;
    printf("\n\n-===================================-");

    printf("\n\ntest : %s\t%s\t%d\t%s", pc->nom, pc->prenom, pc->tel, pc->mail);

    back(pc);
}
void show(struct contact *pc)
{
    //system("cls");
    //printf("-===========-- Contact --===========-");
    printf("\n\ntest : %s\t%s\t%d\t%s\n\n", pc->nom, pc->prenom, pc->tel, pc->mail);
    /*pc = start;
    while(pc->next!=NULL)
    {
        printf("\n\n%s\n%s\n%d\n%s\n\n", pc->nom, pc->prenom, pc->tel, pc->mail);
        pc=pc->next;
    }*/
    //printf("\n\n-===================================-");
    back(pc);
}
void search()
{
    int choix=0; /// valeur du choix du menu
    int choix2=0;
    int choix3=0;
    int choix4=0;
    int tab_modif_id[4][50];
    char nom_recherche[30]; ///chaine de caractére du nom a rechercher
    char variable_entree[30];
    int i=0; ///variable boucle
    int id=0; ///id pour selectionner un contact


     do
    {
         system("cls");
    printf("-===========-- Contact --===========-");
        printf("Recherche par: \n");
        printf("1-Nom \n");
        printf("2-Prenom \n");
        printf("3-Telephone \n");
        printf("4-Mail \n");

    printf("\n\n-===================================-");
        printf("Choix:");
        scanf("%d", &choix);
    }
    while(choix>4 || choix<1);

    if(choix==1) ///Recherche par nom
    {
      fflush(stdin);
        system("cls");
         printf("-===========-- Contact --===========-");
        printf("Saisir le nom:");
         printf("\n\n-===================================-");
        fgets(nom_recherche, sizeof nom_recherche, stdin);


         pc=start; ///remise a zero du pointeur

          do
        {

            if(strcmp(nom_recherche, pc->Nom) == 1)
            {
                id++;
                tab_modif_id[0][id]=pc->Nom;
                tab_modif_id[1][id]=pc->Prenom;
                tab_modif_id[2][id]=pc->Tel;
                tab_modif_id[3][id]=pc->Mail;
                tab_modif_id[4][id]=pc;

                printf("Fiche %d:\n", id);
                printf("    Nom: %s\n", pc->Nom);
                printf("    Prenom: %s\n", pc->Prenom);
                printf("    Telephone: %d\n", pc->Tel);
                printf("    Mail: %s\n", pc->Mail);

            }

             pc = pc->next;
        }
        while(pc->next != NULL);

          do
        {

            printf("Que voullez vous faire?\n");
            printf(" 1- Retour au menu principal\n");
            printf(" 2- Refaire une recherche\n");
            printf(" 3- Modifier une fiche\n");
            printf(" 4- Suprimer une fiche\n");

            printf("Choix:");
            scanf("%d", &choix2);
        }
        while(choix>4 || choix<1);

         if(choix2==1)
        {
            return 0;
        }

        if(choix2==2)
        {
            system("cls");
            recherche(&pc, &end, &start);
        }

        if(choix2==3)
        {
             do
            {
                printf("Quel est le numeros de la fiche a modifier?:");

                scanf("%d", &choix3);
            }
            while(choix3>id || choix3<1);

             system("cls");
            printf("-===========-- Contact --===========-");
            printf("Voici la fiche a modifier:\n");
            printf("    Nom: %s\n", tab_modif_id[0][choix3]);
            printf("    Prenom: %s\n", tab_modif_id[1][choix3]);
            printf("    Telephone: %d\n", tab_modif_id[2][choix3]);
            printf("    Mail: %s\n", tab_modif_id[3][choix3]);


             do
        {
            printf("Que voullez vous modifier?\n");
            printf(" 1- Nom\n");
            printf(" 2- Prenom\n");
            printf(" 3- Telephone\n");
            printf(" 4- Mail\n");

            printf("Choix:");
            scanf("%d", &choix4);
        }
        while(choix4>4 || choix4<1);

        if(choix4==1)
        {


        system("cls");
          printf("-===========-- Contact --===========-");
       printf("Saisir le nom:\n");

       pc=tab_modif_id[4][choix3];
      /*  fgets(variable_entree, sizeof variable_entree, stdin);
        pc->Nom=variable_entree; */

     //   gets(pc->Nom);
        return 0;
        }
        }

    }

    if(choix==2)///recherche par prenom
    {

    }

    if(choix==3)///recherche par telephone
    {

    }

    if(choix==4)///recherche par mail
    {

    }



    back(pc);
}
void edit()
{
    system("cls");
    printf("-===========-- Contact --===========-");

    printf("\n\n-===================================-");
    back(pc);
}
void quit()
{
    exit(0);
}
void test(int *i)
{
    *i = 3;
    return;
}
void main()
{
    /*int i = 2;
    printf("i = %d", i);
    test(&i);
    printf("\ntest : %d", i);*/
    printf("%d\n", first_contact);

    switch (menu())
    {
    case 1 :
        if(first_contact==0)
        {
            first_contact++;
            add_first(&start, &pc, &end);
            back(pc);
        }
        else
        {
            first_contact++;
            add(&pc, &end);
            back(pc);
        }
        break;
    case 2 :
        show(&pc);
        break;
    case 3 :
        search();
        break;
    case 4 :
        edit();
        break;
    case 5 :
        quit();
        break;
    default:
        system("cls");
        printf("-===========- Contact -===========-\n\nChoix incorrect, reessayez");
        Sleep(2000);
        system("cls");
        menu();
    }
}
