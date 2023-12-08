#include "add_category.h"
#include "ui_add_category.h"
#include <QMessageBox>
#include <QStringList>

add_category::add_category(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_category)
{
    ui->setupUi(this);
}

add_category::~add_category()
{
    delete ui;
}

void add_category::on_pb_save_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/anhdv/Documents/Warehouse-Management-System/warehouse-sqlite.db");

    QString tenDM = ui->le_category_name->text();
    QString mo_ta = ui->te_description->toPlainText();

    if(!mydb.open()){
        QMessageBox::information(this, "Database", "Fail connect to DB!");
    }else{
        if(tenDM == ""){
            QMessageBox::information(this, "Error", "Chua nhap ten danh muc!");
        }
        else{
            if(!mydb.open()){
                QMessageBox::information(this, "Database", "Fail connect to Database!");
            }
            else{
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("INSERT INTO category (name, description) VALUES('" + tenDM + "', '" + mo_ta + "')");
                QMessageBox::information(this, "Them danh muc", "Them thanh cong!");
            }
        }
    }
}


void add_category::on_pb_cancel_clicked()
{
    close();
}

