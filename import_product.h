#ifndef IMPORT_PRODUCT_H
#define IMPORT_PRODUCT_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>

namespace Ui {
class import_product;
}

class import_product : public QDialog
{
    Q_OBJECT

public:
    explicit import_product(QWidget *parent = nullptr);
    ~import_product();

private slots:
    void on_pb_save_clicked();

private:
    Ui::import_product *ui;
};

#endif // IMPORT_PRODUCT_H
