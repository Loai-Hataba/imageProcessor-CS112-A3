#include "photoshop_budget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Photoshop_budget w;
    w.show();
    return a.exec();
}
