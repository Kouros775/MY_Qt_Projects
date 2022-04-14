#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class MDIMainWindow;
class QListWidget;
class QListWidgetItem;


namespace Qt3DRender
{
    class QMesh;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addButtons();


private slots:
    void loadModel();
    void deleteModel();

    void itemPressed(QListWidgetItem *item);
private:
    MDIMainWindow* mdiMainWindow;
    QListWidget*   listWidget;
};

#endif // MAINWINDOW_H
