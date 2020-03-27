#pragma once

#include "qdialog.h"

class Ui_MainDialog;

class AppDialog : public QDialog
{
    Q_OBJECT

private:
    std::unique_ptr<Ui_MainDialog> ui_;

public:

    explicit AppDialog(QWidget *parent = nullptr);

    ~AppDialog();

private:
    static std::unique_ptr<Ui_MainDialog> SetupUI(AppDialog *dialog);

    void switchGenerateBtnState();

};
