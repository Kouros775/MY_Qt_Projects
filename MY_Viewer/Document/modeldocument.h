#ifndef MODELDOCUMENT_H
#define MODELDOCUMENT_H

#include <QObject>
#include <QMap>


namespace Qt3DRender
{
    class QMesh;
}


class ModelDocument : public QObject
{
    Q_OBJECT
public:
    static ModelDocument& Instance()
    {
        static ModelDocument* instance = new ModelDocument();
        return *instance;
    }

    int AddModel(Qt3DRender::QMesh* paramMesh);
    Qt3DRender::QMesh* GetModel(const int& paramIndex) const;

    void SetSelectedIndex(const int& paramIndex){selectedIndex = paramIndex;}
    int GetSelectedIndex() const {return selectedIndex;}

private:
    bool isEmptyIndex(const int& paramIndex) const;


private:
    explicit ModelDocument(QObject *parent = nullptr);

    QMap<int, Qt3DRender::QMesh*> mapMesh;
    int currentIndex;
    int selectedIndex;
};

#endif // MODELDOCUMENT_H
