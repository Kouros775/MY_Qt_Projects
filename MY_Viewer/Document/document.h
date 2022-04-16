#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>

class Document : public QObject
{
    Q_OBJECT
public:
    static Document& Instance()
    {
        static Document instance;
        return instance;
    }

    void SetAddIndex(const int& paramIndex){this->addIndex = paramIndex;}
    int GetAddIndex() const {return this->addIndex;}

    void SetSelectedIndex(const int& paramIndex){this->selectedIndex = paramIndex;}
    int GetSelectedIndex() const {return this->selectedIndex;}
private:
    explicit Document(QObject *parent = nullptr);
    ~Document();

private:
    int     addIndex;
    int     selectedIndex;
};

#endif // DOCUMENT_H
