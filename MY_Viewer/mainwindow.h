#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class ICommand;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void _addButtonAction();


private slots:
    void _newFile();
    void _open();

private:
    ICommand* commandOpenFile;
    ICommand* commandNewScene;
};

#endif // MAINWINDOW_H
