#pragma once

#ifndef SCENE_HPP
#define SCENE_HPP

#include "epd/epd2in7b.h"
#include "epd/epdpaint.h"
#include <utility> 

#define PAINT_COLORED	1
#define PAINT_UNCOLORED 0

/// <summary>
/// Interface, which make works with display easier.
/// In main loop, is created instance.
/// "init" - Function does only one time.
/// "scene" - Function does in each main loop step.
/// "closeScene" - Function cleans after works.
/// </summary>
class Scene
{	
public:	
	virtual void init(Epd &epd);
	virtual void scene() = 0;
	virtual void closeScene();
	
	void setSceneRotation(unsigned int rotation);
protected:
	Epd * p_epd = nullptr;//pointer to a display
	std::pair<unsigned char*, unsigned char*>m_bufferPair;//first buffer - black, second buffer - red
	std::pair<Paint*, Paint*>m_paintPair;  //first paint object - black, second paint object - red
};

#endif

