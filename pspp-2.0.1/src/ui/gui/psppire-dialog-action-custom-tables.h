#ifndef __PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H__
#define __PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H__

#include <config.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include "psppire-dialog-action.h"

G_BEGIN_DECLS

#define PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES (psppire_dialog_action_custom_tables_get_type ())
#define PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES, PsppireDialogActionCustomTables))
#define PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES, PsppireDialogActionCustomTablesClass))
#define PSPPIRE_IS_DIALOG_ACTION_CUSTOM_TABLES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES))
#define PSPPIRE_IS_DIALOG_ACTION_CUSTOM_TABLES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES))
#define PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES, PsppireDialogActionCustomTablesClass))

typedef struct _PsppireDialogActionCustomTables PsppireDialogActionCustomTables;
typedef struct _PsppireDialogActionCustomTablesClass PsppireDialogActionCustomTablesClass;

struct _PsppireDialogActionCustomTables {
    PsppireDialogAction parent;
    GtkWidget *variables;
    GtkWidget *create_report_button;
};

struct _PsppireDialogActionCustomTablesClass {
    PsppireDialogActionClass parent_class;
};

GType psppire_dialog_action_custom_tables_get_type (void);

G_END_DECLS

#endif /* __PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H__ */
