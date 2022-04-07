#ifndef RENDERBASE_H
#define RENDERBASE_H


class RenderModel;
class QMatrix4x4;

#include <QMap>

class RenderBase
{
public:
    RenderBase();

    void Init();
    void Paint();
    void Resize(const int& width, const int& height);
    bool AddModel(const RenderModel& paramModel, const int& paramIndex);
    bool SetTransformMatrix(const QMatrix4x4& paramMatrix, const int& paramIndex);
    void GetTransformMatrix(QMatrix4x4& outMatrix);
    bool ApplyTransformMatrix(const QMatrix4x4& paramMatrix, const int& paramIndex);
    bool IsEmptyModelIndex(const int& paramIndex);

    void GetViewMatrix(QMatrix4x4& outViewMatrix) const ;
    void GetProjectionMatrix(QMatrix4x4& outProjectionMatrix) const;

private:
    QMap<int, RenderModel*> renderMap;
};

#endif // RENDERBASE_H
