#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void addTorus();
    void addCommands();
    void connectSignalSlot();
private slots:
    void newScene();
    void loadModel(Qt3DRender::QMesh* paramMesh);
    void deleteModel();

    void itemPressed(QListWidgetItem *item);

signals:
    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    void RemoveModel(const int& paramIndex);
    void SelectModel(const int& paramindex);
private:
    RenderWidget*   renderWidget;
    QListWidget*    listWidget;
    int             currentIndex;

    CommandLoadModel*       commandLoadModel;
};

#endif // MAINWINDOW_H
