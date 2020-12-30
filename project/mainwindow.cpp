#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newrowdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    loadTablesList();
    changeCurrentTable(ui->comboBox_select_table->currentText());
    connect(ui->comboBox_select_table, &QComboBox::currentTextChanged, this, &MainWindow::changeCurrentTable);
    connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::updateRow);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::doCastom);
    this->setWindowTitle("---");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTablesList()
{
    for (auto el: tablesList.keys())
    {
        ui->comboBox_select_table->insertItem(-1, QString("%1, %2, %3").arg(el).arg(tablesList[el].first).arg(tablesList[el].second));
    }
}

void MainWindow::changeCurrentTable(const QString &currentText)
{
   switch (currentTable())
   {
   case TablesNames::CAR :
   {
       ui->tableView->setModel(test.getTableModel_car());
       break;
   }
   case TablesNames::TYPES_PAYMENT :
   {
       ui->tableView->setModel(test.getTableModel_types_payment());
       break;
   }
   case TablesNames::SHIPMENT_STATUS :
   {
       ui->tableView->setModel(test.getTableModel_shipment_status());
       break;
   }
   case TablesNames::CUSTOMER_TYPE :
   {
       ui->tableView->setModel(test.getTableModel_customer_type());
       break;
   }
   case TablesNames::STAFF_POSITION :
   {
       ui->tableView->setModel(test.getTableModel_staff_position());
       break;
   }
   case TablesNames::PAYMENT_ORGANIZATION :
   {
       ui->tableView->setModel(test.getTableModel_payment_organization());
       break;
   }
   case TablesNames::PRODUCT :
   {
       ui->tableView->setModel(test.getTableModel_product());
       break;
   }
   case TablesNames::DELIVERY_POINT :
   {
       ui->tableView->setModel(test.getTableModel_delivery_point());
       break;
   }
   case TablesNames::STAFF :
   {
       ui->tableView->setModel(test.getTableModel_staff());
       break;
   }
   case TablesNames::CUSTOMER :
   {
       ui->tableView->setModel(test.getTableModel_customer());
       break;
   }
   case TablesNames::PAYMENT :
   {
       ui->tableView->setModel(test.getTableModel_payment());
       break;
   }
   case TablesNames::ORDER_INFO :
   {
       ui->tableView->setModel(test.getTableModel_order_info());
       break;
   }
   case TablesNames::ORDER_LIST :
   {
       ui->tableView->setModel(test.getTableModel_order_list());
       break;
   }
   case TablesNames::SHIPMENT :
   {
       ui->tableView->setModel(test.getTableModel_shipment());
       break;
   }
   }
   ui->tableView->update();
   ui->tableView->resizeColumnsToContents();
}

void MainWindow::updateRow(const QModelIndex &index)
{
}

void MainWindow::createNewRow()
{

//    NewRowDialog rowDialog;
//    if(rowDialog.exec() == QDialog::Accepted)
//    {

//    }
//    else
//    {
//        return;
//    }
}

TablesNames MainWindow::currentTable()
{
    QStringList rawTable = ui->comboBox_select_table->currentText().split(", ");
    TablesNames tableNumber = (TablesNames)rawTable[0].toInt();
    QString tableName = rawTable[1];
    QString tableTitle = rawTable[2];
    return tableNumber;
}

void MainWindow::doCastom()
{
    ui->tableView_2->setModel(test.getTableModel_castom(ui->textEdit->toPlainText()));
    ui->tableView_2->update();
    ui->tableView_2->resizeColumnsToContents();
}
