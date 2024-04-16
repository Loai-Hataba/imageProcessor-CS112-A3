#include "photoshop_budget.h"
#include "./ui_photoshop_budget.h"
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include "image_processor.h"
#include <String>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QDockWidget>
#include <QStackedWidget>
#include <QSlider>
#include <QLabel>
// #include <iostream>


QString file_name;
QString save_file_name;
Image image;

QString filePath ;

string ana = filePath.toStdString() ;

Photoshop_budget::Photoshop_budget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Photoshop_budget)
{
    ui->setupUi(this);

    // Set the alignment of the image label to center
    ui->image->setAlignment(Qt::AlignCenter);
    ui->dock_Widget_2->hide();
    QPixmap pix("D:/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/Assets/placeholder.png");
    int w = ui->image->width();
    int h = ui->image->height();

    // Set the pixmap to the label with scaled size
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));



// Get the user's home directory path
    QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    if (homePath.isEmpty()) {
        qWarning() << "Failed to retrieve the home directory path.";
        return;
    }

    // Construct the full path for the image folder
    QString folderPath = QDir::toNativeSeparators(homePath + "/Desktop/temp");

    // Create the folder
    QDir dir(folderPath);
    if (!dir.exists()) {
        if (dir.mkpath(folderPath)) {
            qDebug() << "Folder created successfully: " << folderPath;
        } else {
            qWarning() << "Failed to create folder: " << folderPath;
        }
    } else {
        qDebug() << "Folder already exists: " << folderPath;
    }
//-----------------------------------
    QString fileName = "temp.jpg" ;
    // Define image size
    int width = 400;
    int height = 300;

    // Create a QImage object with the specified size and format
    QImage image(width, height, QImage::Format_RGB32);

    // Fill the image with white color
    image.fill(Qt::white);


    // Construct the full file path
    filePath = folderPath + "/" + fileName;

    // Save the image to the specified file path
    if (!image.save(filePath)) {
        qDebug() << "Failed to save the image.";
    } else {
        qDebug() << "Image saved successfully: " << filePath;
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
void Photoshop_budget::on_save_btn_clicked()
{
    save_file_name = QFileDialog::getSaveFileName(this, "Save Image", "D:/imageProcessor-CS112-A3/cmake-build-debug/Samples", "JPEG (*.jpg);;PNG (*.png);;Bitmap (*.bmp);;Targa (*.tga)");
    Image image(filePath.toStdString());
    save(image, 0, save_file_name.toStdString());
}

void Photoshop_budget::on_inverted_btn_clicked()
{
    inverted(file_name.toStdString(),filePath.toStdString());//tmam
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
void Photoshop_budget::on_grayscale_btn_clicked()
{
    grayscale(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
void Photoshop_budget::on_bw_btn_clicked()
{
    black_white(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_sunlight_btn_clicked()
{
    Sunlight(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_edge_btn_clicked()
{
    edges(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_IR_btn_clicked()
{
    IR(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_TV_btn_clicked()
{
    tv(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_purble_btn_clicked()
{
    look_Purple(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_sepia_btn_clicked()
{
    sepia(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_oil_btn_clicked()
{
    oil(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
void Photoshop_budget::on_darken_btn_clicked()
{
    darken(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
void Photoshop_budget::on_lighten_btn_clicked()
{
    lighten(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}

void Photoshop_budget::on_Pixelate_btn_clicked()
{

}


void Photoshop_budget::on_skewed_btn_clicked()
{

}


void Photoshop_budget::on_rsize_btn_clicked()
{

}


void Photoshop_budget::on_Crop_btn_clicked()
{

}


void Photoshop_budget::on_merge_btn_clicked()
{
    // Show the QDockWidget and set the current widget of the QStackedWidget
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(5);
}


void Photoshop_budget::on_flip_btn_clicked()
{

}

void Photoshop_budget::on_blur_btn_clicked()
{
    // Show the QDockWidget and set the current widget of the QStackedWidget
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(0);
}
void Photoshop_budget::on_brightness_degree_slider_valueChanged(int value)
{
    ui->brightness_degree->setText(QString::number(value));
}


void Photoshop_budget::on_rotate_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(8);
}

