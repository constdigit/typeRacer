
#include "startmenu.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startMenu sm;
    sm.setFixedSize(220, 300);
    sm.show();

    return a.exec();
}
