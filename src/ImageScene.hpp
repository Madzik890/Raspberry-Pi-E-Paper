#pragma once

#ifndef SCENEIMAGE_HPP
#define SCENEIMAGE_HPP

#include "Scene.hpp"

class ImageScene
	:public Scene
{
public:
	void init(Epd &epd);
	void scene();
	void closeScene();
};

#endif