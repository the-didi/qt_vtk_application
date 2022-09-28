﻿#include "mainwindow.h"

#include <vtkOutputWindow.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    vtkOutputWindow::SetGlobalWarningDisplay(0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
