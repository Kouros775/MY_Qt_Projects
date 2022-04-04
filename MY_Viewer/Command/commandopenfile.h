#ifndef COMMANDOPENFILE_H
#define COMMANDOPENFILE_H

#include "icommand.h"


class CommandOpenFile : public ICommand
{
public:
    CommandOpenFile();

    void Execute() override;
};

#endif // COMMANDOPENFILE_H
