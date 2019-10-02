#ifndef PARTVIEWER_H
#define PARTVIEWER_H

#include <QtGui>
#include <xlslib.h>
#include <QTableView>
#include <QHeaderView>
#include <QFileDialog>

using namespace xlslib_core;

class Viewer : public QTableView
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
    void saveXls(QString title);

public slots:
    void resizeToContents();

private:
    void setXlsBorder(cell_t *cref);
};

#endif // PARTVIEWER_H
