#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <openfiledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _pDialog = new OpenFileDialog();

    connect(ui->pushButton, &QPushButton::clicked, _pDialog, &OpenFileDialog::_openFileDialog);


}

MainWindow::~MainWindow()
{
    delete ui;
}
