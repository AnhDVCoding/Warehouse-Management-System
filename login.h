#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "overview.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pb_login_clicked();

private:
    Ui::login *ui;
    overview *overview;
};

#endif // LOGIN_H
