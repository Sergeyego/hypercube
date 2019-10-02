#include "cubewidget.h"
#include <QApplication>
#include <QtSql>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    FILE *fx;
    const int Nb=200;
    char buff[Nb];
    char srv[24], bd[120], login[20], passwd[20], drv[20];
    int dec;

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/cube.png"));
    fx=fopen("profr.txt","r");
    if(!fx){
        fprintf(stderr,"initial file profr.txt not found\n");
        QMessageBox::information(NULL,QObject::tr("Error"),
        QObject::tr("Initial file profr.txt not found"),QMessageBox::Ok);
        return 1;
    }
    fgets(buff,Nb,fx);
    fgets(buff,Nb,fx);buff[strlen(buff)-1]=0;
    QString head=QObject::tr(buff);
    fgets(buff,Nb,fx);

    fgets(buff,Nb,fx);
    fgets(srv,24,fx); srv[strlen(srv)-1]=0;
    fgets(bd,80,fx);  bd[strlen(bd)-1]=0;
    fgets(drv,20,fx); drv[strlen(drv)-1]=0;
    fgets(login,20,fx);login[strlen(login)-1]=0;
    fgets(passwd,20,fx);passwd[strlen(passwd)-1]=0;
    fgets(buff,Nb,fx);

    QStringList axes;
    fgets(buff,Nb,fx);
    fgets(buff,Nb,fx);buff[strlen(buff)-1]=0;
    while(strncmp(buff,"</a>",4)){
        axes.push_back(QString(QObject::tr(buff)));
        fgets(buff,Nb,fx);buff[strlen(buff)-1]=0;
    }

    QString query;
    fgets(buff,Nb,fx);
    fgets(buff,Nb,fx);buff[strlen(buff)-1]=' ';
    while(strncmp(buff,"</q>",4)){
        query+=QString(QObject::tr(buff))+(QObject::tr(" "));
        fgets(buff,Nb,fx);buff[strlen(buff)-1]=' ';
    }

    fgets(buff,Nb,fx);
    fgets(buff,Nb,fx);buff[strlen(buff)-1]=0;
    dec=atoi(buff);
    fgets(buff,Nb,fx);
    fclose(fx);
    if(bd[0]=='~'){
        char* hm=getenv("HOME");
        char sqlitebd[240];
        strcpy(sqlitebd,hm);
        strcat(sqlitebd,bd+1);
        strcpy(bd,sqlitebd);
     }

    QSqlDatabase db = QSqlDatabase::addDatabase(drv);
    db.setDatabaseName(bd);
    db.setHostName(srv);
    db.setUserName(login);
    db.setPassword(passwd);
    if (!db.open()) {
        QMessageBox::critical(NULL,"Error",db.lastError().text(),QMessageBox::Ok);
        exit(1);
    }
    CubeWidget w(head,axes,query,dec);
    w.show();
    
    return a.exec();
}
