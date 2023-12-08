#include "overview.h"
#include "add_category.h"
#include "add_product.h"
#include "import_product.h"
#include "add_supplier.h"
#include "ui_overview.h"

overview::overview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::overview)
{
    ui->setupUi(this);
}

overview::~overview()
{
    delete ui;
}

void overview::on_action_profile_triggered()
{
    profile = new class profile();
    profile->show();
}


void overview::on_actionSetPermission_triggered()
{
    setpermission = new class setpermission();
    setpermission->show();

}


void overview::on_action_add_product_triggered()
{
    add_product = new class add_product(this);
    add_product->show();



}


void overview::on_action_add_category_triggered()
{
    add_category = new class add_category(this);
    add_category->show();
}


void overview::on_action_import_goods_triggered()
{
    import_product = new class import_product(this);
    import_product->show();
}


void overview::on_action_supplier_triggered()
{
    add_supplier = new class add_supplier(this);
    add_supplier->show();
}

