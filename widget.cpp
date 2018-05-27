#include "widget.h"
#include "ui_widget.h"
//#include "liferect.h"
Widget::Widget(int x, int y) :QWidget(0),ui(new Ui::Widget),
    x(x), y(y), iterations(0), scene(NULL)

{
    ui->setupUi(this); // Функция для выставки на нашем виджете GUI из widget.ui. Автогенерируемая
    timer = new QTimer();
    timer->setInterval(500);
    /* Соединяем сигнал таймера о одном тике с слотом(функцией) on_timer_timeout */
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));


    // Таймер не запускаем!
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
     new_game();

}

void Widget:: new_game(){
    if (scene == NULL) {// Если сцена еще не была создана
        /* Создаем графическую сцена с размерами поля для вывода */
        scene = new QGraphicsScene(0,0,ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height());
        fills.resize(x);//Мы будем обращаться к элементам через [][]. А он пуст. Поэтому надо сделать resize.
        /*Цикл обхода*/
        for (int i = 0; i < x; i++){
            // Аналогичный resize. В итоге fills[i] - это вектор который хранит 8 элементов. На самом деле еще не хранит, но мы можем
            //обращаться к этим эелментам как fills[i][j]
            fills[i].resize(y);

            for (int j = 0; j < y; j++)
            {
                /* Создаем LifeRect *, в положении 0-0 и размером зависящим от размера сцены! */
                LifeRect * rec = new LifeRect(0,0,scene->sceneRect().width()/(x),scene->sceneRect().height()/(y));
                //Добавляем на сцену наш элемент
                scene->addItem(rec);
                // А теперь после добавления выставляем его позицию! Позиция расчитывается относительно его номера и размера
                rec->setPos( 0+ i*scene->width()/(x),0 + j* scene->height()/(y) );
                /* "Добавляем" наш элемент в массив */
                fills[i][j] = rec;
            }
        }
    }
    else
    { // Если сцена уже была создана - то просто останавливаем таймерам, обнуляем
      // счетчик итераций, и делаем все клетки белыми

        timer->stop();
        iterations = 0;
        for (int i = 0; i < x; i++){

            for (int j = 0; j < y; j++)
            {
                fills[i][j]->setBrush(QBrush(Qt::white));
            }
        }
    }
    /*  А вот в GUI теперь выставляем нашу сцену*/
    ui->graphicsView->setScene(scene);
}



void Widget::on_timer_timeout(){
    int nebs ; // Переменная для хранения числа соседей
    QVector< LifeRect* > fill_temp; // Вектор в который попадают указатели, на те элементы цвет которых мы будем менять
   //Обход каждого элемента:
    for (int i = 0; i < x; i++){

        for (int j = 0; j < y; j++)
        {
            nebs = count_neighbors(i,j); // Подсчитываем количество соседей для каждой клетки
            //Уравнения на соответствие для перерисовки
            if (fills[i][j]->brush().color() == Qt::white && nebs == 3){
                fill_temp.push_back(fills[i][j]);// Если соответствует - отправляем в вектор на перерисовку
            }
            if (fills[i][j]->brush().color() == Qt::black && (nebs > 3 || nebs < 2)){
                fill_temp.push_back(fills[i][j]);
            }
        }
    }
    if (fill_temp.count() == 0) // Если вектор с клетками на перерисовку пуст - заканчиваем игру!
    {
        timer->stop();// Останавливаем таймер
        QMessageBox::about(this, "GAME OVER!!!", "Iterations="+QString().setNum(iterations)); // Выводим сообщение с итерациями
        iterations = 0;// Обнуляем количество итераций
    }
    else // Если вектор не пуст - ничего не обнуляем
    {
        // Обходим вектор с помощью итератора и тащем-то меняем цвет у тех клеток цвет которых надо поменять
        QVector< LifeRect* >::iterator it = fill_temp.begin();
        for (;it !=fill_temp.end();it++){
            (*it)->changeColor();
        }
        iterations++;// ++ к числу итераций
    }

}

void Widget::on_pushButton_2_clicked()
{
    if (scene != NULL) {
        //Если сцена - существует то говорим таймеру что мы стартуем, как говорила какая-то бабка из видео, хз забыл.
    timer->start();
    }
}



int Widget::count_neighbors(int pos_x, int pos_y)
{
    int j;
    int i;
    int temp_i;
    int temp_j;
    int result = 0;
    for (i = pos_x -1 ; i <= pos_x + 1; i++) {

        temp_i = i; // Вводятся временные переменные на случай если клетка граничная и сосед из другой стороны
        if (i == -1) {temp_i = x-1;}
        else if (i == x) {temp_i = 0;}

        for (j = pos_y-1; j <= pos_y+1; j++) {
            temp_j = j; // Вводятся временные переменные на случай если клетка граничная и сосед из другой стороны
            if (j == -1) {temp_j = y-1;}
            else if (j == y) {temp_j = 0;}
            if (fills[temp_i][temp_j]->brush().color() == Qt::black && !(temp_i == pos_x && temp_j == pos_y/* Если клетка - не мы*/))
            {result++;}

        }
    }
    return result; // Возвращаем результат
}

