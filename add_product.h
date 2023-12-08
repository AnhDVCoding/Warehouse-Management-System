#ifndef ADD_PRODUCT_H
#define ADD_PRODUCT_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QComboBox>

namespace Ui {
class add_product;
}

class add_product : public QDialog
{
    Q_OBJECT

public:
    explicit add_product(QWidget *parent = nullptr);
    ~add_product();

private slots:
    void on_pb_save_clicked();

    void on_cb_danhmuc_activated(int index);

    void on_pb_cancel_clicked();

private:
    Ui::add_product *ui;
};

#endif // ADD_PRODUCT_H
