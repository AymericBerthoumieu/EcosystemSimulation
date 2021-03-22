#include "MoveUtils.h"

void MoveUtils::setMoveParameters(Animal& a, int& x, int& y, int xLim, int yLim, double& orientation, double& speed, double& cumulX, double& cumulY){

	double nx, ny;
	double dx = cos( orientation )*speed;
	double dy = -sin( orientation )*speed;
	int cx, cy;

	cx = static_cast<int>( cumulX ); cumulX -= cx;
	cy = static_cast<int>( cumulY ); cumulY -= cy;

	nx = x + dx + cx;
	ny = y + dy + cy;

	if ( (nx < 0) || (nx > xLim - 1) ) {
	  orientation = M_PI - orientation;
	  cumulX = 0.;}
	else {
	  x = static_cast<int>( nx );
	  cumulX += nx - x;}

	if ( (ny < 0) || (ny > yLim - 1) ) {
	  orientation = -orientation;
	  cumulY = 0.;}
	else {
	  y = static_cast<int>( ny );
	  cumulY += ny - y;} 


	a.setCoordinates(x,y);
	a.setCumul(cumulX,cumulY);
	a.setOrientationSpeed(orientation,speed); 
}