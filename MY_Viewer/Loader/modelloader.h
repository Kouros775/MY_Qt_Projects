#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <QString>

class RenderModel;

class ModelLoader
{
public:
    ModelLoader();

    static bool LoadModel(const QString& path, RenderModel* outRenderModel);
};

#endif // MODELLOADER_H
