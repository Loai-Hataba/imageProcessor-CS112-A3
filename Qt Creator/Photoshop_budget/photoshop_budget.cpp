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

    QPixmap pix("F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/Assets/placeholder.png");
    int w = ui->image->width();
    int h = ui->image->height();

    // Set the pixmap to the label with scaled size
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

Photoshop_budget::~Photoshop_budget()
{
    delete ui;
}

void Photoshop_budget::on_load_button_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "Load Image", "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/cmake-build-debug/Samples/");
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

void Photoshop_budget::on_inverted_button_clicked()
{
    inverted(file_name.toStdString());
    QMessageBox::information(this, "ended", "Filter Applied!");
    QPixmap pix("F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg";
}




void Photoshop_budget::on_grayscale_button_clicked()
{
    grayscale(file_name.toStdString());
    QMessageBox::information(this, "ended", "Filter Applied!");
    QPixmap pix("F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg";
}


void Photoshop_budget::on_bw_button_clicked()
{
    black_white(file_name.toStdString());
    QMessageBox::information(this, "ended", "Filter Applied!");
    QPixmap pix("F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg";
}


void Photoshop_budget::on_save_button_clicked()
{
    save_file_name = QFileDialog::getSaveFileName(this, "Save Image", "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/cmake-build-debug/Samples/");
    Image image("F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg");
    save(image, 0, save_file_name.toStdString());
}

