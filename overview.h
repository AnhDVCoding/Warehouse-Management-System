#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QMainWindow>
#include "add_category.h"
#include "add_product.h"
#include "add_supplier.h"
#include "import_product.h"
#include "profile.h"
#include "setpermission.h"

namespace Ui {
class overview;
}

class overview : public QMainWindow
{
    Q_OBJECT

public:
    explicit overview(QWidget *parent = nullptr);
    ~overview();

private slots:
    void on_action_profile_triggered();

    void on_actionSetPermission_triggered();

    void on_action_add_product_triggered();

    void on_action_add_category_triggered();

    void on_action_import_goods_triggered();

    void on_action_supplier_triggered();

private:
    Ui::overview *ui;
    profile *profile;
    setpermission *setpermission;
    add_product *add_product;
    add_category *add_category;
    import_product *import_product;
    add_supplier *add_supplier;
};

#endif // OVERVIEW_H
