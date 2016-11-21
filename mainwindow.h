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

private:
  Ui::MainWindow *ui;
  std::shared_ptr<imgvol::ImgVol> img_vol;
  std::shared_ptr<imgvol::Img2D> img2d_ptr;
};

#endif // MAINWINDOW_H
