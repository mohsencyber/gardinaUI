#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //qputenv("QT_IM_MODULE",QByteArray("qtvirtualkeyboard"));
    //qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));

    //qputenv("QT_VIRTUALKEYBOARD_STYLE", QByteArray("retro"));
    QApplication a(argc, argv);
    MainWindow w;

    a.setOverrideCursor( QCursor( Qt::BlankCursor ) );

    w.show();
    return a.exec();
}
