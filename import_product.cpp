#include "import_product.h"
#include "ui_import_product.h"
#include <QMessageBox>
#include <QStringList>

import_product::import_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::import_product)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");

    QStringList list_product_id, list_product_name, list_supplier_name;
    if(!mydb.open()){
        QMessageBox::information(this, "Database", "Fail connect to Database!");
    }
    else{
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT MaSP, TenSP FROM product");
        for (int i = 0; i < model->rowCount(); i++){
            list_product_id << model->record(i).value("MaSP").toString();
            list_product_name << model->record(i).value("TenSP").toString();
        }

        model->setQuery("SELECT TenNCC FROM supplier");
        for (int i = 0; i < model->rowCount(); i++){
            list_supplier_name << model->record(i).value("TenNCC").toString();
        }
    }


    ui->cb_ncc->addItems(list_supplier_name);
    ui->cb_product->addItems(list_product_name);
}

import_product::~import_product()
{
    delete ui;
}

void import_product::on_pb_save_clicked()
{
    int MaSP = ui->cb_product->currentIndex();
    QMessageBox::information(this, "Database", QString::number(MaSP));

    // QString danhmuc = ui->cb_danhmuc->currentText();
    // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");



    // if(!mydb.open()){
    //     QMessageBox::information(this, "Database", "Fail connect to DB!");
    // }else{
    //     if(tensp == ""){
    //         QMessageBox::information(this, "Error", "Chua nhap ten san pham!");
    //     }
    //     else{
    //         if(!mydb.open()){
    //             QMessageBox::information(this, "Database", "Fail connect to Database!");
    //         }
    //         else{
    //             QSqlQueryModel *model = new QSqlQueryModel;
    //             model->setQuery("INSERT INTO product (TenSP, Danh_muc) VALUES('" + tensp + "', '" + danhmuc + "')");
    //             QMessageBox::information(this, "Them san pham", "Them thanh cong!");
    //         }
    //     }
    // }
}

