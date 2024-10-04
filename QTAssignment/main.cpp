#include <QApplication>
#include "loginwindow.h"

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Initialize the LoginWindow
    LoginWindow loginWindow;
    loginWindow.show();

    // Run the application
    return app.exec();
}
