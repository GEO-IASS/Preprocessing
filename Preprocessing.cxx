/*========================================================================= */

// CRIM : Centre de recherche en informatique de Montréal

// Équipe Télédetection pour les catastrophes majeures (TCM).

// Programme : Extraction des rivières à partir des images Radar.

// Auteur : Moslem Ouled Sghaier

// Version : 0

/*========================================================================= */

#include "otbImage.h"
#include "otbImageFileReader.h"
#include "otbImageFileWriter.h"
#include "itkCastImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkCannyEdgeDetectionImageFilter.h"
#include "otbSFSTexturesImageFilter.h"
#include "itkGrayscaleDilateImageFilter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryThresholdImageFilter.h"
#include "itkFlatStructuringElement.h"

#include "itkImage.h"
#include "itkImageRegionIteratorWithIndex.h"
#include <iostream>
#include "itkVector.h"
#include "itkBresenhamLine.h"
#include <vector>
#include <math.h>
#include <ctime>

#include "itkIntensityWindowingImageFilter.h"

#include "otbWrapperApplication.h" 
#include "otbWrapperApplicationRegistry.h"
#include "otbWrapperApplicationFactory.h"
#include "otbWrapperTags.h"

// Copier une image dans une autre
#include "itkPasteImageFilter.h"

//Utils
#include "itksys/SystemTools.hxx"
#include "itkListSample.h"

//otb filter
#include "otbExtractROI.h"

// Elevation handler
#include "otbWrapperElevationParametersHandler.h"

// lee filter

#include "otbFrostImageFilter.h"

#include "itkMeanImageFilter.h"

//using namespace std;

namespace otb
{
namespace Wrapper
{

class Preprocessing : public Application
{

public:
	typedef Preprocessing Self;
    typedef Application              Superclass;
    typedef itk::SmartPointer<Self>       Pointer;
    typedef itk::SmartPointer<const Self> ConstPointer;


/** Standard macro */
    itkNewMacro(Self);
    itkTypeMacro(Preprocessing, otb::Application);

private:

void DoInit()
{

SetName("Preprocessing"); // Nécessaire
SetDocName("Preprocessing");
SetDocLongDescription("Un simple module pour application des pretraitement necessaire pour les images radar");
SetDocLimitations("Les autres paramètres seront ajoutés plus tard");
SetDocAuthors("Moslem Ouled Sghaier");


AddParameter(ParameterType_InputImage,"in", "Input Image");
SetParameterDescription("in", "The input image");
AddParameter(ParameterType_OutputImage,"out", "Output Image");
SetParameterDescription("out","The output image");

}

void DoUpdateParameters()
{
	// Nothing to do here : all parameters are independent
}


void DoExecute()
{

typedef unsigned char CharPixelType; // IO
const unsigned int Dimension = 2;
typedef otb::Image<CharPixelType, Dimension> CharImageType;

typedef itk::IntensityWindowingImageFilter <FloatImageType, CharImageType> IntensityWindowingImageFilterType;

IntensityWindowingImageFilterType::Pointer filter = IntensityWindowingImageFilterType::New();
filter->SetInput(GetParameterFloatImage("in"));
filter->SetWindowMinimum(0);
filter->SetWindowMaximum(1);
filter->SetOutputMinimum(0);
filter->SetOutputMaximum(255);
filter->Update(); 


std::cout << "La conversion est faite avec succès" << std::endl ; 

SetParameterOutputImage("out",filter->GetOutput()); 
}

     };
}
   
}
OTB_APPLICATION_EXPORT(otb::Wrapper::Preprocessing);