#ifndef LIFERECT_H
#define LIFERECT_H

#include <QObject>
#include <QtWidgets>
class LifeRect : public QGraphicsRectItem
{
public:
    /* Конструктор класса - такой же как один из конструкторов QGraphicsRectItem */
    LifeRect(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0);
    ~LifeRect();
public:
    /* Переопределние mousePressEvent */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /* Функция смены цвета */
    void changeColor();
};

#endif // LIFERECT_H
