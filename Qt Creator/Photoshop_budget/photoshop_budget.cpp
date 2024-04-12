#include "photoshop_budget.h"
#include "./ui_photoshop_budget.h"
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include "image_processor.h"

QString file_name;

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
{   bool test = false;
    file_name = QFileDialog::getOpenFileName(this, "Load Image", "C://");
    if (!file_name.isEmpty() || file_name.endsWith(".jpg")) {
        QPixmap pix(file_name);
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        test = true;

        image_path(file_name.toStdString());
    }
    else //file didn't open
    {
        QMessageBox msgError;
        msgError.setText("CRITICAL ERROR!\nThe File couldn't be opened!");
        msgError.setIcon(QMessageBox::Critical);
        msgError.setWindowTitle("File not opened");

        msgError.exec();
    }
}

void Photoshop_budget::on_inverted_button_clicked()
{

}

