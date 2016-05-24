#include <string>

#include "camera.h"
/*
std::string CameraPike::getName(){
AVT::VmbAPI::FeaturePtr feature;
std::string name;
if ( VmbErrorSuccess == this ->GetFeatureByName( "Name", feature )){
if(VmbErrorSuccess == feature->GetValue(name)){
}
}
return name;
}

int* CameraPike::getSensorSize(){
AVT::VmbAPI::FeaturePtr feature;
VmbInt64_t width = 0, height = 0;
int size[2];
if ( VmbErrorSuccess == this ->GetFeatureByName( "SensorWidth", feature )){
if(VmbErrorSuccess == feature->GetValue(width)){
size[0] = width;
if ( VmbErrorSuccess == this ->GetFeatureByName( "SensorHeight", feature )){
if(VmbErrorSuccess == feature->GetValue(height)){
size[1] = height;
}
}
}
}
return size;
}

int* CameraPike::getPictureSize(){
AVT::VmbAPI::FeaturePtr feature;
VmbInt64_t width = 0, height = 0;
int size[2];
if ( VmbErrorSuccess == this ->GetFeatureByName( "Width", feature )){
if(VmbErrorSuccess == feature->GetValue(width)){
size[0] = width;
if ( VmbErrorSuccess == this ->GetFeatureByName( "Height", feature )){
if(VmbErrorSuccess == feature->GetValue(height)){
size[1] = height;
}
}
}
}
return size;
}

std::string CameraPike::getPixelFormat(){
AVT::VmbAPI::FeaturePtr feature;
std::string format;
if ( VmbErrorSuccess == this ->GetFeatureByName( "PixelFormat", feature )){
if(VmbErrorSuccess == feature->GetValue(format)){
}
}
return format;
}

int CameraPike::getExposureTime(){
AVT::VmbAPI::FeaturePtr feature;
VmbInt64_t time_us = 0;
std::string featureMode;
if ( VmbErrorSuccess == this ->GetFeatureByName( "ExposureMode", feature )){
if(VmbErrorSuccess == feature->GetValue(featureMode)){
if (featureMode.compare("Timed") == 0){
if ( VmbErrorSuccess == this ->GetFeatureByName( "ExposureTime", feature )){
if(VmbErrorSuccess == feature->GetValue(time_us)){
return time_us;
}
}
}
}
}
return time_us;
}

bool CameraPike::setExposureTime(int time_us){
AVT::VmbAPI::FeaturePtr feature;
std::string featureMode;
if ( VmbErrorSuccess == this ->GetFeatureByName( "ExposureMode", feature )){
if(VmbErrorSuccess == feature->GetValue(featureMode)){
if (featureMode.compare("Timed") == 0){
if(VmbErrorSuccess != feature->SetValue("Timed")) return false;
}
}
if ( VmbErrorSuccess == this ->GetFeatureByName( "ExposureTime", feature )){
if(VmbErrorSuccess == feature->SetValue(time_us)) return true;
else return false;
}
else return false;
}
else return false;
}

bool CameraPike::reverseX(){
AVT::VmbAPI::FeaturePtr feature;
if ( VmbErrorSuccess == this ->GetFeatureByName( "ReverseX", feature )){
if ( VmbErrorSuccess == feature->RunCommand()){
return true;
}
}
return false;
}

bool CameraPike::reverseY(){
AVT::VmbAPI::FeaturePtr feature;
if ( VmbErrorSuccess == this ->GetFeatureByName( "ReverseY", feature )){
if ( VmbErrorSuccess == feature->RunCommand()){
return true;
}
}
return false;
}

bool CameraPike::setPixelColorFilter_auto(){
AVT::VmbAPI::FeaturePtr feature;
if ( VmbErrorSuccess == this ->GetFeatureByName( "PixelColorFilterAuto", feature )){
if ( VmbErrorSuccess == feature->SetValue("Auto")){
return true;
}
}
return false;
}

std::string CameraPike::getPixelColorFilter(){
AVT::VmbAPI::FeaturePtr feature;
std::string mode;
if ( VmbErrorSuccess == this ->GetFeatureByName( "PixelColorFilter", feature )){
if ( VmbErrorSuccess == feature->GetValue(mode)){
}
}
return mode;
}

bool CameraPike::setPixelColorFilter(char *mode){
AVT::VmbAPI::FeaturePtr feature;
if ( VmbErrorSuccess == this ->GetFeatureByName( "PixelColorFilterAuto", feature )){
if ( VmbErrorSuccess == feature->SetValue("Manual")){
if ( VmbErrorSuccess == this ->GetFeatureByName( "PixelColorFilter", feature )){
if ( VmbErrorSuccess == feature->SetValue(mode)){
return true;
}
}
}
}
return false;
}
*/