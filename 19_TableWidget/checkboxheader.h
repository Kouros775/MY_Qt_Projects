#ifndef CHECKBOXHEADER_H
#define CHECKBOXHEADER_H

#include <QHeaderView>


class QPainter;
class QRect;
class QMouseEvent;


class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT
public:
    CheckBoxHeader(Qt::Orientation orientation, QWidget* parent = nullptr);

    bool IsChecked() const {return _isChecked;}
    void SetIsChecked(bool param);

signals:
    void checkBoxClicked(bool stats);

protected:
    virtual void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override;
    virtual void mousePressEvent(QMouseEvent* event) override;

private:
    bool _isChecked;
    void redrawCheckBox();
};

#endif // CHECKBOXHEADER_H
