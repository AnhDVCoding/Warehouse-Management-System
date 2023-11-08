#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QMainWindow>
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

private:
    Ui::overview *ui;
    profile *profile;
    setpermission *setpermission;
};

#endif // OVERVIEW_H
