#pragma once

#ifndef TESTSCENE_HPP
#define TESTSCENE_HPP

#include "Scene.hpp"

class TestScene
	:public Scene
{
public:
	void init(Epd &epd);
	void scene();
	void closeScene();
};

#endif

