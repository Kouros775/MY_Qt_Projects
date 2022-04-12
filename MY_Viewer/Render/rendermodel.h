#ifndef RENDERMODEL_H
#define RENDERMODEL_H

#include <QString>
#include <memory>


namespace Qt3DRender
{
    class QGeometryRenderer;
}


class RenderModel
{
public:
    explicit RenderModel();
    ~RenderModel();

    void SetName(const QString& paramName) {name = paramName;}
    QString GetName() const {return name;}

    std::shared_ptr<Qt3DRender::QGeometryRenderer> GetMesh() const {return mesh;}

    void MakeTorus(const float& paramRadius, const float& paramMinorRadius, const int& paramRing, const int& paramSlice);

private:
    QString name;
    std::shared_ptr<Qt3DRender::QGeometryRenderer> mesh;
};

#endif // RENDERMODEL_H
