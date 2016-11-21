#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include "img_utils.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_actionImportar_triggered()
{
  QString file1Name = QFileDialog::getOpenFileName(this,
           tr("Open SCN File"), "/home", tr(".scn"));

  std::string file_img = file1Name.toUtf8().constData();

  if (!file_img.empty()) {
    img_vol = std::make_shared<imgvol::ImgVol>(file_img);
  }




}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    imgvol::ImgVol::Axis axis = imgvol::ImgVol::Axis::aX;

    if (ui->radio_axis_y->isChecked()) {
      axis = imgvol::ImgVol::Axis::aY;
    } else if (ui->radio_axis_z->isChecked()) {
      axis = imgvol::ImgVol::Axis::aZ;
    }

    imgvol::Img2D img2d = imgvol::Cut(*img_vol, axis, arg1);
    img2d_ptr = std::make_shared<imgvol::Img2D>(img2d);
    imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
    imggray.WriteImg("im__g");

    ShowImage("im__g", ui->label);

}

void MainWindow::on_pushButton_clicked()
{
  imgvol::Img2D img2d = *img2d_ptr;
    imgvol::Negative(img2d);
    imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
    imggray.WriteImg("im__g");

    ShowImage("im__g", ui->label);
}

void MainWindow::on_pushButton_2_clicked()
{
  imgvol::Img2D img2d = *img2d_ptr;
  imgvol::Normalize(img2d, 12);
  imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
  imggray.WriteImg("im__g");

  ShowImage("im__g", ui->label);
}

void MainWindow::on_pushButton_3_clicked()
{
  imgvol::Img2D img2d = *img2d_ptr;
  imgvol::BrightinessContrast(img2d, 12, ui->slider_bright->value(), ui->slider_constrast->value());
  imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
  imggray.WriteImg("im__g");

  ShowImage("im__g", ui->label);
}
