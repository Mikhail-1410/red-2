//#include <config.h>
#include "psppire-dialog-action-custom-tables.h"
#include "dialog-common.h"
#include <ui/syntax-gen.h>
#include "builder-wrapper.h"
#include "psppire-dialog.h"

static void psppire_dialog_action_custom_tables_class_init (PsppireDialogActionCustomTablesClass *class);
G_DEFINE_TYPE (PsppireDialogActionCustomTables, psppire_dialog_action_custom_tables, PSPPIRE_TYPE_DIALOG_ACTION);

static GtkBuilder* psppire_dialog_action_custom_tables_activate (PsppireDialogAction *a, GVariant *param) {
    GtkBuilder *xml = builder_new ("custom-tables.ui");
    PsppireDialogAction *pda = PSPPIRE_DIALOG_ACTION (a);
    pda->dialog = get_widget_assert (xml, "custom-tables-dialog");
    GtkWidget *create_report_button = get_widget_assert (xml, "create-report-button");
    g_signal_connect (create_report_button, "clicked", G_CALLBACK (on_create_report_button_clicked), a);
    return xml;
}

static char* generate_syntax (const PsppireDialogAction *a) {
    return g_strdup ("/VLABELS VARIABLES= ФО M1_Контр1_Пол M2_Контр2_Возраст DISPLAY=LABEL\n"
                     "/TABLE BY ФО > M1_Контр1_Пол > M2_Контр2_Возраст.");
}

static void on_create_report_button_clicked (GtkButton *button, gpointer user_data) {
    PsppireDialogAction *a = PSPPIRE_DIALOG_ACTION (user_data);
    char *syntax = generate_syntax (a);
    psppire_append_syntax (syntax);
    g_free (syntax);
}

static void psppire_dialog_action_custom_tables_class_init (PsppireDialogActionCustomTablesClass *class) {
    PSPPIRE_DIALOG_ACTION_CLASS (class)->initial_activate = psppire_dialog_action_custom_tables_activate;
    PSPPIRE_DIALOG_ACTION_CLASS (class)->generate_syntax = generate_syntax;
}

static void psppire_dialog_action_custom_tables_init (PsppireDialogActionCustomTables *act) {}
