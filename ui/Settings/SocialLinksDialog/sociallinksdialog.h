#ifndef SOCIALLINKSDIALOG_H
#define SOCIALLINKSDIALOG_H

#include <QDialog>
#include <QHBoxLayout>

#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SocialLinksDialog; }
QT_END_NAMESPACE

class SocialLinksDialog : public QDialog {
Q_OBJECT

public:
    explicit SocialLinksDialog(QWidget *parent = nullptr);
    ~SocialLinksDialog() override;

private slots:
    void handleSave();
    void handleAdd();
    void handleClose();

private:
    Ui::SocialLinksDialog *ui;
    vector<string> links;
    vector<string> errors;

    void initializeLinks();
    void initializeErrors(vector<string> errors);
    void createLinkInput(int count, string link);
    bool validateUrl(string url);
    QWidget* wrapCentered(QWidget *widget);
};


#endif //SOCIALLINKSDIALOG_H
