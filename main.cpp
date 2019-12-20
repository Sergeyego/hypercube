#include "olap/cubewidget.h"
#include "dialogopen.h"
#include <QApplication>
#include <QtSql>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon.ico"));

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("neo_rtx");
    db.setHostName("192.168.1.10");
    db.setUserName("user");
    db.setPassword("szsm");
    if (!db.open()) {
        QMessageBox::critical(NULL,"Error",db.lastError().text(),QMessageBox::Ok);
        exit(1);
    }

    int id=-1;
    bool ok=false;
    if (argc>1){
        id=QString(argv[1]).toInt(&ok);
    }
    if (!ok){
        DialogOpen d;
        if (d.exec()==QDialog::Accepted){
            id=d.id();
        } else {
            exit(1);
        }
    }

    CubeWidget w(id);
    w.show();

    return a.exec();
}
