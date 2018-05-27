#include "liferect.h"

LifeRect::LifeRect(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):QGraphicsRectItem(x,y,w,h,parent)
{
   // Вначале цвет - белый(0)
  this->setBrush(QBrush(Qt::white));
}

LifeRect::~LifeRect()
{

}

void LifeRect::mousePressEvent(QGraphicsSceneMouseEvent *event){
    changeColor();//Вызываем changeColor если кликнули по прямоугольнику
}


void LifeRect::changeColor(){
    /* Здесь проблем быть не должно. Если текущий цвет - белый, выставляем черный и наоборот */
    if (this->brush().color() == Qt::white)
    {
        this->setBrush(QBrush(Qt::black));
    }
    else{
        this->setBrush(QBrush(Qt::white));
    }
}
