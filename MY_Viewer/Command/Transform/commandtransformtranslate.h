#ifndef COMMANDTRANSFORMTRANSLATE_H
#define COMMANDTRANSFORMTRANSLATE_H

#include "Command/icommand.h"
#include <QVector3D>
#include <QMatrix4x4>


class CommandTransformTranslate : public ICommand
{
    Q_OBJECT
public:
    explicit CommandTransformTranslate(QObject *parent=nullptr);
    ~CommandTransformTranslate() override;

public:
    virtual void Execute() override;
    QMatrix4x4 GetUpdateMatrix() const {return this->updateMatrix;}

    void SetStartWorldPosition(const QVector3D& param){this->startWorldPosition = param;}
    void SetEndWorldPosition(const QVector3D& param){this->endWorldPosition = param;}
private:
    void translate();

private:
    QVector3D  startWorldPosition;
    QVector3D  endWorldPosition;
    QMatrix4x4 updateMatrix;
};

#endif // COMMANDTRANSFORMTRANSLATE_H
