#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    <QFileDialog>
#include    <QMessageBox>
#include    <QSoundEffect>
#include    <QSound>

// vtk
#include "vtkRenderer.h"
#include "vtkSTLReader.h"
#include "vtkPolyDataMapper.h";
#include "vtkLight.h"
#include "vtkCamera.h"
#include "vtkConeSource.h"
#include "vtkProperty.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 隐藏默认的标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    // 获取默认的摄像机列表
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.size()>0)
    {
        iniCamera();
        curCamera->start();
    }

    // 加载vtk函数
    // 加载背景颜色
    init_background();
    // 加载飞机模型
    init_model();
    // 加载地面
    init_ground();
    // 加载场景灯光
    init_light();
    // 加载相机
    init_camera();
    init_sub_renderer();
    renderWindow->AddRenderer(renderer);
    ui->vtk_view_finder->SetRenderWindow(renderWindow);
    ui->vtk_view_finder->update();
}


void MainWindow::init_background(){
    renderWindow=vtkSmartPointer<vtkRenderWindow>::New();
    renderer = vtkRenderer::New();
    renderer->SetBackground(0.1, 0.2, 0.4);

}

void MainWindow::init_model(){
    vtkSmartPointer<vtkSTLReader> reader=vtkSmartPointer<vtkSTLReader>::New();
    std::string inputFilename = "D://Allproject//QT//fly_application//res//model.stl";
    reader->SetFileName(inputFilename.c_str());
    reader->Update();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetAmbient(0.125);
    renderer->AddActor(actor);
}

// 加载地面网格
void MainWindow::init_ground(){
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

    double rangeX[2] = { -100.0, 100.0 };
    double rangeY[2] = { -100.0, 100.0 };
    double intervalX = 1.0, intervalY = 1.0;
    // Y lines
    for (double gridX = rangeX[0]; gridX < rangeX[1] + (intervalX / 2.0); gridX += intervalX)
    {
       double lineStart[3] = { gridX, rangeY[0], 0.0 };
       double lineEnd[3] = { gridX, rangeY[1], 0.0 };

       vtkIdType pointIdStart = points->InsertNextPoint(lineStart);
       vtkIdType pointIdEnd = points->InsertNextPoint(lineEnd);
       vtkIdType singleLineCell[2] = { pointIdStart, pointIdEnd };
       cells->InsertNextCell(2, singleLineCell);
    }

        // x lines
    for (double gridY = rangeY[0]; gridY < rangeY[1] + (intervalY / 2.0); gridY += intervalY)
    {
       double lineStart[3] = { rangeX[0], gridY, 0.0 };
       double lineEnd[3] = { rangeX[1], gridY, 0.0 };

       vtkIdType pointIdStart = points->InsertNextPoint(lineStart);
       vtkIdType pointIdEnd = points->InsertNextPoint(lineEnd);

       vtkIdType singleLineCell[2] = { pointIdStart, pointIdEnd };
       cells->InsertNextCell(2, singleLineCell);
    }

    polydata->SetLines(cells);
    polydata->SetPoints(points);
    mapper->SetInputData(polydata);
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->RotateX(90);
    renderer->AddActor(actor);
}

void MainWindow::init_light(){
//    vtkSmartPointer<vtkLight> myLight =vtkSmartPointer<vtkLight>::New();
//    myLight->SetColor(0, 255, 0);
//    myLight->SetPosition(100, 0, 10);
//    myLight->SetFocalPoint(
//    renderer->GetActiveCamera()->GetFocalPoint());
//    renderer->AddLight(myLight);
//    vtkSmartPointer<>
}

void MainWindow::init_camera(){
    vtkSmartPointer<vtkConeSource> Cone=vtkSmartPointer<vtkConeSource>::New();
    Cone->SetHeight(100.0);
    Cone->SetRadius(30.0);
    Cone->SetResolution(9);
    vtkSmartPointer<vtkPolyDataMapper> coneMapper=vtkSmartPointer<vtkPolyDataMapper>::New();
    coneMapper->SetInputConnection(Cone->GetOutputPort());
    vtkSmartPointer<vtkActor> coneActor=vtkSmartPointer<vtkActor>::New();
    coneActor->SetMapper(coneMapper);
    coneActor->SetPosition(0,10,40);
    coneActor->RotateY(-90);
    coneActor->RotateX(-60);
    coneActor->GetProperty()->SetOpacity(0.5);
    renderer->AddActor(coneActor);

}

void MainWindow::init_sub_renderer(){
    // 设置渲染窗口
    vtkSmartPointer<vtkRenderWindow> win=vtkSmartPointer<vtkRenderWindow>::New();
    // 设置渲染器
    vtkSmartPointer<vtkRenderer> ren=vtkSmartPointer<vtkRenderer>::New();
    ren->SetBackground(0.1, 0.2, 0.4);
    // 加载模型
    vtkSmartPointer<vtkSTLReader> reader=vtkSmartPointer<vtkSTLReader>::New();
    std::string inputFilename = "D://Allproject//QT//fly_application//res//model.stl";
    reader->SetFileName(inputFilename.c_str());
    reader->Update();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetAmbient(0.125);
    ren->AddActor(actor);
    win->AddRenderer(ren);
    ui->vtk_subview_finder->SetRenderWindow(win);
    ui->vtk_subview_finder->update();
}

// 初始化摄像头
void MainWindow::iniCamera()
{//  创建  QCamera对象
    QCameraInfo curCameraInfo=QCameraInfo::defaultCamera(); //获取缺省摄像头
    curCamera=new QCamera(curCameraInfo,this); //创建摄像头对象
    QCameraViewfinderSettings viewfinderSettings;
//    viewfinderSettings.setResolution(640, 480);
//    viewfinderSettings.setMinimumFrameRate(15.0);
//    viewfinderSettings.setMaximumFrameRate(30.0);
    curCamera->setViewfinderSettings(viewfinderSettings);

    curCamera->setViewfinder(ui->viewFinder_3); //设置取景框预览
//    curCamera->setCaptureMode(QCamera::CaptureViewfinder);
    curCamera->setCaptureMode(QCamera::CaptureStillImage);//设置为抓图
//    curCamera->setCaptureMode(QCamera::CaptureVideo);
//    ui->checkExposure->setChecked(curCamera->exposure()->isAvailable()); //支持报告补偿
//    ui->checkFocus->setChecked(curCamera->focus()->isAvailable());//支持变焦

    connect(curCamera,SIGNAL(stateChanged(QCamera::State)),
            this,SLOT(on_cameraStateChanged(QCamera::State)));

//Windows平台上不支持captureModeChanged()信号
    connect(curCamera,SIGNAL(captureModeChanged(QCamera::CaptureModes)),
            this,SLOT(on_cameraCaptureModeChanged(QCamera::CaptureModes)));

//    connect(curCamera,SIGNAL(statusChanged(QCamera::Status)),
//            this,SLOT(on_camera_statusChanged(QCamera::Status)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_menu_tab_currentChanged(int index)
{
    if(index==5){
        ui->stackedWidget->setCurrentIndex(1);
    }
    if(index==0){
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void MainWindow::on_min_button_clicked()
{

    showMinimized();
}


void MainWindow::on_max_button_clicked()
{

    showMaximized();
}


void MainWindow::on_close_button_clicked()
{

    close();
}

