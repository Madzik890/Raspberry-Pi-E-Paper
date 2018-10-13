#include "ImageScene.hpp"
#include "picture/pictureData.hpp"

/// <summary>
/// Inits the image scene.
/// </summary>
/// <param name = "epd"> Reference to a display </param>
void ImageScene::init(Epd &epd)
{
	Scene::init(epd);
	m_paintPair.first->Clear(PAINT_UNCOLORED);
	m_paintPair.second->Clear(PAINT_UNCOLORED);
	this->setSceneRotation(ROTATE_270);	
	p_epd->DisplayFrame(g_pictureDataBlack, g_pictureDataRed);
}

/// <summary>
/// Loop is empty, because the image does not have,
/// to be redraw.
/// </summary>
void ImageScene::scene()
{
}

/// <summary>
/// Cleans after work.
/// </summary>
void ImageScene::closeScene()
{
	Scene::closeScene();
}
