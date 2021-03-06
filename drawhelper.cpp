#include "gamecontroller.h"
#include "drawhelper.h"

using namespace std;

DrawHelper::DrawHelper() {}

void DrawHelper::drawCars(vector<CellCar> &cars)
{
    for(vector<CellCar>::iterator iter = cars.begin(); iter != cars.end(); ++iter) {
        drawCar(*iter);
    }
}

void DrawHelper::drawBlocks(std::vector<CellBlock> &blocks)
{
    for(vector<CellBlock>::iterator iter = blocks.begin(); iter != blocks.end(); ++iter) {
        drawBlock(*iter);
    }
}

void DrawHelper::drawCarFactories(std::vector<CarFactory> &cfs)
{
    for(vector<CarFactory>::iterator iter = cfs.begin(); iter != cfs.end(); ++iter) {
        drawCarFactory(*iter);
    }
}

void DrawHelper::drawCarCollectors(std::vector<CarCollector> &ccs)
{
    for(vector<CarCollector>::iterator iter = ccs.begin(); iter != ccs.end(); ++iter) {
        drawCarCollector(*iter);
    }
}

void DrawHelper::syncPainter(QPainter *painter)
{
    this->painter = painter;
}

void DrawHelper::clc()
{
    this->painter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap));
    this->painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->painter->drawRect(0, 0, SIZE * RIGHTXLIM, SIZE * BOTTOMYLIM);
}

void DrawHelper::drawCar(CellCar &car)
{
    this->painter->setRenderHint(QPainter::Antialiasing, true);
    if(car.getSpeed() != 0) {
        this->painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
        this->painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    }
    else {
        this->painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap));
        this->painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));

    }
    this->painter->drawRect((int)(car.getX() * SIZE), (int)(car.getY() * SIZE), SIZE, SIZE);
}

void DrawHelper::drawBlock(CellBlock &block)
{
    this->painter->setRenderHint(QPainter::Antialiasing, true);
    this->painter->setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap));
    this->painter->setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    QRectF rect((int)(block.getX() * SIZE), (int)(block.getY() * SIZE), SIZE, SIZE);
    this->painter->drawRect(rect);
    this->painter->setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap));
    char text[] = {  block.getType(), '\0' };
    this->painter->drawText(rect, Qt::AlignHCenter, text);
}

void DrawHelper::drawCarFactory(CarFactory &cf)
{
    this->painter->setRenderHint(QPainter::Antialiasing, true);
    this->painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    this->painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->painter->drawRect((int)(cf.getX() * SIZE), (int)(cf.getY() * SIZE), SIZE, SIZE);
}

void DrawHelper::drawCarCollector(CarCollector &cc)
{
    this->painter->setRenderHint(QPainter::Antialiasing, true);
    this->painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    this->painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->painter->drawRect((int)(cc.getX() * SIZE), (int)(cc.getY() * SIZE), SIZE, SIZE);
}
