#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class RenderWidget;
class QListWidget;
class QListWidgetItem;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addWidgets();


private slots:
    void newScene();
    void loadModel();
    void deleteModel();

    void itemPressed(QListWidgetItem *item);
private:
    RenderWidget*  renderWidget;
    QListWidget*   listWidget;
};

#endif // MAINWINDOW_H
