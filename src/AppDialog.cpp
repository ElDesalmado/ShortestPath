#include "AppDialog.h"

#include "ui_appdialog.h"

#include "qvalidator.h"

AppDialog::AppDialog(QWidget *parent)
    : QDialog(parent),
    ui_(SetupUI(this))
{}

AppDialog::~AppDialog()
{
}

std::unique_ptr<Ui_MainDialog> AppDialog::SetupUI(AppDialog * dialog)
{
    std::unique_ptr<Ui_MainDialog> ui = std::make_unique<Ui_MainDialog>();
    ui->setupUi(dialog);

    ui->inputWidth->setValidator(new QIntValidator(1, 99));
    ui->inputHeight->setValidator(new QIntValidator(1, 99));


    connect(ui->inputHeight, &QLineEdit::textChanged, dialog, &AppDialog::switchGenerateBtnState);
    connect(ui->inputWidth, &QLineEdit::textChanged, dialog, &AppDialog::switchGenerateBtnState);

    return std::move(ui);
}

void AppDialog::switchGenerateBtnState()
{
    ui_->btnGenerate->setEnabled(!ui_->inputHeight->text().isEmpty() &&
        !ui_->inputWidth->text().isEmpty());
}
