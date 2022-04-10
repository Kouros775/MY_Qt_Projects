#ifndef RENDERMODEL_H
#define RENDERMODEL_H

#include <QString>
#include <QVector>
#include <QVector3D>

class RenderModel
{
public:
    explicit RenderModel();
    ~RenderModel();

    void DeepCopy(const RenderModel& paramModel);

    void SetName(const QString& paramName) {name = paramName;}
    QString GetName() const {return name;}

    QVector<QVector3D> GetVertices() const {return vertices;}


    void TempFunction();
private:
    QString name;
    QVector<QVector3D> vertices;
};

#endif // RENDERMODEL_H
