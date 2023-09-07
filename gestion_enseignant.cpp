#include "gestion_enseignant.h"
#include "ui_gestion_enseignant.h"
#include<QMessageBox>
#include"enseignant.h"

#include<QComboBox>
#include<QtCharts>
#include<QtCharts>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include "Result.h"
#include "Operation.h"

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include<QRegExpValidator>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>


#include <QMessageBox>
#include<QIntValidator>
#include <QApplication>
#include<QSound>
#include<QDebug>
#include<QMediaPlayer>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDataStream>
#include <QPrintDialog>
#include <QSqlQuery>
#include<QComboBox>
#include<QSaveFile>
#include<QBuffer>
#include<QFileDialog>
#include<QFile>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>

#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include"smtp.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include <QPrinter>

#include "QrCode.hpp"
#include<QLabel>
#include"QMessageBox"
#include <QPdfWriter>
#include <QtGui/QDesktopServices>
#include <QUrl>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QtSvg/QSvgRenderer>
#include <QFileDialog>
#include <fstream>
#include "QrCode.hpp"
#include <QAxObject>
#include <QObject>
#include <QDesktopServices>

#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

#include <QPrintDialog>
#include <QFileDialog>
#include <QSettings>
#include <QCoreApplication>

using namespace qrcodegen;

gestion_enseignant::gestion_enseignant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestion_enseignant)
{
    ui->setupUi(this);


}

gestion_enseignant::~gestion_enseignant()
{
    delete ui;
}


