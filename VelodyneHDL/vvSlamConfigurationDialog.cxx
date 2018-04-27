#include "vvSlamConfigurationDialog.h"
#include "ui_vvSlamConfigurationDialog.h"
#include <QMessageBox>
#include <pqSettings.h>

vvSlamConfigurationDialog::vvSlamConfigurationDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::vvSlamConfigurationDialog)
{
  ui->setupUi(this);
  this->ui->Start->setMinimum(0);
  this->ui->End->setMinimum(0);
  this->ui->Start->setMaximum(50000);
  this->ui->End->setMaximum(50000);
}

vvSlamConfigurationDialog::~vvSlamConfigurationDialog()
{
  delete ui;
}

void vvSlamConfigurationDialog::accept()
{
  if (ui->Start->value() > ui->End->value())
  {
    QMessageBox::critical(this, "Invalid frame range",
      "The requested frame range is not valid. "
      "The start frame must be less than or equal to the stop frame.");
    return;
  }
  QDialog::accept();
}

int vvSlamConfigurationDialog::frameMode() const
{
  if (ui->currentFrame->isChecked())
  {
    return CURRENT_FRAME;
  }
  if (ui->allFrames->isChecked())
  {
    return ALL_FRAMES;
  }
  if (ui->frameRange->isChecked())
  {
    return FRAME_RANGE;
  }
}

int vvSlamConfigurationDialog::frameStart() const
{
  return ui->Start->value();
}

int vvSlamConfigurationDialog::frameStop() const
{
  return ui->End->value();
}

//--------------------------------------------------------------//
//                         General option
//--------------------------------------------------------------//
int vvSlamConfigurationDialog::NbVoxel()
{
  return ui->NbVoxel->value();
}

double vvSlamConfigurationDialog::AngleResolution()
{
  return ui->AngleResolution->value();
}
//--------------------------------------------------------------//
//                         Keypoint option
//--------------------------------------------------------------//
int vvSlamConfigurationDialog::Keypoint_MaxEdgePerScanLine()
{
  return ui->Keypoint_MaxEdgePerScanLine->value();
}

int vvSlamConfigurationDialog::Keypoint_MaxPlanarsPerScanLine()
{
  return ui->Keypoint_MaxPlanarsPerScanLine->value();
}

double vvSlamConfigurationDialog::Keypoint_MinDistanceToSensor()
{
  return ui->Keypoint_MinDistanceToSensor->value();
}

double vvSlamConfigurationDialog::Keypoint_PlaneCurvatureThreshold()
{
  return ui->Keypoint_PlaneCurvatureThreshold->value();
}

double vvSlamConfigurationDialog::Keypoint_EdgeCurvatureThreshold()
{
  return ui->Keypoint_EdgeCurvatureThreshold->value();
}
//--------------------------------------------------------------//
//                         Egomotion
//--------------------------------------------------------------//
int vvSlamConfigurationDialog::EgoMotion_MaxIter()
{
  return ui->EgoMotion_MaxIter->value();
}

int vvSlamConfigurationDialog::EgoMotion_IcpFrequence()
{
  return ui->EgoMotion_IcpFrequence->value();
}

int vvSlamConfigurationDialog::EgoMotion_LineDistance_k()
{
  return ui->EgoMotion_LineDistance_k->value();
}

double vvSlamConfigurationDialog::EgoMotion_LineDistance_factor()
{
  return ui->EgoMotion_LineDistance_factor->value();
}

int vvSlamConfigurationDialog::EgoMotion_PlaneDistance_k()
{
  return ui->EgoMotion_PlaneDistance_k->value();
}

double vvSlamConfigurationDialog::EgoMotion_PlaneDistance_factor1()
{
  return ui->EgoMotion_PlaneDistance_factor1->value();
}

double vvSlamConfigurationDialog::EgoMotion_PlaneDistance_factor2()
{
  return ui->EgoMotion_PlaneDistance_factor2->value();
}

double vvSlamConfigurationDialog::EgoMotion_Line_Max_Distance()
{
  return ui->EgoMotion_Line_Max_Distance->value();
}

double vvSlamConfigurationDialog::EgoMotion_Plane_Max_Distance()
{
  return ui->EgoMotion_Line_Max_Distance->value();
}

//--------------------------------------------------------------//
//                         Mapping
//--------------------------------------------------------------//
int vvSlamConfigurationDialog::Mapping_MaxIter()
{
  return ui->Mapping_MaxIter->value();
}

int vvSlamConfigurationDialog::Mapping_IcpFrequence()
{
  return ui->Mapping_IcpFrequence->value();
}

int vvSlamConfigurationDialog::Mapping_LineDistance_k()
{
  return ui->Mapping_LineDistance_k->value();
}

double vvSlamConfigurationDialog::Mapping_LineDistance_factor()
{
  return ui->Mapping_LineDistance_factor->value();
}

int vvSlamConfigurationDialog::Mapping_PlaneDistance_k()
{
  return ui->Mapping_PlaneDistance_k->value();
}

double vvSlamConfigurationDialog::Mapping_PlaneDistance_factor1()
{
  return ui->Mapping_PlaneDistance_factor1->value();
}

double vvSlamConfigurationDialog::Mapping_PlaneDistance_factor2()
{
  return ui->Mapping_PlaneDistance_factor2->value();
}

double vvSlamConfigurationDialog::Mapping_Line_Max_Distance()
{
  return ui->Mapping_Line_Max_Distance->value();
}

double vvSlamConfigurationDialog::Mapping_Plane_Max_Distance()
{
  return ui->Mapping_Plane_Max_Distance->value();
}