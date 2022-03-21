#ifndef OPENFILEDIALOG_H
#define OPENFILEDIALOG_H

#include <QWidget>


class OpenFileDialog : public QWidget
{
    Q_OBJECT
public:
    explicit OpenFileDialog(QWidget *parent = nullptr);

signals:

public slots:
    void _openFileDialog();
};

#endif // OPENFILEDIALOG_H
