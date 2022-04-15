#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include <QMap>


namespace Qt3DCore
{
    class QEntity;
}


class MeshModel;


class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    ~RenderBase();
    Qt3DCore::QEntity* Initialize();

    bool AddModel(const int& paramIndex, MeshModel* paramModel);
    bool RemoveModel(const int& paramIndex);
    bool IsEmptyIndex(const int& paramIndex) const;

    MeshModel* GetModel(const int& paramIndex) const;
    QMap<int, MeshModel*>* GetModelMap();

private:
    Qt3DCore::QEntity*                  rootEntity;
    QMap<int, MeshModel*>               modelMap;
};

#endif // RENDERBASE_H
