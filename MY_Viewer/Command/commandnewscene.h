#ifndef COMMANDNEWSCENE_H
#define COMMANDNEWSCENE_H

#include "icommand.h"


class CommandNewScene : public ICommand
{
public:
    CommandNewScene();
    void Execute() override;
};

#endif // COMMANDNEWSCENE_H
