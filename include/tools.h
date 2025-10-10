// tools.h

#ifndef TOOLS_H
#define TOOLS_H

typedef struct {
    int x;
    int y;
} Point;

Point*  point_create(int x, int y);
void    point_set_location(Point *point, int x, int y);
void    point_move_by(Point *point, int dx, int dy);
void    point_print_location(Point *point);

typedef struct car VEHICLE;             //Définition de la structure des voitures
struct car
{
    char direction ;			/*N => Nord, S => Sud, E => EST, O => OUEST*/
    int posx;					//Position courante coin haut gauche x de la voiture
    int posy;					//Position courante coin haut gauche y de la voiture/
    int speed;				    //Vitesse du véhicule/
    char road_side;			    //’l’=>left ou ’r’=>right/
    char type;					//’c’=>car, ’t’=>truck, etc./

    //char Carrosserie [4][30];	/*Carrosserie de la voiture, servira pour
    //l’affichage du véhicule à tout moment*/

    //int code_couleur;			/*Code couleur de la voiture à utiliser lors de
    //l’affichage*/

    char etat;					/*État du véhicule : ’1’ => actif et ’0’ => inactif/
                                unsigned long int tps;/pour stocker le temps passé dans le parking*/

    struct car *NXT;		    /*Pointeur vers une prochaine voiture,
                                nécessaire pour la liste chaînée*/
};

VEHICLE *create_vehicle(void);

VEHICLE *travel_to_last(VEHICLE *head);

VEHICLE *append_element(VEHICLE *head);

void print_list(VEHICLE *head);

void free_list(VEHICLE *head);

int list_length(VEHICLE *head);

VEHICLE *insert_element_after(VEHICLE *prev_vehicle);

VEHICLE *insert_element_index(const int index, VEHICLE *head);

VEHICLE *adress_at_index(const int index, VEHICLE *head);

void delete_vehicle(VEHICLE *head, const int index_to_delete);

VEHICLE *push_element(VEHICLE *head);

#endif