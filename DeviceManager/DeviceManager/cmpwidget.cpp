#include <QHBoxLayout>
#include <QFileDialog>
#include "cmpwidget.h"
#include "xmlprocessor.h"

CMPWidget::CMPWidget(QWidget *parent)
    :QFrame(parent)
{
    mXMLWidgets.push_back(new XMLWidget(this));
    mXMLWidgets.push_back(new XMLWidget(this));
    for(auto widget : mXMLWidgets)
        widget->setEditable(false);

    build();
    QVector<QString> filenames;
    filenames.push_back(":/res/res/xml_new_format.xml");
    filenames.push_back(":/res/res/xml_source_format.xml");
    compare(filenames);
}

void CMPWidget::slotCompare()
{
    QVector<QString> filenames(2);
    for(int i=0; i<2;++i)
    {
        filenames[i] = QFileDialog::getOpenFileName(this, "Open file", mXMLWidgets[i]->getCurFileName(), "files(*.xml )");
        if(filenames[i].isEmpty())
            return;
    }
    compare(filenames);
}
void CMPWidget::build()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    for(auto widget : mXMLWidgets)
        mainLayout->addWidget(widget);

    mainLayout->setMargin(2);
    mainLayout->setSpacing(4);
}

bool CMPWidget::compare(const QVector<QString> &filenames)
{
    QVector<TreeItem*> rootItems;
    for(int i=0;i<2;++i)
    {
        rootItems.push_back(new TreeItem());
        XMLProcessor::Load(filenames[i],rootItems[i]);
        mXMLWidgets[i]->setModelData(filenames[i],rootItems[i]);
    }
}

