//====================================================
// App.cpp
//====================================================
#include "DragonFireSDK.h"
#include "time.h"
int BallImage2;														//informacion
int BallView2;
int BallX;															//posicion
int BallY;
int BackdropImage;													//Image handles:
int BackdropView;
int GlobalY;														//Keeps track of the "world's" Y coordinate.
int DeltaY;
#define ImpulseSpeed 1												//Scroll Speeds
void AppMain()
{
// Application initialization code goes here.  Create the items / objects / etc.
// that your app will need while it is running.
/*valida licencia*/
	time_t now;														//time_t should be declared in time.h as long
	struct tm *current;												//pointer to array holding the current time
	now = time(0);													//current time in C representation
	current = localtime(&now);										//IMPORTANT you have to use a pointer to
	if ((current->tm_year + 1900) < 2013)
	{
		ViewAdd("Images/0.png",0,0);
		BallX=0;
		BallY=143;
		BallImage2 = ImageAdd("Images/2.png");
		BallView2 = ViewAdd(BallImage2, BallX, BallY);
		DeltaY = ImpulseSpeed;										//para el fondo
		GlobalY = -141;												//-4800
		BackdropImage = ImageAdd("Images/1.png");					//gira logotipo
		BackdropView = ViewAdd(BackdropImage, 41, GlobalY);			// Show background image
	}
	return;
	struct tm {
		int tm_sec;														/* seconds after the minute - [0,59] */
		int tm_min;														/* minutes after the hour - [0,59] */
		int tm_hour;													/* hours since midnight - [0,23] */
		int tm_mday;													/* day of the month - [1,31] */
		int tm_mon;														/* months since January - [0,11] */
		int tm_year;													/* years since 1900 */
		int tm_wday;													/* days since Sunday - [0,6] */
		int tm_yday;													/* days since January 1 - [0,365] */
		int tm_isdst;													/* daylight savings time flag */
	};
}
void AppExit()
{
	// Application exit code goes here.  Perform any clean up your app might 
	// need to do in the event of interruption by a phone call or the user
	// pressing the Home button, or some other event that would cause your
	// application to terminate.
}
void OnTimer()
{
// Main loop code goes here.  OnTimer() is called 30 times per second.
	GlobalY += DeltaY;							//Scroll the Background
	if (GlobalY >= 0)							//When at the end, loop background  0
		//GlobalY = -141;						//hace el loop
		GlobalY = 0;
	ViewSetxy(BackdropView, 41, GlobalY);		// Update Backdrop's location	0
}