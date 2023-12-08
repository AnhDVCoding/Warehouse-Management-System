#include "add_product.h"
#include "ui_add_product.h"
#include <QMessageBox>
#include <QStringList>
// #include <QSqlQuery>

add_product::add_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_product)
{
    ui->setupUi(this);


    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");

    QStringList list_category;
    if(!mydb.open()){
        QMessageBox::information(this, "Database", "Fail connect to Database!");
    }
    else{
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT name FROM category");
        for (int i = 0; i < model->rowCount(); i++){
            list_category << model->record(i).value("name").toString();
        }
        // model->setQuery("SELECT MaSP FROM product ORDER BY MaSP DESC LIMIT 1");
        // int latest_id = model->record(0).value('MaSP').toInt();

    }

    QSqlQuery query;
    query.prepare("SELECT MaSP FROM product ORDER BY MaSP DESC LIMIT 1");
    query.exec();
    ui->le_msp->setText(query.record().value("MaSP").toString());

    ui->cb_danhmuc->addItems(list_category);
}

add_product::~add_product()
{
    delete ui;
}

void add_product::on_pb_save_clicked()
{
    QString tensp = ui->le_tensp->text();

    QString danhmuc = ui->cb_danhmuc->currentText();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");



    if(!mydb.open()){
        QMessageBox::information(this, "Database", "Fail connect to DB!");
    }else{
        if(tensp == ""){
            QMessageBox::information(this, "Error", "Chua nhap ten san pham!");
        }
        else{
            if(!mydb.open()){
                QMessageBox::information(this, "Database", "Fail connect to Database!");
            }
            else{
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("INSERT INTO product (TenSP, Danh_muc) VALUES('" + tensp + "', '" + danhmuc + "')");
                QMessageBox::information(this, "Them san pham", "Them thanh cong!");
            }
        }
    }
}


void add_product::on_cb_danhmuc_activated(int index)
{

}


void add_product::on_pb_cancel_clicked()
{
    close();
}

