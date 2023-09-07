#ifndef GESTION_ENSEIGNANT_H
#define GESTION_ENSEIGNANT_H

#include <QDialog>
#include "enseignant.h"
#include "NotificationLayout.h"

namespace Ui {
class gestion_enseignant;
}

class gestion_enseignant : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_enseignant(QWidget *parent = nullptr);
    ~gestion_enseignant();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_statistique_clicked();

    void on_comboBox_tri_activated(const QString &arg1);
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_qrcodegen_clicked();

    void on_PDF_clicked();

    void on_pushButton_success_clicked();
void on_pushButton_error_clicked();

void on_pushButton_success1_clicked();
void on_pushButton_error1_clicked();

void on_pushButton_success2_clicked();
void on_pushButton_error2_clicked();



private:
    Ui::gestion_enseignant *ui;
    Enseignant E;
    NotificationLayout notificationLayout;

};

#endif
