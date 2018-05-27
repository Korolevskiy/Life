#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include "liferect.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(int x,int y);
    ~Widget();
private slots:
    void on_pushButton_clicked();
    void on_timer_timeout();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui; // ui  - наше GUI приложения(из widget.ui). К этим элементам мы будем общататься, например this->ui->pushButton.
    int x;
    int y;
    int iterations; // Количество итераций
    QVector< QVector<LifeRect* > > fills ; // Двумерный вектор наших LifeRect
    QGraphicsScene * scene; // Графическая сцена
    void  new_game(); // Функция начала новой игры.
    QTimer * timer; // Таймер
    int count_neighbors(int pos_x, int pos_y); // Функция для подсчета живых соседей

};

#endif // WIDGET_H
