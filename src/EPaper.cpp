#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "epd/epd2in7b.h"
#include "epd/epdpaint.h"

#include "TestScene.hpp"
#include "ImageScene.hpp"
#include "ClockScene.hpp"
#include "Keys.hpp"


int main()
{
	Epd m_epd;
	if (m_epd.Init() != 0)//init 
	{
		printf("e-Paper init failed\n");
		return -1;
	}
	initKeys();//prepare keys
	
	Scene * m_scene = dynamic_cast<TestScene*>(new TestScene());
	
	while (true)
	{
		switch (getKeyInput())
		{
		case 1://"Key1" is pressed
			m_scene->closeScene();
			delete(m_scene);
			m_scene = dynamic_cast<ImageScene*>(new ImageScene());
			m_scene->init(m_epd);
			break;
			
		case 2://"Key2" is pressed
			m_scene->closeScene();
			delete(m_scene);
			m_scene = dynamic_cast<ClockScene*>(new ClockScene());
			m_scene->init(m_epd);
			break;
			
		case 3://"Key1" & "Key2" is pressed
			m_scene->closeScene();
			delete(m_scene);
			m_scene = dynamic_cast<TestScene*>(new TestScene());
			m_scene->init(m_epd);
			break;
		}
		
		m_scene->scene();//main loop the scene
		usleep(10000);//waits 1 second to not waste CPU time
	}
	
	return 0;
}