#ifndef ICOMMAND_H
#define ICOMMAND_H


class ICommand
{
public:
    ICommand() = default;
    virtual ~ICommand() = default;

public:
    virtual void Execute() = 0;

};

#endif // ICOMMAND_H
