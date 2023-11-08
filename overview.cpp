#include "overview.h"
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

