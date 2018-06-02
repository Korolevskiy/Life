#include "liferect.h"

LifeRect::LifeRect(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):QGraphicsRectItem(x,y,w,h,parent)
{
   // Вначале цвет - Циан
  this->setBrush(QBrush(Qt::cyan));
}

LifeRect::~LifeRect()
{

}

void LifeRect::mousePressEvent(QGraphicsSceneMouseEvent *event){
    changeColor();//Вызываем changeColor если кликнули по прямоугольнику
}


void LifeRect::changeColor(){
    /* Здесь проблем быть не должно. Если текущий цвет - Циан, выставляем Лайм и наоборот */
    if (this->brush().color() == Qt::cyan)
    {
        this->setBrush(QBrush("#FF4500"));
    }
    else{
        this->setBrush(QBrush(Qt::cyan));
    }
}
