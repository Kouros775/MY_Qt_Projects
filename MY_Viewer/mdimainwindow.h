#ifndef MDIMAINWINDOW_H
#define MDIMAINWINDOW_H

#include <QMainWindow>
#include <memory>

class RenderModel;
class RenderWidget;


class MDIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void AddModel(const RenderModel* paramModel);

private:
    std::shared_ptr<RenderWidget> renderWidget;
};

#endif // MDIMAINWINDOW_H
