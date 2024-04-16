#include "photoshop_budget.h"
#include "./ui_photoshop_budget.h"
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include "image_processor.h"
#include <String>
// #include <iostream>


QString file_name;
QString save_file_name;
Image image;

Photoshop_budget::Photoshop_budget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Photoshop_budget)
{
    ui->setupUi(this);

    // Set the alignment of the image label to center
    ui->image->setAlignment(Qt::AlignCenter);

    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/Assets/placeholder.png");
    int w = ui->image->width();
    int h = ui->image->height();

    // Set the pixmap to the label with scaled size
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    //rotate combo box
    ui->rotate_combobox->addItem("");
    for (int i = 1; i <= 3; i++)
    {
        int angle = i * 90;
        ui->rotate_combobox->addItem(QString::number(angle));
    }

}

Photoshop_budget::~Photoshop_budget()
{
    delete ui;
}

void Photoshop_budget::on_load_btn_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "Load Image", "D:/imageProcessor-CS112-A3/cmake-build-debug/Samples");
    if (!file_name.isEmpty() && (file_name.endsWith(".jpg") || file_name.endsWith(".png") || file_name.endsWith(".bmp") || file_name.endsWith(".tga"))) {
        QPixmap pix(file_name);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        image = image_path(file_name.toStdString());
    }
    else //file didn't open
    {
        QMessageBox msgError;
        msgError.setText("The File couldn't be opened!");
        msgError.setIcon(QMessageBox::Critical);
        msgError.setWindowTitle("File not opened");
        msgError.exec();
        file_name = "";
    }
}

void Photoshop_budget::on_inverted_btn_clicked()
{
    inverted(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}




void Photoshop_budget::on_grayscale_btn_clicked()
{
    grayscale(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_bw_btn_clicked()
{
    black_white(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_save_btn_clicked()
{
    save_file_name = QFileDialog::getSaveFileName(this, "Save Image", "D:/imageProcessor-CS112-A3/cmake-build-debug/Samples", "JPEG (*.jpg);;PNG (*.png);;Bitmap (*.bmp);;Targa (*.tga)");
    Image image("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    save(image, 0, save_file_name.toStdString());
}


void Photoshop_budget::on_sunlight_btn_clicked()
{
    Sunlight(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_edge_btn_clicked()
{
    edges(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_IR_btn_clicked()
{
    IR(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_TV_btn_clicked()
{
    tv(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}



void Photoshop_budget::on_purble_btn_clicked()
{
    look_Purple(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


void Photoshop_budget::on_sepia_btn_clicked()
{
    sepia(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}



void Photoshop_budget::on_oil_btn_clicked()
{
    oil(file_name.toStdString());
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp.jpg";
}


