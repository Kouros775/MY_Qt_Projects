#ifndef COMMANDOPENFILE_H
#define COMMANDOPENFILE_H


#include "icommand.h"


class CommandOpenFile : public ICommand
{
public:
    CommandOpenFile();

    virtual void Execute() final;
};

#endif // COMMANDOPENFILE_H
