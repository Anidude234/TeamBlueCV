#ifndef M_PI
#define M_PI 3.141592653589793238462643383
#endif

#include "targetProcessing.hpp"

TargetProcessing::TargetProcessing(double fl, int imgWidth, int imgHeight):
focalLength(fl), horizCenter(imgWidth/2), vertCenter(imgHeight/2)
{

}

void ::loadTarget(Target& target, double tgtWidth)
{
  targetWidth = target.getWidth();
  targetCenter = target.getCenter();
}

double TargetProcessing::calcDistance()
{
  return objectWidth*focalLength/targetWidth;
}

double TargetProcessing::calcAzimuth()
{
  return atan((double) ((targetCenter.x - horizCenter)/focalLength)) * (180/M_PI);
}

double TargetProcessing::calcAltitude()
{
  return atan((double) ((targetCenter.y - vertCenter)/focalLength)) * (180/M_PI);
}
