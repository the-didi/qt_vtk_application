QT       += core gui

QT += multimedia

QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hardware_infomation.cpp \
    main.cpp \
    mainwindow.cpp \
    vtk_function.cpp

HEADERS += \
    hardware_infomation.h \
    mainwindow.h \
    vtk_function.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/PCL/PCL1.11.1/3rdParty/vtk_QT/include/vtk-8.2\

LIBS += -LD:/PCL/PCL1.11.1/3rdParty/VTK_QT/lib\
        -lQVTKWidgetPlugin\
        -lvtkChartsCore-8.2\
        -lvtkCommonColor-8.2\
        -lvtkCommonComputationalGeometry-8.2\
        -lvtkCommonCore-8.2\
        -lvtkCommonDataModel-8.2\
        -lvtkCommonExecutionModel-8.2\
        -lvtkCommonMath-8.2\
        -lvtkCommonMisc-8.2\
        -lvtkCommonSystem-8.2\
        -lvtkCommonTransforms-8.2\
        -lvtkDICOMParser-8.2\
        -lvtkDomainsChemistry-8.2\
        -lvtkDomainsChemistryOpenGL2-8.2\
        -lvtkdoubleconversion-8.2\
        -lvtkexodusII-8.2\
        -lvtkexpat-8.2\
        -lvtkFiltersAMR-8.2\
        -lvtkFiltersCore-8.2\
        -lvtkFiltersExtraction-8.2\
        -lvtkFiltersFlowPaths-8.2\
        -lvtkFiltersGeneral-8.2\
        -lvtkFiltersGeneric-8.2\
        -lvtkFiltersGeometry-8.2\
        -lvtkFiltersHybrid-8.2\
        -lvtkFiltersHyperTree-8.2\
        -lvtkFiltersImaging-8.2\
        -lvtkFiltersModeling-8.2\
        -lvtkFiltersParallel-8.2\
        -lvtkFiltersParallelImaging-8.2\
        -lvtkFiltersPoints-8.2\
        -lvtkFiltersProgrammable-8.2\
        -lvtkFiltersSelection-8.2\
        -lvtkFiltersSMP-8.2\
        -lvtkFiltersSources-8.2\
        -lvtkFiltersStatistics-8.2\
        -lvtkFiltersTexture-8.2\
        -lvtkFiltersTopology-8.2\
        -lvtkFiltersVerdict-8.2\
        -lvtkfreetype-8.2\
        -lvtkGeovisCore-8.2\
        -lvtkgl2ps-8.2\
        -lvtkglew-8.2\
        -lvtkGUISupportQt-8.2\
        -lvtkGUISupportQtOpenGL-8.2\
        -lvtkGUISupportQtSQL-8.2\
        -lvtkhdf5-8.2\
        -lvtkhdf5_hl-8.2\
        -lvtkImagingColor-8.2\
        -lvtkImagingCore-8.2\
        -lvtkImagingFourier-8.2\
        -lvtkImagingGeneral-8.2\
        -lvtkImagingHybrid-8.2\
        -lvtkImagingMath-8.2\
        -lvtkImagingMorphological-8.2\
        -lvtkImagingSources-8.2\
        -lvtkImagingStatistics-8.2\
        -lvtkImagingStencil-8.2\
        -lvtkInfovisCore-8.2\
        -lvtkInfovisLayout-8.2\
        -lvtkInteractionImage-8.2\
        -lvtkInteractionStyle-8.2\
        -lvtkInteractionWidgets-8.2\
        -lvtkIOAMR-8.2\
        -lvtkIOAsynchronous-8.2\
        -lvtkIOCityGML-8.2\
        -lvtkIOCore-8.2\
        -lvtkIOEnSight-8.2\
        -lvtkIOExodus-8.2\
        -lvtkIOExport-8.2\
        -lvtkIOExportOpenGL2-8.2\
        -lvtkIOExportPDF-8.2\
        -lvtkIOGeometry-8.2\
        -lvtkIOImage-8.2\
        -lvtkIOImport-8.2\
        -lvtkIOInfovis-8.2\
        -lvtkIOLegacy-8.2\
        -lvtkIOLSDyna-8.2\
        -lvtkIOMINC-8.2\
        -lvtkIOMovie-8.2\
        -lvtkIONetCDF-8.2\
        -lvtkIOParallel-8.2\
        -lvtkIOParallelXML-8.2\
        -lvtkIOPLY-8.2\
        -lvtkIOSegY-8.2\
        -lvtkIOSQL-8.2\
        -lvtkIOTecplotTable-8.2\
        -lvtkIOVeraOut-8.2\
        -lvtkIOVideo-8.2\
        -lvtkIOXML-8.2\
        -lvtkIOXMLParser-8.2\
        -lvtkjpeg-8.2\
        -lvtkjsoncpp-8.2\
        -lvtklibharu-8.2\
        -lvtklibxml2-8.2\
        -lvtklz4-8.2\
        -lvtklzma-8.2\
        -lvtkmetaio-8.2\
        -lvtkNetCDF-8.2\
        -lvtkogg-8.2\
        -lvtkParallelCore-8.2\
        -lvtkpng-8.2\
        -lvtkproj-8.2\
        -lvtkpugixml-8.2\
        -lvtkRenderingAnnotation-8.2\
        -lvtkRenderingContext2D-8.2\
        -lvtkRenderingContextOpenGL2-8.2\
        -lvtkRenderingCore-8.2\
        -lvtkRenderingFreeType-8.2\
        -lvtkRenderingGL2PSOpenGL2-8.2\
        -lvtkRenderingImage-8.2\
        -lvtkRenderingLabel-8.2\
        -lvtkRenderingLOD-8.2\
        -lvtkRenderingOpenGL2-8.2\
        -lvtkRenderingQt-8.2\
        -lvtkRenderingVolume-8.2\
        -lvtkRenderingVolumeOpenGL2-8.2\
        -lvtksqlite-8.2\
        -lvtksys-8.2\
        -lvtktheora-8.2\
        -lvtktiff-8.2\
        -lvtkverdict-8.2\
        -lvtkViewsContext2D-8.2\
        -lvtkViewsCore-8.2\
        -lvtkViewsInfovis-8.2\
        -lvtkViewsQt-8.2\
        -lvtkzlib-8.2


RESOURCES += \
    res.qrc
