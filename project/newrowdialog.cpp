#include "newrowdialog.h"
#include "ui_newrowdialog.h"

NewRowDialog::NewRowDialog(RowContent current, RowContent allVariants, QWidget *parent) : QDialog(parent), ui(new Ui::NewRowDialog)
{
    ui->setupUi(this);
}

NewRowDialog::NewRowDialog(RowContent allVariants, QWidget *parent) : QDialog(parent), ui(new Ui::NewRowDialog)
{
    ui->setupUi(this);
}

RowContent NewRowDialog::getData()
{
}

NewRowDialog::~NewRowDialog()
{
    delete ui;
}

RowContent::RowContent(const QVector<RowElement> &p_rowElements) : rowElements(p_rowElements)
{
}

QVector<RowElement> RowContent::getRowElements() const
{
    return rowElements;
}

RowElement::RowElement(const DisplayOptions &p_option, const QString &p_columnName, const QVector<QPair<int, QString> > &p_values):
    option(p_option), columnName(p_columnName), values(p_values)
{
}
