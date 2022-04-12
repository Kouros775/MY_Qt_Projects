#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class MDIMainWindow;
class QListWidget;

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
    void _newFile();
    void loadModel();

private:
    MDIMainWindow* mdiMainWindow;
    QListWidget*   listWidget;
};

#endif // MAINWINDOW_H