void gestion_enseignant::on_pb_ajouter_clicked()
{


        QString cin=ui->le_id->text();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_ville->text();
        QString matiere = ui->comboBox->currentText();
        QString salaire=ui->le_tel->text();


        Enseignant E(cin,nom, prenom, matiere, salaire);

                QSqlQuery query;



                bool test=E.ajouter();
                if(test)
                {

                    ui->tableView->setModel(E.afficher());//refresh




                    QMessageBox::information(nullptr, QObject::tr("Ajout enseignant"),
                                QObject::tr("enseignant Modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                    on_pushButton_success_clicked();




                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr("Ajout eleve"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                    on_pushButton_error_clicked();

                }
    }

void gestion_enseignant::on_pushButton_success_clicked()
{
    NotificationParams params;
    params.title = "Enseignant a ete ajoute avec succès";
    params.message = Operation::DoSomething(Result::RESULT_SUCCESS);
    notificationLayout.AddNotificationWidget(this, params);
}

void gestion_enseignant::on_pushButton_error_clicked()
{
    NotificationParams params;
    params.title = "Enseignant n'est pas ajoute";
    params.message = Operation::DoSomething(Result::RESULT_ERROR);

    notificationLayout.AddNotificationWidget(this, params);
}
void gestion_enseignant::on_comboBox_tri_activated(const QString &arg1)
{


Enseignant E;
    QString NOM=ui->comboBox_tri->currentText();
   // QString name=ui->lineEdit->text();
   //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
   ui->tableView->setModel(E.trier(NOM));
   // ui->tableView_2->setModel(cp.rechercher_nom(name));
  ui->tableView->clearSelection();
}

void gestion_enseignant::on_statistique_clicked()
{


        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM enseignant WHERE matiere='scientifique'");
        float dispo1 = model->rowCount();

        model->setQuery("SELECT * FROM enseignant WHERE matiere='litteraire'");
        float dispo = model->rowCount();

        float total = dispo1 + dispo;
        QString a = QString("scientifique " + QString::number((dispo1 * 100) / total, 'f', 2) + "%");
        QString b = QString("litteraire  " + QString::number((dispo * 100) / total, 'f', 2) + "%");

        QPieSeries *series = new QPieSeries();
        series->append(a, dispo1);
        series->append(b, dispo);

        if (dispo1 != 0)
        {
            QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());
        }

        if (dispo != 0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("TYPE DE MATIERE" + QString::number(total));

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000, 500);
        chartView->show();


        }



void gestion_enseignant::on_lineEdit_recherche_textChanged(const QString &arg1) //recherche dynamique
{
    Enseignant E;
        QString NOM=ui->lineEdit_recherche->text();
       // QString name=ui->lineEdit->text();
       //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
       ui->tableView->setModel(E.rechercher(NOM));
       // ui->tableView_2->setModel(cp.rechercher_nom(name));
      ui->tableView->clearSelection();
}


void gestion_enseignant::on_pushButton_Afficher_clicked()
{

        ui->tableView->setModel(E.afficher());


}





void gestion_enseignant::on_pushButton_supprimer_clicked()
{
    QString ID=ui->lineEdit_supp->text();
            bool test=E.supprimer(ID);
            ui->tableView->setModel(E.afficher());
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("suppression effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                on_pushButton_success1_clicked();


        }
            else {
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("suppression non effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            on_pushButton_error1_clicked();
            }

}
void gestion_enseignant::on_pushButton_success1_clicked()
{
    NotificationParams params;
    params.title = "Enseignant a ete supprimer avec succès";
    params.message = Operation::DoSomething(Result::RESULT_SUCCESS);
    notificationLayout.AddNotificationWidget(this, params);
}

void gestion_enseignant::on_pushButton_error1_clicked()
{
    NotificationParams params;
    params.title = "suppression non effectue";
    params.message = Operation::DoSomething(Result::RESULT_ERROR);

    notificationLayout.AddNotificationWidget(this, params);
}

void gestion_enseignant::on_pushButton_modifier_clicked()
{

    QString cin=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_ville->text();
    QString matiere = ui->comboBox->currentText();
    QString salaire=ui->le_tel->text();


    Enseignant E(cin,nom, prenom, matiere, salaire);

            QSqlQuery query;



            bool test=E.modifier(cin);
            if(test)
            {

                ui->tableView->setModel(E.afficher());//refresh




                QMessageBox::information(nullptr, QObject::tr("Modifier Enseignant"),
                            QObject::tr("Enseignant Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

                on_pushButton_success2_clicked();


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier Enseignant"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                on_pushButton_error2_clicked();

            }
}



void gestion_enseignant::on_pushButton_success2_clicked()
{
    NotificationParams params;
    params.title = "Enseignant a ete modifier avec succès";
    params.message = Operation::DoSomething(Result::RESULT_SUCCESS);
    notificationLayout.AddNotificationWidget(this, params);
}

void gestion_enseignant::on_pushButton_error2_clicked()
{
    NotificationParams params;
    params.title = "modification non effectue";
    params.message = Operation::DoSomething(Result::RESULT_ERROR);

    notificationLayout.AddNotificationWidget(this, params);
}


void gestion_enseignant::on_qrcodegen_clicked()
    {
        using namespace qrcodegen;


                    QTableView tableView;
                    QSqlQueryModel * Mod=new  QSqlQueryModel();
                    QString value=ui->lineEdit_qrcode->text();


                         QSqlQuery qry;




                         qry.prepare("select * from enseignant where cin='"+value+"'");
                         qry.exec();
                         Mod->setQuery(qry);
                         tableView.setModel(Mod);



                        QString cin = tableView.model()->data(tableView.model()->index(0, 0)).toString().simplified();
                        QString nom= tableView.model()->data(tableView.model()->index(0, 1)).toString().simplified();
                        QString prenom = tableView.model()->data(tableView.model()->index(0, 2)).toString().simplified();
                        QString matiere = tableView.model()->data(tableView.model()->index(0, 3)).toString().simplified();
                        QString salaire = tableView.model()->data(tableView.model()->index(0, 4)).toString().simplified();




                    QString text = "cin"+cin+"\n"+"Nom  "+nom+"\n"+"prenom  "+prenom+"\n"+" matiere  "+matiere+"\n"+"SALAIRE  "+salaire;
                      // Create the QR Code object
                      QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );

                      qint32 sz = qr.getSize();
                      QImage im(sz,sz, QImage::Format_RGB32);
                        QRgb black = qRgb( 191,112,105 );
                        QRgb white = qRgb(255,255,255);
                      for (int y = 0; y < sz; y++)
                        for (int x = 0; x < sz; x++)
                          im.setPixel(x,y,qr.getModule(x, y) ? black : white );//setpixelmap tafichilek qr code
                      ui->qrcodecommande->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );


    }

void gestion_enseignant::on_PDF_clicked()
{

    QPdfWriter pdf("C:/Users/Ramzi/Desktop/session_septembre/img/listenseignant.pdf");

        QPainter painter(&pdf);


               int i = 4000;
               painter.setPen(Qt::black);
               painter.setFont(QFont("Book Script",20));
               painter.drawText(2500, 1400, "LISTE DES ENSEIGNANT");
               painter.setPen(Qt::red);
               painter.setFont(QFont("Time New Roman", 10));
               painter.drawRect(100, 100, 9200, 2700); // dimension ta3 rectangle
               painter.drawRect(100, 3000, 9200, 500);


               painter.drawText(300,3300,"CIN");
               painter.drawText(2000,3300,"NOM");
               painter.drawText(3500,3300,"PRENOM");
               painter.drawText(4500,3300,"MATIERE");
               painter.drawText(6500,3300,"SALAIRE");





               QImage image("C:/Users/Ramzi/Desktop/session_septembre/img/photo.png");
               painter.drawImage(QRectF(200, 200, 2000, 2000), image);

               QImage image1("C:/Users/Ramzi/Desktop/session_septembre/img/photo5.jpg");
               painter.drawImage(QRectF(7000, 200, 2000, 2000), image1);

               painter.drawRect(100, 3700, 9200, 9000);

               QSqlQuery query;
               query.prepare("select * from enseignant");
               query.exec();
               while (query.next())
               {
                   painter.drawText(300, i, query.value(0).toString());
                   painter.drawText(2000, i, query.value(1).toString());
                   painter.drawText(3500, i, query.value(2).toString());
                   painter.drawText(4500, i, query.value(3).toString());
                   painter.drawText(6500, i, query.value(4).toString());

                   i = i + 350;
               }

               QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                   QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}
