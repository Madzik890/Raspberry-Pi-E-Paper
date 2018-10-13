#include "ClockScene.hpp"
#include "epd/fonts.h"
#include <stdio.h>
#include <math.h>


#define M_PI 3.14159265358979323846//Math PI used in clock hands calculation.
/// <clock variables>
#define CLOCK_CENTER_X 88
#define CLOCK_CENTER_Y 110
#define CLOCK_RADIUS 80
/// </clock variables>

/// <summary>
/// Inits the clock scene.
/// </summary>
/// <param name = "epd"> Reference to a display </param>
void ClockScene::init(Epd &epd)
{
	Scene::init(epd);
	this->setSceneRotation(ROTATE_0);	
}

/// <summary>
/// Draws a analog clock on E-Paper.
/// Clock is synchronizes with system time.
/// Every minute clock is redraw.
/// </summary>
void ClockScene::scene()
{
	getLastTime();//check time
	if (b_refreshDisplay)//if the redraw flag is true
	{	
		m_paintPair.first->Clear(PAINT_UNCOLORED);//clear display
		m_paintPair.second->Clear(PAINT_UNCOLORED);//clear display
		unsigned int u_lineEndX, u_lineEndY;
		/// <display clock>
		m_paintPair.first->DrawCircle(CLOCK_CENTER_X, CLOCK_CENTER_Y, CLOCK_RADIUS, PAINT_COLORED);
		
		u_lineEndX = CLOCK_CENTER_X + 60 * sin(i_lastHour * 30 * M_PI / 180); //firstPos_x + radius * sin((hour * angleOfHour) * PI / 180)
		u_lineEndY = CLOCK_CENTER_Y - 60 * cos(i_lastHour * 30 * M_PI / 180); //firstPos_y - radius * cos((hour * angleOfHour) * PI / 180)
		m_paintPair.first->DrawLine(CLOCK_CENTER_X, CLOCK_CENTER_Y, u_lineEndX, u_lineEndY, PAINT_COLORED);  //draw hour hand
		
		u_lineEndX = CLOCK_CENTER_X + 70 * sin(i_lastMinute * 6 * M_PI / 180); //firstPos_x + radius * sin((hour * angleOfHour) * PI / 180)
		u_lineEndY = CLOCK_CENTER_Y - 70 * cos(i_lastMinute * 6 * M_PI / 180); //firstPos_y - radius * cos((hour * angleOfHour) * PI / 180)
		m_paintPair.second->DrawLine(CLOCK_CENTER_X, CLOCK_CENTER_Y, u_lineEndX, u_lineEndY, PAINT_COLORED);  //draw minute hand
		/// </display clock>
		
		std::string s_time = getTimeToString();
		m_paintPair.second->DrawStringAt(30, 230, s_time.c_str(), &Font20, PAINT_COLORED);//draw the string time
		
		p_epd->DisplayFrame(m_paintPair.first->GetImage(), m_paintPair.second->GetImage());//draw the prepared scene
		b_refreshDisplay = false;//set flag to done draw
	}
}

/// <summary>
/// Close scene.
/// </summary>
void ClockScene::closeScene()
{
	Scene::closeScene();
}

/// <summary>
/// Gets time, when last minute is not current,
/// sets a flag to redraw clock.
/// </summary>
void ClockScene::getLastTime()
{
	m_timeNow = time(0);//reset the time object
	m_tmNow = localtime(&m_timeNow);//gets an actual time
	if (i_lastMinute != m_tmNow->tm_min)//if last elapsed second is different than actual
	{
		i_lastHour = m_tmNow->tm_hour;
		i_lastMinute = m_tmNow->tm_min;//refresh minute
		b_refreshDisplay = true;//command to refresh a display
	}
	else
		b_refreshDisplay = false;//if not waits to change
}

/// <summary>
/// Changes a time from int's to char string.
/// </summary>
/// <return> An actual time in string </return>
std::string ClockScene::getTimeToString()
{
	std::string s_result;
	s_result += std::to_string(i_lastHour);
	s_result += ":";
	s_result += std::to_string(i_lastMinute);
	
	return s_result;
}