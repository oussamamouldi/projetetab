#ifndef functions_H_INCLUDED
#define functions_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//include<gtk/gtk.h>
extern const char ets_path;
int i ;
typedef struct {
char id[8];
char nom[50];
char region[10];
int capacite;
int dispo;
char adresse[30];
char contact[20];
int collaborateur[2];
}etablissement;
void ajouter_ets(const char *ets_path,etablissement ets,char *error);
void modifier_ets(const char *ets_path,etablissement new,char *id,char *error) ;
void supprimer_ets(const char *ets_path,const char *id,char *error);
void chercher_nom_region(const char *ets_path, const char *nom, const char *region, char *error);
etablissement generer_id(etablissement ets);
void afficher_etablissements_par_region(const char *ets_path, const char *region, char *error);
int compare_capacite(const void *a, const void *b);
void afficher_etablissements_tries_par_capacite(const char *ets_path, char *error);
#endif


