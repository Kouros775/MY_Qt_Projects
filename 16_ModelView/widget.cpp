#include "widget.h"
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QVBoxLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600,300);
    QSplitter* splitter = new QSplitter(this);

    QFileSystemModel* model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());

    QTreeView* tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView* list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(splitter);
    setLayout(layout);
}

Widget::~Widget()
{
}
