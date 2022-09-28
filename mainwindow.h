#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include    <QCameraInfo>
#include    <QCamera>
#include    <QLabel>

#include    <QCameraViewfinder>
#include    <QCameraImageCapture>
#include    <QMediaRecorder>

#include <hardware_infomation.h>
#include <vtk_function.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QCamera     *curCamera=Q_NULLPTR;//
    void    iniCamera();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 加载背景
    void init_background();
    // 加载模型
    void init_model();
    // 加载相机
    void init_camera();

    // 加载地面
    void init_ground();


    // 加载灯光
    void init_light();


    // 加载子视口飞机
    void init_sub_renderer();
private:
    vtkSmartPointer<vtkRenderWindow> renderWindow;

    vtkSmartPointer<vtkRenderer> renderer;

    vtkSmartPointer<vtkPolyDataMapper> mapper;

private slots:
    void on_menu_tab_currentChanged(int index);

    void on_min_button_clicked();

    void on_max_button_clicked();

    void on_close_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
