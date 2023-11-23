#include "fonctions.h"
etablissement generer_id(etablissement ets)
{
    srand(time(NULL));  

    int random = rand() % 9000 + 1000;
    snprintf(ets.id, sizeof(ets.id), "%d", random);

return ets;
}
void ajouter_ets(const char *ets_path,etablissement ets,char *error)
{
    ets=generer_id(ets);
    FILE * f=fopen(ets_path, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %s %s %d\n",ets.id,ets.nom,ets.region,ets.capacite,ets.dispo,ets.adresse,ets.contact,ets.collaborateur[i]);
        fclose(f);
        strcpy(error,"etablissement ajouté avec succès\n");

    }
    else
        strcpy(error,"erreur d'ajout\n");
}
 void modifier_ets(const char *ets_path,etablissement new,char *id,char *error)  
{
     etablissement e ;
    FILE * f=fopen(ets_path, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %s %s %d\n",e.id,e.nom,e.region,&e.capacite,&e.dispo,e.adresse,e.contact,&e.collaborateur[i])!=EOF)
        {
             if (strcmp(e.id,id)==0)
            {    fprintf(f2,"%s %s %s %d %d %s %s %d\n",new.id,new.nom,new.region,new.capacite,new.dispo,new.adresse,new.contact,new.collaborateur[i]);
                
            }
            else
                 fprintf(f2,"%s %s %s %d %d %s %s %d\n",e.id,e.nom,e.region,e.capacite,e.dispo,e.adresse,e.contact,e.collaborateur[i]);
        }
        strcpy(error,"etablissement modifié avec succès\n");
    }
    else
        strcpy(error,"erreur d'ajout\n");
    fclose(f);
    fclose(f2);
    remove(ets_path);
    rename("nouv.txt",ets_path);
}
/*void supprimer_ets(const char *ets_path,const char *id,char *error)
{

    etablissement ets;
    FILE * f=fopen(ets_path, "r");
    FILE * f2=fopen("supp.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %s %s %d\n",ets.id,ets.nom,ets.region,&ets.capacite,&ets.dispo,ets.adresse,ets.contact,&ets.collaborateur[i])!=EOF)
        {
            if(strcmp(ets.id,id)!=0)
                fprintf(f2,"%s %s %s %d %d %s %s %d\n",ets.id,ets.nom,ets.region,ets.capacite,ets.dispo,ets.adresse,ets.contact,ets.collaborateur[i]);
            
        strcpy(error,"etablissement supprimé avec succès\n");
	}	
           else 
	strcpy(error,"etablissement non trouvée\n");
    }
    else
        strcpy(error,"erreur de supression\n");
    fclose(f);
    fclose(f2);
    remove("etab.txt");
    rename("supp.txt",ets_path);
}*/
void supprimer_ets(const char *ets_path, const char *id, char *error)
{
    etablissement ets;
    int found = 0;  // Add a flag to check if the ID is found

    FILE *f = fopen(ets_path, "r");
    FILE *f2 = fopen("supp.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, &ets.capacite, &ets.dispo, ets.adresse, ets.contact, &ets.collaborateur[i]) != EOF)
        {
            if (strcmp(ets.id, id) != 0)
            {
                fprintf(f2, "%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, ets.capacite, ets.dispo, ets.adresse, ets.contact, ets.collaborateur[i]);
            }
            else
            {
                found = 1;  // Set the flag to indicate ID is found
            }
        }

        if (found)
        {
            strcpy(error, "etablissement supprimé avec succès\n");
        }
        else
        {
            strcpy(error, "etablissement non trouvé\n");
        }
    } 
    else
    {
        strcpy(error, "erreur de suppression\n");
    }

    fclose(f);
    fclose(f2);
    remove(ets_path);
    rename("supp.txt", ets_path);
}


/*void chercher_nom_region(const char *ets_path, char *nom[], char *region[], char *error)
{
    etablissement ets;

    FILE *f = fopen(ets_path, "r");

    if (f != NULL)
    {
        int found = 0; 

        while (fscanf(f, "%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, &ets.capacite, &ets.dispo, ets.adresse, ets.contact, &ets.collaborateur[i]) != EOF)
        {
            if (strcmp(nom,ets.nom) == 0 && (strcmp(region, ets.region) == 0))
            {
                printf("%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, ets.capacite, ets.dispo, ets.adresse, ets.contact, ets.collaborateur[i]);
                found = 1;
            }
        }

        if (!found)
        {
            printf("non trouvé\n");
            strcpy(error, "Aucun établissement trouvé avec le nom et la région spécifiés.\n");
        }

        fclose(f);
    }
    else
    {
        strcpy(error, "Erreur d'ouverture du fichier.\n");
    }
}*/
void chercher_nom_region(const char *ets_path, const char *nom, const char *region, char *error)
{
    etablissement ets;

    FILE *f = fopen(ets_path, "r");

    if (f != NULL)
    {
        int found = 0;

        while (fscanf(f, "%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, &ets.capacite, &ets.dispo, ets.adresse, ets.contact, &ets.collaborateur[i]) != EOF)
        {
            if (strcmp(nom, ets.nom) == 0 && strcmp(region, ets.region) == 0)
            {
                printf("%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, ets.capacite, ets.dispo, ets.adresse, ets.contact, ets.collaborateur[i]);
                found = 1;
            }
        }

        if (!found)
        {
            printf("non trouvé\n");
            strcpy(error, "Aucun établissement trouvé avec le nom et la région spécifiés.\n");
        }

        fclose(f);
    }
    else
    {
        strcpy(error, "Erreur d'ouverture du fichier.\n");
    }
}
void afficher_etablissements_par_region(const char *ets_path, const char *region, char *error) {
    etablissement ets;
    FILE *f = fopen(ets_path, "r");

    if (f != NULL) {
        int count = 0; 

        printf("Liste des établissements dans la région %s :\n", region);

        while (fscanf(f, "%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, &ets.capacite, &ets.dispo, ets.adresse, ets.contact, &ets.collaborateur[i]) != EOF) {
            if (strcmp(region, ets.region) == 0) {
                printf("%s %s %s %d %d %s %s %d\n", ets.id, ets.nom, ets.region, ets.capacite, ets.dispo, ets.adresse, ets.contact, ets.collaborateur[i]);
                count++;
            }
        }

        if (count == 0) {
            printf("Aucun établissement trouvé dans la région %s.\n", region);
            strcpy(error, "Aucun établissement trouvé dans la région spécifiée.\n");
        } else {
            printf("Nombre total d'établissements dans la région %s : %d\n", region, count);
        }

        fclose(f);
    } else {
        strcpy(error, "Erreur d'ouverture du fichier.\n");
    }
}
#include <stdio.h>
#include <stdlib.h> // for qsort

// ...

// Comparison function for qsort
int compare_capacite(const void *a, const void *b) {
    const etablissement *et1 = (const etablissement *)a;
    const etablissement *et2 = (const etablissement *)b;
    
    return et1->capacite - et2->capacite;
}

void afficher_etablissements_tries_par_capacite(const char *ets_path, char *error) {
    etablissement *ets_array; // Dynamic array to store establishments
    int ets_count = 0;        // Counter for the number of establishments

    FILE *f = fopen(ets_path, "r");

    if (f != NULL) {
        // Count the number of establishments
        while (fscanf(f, "%*s %*s %*s %*d %*d %*s %*s %*d\n") != EOF) {
            ets_count++;
        }

        // Allocate memory for the dynamic array
        ets_array = (etablissement *)malloc(ets_count * sizeof(etablissement));
        
        // Rewind the file to the beginning
        rewind(f);

        // Read establishments into the dynamic array
        for (int i = 0; i < ets_count; i++) {
            fscanf(f, "%s %s %s %d %d %s %s %d\n", ets_array[i].id, ets_array[i].nom, ets_array[i].region,
                   &ets_array[i].capacite, &ets_array[i].dispo, ets_array[i].adresse, ets_array[i].contact, &ets_array[i].collaborateur[i]);
        }

        // Close the file
        fclose(f);

        // Use qsort to sort the dynamic array by capacity
        qsort(ets_array, ets_count, sizeof(etablissement), compare_capacite);

        // Display the sorted list
        printf("Liste des établissements triés par capacité :\n");
        for (int i = 0; i < ets_count; i++) {
            printf("%s %s %s %d %d %s %s %d\n", ets_array[i].id, ets_array[i].nom, ets_array[i].region,
                   ets_array[i].capacite, ets_array[i].dispo, ets_array[i].adresse, ets_array[i].contact, ets_array[i].collaborateur[i]);
        }

        // Free the allocated memory
        free(ets_array);
    } else {
        strcpy(error, "Erreur d'ouverture du fichier.\n");
    }
}



