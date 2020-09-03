#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QDir>
#include <QFileDialog>
#include "xlsx/xlsxdocument.h"

using namespace QXlsx;

class TableView : public QTableView
{
        Q_OBJECT
public:

    TableView(QWidget *parent=0);

public slots:
    void resizeToContents();
    void save(QString fnam, int dec=-1, bool fitToHeight=false, Qt::ScreenOrientation orientation=Qt::PortraitOrientation);
};

#endif // TABLEVIEW_H
