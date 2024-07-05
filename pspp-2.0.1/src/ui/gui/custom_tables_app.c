#include <gtk/gtk.h>

// Функция обратного вызова для кнопки
static void on_create_report_button_clicked(GtkButton *button, gpointer user_data) {
    const char *command = "/VLABELS VARIABLES= ФО M1_Контр1_Пол M2_Контр2_Возраст DISPLAY=LABEL\n"
                          "/TABLE BY ФО > M1_Контр1_Пол > M2_Контр2_Возраст.\n";

    // Вывод команды в консоль (можно заменить на отправку в PSPPIRE Output Viewer)
    g_print("%s\n", command);

    // Завершение приложения
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    // Создание основного окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Custom Tables");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Создание кнопки
    button = gtk_button_new_with_label("Создать отчет");
    g_signal_connect(button, "clicked", G_CALLBACK(on_create_report_button_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    // Показать все виджеты в окне
    gtk_widget_show_all(window);

    // Обработка сигнала "delete-event" для завершения приложения
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    // Запуск главного цикла GTK
    gtk_main();

    return 0;
}
