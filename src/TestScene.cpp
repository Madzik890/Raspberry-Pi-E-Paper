#include "TestScene.hpp"
#include "epd/fonts.h"

/// <summary>
/// Inits a test scene.
/// </summary>
/// <param name = "epd"> Reference to a display </param>
void TestScene::init(Epd &epd)
{
	Scene::init(epd);
	m_paintPair.first->Clear(PAINT_UNCOLORED);
	m_paintPair.second->Clear(PAINT_UNCOLORED);
	setSceneRotation(ROTATE_270);
	
	m_paintPair.first->DrawStringAt(50, 150, "Scene test", &Font20, PAINT_COLORED);
	p_epd->DisplayFrame(m_paintPair.first->GetImage(), m_paintPair.second->GetImage());
}

/// <summary>
/// Loop is empty, because the image does not have,
/// to be redraw.
/// </summary>
void TestScene::scene()
{
}

/// <summary>
/// Cleans after work.
/// </summary>
void TestScene::closeScene()
{
	Scene::closeScene();
}

