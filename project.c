#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tasks
{
    int id;
    char titles[1000];
    char description[1000];
    char Deadline[1000];
    int prix;
    char condition[1000];
};

int counter = 0;

int main()
{
    struct tasks task[1000];
    int stop = 0;

    do
    {
        printf("\n======= Ajouter une tache '1' \n");
        printf("======= Afficher Tous les taches '2' \n");
        printf("======= Rechercher une tache '3' \n");
        printf("======= Supprimer une tache '4' \n");
        printf("======= confirme une tache '5' \n");
        printf("======= Modifier les informations du tache '6' \n");
        printf("======= Statistique des taches '7' \n");
        printf("======= Get Out from the program '0' \n");

        int answer;
        printf("\nVotre choix est: ");
        scanf("%i", &answer);
        getchar();

        char chercher[100];
        int chercher_id;
        int stop_chercher = 0;
        int search;
        int year;
        int month;
        int day;
        int choix;
        int statistique = 0;
        int fait;

        switch (answer)
        {
        case 1:
            system("cls");

            task[counter].id = counter + 1;

            printf("\n======= Titre du tache: ");
            fgets(task[counter].titles, sizeof(task[counter].titles), stdin);

            printf("======= Description du tache: ");
            fgets(task[counter].description, sizeof(task[counter].description), stdin);

            printf(" ======= Deadline du tache: \n");
            printf(" ==== Year: ");
            scanf(" %i", &year);
            getchar();
            printf(" ==== month: ");
            scanf(" %i", &month);
            getchar();
            printf(" ==== day: ");
            scanf(" %i", &day);
            getchar();
            sprintf(task[counter].Deadline, "%i-%i-%i", day, month, year);

            printf("\n ======= Prix du Task: ");
            scanf("%d", &task[counter].prix);
            getchar();

            strcpy(task[counter].condition, "Pending");
            counter++;

            printf("\n ========= Votre tache a ete ajoute avec succes ========== \n \n");
            break;

        case 2:
            printf("\n ========= Afficher Tous les taches ========== \n \n");
            for (int i = 0; i < counter; i++)
            {
                printf("\n===== tache %d: \n \n", i + 1);
                printf("\n=== ID: %d \n", task[i].id);
                printf("=== Titre: %s ", task[i].titles);
                printf("=== description: %s ", task[i].description);
                printf("=== Deadline: %s ", task[i].Deadline);
                printf("\n=== prix: %d \n", task[i].prix);
                printf("=== condition: %s \n \n", task[i].condition);
            }

            break;
        case 3:
            system("cls");

            printf("======= Rechercher une tache par ID '1' \n");
            printf("======= Rechercher une tache par le titre '2' \n");
            printf("======= Return to list '0' \n");

            printf("\nVotre choix est: ");
            scanf("%i", &search);
            getchar();
            switch (search)
            {
            case 1:
                printf("Enter 'ID' du tache: ");
                scanf("%i", &chercher_id);
                for (int i = 0; i < counter; i++)
                {
                    if (task[i].id == chercher_id)
                    {
                        printf("\n===== la tache est: \n \n");
                        printf("=== ID: %d \n", task[i].id);
                        printf("=== Titre: %s ", task[i].titles);
                        printf("=== Description: %s ", task[i].description);
                        printf("=== prix: %d \n", task[i].prix);
                        printf("=== Condition: %s ", task[i].condition);
                        stop_chercher = 1;
                    }
                }
                if (stop_chercher == 0)
                {
                    printf("\nYour search doesn't exict...\n");
                }
                break;

            case 2:
                printf("Enter le titre du tache: ");
                fgets(chercher, sizeof(chercher), stdin);
                for (int i = 0; i < counter; i++)
                {
                    if (strcmp(task[i].titles, chercher) == 0)
                    {
                        printf("\n===== la tache est: \n \n");
                        printf("=== ID: %d \n", task[i].id);
                        printf("=== Titre: %s ", task[i].titles);
                        printf("=== Description: %s ", task[i].description);
                        printf("=== prix: %d \n", task[i].prix);
                        printf("=== Condition: %s ", task[i].condition);
                        stop_chercher = 1;
                    }
                }
                if (stop_chercher == 0)
                {
                    printf("\nYour search doesn't exict...\n");
                }

                break;

            default:
                break;
            }

            break;

        case 4:
            system("cls");
            printf("Enter 'ID' du tache: ");
            scanf("%i", &chercher_id);
            for (int i = 0; i < counter; i++)
            {
                if (task[i].id == chercher_id)
                {
                    for (int j = i; j < counter; j++)
                    {
                        task[j].id = task[j + 1].id;
                        strcpy(task[j].titles, task[j + 1].titles);
                        strcpy(task[j].description, task[j + 1].description);
                        strcpy(task[j].Deadline, task[j + 1].Deadline);
                        task[j].prix = task[j + 1].prix;
                        strcpy(task[j].condition, task[j + 1].condition);
                    }

                    counter--;
                    stop_chercher = 1;
                    printf("\nYour search removed succefuly...\n");
                }
            }
            if (stop_chercher == 0)
            {
                printf("\nYour search doesn't exict...\n");
            }
            break;

            break;

        case 5:
            system("cls");
            printf("Enter 'ID' du tache: ");
            scanf("%i", &chercher_id);
            for (int i = 0; i < counter; i++)
            {
                if (task[i].id == chercher_id)
                {

                    strcpy(task[i].condition, "Done");
                    stop_chercher = 1;
                    printf("\nYour search confirmed succefuly...\n");
                }
            }
            if (stop_chercher == 0)
            {
                printf("\nYour search doesn't exict...\n");
            }

            break;

        case 6:
            system("cls");
            printf("Entrez ID du tache que vous souhaitez modifier: ");
            scanf("%i", &chercher_id);

            for (int i = 0; i < counter; i++)
            {
                if (task[i].id == chercher_id)
                {

                    printf("\n======= Modifier le titre '1' \n");
                    printf("\n======= Modifier la description '2' \n");
                    printf("\n======= Modifier le prix '3' \n");
                    printf("\n======= Modifier tout les information '4' \n");
                    printf("======= Return to list '0' \n");

                    printf("\nVotre choix est: ");
                    scanf("%i", &choix);
                    getchar();

                    switch (choix)
                    {
                    case 1:
                        printf("\n=======Nouvelle Titre du tache: ");
                        fgets(task[i].titles, sizeof(task[i].titles), stdin);
                        printf("\n ========= Votre tache a ete modifie avec succes ========== \n \n");
                        break;
                    case 2:
                        printf("=======Nouvelle Description du tache: ");
                        fgets(task[i].description, sizeof(task[i].description), stdin);
                        printf("\n ========= Votre tache a ete modifie avec succes ========== \n \n");

                        break;
                    case 3:
                        printf("\n =======Nouveau Prix du Task: ");
                        scanf("%d", &task[i].prix);
                        printf("\n ========= Votre tache a ete modifie avec succes ========== \n \n");
                        break;
                    case 4:
                        printf("\n======= Titre du tache: ");
                        fgets(task[i].titles, sizeof(task[i].titles), stdin);

                        printf("======= Description du tache: ");
                        fgets(task[i].description, sizeof(task[i].description), stdin);

                        printf(" ======= Deadline du tache: \n");
                        printf(" ==== Year: ");
                        scanf(" %i", &year);
                        getchar();
                        printf(" ==== month: ");
                        scanf(" %i", &month);
                        getchar();
                        printf(" ==== day: ");
                        scanf(" %i", &day);
                        getchar();
                        sprintf(task[i].Deadline, "%i-%i-%i", day, month, year);

                        printf("\n ======= Prix du Task: ");
                        scanf("%d", &task[i].prix);
                        getchar();

                        printf("\n ========= Votre tache a ete modifie avec succes ========== \n \n");

                        break;
                    default:
                        break;
                    }

                    stop_chercher = 1;
                }
            }
            if (stop_chercher == 0)
            {
                printf("\nYour search doesn't exict...\n");
            }

            break;

        case 7:
        system("cls");
            printf("\n \n========= Statistique =========\n \n");
            if (counter != 0)
            {
                for (int i = 0; i < counter; i++)
                {
                    if (strcmp(task[i].condition, "Pending") == 0)
                    {
                        statistique++;
                    }
                }
                fait = counter - statistique;
                printf("====== Totale des taches est: %i\n \n", counter);
                printf("====== Les tache en cours: %i qui est: %i%\n \n", statistique, (statistique * 100) / counter);
                printf("====== Les taches faits: %i qui est: %i%\n", fait, (fait * 100) / counter);
            }
            else
            {
                printf("====== Totale des taches est: 0\n \n");
                printf("====== Les tache en cours: 0 qui est: 0%\n \n");
                printf("====== Les taches faits: 0 qui est: 0%\n");
            }

            break;

        default:
            printf("\n====== MERCI POUR UTILISE LE PROGRAMME... =======\n");
            stop = 1;
            break;
        }
    } while (stop == 0);

    return 0;
}