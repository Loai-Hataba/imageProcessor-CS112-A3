#ifndef PHOTOSHOP_BUDGET_H
#define PHOTOSHOP_BUDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Photoshop_budget;
}
QT_END_NAMESPACE

class Photoshop_budget : public QMainWindow
{
    Q_OBJECT

public:
    Photoshop_budget(QWidget *parent = nullptr);
    ~Photoshop_budget();

private slots:
    void on_load_button_clicked();

    void on_inverted_button_clicked();

    void on_grayscale_button_clicked();

    void on_bw_button_clicked();

    void on_save_button_clicked();

private:
    Ui::Photoshop_budget *ui;
};
#endif // PHOTOSHOP_BUDGET_H
