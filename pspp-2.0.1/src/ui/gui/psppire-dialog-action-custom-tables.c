#include <config.h>
#include "psppire-dialog-action-custom-tables.h"
#include "builder-wrapper.h"

static void psppire_dialog_action_custom_tables_init (PsppireDialogActionCustomTables *act);
static void psppire_dialog_action_custom_tables_class_init (PsppireDialogActionCustomTablesClass *class);

G_DEFINE_TYPE (PsppireDialogActionCustomTables, psppire_dialog_action_custom_tables, PSPPIRE_TYPE_DIALOG_ACTION);

static void
on_create_report_button_clicked (GtkButton *button, PsppireDialogActionCustomTables *act)
{

    GString *syntax = g_string_new ("/VLABELS VARIABLES= ФО M1_Контр1_Пол M2_Контр2_Возраст DISPLAY=LABEL\n");
    g_string_append (syntax, "/TABLE BY ФО > M1_Контр1_Пол > M2_Контр2_Возраст.\n");

    g_print ("PSPP Syntax: %s", syntax->str);

}

static GtkBuilder *
psppire_dialog_action_custom_tables_activate (PsppireDialogAction *a, GVariant *param)
{
    PsppireDialogAction *pda = PSPPIRE_DIALOG_ACTION (a);

        GtkBuilder *xml = builder_new ("custom-tables.ui");

        pda->dialog = get_widget_assert (xml, "custom-tables-dialog");

        GtkWidget *create_report_button = get_widget_assert (xml, "create-report-button");
        g_signal_connect (create_report_button, "clicked", G_CALLBACK (on_create_report_button_clicked), a);

        return xml;
}

static void
psppire_dialog_action_custom_tables_class_init (PsppireDialogActionCustomTablesClass *class)
{
    PsppireDialogActionClass *pdac = PSPPIRE_DIALOG_ACTION_CLASS (class);
    pdac->initial_activate = psppire_dialog_action_custom_tables_activate;
}

static void
psppire_dialog_action_custom_tables_init (PsppireDialogActionCustomTables *act)
{
}

