#include "Scene.hpp"
#include <stdlib.h>
#include <stdio.h>

/// <summary>
/// Initiates buffer and paints.
/// Buffers and paints are in pair.
/// First object - black color.
/// Second object - red color.
/// <summary>
/// <param name = "epd"> Reference to a display </param>
void Scene::init(Epd &epd)
{
	this->p_epd = &epd;//reference to a display
	
	/// <black color>
	m_bufferPair.first = (unsigned char*)calloc(1, p_epd->width / 8 * p_epd->height);  //black
	m_paintPair.first = new Paint(m_bufferPair.first, p_epd->width, p_epd->height);  //black paint
	/// </black color>
	
	/// <red color>
	m_bufferPair.second = (unsigned char*)calloc(1, p_epd->width / 8 * p_epd->height);   //red
	m_paintPair.second = new Paint(m_bufferPair.second, p_epd->width, p_epd->height);  //red paint
	/// </red color>
}

/// <summary>
/// Releases a memory from objects, created in "init" function.
/// <summary>
void Scene::closeScene()
{
	delete(m_bufferPair.first);//release the buffer red color
	delete(m_paintPair.first);//release the paint red color
	
	delete(m_bufferPair.second);//release the buffer black color
	delete(m_paintPair.second);//release the paint black color
}

/// <summary>
/// Sets a screen rotation and makes it to paint members.
/// <summary>
/// <param name = "rotation"> Type of rotation </param>
void Scene::setSceneRotation(unsigned int rotation)
{
	m_paintPair.first->SetRotate(rotation);
	m_paintPair.second->SetRotate(rotation);
}
