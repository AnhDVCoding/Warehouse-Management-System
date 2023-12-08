#include "add_supplier.h"
#include "ui_add_supplier.h"
#include <QMessageBox>
#include <QStringList>

add_supplier::add_supplier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_supplier)
{
    ui->setupUi(this);
}

add_supplier::~add_supplier()
{
    delete ui;
}

void add_supplier::on_pushButton_2_clicked()
{
    close();
}


void add_supplier::on_pushButton_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");

    QString tenNCC = ui->le_tenNCC->text();
    QString diaChi = ui->le_dia_chi->text();

    if(!mydb.open()){
        QMessageBox::information(this, "Database", "Fail connect to DB!");
    }else{
        if(tenNCC == ""){
            QMessageBox::information(this, "Error", "Chua nhap ten nha cung cap!");
        }
        else{
            if(!mydb.open()){
                QMessageBox::information(this, "Database", "Fail connect to Database!");
            }
            else{
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("INSERT INTO supplier (TenNCC, DiaChi) VALUES('" + tenNCC + "', '" + diaChi + "')");
                QMessageBox::information(this, "Them nha cung cap", "Them thanh cong!");
            }
        }
    }
}

