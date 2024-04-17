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
    void on_load_btn_clicked();

    void on_inverted_btn_clicked();

    void on_grayscale_btn_clicked();

    void on_bw_btn_clicked();

    void on_save_btn_clicked();

    void on_sunlight_btn_clicked();

    void on_edge_btn_clicked();

    void on_IR_btn_clicked();

    void on_TV_btn_clicked();

    void on_purble_btn_clicked();

    void on_sepia_btn_clicked();

    void on_oil_btn_clicked();

    void on_darken_btn_clicked();

    void on_lighten_btn_clicked();

    void on_Pixelate_btn_clicked();

    void on_skewed_btn_clicked();

    void on_rsize_btn_clicked();

    void on_Crop_btn_clicked();

    void on_merge_btn_clicked();

    void on_flip_btn_clicked();

    void on_blur_btn_clicked();

    void on_brightness_degree_slider_valueChanged(int value);


    void on_rotate_btn_clicked();

    void on_pushButton_clicked();

    void on_apply_rotation_clicked();

    void on_rotate_apply_clicked();

    void on_color_btn_clicked();

    void on_frame_btn_clicked();

    void on_flip_v_clicked();

    void on_flip_h_clicked();

    void on_flipV_clicked();

    void on_resize_w_editingFinished();

private:
    Ui::Photoshop_budget *ui;
};
#endif // PHOTOSHOP_BUDGET_H
