#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>


#include "widget.h"
#include "liferect.h"
#include "ui_widget.h"


/*TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 5);
    ASSERT_EQ(fibonachi(10), 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}
*/

TEST (WidgetTest, test1) {
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    SUCCEED();
}

TEST (WidgetTest, test2) {
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    ASSERT_NE(w.x, 0);
}

TEST (WidgetTest, test3) {
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    ASSERT_EQ(w.iterations, 0);
}

TEST (NewGame, test1) {
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    ASSERT_FALSE(w.scene == NULL);
}

TEST (NewGame, test2){
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    w.fills[0][0]->setBrush(Qt::cyan);
    ASSERT_EQ(w.fills[0][0]->brush().color(), "#00FFFF");
}



TEST (NonWidgetTest, test1) {
    SUCCEED();
}



TEST (NonWidgetTest, test2) {
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    w.fills[0][0]->setBrush(Qt::cyan);
    w.fills[0][0]->changeColor();
    SUCCEED();
}



TEST (NonWidgetTest, test3) {
        int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    w.new_game();
    SUCCEED();
}



TEST (NonWidgetTest, test4) {
    
    int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    w.fills[0][0]->setBrush(Qt::cyan);
    w.fills[0][0]->changeColor();
    w.on_timer_timeout();
    SUCCEED();
}



TEST (NonWidgetTest, test5) {
        int argc = 0; char *argv[3] = {};
    QApplication a(argc, argv);
    Widget w(10,10);
    w.new_game();
    w.on_pushButton_clicked();
    w.fills[0][0]->setBrush(Qt::cyan);
    w.fills[0][0]->changeColor();
    w.fills[0][1]->changeColor();
    w.fills[0][2]->changeColor();
    w.fills[0][3]->changeColor();
    w.fills[0][4]->changeColor();
    w.fills[2][1]->changeColor();
    w.fills[2][2]->changeColor();
    w.fills[2][3]->changeColor();
    w.fills[2][4]->changeColor();
    w.fills[6][1]->changeColor();
    w.fills[6][2]->changeColor();
    w.fills[6][3]->changeColor();
    w.on_pushButton_2_clicked();
    SUCCEED();
}



TEST (NonWidgetTest, test6) {
    SUCCEED();
}



TEST (NonWidgetTest, test7) {
    SUCCEED();
}
#endif // FIBONACHI_H
