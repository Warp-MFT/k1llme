#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    m_stored_db = QSqlDatabase::addDatabase("QPSQL");
       m_stored_db.setHostName("127.0.0.1");
       m_stored_db.setDatabaseName("my_db");
       m_stored_db.setUserName("postgres");
       m_stored_db.setPassword("postgres");
       m_stored_db.setConnectOptions("connect_timeout=2");
       if (!m_stored_db.open())
       {

       }
       else
       {
           initModels();
       }
}

void DatabaseManager::initModels()
{
    tableModel_car = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_car->setQuery("select * from car_v;");

    tableModel_shipment_status = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_shipment_status->setQuery("select * from shipment_status_v;");

    tableModel_types_payment = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_types_payment->setQuery("select * from types_payment_v;");

    tableModel_customer_type = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_customer_type->setQuery("select * from customer_type_v;");

    tableModel_staff_position = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_staff_position->setQuery("select * from staff_position_v;");

    tableModel_payment_organization = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_payment_organization->setQuery("select * from payment_organization_v;");

    tableModel_product = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_product->setQuery("select * from product_v;");

    tableModel_delivery_point = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_delivery_point->setQuery("select * from delivery_point_v;");

    tableModel_staff = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_staff->setQuery("select * from staff_v;");

    tableModel_customer = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_customer->setQuery("select * from customer_v;");

    tableModel_payment = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_payment->setQuery("select * from payment_v;");

    tableModel_order_info = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_order_info->setQuery("select * from order_info_v;");

    tableModel_order_list = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_order_list->setQuery("select * from order_list_v;");

    tableModel_shipment = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_shipment->setQuery("select * from shipment_v;");

    tableModel_castom = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_castom->setQuery("");

}

QSqlQueryModel *DatabaseManager::getTableModel_shipment() const
{
    return tableModel_shipment;
}

QSqlQueryModel *DatabaseManager::getTableModel_castom(QString qu)
{
    if (tableModel_castom != nullptr)
    {
        delete tableModel_castom;
    }
    tableModel_castom = new QSqlTableModel(nullptr, m_stored_db);
    tableModel_castom->setQuery(qu);
    return tableModel_castom;
}

QSqlQueryModel *DatabaseManager::getTableModel_order_list() const
{
    return tableModel_order_list;
}

QSqlQueryModel *DatabaseManager::getTableModel_order_info() const
{
    return tableModel_order_info;
}

QSqlQueryModel *DatabaseManager::getTableModel_payment() const
{
    return tableModel_payment;
}

QSqlQueryModel *DatabaseManager::getTableModel_customer() const
{
    return tableModel_customer;
}

QSqlQueryModel *DatabaseManager::getTableModel_staff() const
{
    return tableModel_staff;
}

QSqlQueryModel *DatabaseManager::getTableModel_delivery_point() const
{
    return tableModel_delivery_point;
}

QSqlQueryModel *DatabaseManager::getTableModel_product() const
{
    return tableModel_product;
}

QSqlQueryModel *DatabaseManager::getTableModel_payment_organization() const
{
    return tableModel_payment_organization;
}

QSqlQueryModel *DatabaseManager::getTableModel_staff_position() const
{
    return tableModel_staff_position;
}

QSqlQueryModel *DatabaseManager::getTableModel_customer_type() const
{
    return tableModel_customer_type;
}

QSqlQueryModel *DatabaseManager::getTableModel_shipment_status() const
{
    return tableModel_shipment_status;
}

QSqlQueryModel *DatabaseManager::getTableModel_types_payment() const
{
    return tableModel_types_payment;
}

QSqlQueryModel *DatabaseManager::getTableModel_car() const
{
    return tableModel_car;
}
