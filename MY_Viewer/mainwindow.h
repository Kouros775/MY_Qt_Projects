#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CommandRemoveModel;
class CommandLoadModel;
class RenderWidget;
class QListWidget;
class QListWidgetItem;
namespace Qt3DRender
{
    class QGeometryRenderer;
    class QMesh;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addToolBarActions();
    void addListWidget();
    void addRenderWidget();
    void addCommands();

private slots:


    void itemPressed(QListWidgetItem *item);

signals:
    void SelectModel(const int& paramindex);

private:
    RenderWidget*   renderWidget;
    QListWidget*    listWidget;


    CommandLoadModel*       commandLoadModel;
    CommandRemoveModel*     commandRemoveModel;
};

#endif // MAINWINDOW_H
