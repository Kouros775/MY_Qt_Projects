#ifndef MODELLISTWIDGETITEM_H
#define MODELLISTWIDGETITEM_H


#include <QListWidgetItem>
#include <QObject>


class ModelListWidgetItem : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit ModelListWidgetItem(const QIcon &icon, const QString &text,
                             QListWidget *view = nullptr, int type = Type);
    ~ModelListWidgetItem() override;

    void SetIndex(const int& paramIndex){index = paramIndex;}
    int GetIndex() const {return index;}

    void SetName(const QString& paramName){name = paramName;}
    QString GetName() const {return name;}
private:
    int index;
    QString name;
};

#endif // MODELLISTWIDGETITEM_H
