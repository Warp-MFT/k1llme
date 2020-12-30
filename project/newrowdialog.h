#ifndef NEWROWDIALOG_H
#define NEWROWDIALOG_H

#include <QDialog>

namespace Ui {
class NewRowDialog;
}
enum DisplayOptions
{
    USERS_TEXT = 1,
    COMBO = 2,
    DATE = 3,
    TIME = 4,
    DATE_TIME = 5,
    NUMBER_INT = 6,
    NUMBER_DOUBLE = 7,
    SELECT_VALUES = 8
};

class RowElement
{
    RowElement(const DisplayOptions &p_option, const QString &p_columnName, const QVector<QPair<int, QString>> &p_values);
    const DisplayOptions option;
    const QString columnName;
    const QVector<QPair<int, QString>> values;
};

class RowContent
{
public:
    RowContent(const QVector<RowElement> &p_rowElements);
    QVector<RowElement> getRowElements() const;
private:
    const QVector<RowElement> rowElements;
};

class NewRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewRowDialog(RowContent current, RowContent allVariants, QWidget *parent = nullptr);
    explicit NewRowDialog(RowContent allVariants, QWidget *parent = nullptr);
    RowContent getData();
    ~NewRowDialog();

private:
    Ui::NewRowDialog *ui;
};

#endif // NEWROWDIALOG_H
