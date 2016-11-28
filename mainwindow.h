#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "img_vol.h"
#include "operations.h"
#include "img2d.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_actionImportar_triggered();

  void on_spinBox_valueChanged(int arg1);

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_horizontalSlider_actionTriggered(int action);

  void on_slider_radz_actionTriggered(int action);

  void on_slider_rady_actionTriggered(int action);

  void on_slider_radx_actionTriggered(int action);

  void on_actionImportar_Label_triggered();

  void on_pushButton_4_clicked();

  void on_radio_axis_x_clicked();

  void on_radio_axis_y_clicked();

  void on_radio_axis_z_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

private:
  Ui::MainWindow *ui;
  std::shared_ptr<imgvol::ImgVol> img_vol;
  std::shared_ptr<imgvol::ImgVol> img_vol_label;
  std::shared_ptr<imgvol::Img2D> img2d_ptr;
  std::shared_ptr<imgvol::Img2D> img2d_label_ptr;
};

#endif // MAINWINDOW_H
