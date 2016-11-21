#include "img_utils.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

void ShowImage(std::string file, QLabel* label) {
  cv::Mat img;
  img = cv::imread(file);
  cv::cvtColor(img,img,CV_BGR2RGB);
  QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
  label->setPixmap(QPixmap::fromImage(imdisplay));
}
