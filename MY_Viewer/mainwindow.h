#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class CommandAddCube;
class CommandAddTorus;
class CommandLoadModel;
class CommandRemoveModel;
class CommandEditModelColor;
class CommandSelectListWidgetItem;
class RenderWidget;
class QListWidget;


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
    void slotSelctListWidget(const int& paramIndex);
    void slotRemoveAllWidget();
private:
    RenderWidget*   renderWidget;
    QListWidget*    listWidget;

    CommandLoadModel*               commandLoadModel;
    CommandRemoveModel*             commandRemoveModel;
    CommandSelectListWidgetItem*    commandSelectWidgetItem;
    CommandEditModelColor*          commandEditModelColor;
    CommandAddTorus*                commandAddTorus;
    CommandAddCube*                 commandAddCube;
};

#endif // MAINWINDOW_H
