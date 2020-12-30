#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMap>

#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum TablesNames
{
    CAR = 1,
    TYPES_PAYMENT = 2,
    SHIPMENT_STATUS = 3,
    CUSTOMER_TYPE = 4,
    STAFF_POSITION = 5,
    PAYMENT_ORGANIZATION = 6,
    PRODUCT = 7,
    DELIVERY_POINT = 8,
    STAFF = 9,
    CUSTOMER = 10,
    PAYMENT = 11,
    ORDER_INFO = 12,
    ORDER_LIST = 13,
    SHIPMENT = 14
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void loadTablesList();
    void changeCurrentTable(const QString & currentText);
    void updateRow(const QModelIndex &index);
    void createNewRow();
    TablesNames currentTable();
    void doCastom();

    Ui::MainWindow *ui;
    QMap<TablesNames, QPair<QString, QString>> tablesList =
    {
        {TablesNames::CAR, {"car", "Транспорт"}},
        {TablesNames::TYPES_PAYMENT, {"types_payment", "Типы оплаты"}},
        {TablesNames::SHIPMENT_STATUS, {"shipment_status", "Статусы заказа"}},
        {TablesNames::CUSTOMER_TYPE, {"customer_type", "Лицо"}},
        {TablesNames::STAFF_POSITION, {"staff_position", "Должности"}},
        {TablesNames::PAYMENT_ORGANIZATION, {"payment_organization", "Платёжные организации"}},
        {TablesNames::PRODUCT, {"product", "Товары"}},
        {TablesNames::DELIVERY_POINT, {"delivery_point", "Точки доставки"}},
        {TablesNames::STAFF, {"staff", "Сотрудники"}},
        {TablesNames::CUSTOMER, {"customer", "Покупатели"}},
        {TablesNames::PAYMENT, {"payment", "Квитанции оплаты"}},
        {TablesNames::ORDER_INFO, {"order_info", "Заказы"}},
        {TablesNames::ORDER_LIST, {"order_list", "---"}},
        {TablesNames::SHIPMENT, {"shipment", "График поставок"}},
    };
    DatabaseManager test;
};
#endif // MAINWINDOW_H
