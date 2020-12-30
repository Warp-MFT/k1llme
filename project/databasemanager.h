#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QTableView>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    bool openConnection();
    bool closeConnection();
    QSqlQueryModel *getTableModel_car() const;
    QSqlQueryModel *getTableModel_types_payment() const;
    QSqlQueryModel *getTableModel_shipment_status() const;
    QSqlQueryModel *getTableModel_customer_type() const;
    QSqlQueryModel *getTableModel_staff_position() const;
    QSqlQueryModel *getTableModel_payment_organization() const;
    QSqlQueryModel *getTableModel_product() const;
    QSqlQueryModel *getTableModel_delivery_point() const;
    QSqlQueryModel *getTableModel_staff() const;
    QSqlQueryModel *getTableModel_customer() const;
    QSqlQueryModel *getTableModel_payment() const;
    QSqlQueryModel *getTableModel_order_info() const;
    QSqlQueryModel *getTableModel_order_list() const;
    QSqlQueryModel *getTableModel_shipment() const;
    QSqlQueryModel *getTableModel_castom(QString qu);

private:
    void initModels();

    QSqlQueryModel *tableModel_car;
    QSqlQueryModel *tableModel_types_payment;
    QSqlQueryModel *tableModel_shipment_status;
    QSqlQueryModel *tableModel_customer_type;
    QSqlQueryModel *tableModel_staff_position;
    QSqlQueryModel *tableModel_payment_organization;
    QSqlQueryModel *tableModel_product;
    QSqlQueryModel *tableModel_delivery_point;
    QSqlQueryModel *tableModel_staff;
    QSqlQueryModel *tableModel_customer;
    QSqlQueryModel *tableModel_payment;
    QSqlQueryModel *tableModel_order_info;
    QSqlQueryModel *tableModel_order_list;
    QSqlQueryModel *tableModel_shipment;
    QSqlQueryModel *tableModel_castom;

    QSqlDatabase m_stored_db;

signals:

};

#endif // DATABASEMANAGER_H
