#ifndef COMMANDOPENFILE_H
#define COMMANDOPENFILE_H

#include "icommand.h"


class RenderModel;


class CommandOpenFile : public ICommand
{
public:
    CommandOpenFile();

    void Execute() override;

signals:
    bool AddModel(const RenderModel& paramModel);
};

#endif // COMMANDOPENFILE_H
