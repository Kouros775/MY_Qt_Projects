#include "signalslot.h"


void SignalSlot::SetValue(int val)
{
    emit valueChanged(val);
}
