#include "combat.h"
#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Interface interf;
    interf.show();

    return app.exec();
}
