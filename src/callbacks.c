#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "fonctions.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

/*
void
on_ajoutbutton_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	etablissment ETS;
	GtkWidget *widget = lookup_widget(button,"identry");
	strcpy(ETS.id,gtk_entry_get_text(GTK_ENTRY(widget)));
	GtkWidget *widget = lookup_widget(button,"nomentry");
	strcpy(ETS.nom,gtk_entry_get_text(GTK_ENTRY(widget)));	
	widget=lookup_widget(button,"regioncombo");
	strcpy(ETS.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget)));
	widget=lookup_widget(button,"capacspinbutton");
	ETS.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
	widget=lookup_widget(button,"57radiobutton");
	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(widget)))
	ETS.dispo=0;
	else 
	{
		widget=lookup_widget(button,"67radiobutton");
		if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(widget)))
			ETS.dispo=1;
		else		
		{
			widget=lookup_widget(button,"77radiobutton");
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)));
			ETS.dispo=2;
		}
	}
	GtkWidget *widget = lookup_widget(button,"adrrentry");
	strcpy(ETS.adresse,gtk_entry_get_text(GTK_ENTRY(widget)));
	GtkWidget *widget = lookup_widget(button,"contentry");
	strcpy(ETS.contact,gtk_entry_get_text(GTK_ENTRY(widget)));	
	widget=lookup_widget(button,"crcheckbutton");
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
			strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(widget)));
	widget=lookup_widget(button,"msfcheckbutton");
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
				strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(widget)));
	widget=lookup_widget(button,"autrecheckbutton");
						if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
							strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(widget)));	
	ajouter_ets(ets_path,ETS,error);								
}
*/
void
on_ajoutbutton_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	char erreur[100];
	GtkWidget *REGION;
	GtkWidget *CAPAC;
	GtkWidget *khamsa;
	GtkWidget *setta;
	GtkWidget *sab3a;
	GtkWidget *CR;
	GtkWidget *MSF;
	GtkWidget *AUTRE;
	etablissement ETS;
	GtkWidget *ID = lookup_widget(GTK_WIDGET(button),"identry");
	strcpy(ETS.id,gtk_entry_get_text(GTK_ENTRY(ID)));
	GtkWidget *NOM = lookup_widget(GTK_WIDGET(button),"nomentry");
	strcpy(ETS.nom,gtk_entry_get_text(GTK_ENTRY(NOM)));	
	REGION=lookup_widget(GTK_WIDGET(button),"regioncombobox");
	strcpy(ETS.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(REGION)));
	CAPAC=lookup_widget(GTK_WIDGET(button),"capacspinbutton");
	ETS.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(CAPAC));
	khamsa=lookup_widget(GTK_WIDGET(button),"57radiobutton");
	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(khamsa)))
	ETS.dispo=0;
	else 
	{
		setta=lookup_widget(GTK_WIDGET(button),"67radiobutton");
		if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(setta)))
			ETS.dispo=1;
		else		
		{
			sab3a=lookup_widget(GTK_WIDGET(button),"77radiobutton");
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sab3a)))
			ETS.dispo=2;
		}
	}
	GtkWidget *ADR = lookup_widget(GTK_WIDGET(button),"adrrentry");
	strcpy(ETS.adresse,gtk_entry_get_text(GTK_ENTRY(ADR)));
	GtkWidget *CONT = lookup_widget(GTK_WIDGET(button),"contentry");
	strcpy(ETS.contact,gtk_entry_get_text(GTK_ENTRY(CONT)));	
	/*CR=lookup_widget(GTK_WIDGET(button),"crcheckbutton");
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CR)))
			strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(CR)));
	MSF=lookup_widget(GTK_WIDGET(button),"msfcheckbutton");
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(MSF)))
				strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(MSF)));
	AUTRE=lookup_widget(GTK_WIDGET(button),"autrecheckbutton");
						if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(AUTRE)))
							strcat( ETS.collaborateur, gtk_button_get_label(GTK_BUTTON(AUTRE)));	*/
       CR = lookup_widget(GTK_WIDGET(button), "crcheckbutton");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CR))) 
        ETS.collaborateur[0]=1;
	else 
	    ETS.collaborateur[0]=0;
    

    MSF = lookup_widget(GTK_WIDGET(button), "msfcheckbutton");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(MSF))) 
        ETS.collaborateur[1]=1;
	else
	ETS.collaborateur[1]=0;
    

    AUTRE = lookup_widget(GTK_WIDGET(button), "autrecheckbutton");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(AUTRE))) 
        ETS.collaborateur[2]=1;
else 
ETS.collaborateur[2]=0;
;    
	ajouter_ets("/home/oussamamouldi/ets/etab.txt",ETS,erreur);								
}


void
on_rechbutton_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_suppbutton_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifbutton_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajoutfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonrech_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmod_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_utbuttonsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_utbuttonmod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gestut_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gestetab_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouterdon_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifierdon_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rechdonbutton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_suppdonbutton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_57radiobutton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_67radiobutton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_77radiobutton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_gereretabtreeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_radiobuttonm67_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonm77_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

