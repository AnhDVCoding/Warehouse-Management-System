#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_login_clicked()
{
    QString username = ui->le_username->text();
    QString password = ui->le_password->text();

    if(username != "anhdv"){
        QMessageBox::warning(this, "Login", "Ten nguoi dung khong ton tai!");
    }else{
        if(password != "123456"){
            QMessageBox::warning(this, "Login", "Mat khau khong dung!");
        }else{
            QMessageBox::information(this, "Login", "Dang nhap thanh cong!");
            hide();
            overview = new class overview(this);
            overview->show();
        }
    }
}

