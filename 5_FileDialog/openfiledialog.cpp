#include "openfiledialog.h"
#include <QFileDialog>

OpenFileDialog::OpenFileDialog(QWidget *parent)
    : QWidget(parent)
{

}

void OpenFileDialog::_openFileDialog()
{
    QFileDialog::Options options;
    options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    options |= QFileDialog::DontUseNativeDialog;
    QString directory = QFileDialog::getExistingDirectory(this,
     "파일 다이얼로그", "C:", options);
}
