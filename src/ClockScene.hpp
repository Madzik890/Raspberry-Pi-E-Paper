#pragma once

#ifndef CLOCKSCENE_HPP
#define CLOCKSCENE_HPP

#include "Scene.hpp"
#include <ctime>
#include <string>

/// <summary>
/// Scene which draws an analog clock.
/// Clock is synchrony with system time.
/// <summary>
class ClockScene
	:public Scene
{
public:
	void init(Epd &epd);
	void scene();
	void closeScene();
	
private:
	bool b_refreshDisplay = true;//redraw flag
	
	/// <ctime members>
	int i_lastHour = 0;	
	int i_lastMinute = 0;
	time_t m_timeNow = time(0);
	tm * m_tmNow;
	/// <ctime members>
	
	void getLastTime();
	std::string getTimeToString();
};

#endif

