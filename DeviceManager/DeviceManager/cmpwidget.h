#ifndef CMPWIDGET_H
#define CMPWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QVector>
#include "xmlwidget.h"

class CMPWidget : public QFrame
{
    Q_OBJECT
public:
    CMPWidget(QWidget *parent = Q_NULLPTR);
public slots:
    void slotCompare();
private:
    QVector<XMLWidget*> mXMLWidgets;
    void build();
    bool compare(const QVector<QString> &filenames);
};

#endif // CMPWIDGET_H
