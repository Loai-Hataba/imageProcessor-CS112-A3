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

    void on_apply_rotation_clicked();

     void on_color_btn_clicked();

    void on_frame_btn_clicked();

    void on_resize_w_editingFinished();


    void on_frame_size_val_valueChanged(int arg1);

    void on_apply_frame_clicked();

    void on_apply_vertical_clicked();

    void on_apply_horizontal_clicked();

    void on_resize_width_valueChanged(int arg1);

    void on_resize_height_valueChanged(int arg1);

    void on_apply_resize_clicked();

    void on_crop_x_valueChanged(int arg1);

    void on_crop_y_valueChanged(int arg1);

    void on_crop_w_valueChanged(int arg1);

       void on_crop_h_valueChanged(int arg1);

    void on_Apply_crop_clicked();

    void on_height_crop_apply_valueChanged(int arg1);

    void on_apply_brightness_btn_clicked();

    void on_original_image_clicked();

private:
    Ui::Photoshop_budget *ui;
};
#endif // PHOTOSHOP_BUDGET_H
