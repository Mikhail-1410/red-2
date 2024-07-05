#ifndef PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H
#define PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H

#include "psppire-dialog-action.h"

G_BEGIN_DECLS

#define PSPPIRE_TYPE_DIALOG_ACTION_CUSTOM_TABLES (psppire_dialog_action_custom_tables_get_type ())
G_DECLARE_FINAL_TYPE (PsppireDialogActionCustomTables, psppire_dialog_action_custom_tables, PSPPIRE, DIALOG_ACTION_CUSTOM_TABLES, PsppireDialogAction)

struct _PsppireDialogActionCustomTablesClass
{
  PsppireDialogActionClass parent_class;
};

struct _PsppireDialogActionCustomTables
{
  PsppireDialogAction parent_instance;
};

G_END_DECLS

#endif /* PSPPIRE_DIALOG_ACTION_CUSTOM_TABLES_H */
