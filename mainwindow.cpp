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
           tr("Open SCN File"), "/home/alex/Unicamp/img/libmc920/data", tr(".scn"));

  std::string file_img = file1Name.toUtf8().constData();

  if (!file_img.empty()) {
    img_vol = std::make_shared<imgvol::ImgVol>(file_img);
    NormalizeImage(*img_vol);
    std::string str = "image: " + file_img + " <" + std::to_string(img_vol->SizeX())
        + ", " + std::to_string(img_vol->SizeY()) + ", " + std::to_string(img_vol->SizeY())
        + ">";
    ui->label_img_status->setText(QString::fromUtf8(str.c_str()));
  }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    imgvol::ImgVol::Axis axis = imgvol::ImgVol::Axis::aX;
    bool w = false;
    w = ui->check_side->isChecked();

    if (ui->radio_axis_y->isChecked()) {
      axis = imgvol::ImgVol::Axis::aY;
    } else if (ui->radio_axis_z->isChecked()) {
      axis = imgvol::ImgVol::Axis::aZ;
    }

    if (!img_vol) {
      return;
    }

    if (img_vol_label) {
      imgvol::Img2D img2d_label = imgvol::Cut(*img_vol_label, axis, arg1, w);
      imgvol::Img2D img2d = imgvol::Cut(*img_vol, axis, arg1, w);

      imgvol::ImgColor img_color = imgvol::ColorLabels(img2d, img2d_label, 16);
      img_color.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
    } else {
      imgvol::Img2D img2d = imgvol::Cut(*img_vol, axis, arg1, w);
      img2d_ptr = std::make_shared<imgvol::Img2D>(img2d);
      imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
      imggray.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
    }

    ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_pushButton_clicked()
{
  imgvol::Img2D img2d = *img2d_ptr;
    imgvol::Negative(img2d);
    imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
    imggray.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");

    ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_pushButton_2_clicked()
{
  int num_bits = ui->spin_num_bits->value();
  imgvol::Img2D img2d = *img2d_ptr;
  imgvol::Normalize(img2d, num_bits);
  imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
  imggray.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");

  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_pushButton_3_clicked()
{
  imgvol::Img2D img2d = *img2d_ptr;
  imgvol::BrightinessContrast(img2d, 12, ui->slider_bright->value(), ui->slider_constrast->value());
  imgvol::ImgVet imggray(img2d.Data(), img2d.SizeX(), img2d.SizeY());
  imggray.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");

  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

}

void MainWindow::on_slider_radz_actionTriggered(int action)
{
  imgvol::Img2D img2d = *img2d_ptr;
  int rad_x = ui->slider_radx->value();
  int rad_y = ui->slider_rady->value();
  int rad_z = ui->slider_radz->value();
  imgvol::ImgGray cube = imgvol::DrawWireframe(*img_vol, std::array<float, 3> {M_PI/180*rad_x, M_PI/180*rad_y, M_PI/180*rad_z});
  cube.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_slider_rady_actionTriggered(int action)
{
  imgvol::Img2D img2d = *img2d_ptr;
  int rad_x = ui->slider_radx->value();
  int rad_y = ui->slider_rady->value();
  int rad_z = ui->slider_radz->value();
  imgvol::ImgGray cube = imgvol::DrawWireframe(*img_vol, std::array<float, 3> {M_PI/180*rad_x, M_PI/180*rad_y, M_PI/180*rad_z});
  cube.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_slider_radx_actionTriggered(int action)
{
  imgvol::Img2D img2d = *img2d_ptr;
  int rad_x = ui->slider_radx->value();
  int rad_y = ui->slider_rady->value();
  int rad_z = ui->slider_radz->value();
  imgvol::ImgGray cube = imgvol::DrawWireframe(*img_vol, std::array<float, 3> {M_PI/180*rad_x, M_PI/180*rad_y, M_PI/180*rad_z});
  cube.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_actionImportar_Label_triggered()
{
  QString file1Name = QFileDialog::getOpenFileName(this,
           tr("Open SCN File"), "/home/alex/Unicamp/img/libmc920/data", tr(".scn"));

  std::string file_img = file1Name.toUtf8().constData();

  if (!file_img.empty()) {
    img_vol_label = std::make_shared<imgvol::ImgVol>(file_img);
  }
}

void MainWindow::on_pushButton_4_clicked()
{
  int p1x = std::stoi(ui->edit_p1x->text().toUtf8().constData());
  int p1y = std::stoi(ui->edit_p1y->text().toUtf8().constData());
  int p1z = std::stoi(ui->edit_p1z->text().toUtf8().constData());

  int p2x = std::stoi(ui->edit_p2x->text().toUtf8().constData());
  int p2y = std::stoi(ui->edit_p2y->text().toUtf8().constData());
  int p2z = std::stoi(ui->edit_p2z->text().toUtf8().constData());

  int n = std::stoi(ui->edit_slices_num->text().toUtf8().constData());

  std::array<float,3> p1 {float(p1x), float(p1y), float(p1z)};
  std::array<float,3> pn {float(p2x), float(p2y), float(p2z)};

  imgvol::ImgVol ref_img = imgvol::ReformataImg(*img_vol, 100, p1, pn);

  imgvol::ImgGray img = MaxIntensionProjection(ref_img, M_PI/180*0, M_PI/180*0,
                                               std::array<float,3>{0,0,1});
  img.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_radio_axis_x_clicked()
{
    ui->spinBox->setMaximum(img_vol->SizeX());
}

void MainWindow::on_radio_axis_y_clicked()
{
    ui->spinBox->setMaximum(img_vol->SizeY());
}

void MainWindow::on_radio_axis_z_clicked()
{
    ui->spinBox->setMaximum(img_vol->SizeZ());
}

void MainWindow::on_pushButton_5_clicked()
{
    float delta_x = std::stof(ui->spin_mipdeltax->text().toUtf8().constData());
    float delta_y = std::stof(ui->spin_mipdeltay->text().toUtf8().constData());

    std::array<float, 3> vet_normal {
      std::stof(ui->mipvetx_edit->text().toUtf8().constData()),
      std::stof(ui->mipvety_edit->text().toUtf8().constData()),
      std::stof(ui->mipvetz_edit->text().toUtf8().constData())
    };

    imgvol::ImgGray img = imgvol::MaxIntensionProjection(*img_vol, M_PI/180*delta_x, M_PI/180*delta_y, vet_normal);
    img.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
    ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}

void MainWindow::on_pushButton_6_clicked()
{
    std::array<float, 3> p1 {
      std::stof(ui->planar_edit_px->text().toUtf8().constData()),
      std::stof(ui->planar_edit_py->text().toUtf8().constData()),
      std::stof(ui->planar_edit_pz->text().toUtf8().constData())
    };

    std::array<float, 3> vec {
      std::stof(ui->planar_edit_vx->text().toUtf8().constData()),
      std::stof(ui->planar_edit_vy->text().toUtf8().constData()),
      std::stof(ui->planar_edit_vz->text().toUtf8().constData())
    };
  imgvol::ImgGray img = imgvol::CortePlanar(*img_vol, p1, vec);
  img.WriteImg("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g");
  ShowImage("/home/alex/Unicamp/img_ui/build-img_ui-Desktop-Debug/im__g", ui->label);
}
