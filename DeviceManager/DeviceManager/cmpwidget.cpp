#include "cmpwidget.h"
#include <QHBoxLayout>

CMPWidget::CMPWidget(QWidget *parent)
    :QFrame(parent)
{
    mXMLWidgets.push_back(new XMLWidget(this));
    mXMLWidgets.push_back(new XMLWidget(this));
    for(auto widget : mXMLWidgets)
        widget->setEditable(false);

    build();
}
void CMPWidget::build()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    for(auto widget : mXMLWidgets)
        mainLayout->addWidget(widget);

    mainLayout->setMargin(2);
    mainLayout->setSpacing(4);
}

