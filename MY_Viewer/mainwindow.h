#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

using namespace std;

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
    shared_ptr<RenderWidget>  renderWidget;
    QListWidget*   listWidget;
    int             currentIndex;
};

#endif // MAINWINDOW_H
