#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <QString>


class ModelLoader
{
public:
    ModelLoader();

    static bool LoadModel(const QString path);
};

#endif // MODELLOADER_H
