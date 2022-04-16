#include "document.h"

Document::Document(QObject *parent)
    : QObject(parent)
    , addIndex(1)
    , selectedIndex(0)
{

}

Document::~Document()
{

}
