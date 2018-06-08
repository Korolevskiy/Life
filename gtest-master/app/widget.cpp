#include "widget.h"
#include "ui_widget.h"
//#include "liferect.h"
Widget::Widget(int x, int y) :QWidget(0),ui(new Ui::Widget),
    x(x), y(y), iterations(0), scene(NULL)

{
    ui->setupUi(this); 
    timer = new QTimer();
    timer->setInterval(500);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
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
        scene = new QGraphicsScene(0,0,ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height());
        fills.resize(x);//Мы будем обращаться к элементам через [][]. А он пуст. Поэтому надо сделать resize.
        /*Цикл обхода*/
        for (int i = 0; i < x; i++){
       
            fills[i].resize(y);

            for (int j = 0; j < y; j++)
            {
                /* Создаем LifeRect *, в положении 0-0 и размером зависящим от размера сцены! */
                LifeRect * rec = new LifeRect(0,0,scene->sceneRect().width()/(x),scene->sceneRect().height()/(y));
                scene->addItem(rec);
                rec->setPos( 0+ i*scene->width()/(x),0 + j* scene->height()/(y) );
                /* "Добавляем" наш элемент в массив */
                fills[i][j] = rec;
            }
        }
    }
    else
    { 
        timer->stop();
        iterations = 0;
        for (int i = 0; i < x; i++){

            for (int j = 0; j < y; j++)
            {
                fills[i][j]->setBrush(QBrush(Qt::cyan));
            }
        }
    }
    /*  А вот в GUI теперь выставляем нашу сцену*/
    ui->graphicsView->setScene(scene);
}

void Widget::on_timer_timeout(){
    int nebs ; 
    QVector< LifeRect* > fill_temp; 
    for (int i = 0; i < x; i++){

        for (int j = 0; j < y; j++)
        {   nebs = count_neighbors(i,j);
            if (fills[i][j]->brush().color() == Qt::cyan && nebs == 3){
                fill_temp.push_back(fills[i][j]);
            }
            if (fills[i][j]->brush().color() == "#FF4500" && (nebs > 3 || nebs < 2)){
                fill_temp.push_back(fills[i][j]);
            }
        }
    }
    if (fill_temp.count() == 0) // Если вектор с клетками на перерисовку пуст - заканчиваем игру!
    {
        timer->stop();
        QMessageBox::about(this, "GAME OVER!!!", "Iterations="+QString().setNum(iterations)); // Выводим сообщение с итерациями
        iterations = 0;
    }
    else 
    {   QVector< LifeRect* >::iterator it = fill_temp.begin();
        for (;it !=fill_temp.end();it++){
            (*it)->changeColor();
        }
        iterations++;
    }
}

void Widget::on_pushButton_2_clicked()
{
    if (scene != NULL) {
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
        temp_i = i; 
        if (i == -1) {temp_i = x-1;}
        else if (i == x) {temp_i = 0;}
        for (j = pos_y-1; j <= pos_y+1; j++) {
            temp_j = j;
            if (j == -1) {temp_j = y-1;}
            else if (j == y) {temp_j = 0;}
            if (fills[temp_i][temp_j]->brush().color() == "#FF4500" && !(temp_i == pos_x && temp_j == pos_y/* Если клетка - не мы*/))
            {result++;}
        }
    }
    return result; 
}

