#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QImage>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filename("C:/test/pic.jpg");
    QImage img;
    if(! ( img.load(filename) ) ) //加载图像
    {
        QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
        return;
    }
    QImage newImg = img.scaled(ui->label->width(), ui->label->height());//设定大小   图片适应label大小
    ui->label->setPixmap(QPixmap::fromImage(newImg));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QImage img("C:/test/pic.jpg");
    QPixmap cutPic = QPixmap::fromImage(img).copy(0,0,200,300);//从（0，0）截取200*300的图像
    ui->label->resize(cutPic.width(),cutPic.height());//设定大小  label适应图片
    ui->label->setPixmap(cutPic);

}
