#ifndef VTK_FUNCTION_H
#define VTK_FUNCTION_H

//-----------------------------vtk---------------------------------
#include "QVTKWidget.h"
#include <vtkRenderWindow.h>
#include <vtkAutoInit.h>
#include "vtkVertexGlyphFilter.h"
#include "vtkClipPolyData.h"
#include "vtkNamedColors.h"
#include "vtkImplicitPlaneRepresentation.h"
#include "vtkImplicitPlaneWidget2.h"
#include "vtkIdFilter.h"
#include "vtkPlane.h"
#include "vtkPLYWriter.h"
#include "vtkBoxWidget.h"
#include "vtkBoxRepresentation.h"
#include "vtkBoxWidget2.h";
#include "vtkVolume.h"
#include <vtkTransform.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

class vtk_function
{
public:
    vtk_function();
};

#endif // VTK_FUNCTION_H
