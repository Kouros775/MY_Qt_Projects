#include "checkboxheader.h"
#include <QHeaderView>
#include <QPainter>


CheckBoxHeader::CheckBoxHeader(Qt::Orientation orientation, QWidget* parent)
    : QHeaderView (orientation, parent)
    , _isChecked(true)
{
}

void CheckBoxHeader::SetIsChecked(bool param)
{
    if(_isChecked != param)
    {
        _isChecked = param;
        redrawCheckBox();
    }
}


void CheckBoxHeader::redrawCheckBox()
{
    viewport()->update();
}

void CheckBoxHeader::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if(logicalIndex == 0)
    {
        QStyleOptionButton option;
        option.rect = QRect(1, 3, 20, 20);
        option.state = QStyle::State_Enabled | QStyle::State_Active;

        if(_isChecked)
        {
            option.state |= QStyle::State_On;
        }
        else
        {
            option.state |= QStyle::State_Off;
        }

        option.state |= QStyle::State_Off;
        style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
    }
}

void CheckBoxHeader::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    SetIsChecked(_isChecked);

    emit checkBoxClicked(_isChecked);
}

