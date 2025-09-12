// Juste un exemple de .c
// dont une fonction est importé
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tools.h"


//FONCTION A DES FINS DE TESTS
int add(int a, int b)
{
    return a + b;
}

//#############################################
//            TOOLS LISTE CHAINEE
//#############################################

typedef struct car VEHICLE;
struct car
{
    char direction ;			/*N => North, S => South, E => East, W => West*/
    int posx;					//Position courante coin haut gauche x de la voiture
    int posy;					//Position courante coin haut gauche y de la voiture/
    int vitesse;				//Vitesse du véhicule/
    char alignement;			//’g’=>gauche ou ’d’=>droite/
    char type;					//’v’=>voiture, ’c’=>camion, etc./

    //char Carrosserie [4][30];	/*Carrosserie de la voiture, servira pour
    //l’affichage du véhicule à tout moment*/

    //int code_couleur;			/*Code couleur de la voiture à utiliser lors de
    //l’affichage*/

    char etat;					/*État du véhicule : ’1’ => actif et ’0’ => inactif/
                                unsigned long int tps;/pour stocker le temps passé dans le parking*/

    struct car *NXT;		    /*Pointeur vers une prochaine voiture,
                                nécessaire pour la liste chaînée*/
};

VEHICLE *create_vehicle(void)                       //Crée un véhicule
{
    //A utiliser dans le main de cette manière :
    //VEHICLE *vehicle_0 = create_vehicle();

    VEHICLE *vehicle= NULL;
    vehicle = malloc(sizeof(VEHICLE));
    vehicle->NXT = NULL;

    return vehicle;
}

VEHICLE *travel_to_last(VEHICLE *head)             //Retourne un pointeur vers le dernier élément de la liste
{
    VEHICLE *cur = head;

    while (cur->NXT != NULL)
    {
        cur = cur->NXT;
    }

    return cur;
}

VEHICLE *append_element(VEHICLE *head)              //Ajoute un élément à la fin de la liste
{
    //A utiliser dans le main de cette manière :
    //VEHICLE *vehicle_1 = append_element(premier_élément_de_la_liste);

    VEHICLE *new_vehicle = create_vehicle();
    travel_to_last(head)->NXT = new_vehicle;

    return new_vehicle;
}


void print_list(VEHICLE *head)                      //Imprime toute la liste avec l'adresse de l'élément actuel...
                                                    //...et l'adresse de celui qui le suit.
{
    //A utiliser dans le main de cette manière :
    //print_list(premier_élément_de_la_liste);
    VEHICLE *cur = head;
    int i = 0;
    while (cur != NULL)
    {
        printf("Index [%d] Adresse : %p Next = %p\n", i, (void *)cur, (void *)cur->NXT);
        i++;
        cur = cur->NXT;
    }
}


void free_list(VEHICLE *head)
{
    VEHICLE *cur = head;
    while (cur != NULL)
    {
        VEHICLE *next = cur->NXT;   // on sauve l’adresse du suivant
        free(cur);                  // on libère le nœud courant
        cur = next;                 // on avance
    }
}

int list_length(VEHICLE *head)                      //Retourne le nombre d'éléments de la liste
{
    //A utiliser dans le main de cette manière :
    //list_length(premier_élément_de_la_liste);
    VEHICLE *cur = head;
    int length = 0;
    while (cur != NULL)
    {
        cur = cur->NXT;
        length++;
    }
    return length;
}

VEHICLE *insert_element_after(VEHICLE *prev_vehicle)    //Crée et insert un nouvel élément après l'élément spécifié
{
    VEHICLE *new_vehicle = create_vehicle();
    new_vehicle->NXT = prev_vehicle->NXT;
    prev_vehicle->NXT = new_vehicle;

    return new_vehicle;

}

VEHICLE *insert_element_index(const int index, VEHICLE *head)   //Crée et insert un nouvel élément à l'index...
                                                                //...spécifié de la list spécifiée
{
    int i = 0;
    VEHICLE *adress_of_index = NULL;
    VEHICLE *cur = head;
    VEHICLE *prev = cur;
    while (i!=index)
    {
        prev = cur;
        cur = cur->NXT;
        i++;
    }
    VEHICLE *new_vehicle = insert_element_after(prev);

    return new_vehicle;
}

VEHICLE *adress_at_index(const int index, VEHICLE *head)    //Rtourne l'adresse de l'élément à l'index spécifié
{
    int i = 0;
    VEHICLE *cur = head;
    while (i!=index)
    {
        cur = cur->NXT;
        i++;
    }
    return cur;
}

void delete_vehicle(VEHICLE *head, const int index_to_delete)      //Supprime le véhicule à l'index spécifié
{
    VEHICLE *temp_nxt = adress_at_index(index_to_delete, head)->NXT;
    VEHICLE *prev = NULL;
    if (index_to_delete == 1)
    {
        free(adress_at_index(index_to_delete, head));
        head->NXT = temp_nxt;
    }
    else
    {
        prev = adress_at_index(index_to_delete-1, head);
        free(adress_at_index(index_to_delete, head));
        prev->NXT = temp_nxt;
    }

}

VEHICLE *push_element(VEHICLE *head)                //Ajoute un élément en tête de liste
{
    VEHICLE *new_vehicle = create_vehicle();
    new_vehicle->NXT = head->NXT;
    head->NXT = new_vehicle;

    return new_vehicle;
}