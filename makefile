CC = g++
PARAM = -o ePaper -std=c++11
LIBS = -lwiringPi
LIBSSOURCE = ./src/epd/epdpaint.cpp ./src/epd/epdif.cpp ./src/epd/epd2in7b.cpp ./src/epd/font8.c ./src/epd/font12.c ./src/epd/font16.c ./src/epd/font20.c ./src/epd/font24.c
IMAGEDATA = ./src/picture/pictureData.cpp
SOURCE = ./src/EPaper.cpp ./src/Keys.cpp ./src/Scene.cpp ./src/TestScene.cpp ./src/ImageScene.cpp ./src/ClockScene.cpp

all:	$(LIBSSOURCE) $(IMAGEDATA) $(SOURCE)
		$(CC) $(PARAM) $(LIBSSOURCE) $(IMAGEDATA) $(SOURCE) $(LIBS)