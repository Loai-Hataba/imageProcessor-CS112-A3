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
#include "Image_Class.h"
#include <QSlider>
#include <QLabel>
#include <QColor>
#include <QColorDialog>
#include <iostream>
#include <QSpinBox>


QString file_name;
QString merge_name; //for sec image in merge filter
QString original;
QString save_file_name;
Image image;

QString filePath ;

//for resize filter
//resize width
int res_width = 50 ;
// resize height
int res_height =  50 ;

// for crop filter
int x_value = 1 ;
int y_value = 1 ;
int crop_width_value = 50 ;
int height_crop = 50 ;
int crop_height_value = 50 ;

Photoshop_budget::Photoshop_budget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Photoshop_budget)
{
    ui->setupUi(this);

    connect(ui->apply_brightness_btn, &QPushButton::clicked, this, &Photoshop_budget::on_apply_brightness_btn_clicked);
    connect(ui->apply_merge, &QPushButton::clicked, this, &Photoshop_budget::on_apply_merge_clicked);
/*connect(ui->vertical, &QPushButton::clicked, this, &Photoshop_budget::on_vertical_clicked);
connect(ui->horizontal, &QPushButton::clicked, this, &Photoshop_budget::on_horizontal_clicked);*/
    //connect(ui->pushButton, &QPushButton::clicked, this, &Photoshop_budget::on_pushButton_clicked);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &Photoshop_budget::on_pushButton_2_clicked);
    // connect(ui->frame_size_val, &QSpinBox::valueChanged, this, &Photoshop_budget::on_frame_size_val_valueChanged);
    connect(ui->frame_btn, &QPushButton::clicked, this, &Photoshop_budget::on_frame_btn_clicked);
    // connect(ui->apply_frame, &QPushButton::clicked, this, &Photoshop_budget::on_apply_frame_clicked);

    ui->dock_Widget_2->hide();

    //logo
    QPixmap pixmap(":/images/Assets/Logo.png");
    int logo_w = ui->logo->width();
    int logo_h = ui->logo->height();
    ui->logo->setPixmap(pixmap.scaled(logo_w, logo_h, Qt::KeepAspectRatio));

    // Set the alignment of the image label to center
    ui->image->setAlignment(Qt::AlignCenter);
    QPixmap pix(":/images/Assets/image-holder-icon-614x460.png");
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
//***************************************************************************************************************************
//load
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
    original = file_name ;
}
//***************************************************************************************************************************
//save
void Photoshop_budget::on_save_btn_clicked()
{
    save_file_name = QFileDialog::getSaveFileName(this, "Save Image", "D:/imageProcessor-CS112-A3/cmake-build-debug/Samples", "JPEG (*.jpg);;PNG (*.png);;Bitmap (*.bmp);;Targa (*.tga)");
    Image image(filePath.toStdString());
    save(image, 0, save_file_name.toStdString());
}
//***************************************************************************************************************************
//inverted
void Photoshop_budget::on_inverted_btn_clicked()
{
    inverted(file_name.toStdString(),filePath.toStdString());//tmam
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************
//grayscale
void Photoshop_budget::on_grayscale_btn_clicked()
{
    grayscale(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************
//black and white
void Photoshop_budget::on_bw_btn_clicked()
{
    black_white(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//sunlight
void Photoshop_budget::on_sunlight_btn_clicked()
{
    Sunlight(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//edges
void Photoshop_budget::on_edge_btn_clicked()
{
    edges(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//IR
void Photoshop_budget::on_IR_btn_clicked()
{
    IR(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//tv
void Photoshop_budget::on_TV_btn_clicked()
{
    tv(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//purple
void Photoshop_budget::on_purble_btn_clicked()
{
    look_Purple(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//sepia
void Photoshop_budget::on_sepia_btn_clicked()
{
    sepia(file_name.toStdString(),filePath.toStdString());
      QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     file_name = filePath;
}
//***************************************************************************************************************************
//oil
void Photoshop_budget::on_oil_btn_clicked()
{
    QMessageBox *oilmessageBox = new QMessageBox;
    QPixmap pixmap(":/images/Assets/png-transparent-black-loading-ic.png");
    pixmap = pixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    oilmessageBox->setIconPixmap(pixmap);
    oilmessageBox->setText("Processing Image...");
    oilmessageBox->show();
    QApplication::processEvents();
    oil(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
    delete oilmessageBox;
}
//***************************************************************************************************************************
//lighten-darken
int degree = 0;
void Photoshop_budget::on_brightness_degree_slider_valueChanged(int value)
{
    ui->brightness_degree->setText(QString::number(value));
    degree = value;
}
int cntrd = 0;
int cntrl = 0;
void Photoshop_budget::on_darken_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(2);
    degree = 0;
    cntrd = 1;
    cntrl = 0;
}
void Photoshop_budget::on_lighten_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(2);
    degree = 0;
    cntrl = 1;
    cntrd = 0;
}
void Photoshop_budget::on_apply_brightness_btn_clicked()
{
    if(cntrd == 1){
        darken(file_name.toStdString(),filePath.toStdString(),degree);
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
    else if(cntrl == 1){
        lighten(file_name.toStdString(),filePath.toStdString(),degree);
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
}
//***************************************************************************************************************************
//pixelate
void Photoshop_budget::on_Pixelate_btn_clicked()
{
    Pixelate(file_name.toStdString(),filePath.toStdString());
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************
//skew
int skew_degree = 0 ;
void Photoshop_budget::on_skewed_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(9);
}

void Photoshop_budget::on_skew_degree_val_valueChanged(int arg1)
{
    skew_degree = arg1;
}

void Photoshop_budget::on_apply_skew_clicked()
{
    QMessageBox::information(this, "test",QString::number(skew_degree));
    Skewed(file_name.toStdString(),filePath.toStdString(),skew_degree);
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h ,Qt::KeepAspectRatio));
    file_name = filePath;
}


void Photoshop_budget::on_rsize_btn_clicked()
{
    // Show the QDockWidget and set the current widget of the QStackedWidget
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(7);
}

void Photoshop_budget::on_Crop_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(1);

}
//***************************************************************************************************************************
//merge
void Photoshop_budget::on_merge_btn_clicked()
{
    // Show the QDockWidget and set the current widget of the QStackedWidget
    merge_name = QFileDialog::getOpenFileName(this, "Load Image to be merged", "D:/imageProcessor-CS112-A3/cmake-build-debug/Samples");
    if (!merge_name.isEmpty() && (merge_name.endsWith(".jpg") || merge_name.endsWith(".png") || merge_name.endsWith(".bmp") || merge_name.endsWith(".tga"))) {
        ui->dock_Widget_2->show();
        ui->stackedWidget->setCurrentIndex(5);
    }
    else{
        QMessageBox msgError;
        msgError.setText("The File couldn't be opened!");
        msgError.setIcon(QMessageBox::Critical);
        msgError.setWindowTitle("File not opened");
        msgError.exec();
        merge_name = "";
    }
}
void Photoshop_budget::on_apply_merge_clicked()
{
    if (ui->common_area_merge->isChecked())
    {
        merge(file_name.toStdString(),filePath.toStdString(),1,merge_name.toStdString());
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
    else if (ui->biggest_area_merge->isChecked())
    {
        merge(file_name.toStdString(),filePath.toStdString(),2,merge_name.toStdString());
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
}


//**********************************************************************************************************
//blur
void Photoshop_budget::on_blur_btn_clicked()
{
    // Show the QDockWidget and set the current widget of the QStackedWidget
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(0);
}

//************************************************************************************************************
// rotate
void Photoshop_budget::on_rotate_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(8);
}
void Photoshop_budget::on_apply_rotation_clicked()
{

    if (ui->angle_90->isChecked())
    {
        rotate(file_name.toStdString(),filePath.toStdString(), 90);
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
    else if (ui->angle_180->isChecked())
    {
        rotate(file_name.toStdString(),filePath.toStdString(), 180);
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
    else if (ui->angle_270->isChecked())
    {
        rotate(file_name.toStdString(),filePath.toStdString(), 270);
        QPixmap pix(filePath);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        file_name = filePath;
    }
}
//****************************************************************************************************************
//frame filter
int frame_size_num = 50;
QColor color = Qt::white;
void Photoshop_budget::on_frame_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(4);
}

void Photoshop_budget::on_color_btn_clicked()
{
    color = QColorDialog::getColor(Qt::white, this, "Frame Color");
    if (color.isValid())
    {
        ui->color_btn->setStyleSheet("background-color: " + color.name() + ";");
    }

}

void Photoshop_budget::on_frame_size_val_valueChanged(int arg1)
{
    frame_size_num = arg1;
}

void Photoshop_budget::on_apply_frame_clicked()
{
    QMessageBox *framemessageBox = new QMessageBox;
    QPixmap pixmap(":/images/Assets/png-transparent-black-loading-ic.png");
    pixmap = pixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    framemessageBox->setIconPixmap(pixmap);
    framemessageBox->setText("Processing Image...");
    framemessageBox->show();
    QApplication::processEvents();
    // simple frame
    if (ui->simple_frame->isChecked())
    {
        frame(file_name.toStdString(),filePath.toStdString(), frame_size_num, 1, color.red(), color.green(), color.blue());
    }
    // textured frame
    else if (ui->textured_frame->isChecked())
    {
        frame(file_name.toStdString(),filePath.toStdString(), frame_size_num, 2, color.red(), color.green(), color.blue());
    }
    // diagonal frame
    else if (ui->fancy_frame->isChecked())
    {
        frame(file_name.toStdString(),filePath.toStdString(), frame_size_num, 3, color.red(), color.green(), color.blue(), 1);
    }
    // checkered frame
    else if (ui->fancy_frame_2->isChecked())
    {
        frame(file_name.toStdString(),filePath.toStdString(), frame_size_num, 3, color.red(), color.green(), color.blue(), 2);
    }
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
    delete framemessageBox;
}
//*************************************************************************************************************
//flip
void Photoshop_budget::on_flip_btn_clicked()
{
    ui->dock_Widget_2->show();
    ui->stackedWidget->setCurrentIndex(3);
}
void Photoshop_budget::on_apply_vertical_clicked()
{
    flip(file_name.toStdString(),filePath.toStdString(),"V");
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}

void Photoshop_budget::on_apply_horizontal_clicked()
{
    flip(file_name.toStdString(),filePath.toStdString(),"H");
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************
//resize
void Photoshop_budget::on_resize_width_valueChanged(int width )
{
    res_width = width ;
}


void Photoshop_budget::on_resize_height_valueChanged(int height)
{
    res_height = height ;
}


void Photoshop_budget::on_apply_resize_clicked()
{ //
  cout << res_height<<" "<<res_width <<endl ;
  resize_filter(file_name.toStdString(),filePath.toStdString(),res_width,res_height);
    QPixmap pix(filePath);
  int w = ui->image->width();
  int h = ui->image->height();
  ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************
//crop
void Photoshop_budget::on_crop_x_valueChanged(int arg1)
{
    x_value = arg1 ;
}
void Photoshop_budget::on_crop_y_valueChanged(int arg1)
{
    y_value = arg1 ;
}
void Photoshop_budget::on_crop_w_valueChanged(int arg1)
{
    crop_width_value = arg1 ;
}
void Photoshop_budget::on_height_crop_apply_valueChanged(int arg1)
{
    height_crop = arg1 ;
}
void Photoshop_budget::on_crop_h_valueChanged(int arg1)
{
   height_crop = arg1 ;
}
void Photoshop_budget::on_Apply_crop_clicked()
{


   Image image(file_name.toStdString()) ;
    if ((x_value +crop_width_value ) > image.width  ){
       QMessageBox msgError;
       msgError.setText("Out of Width bounds !! ");
       msgError.setIcon(QMessageBox::Critical);
       msgError.setWindowTitle("File not opened");
       msgError.exec();
       return ;
   }
    if ( (y_value + height_crop)  > image.height){
       QMessageBox msgError;
       msgError.setText("Out of Height bounds !! ");
       msgError.setIcon(QMessageBox::Critical);
       msgError.setWindowTitle("File not opened");
       msgError.exec();
       return ;
   }
    crop(file_name.toStdString(),filePath.toStdString(),x_value , y_value ,crop_width_value , height_crop);
    QPixmap pix(filePath);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    file_name = filePath;
}
//***************************************************************************************************************************



/*
void Photoshop_budget::on_original_image_clicked()
{
    QPixmap pix(original);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    image = image_path(file_name.toStdString());
}
*/


void Photoshop_budget::on_original_image_pressed()
{
    QPixmap pix(original);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    image = image_path(original.toStdString());
    file_name = original ;
}
