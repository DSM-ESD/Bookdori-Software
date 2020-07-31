#include "bookeyes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookEyes w;
    w.show();
    return a.exec();
}
