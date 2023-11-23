/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *authentification;
  GtkWidget *Gestion_des_etablissement;
  GtkWidget *Gestion_fichedonneur;
  GtkWidget *Gestion_utilisateur;
  GtkWidget *paneauAdmin;
  GtkWidget *Gestion_des_dons;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*authentification = create_authentification ();
  gtk_widget_show (authentification);*/
  Gestion_des_etablissement = create_Gestion_des_etablissement ();
  gtk_widget_show (Gestion_des_etablissement);
 /* Gestion_fichedonneur = create_Gestion_fichedonneur ();
  gtk_widget_show (Gestion_fichedonneur);
  Gestion_utilisateur = create_Gestion_utilisateur ();
  gtk_widget_show (Gestion_utilisateur);
  paneauAdmin = create_paneauAdmin ();
  gtk_widget_show (paneauAdmin);
  Gestion_des_dons = create_Gestion_des_dons ();
  gtk_widget_show (Gestion_des_dons);*/

  gtk_main ();
  return 0;
}

