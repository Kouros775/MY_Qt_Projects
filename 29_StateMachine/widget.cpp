#include "widget.h"
#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(360, 290);

    QPushButton* button = new QPushButton("Button", this);
    button->setGeometry(10, 10, 100, 30);

    QStateMachine* machine = new QStateMachine();
    QState* state1 = new QState(machine);
    state1->assignProperty(button, "geometry", QRect(10, 10, 100, 30));
    machine->setInitialState(state1);

    QState* state2 = new QState(machine);
    state2->assignProperty(button, "geometry", QRect(250, 250, 100, 30));


    // transition 1
    QSignalTransition* transition1;
    transition1 = state1->addTransition(button, &QPushButton::clicked, state2);
    transition1->addAnimation(new QPropertyAnimation(button, "geometry"));


    // transition 2
    QSignalTransition* transition2;
    transition2 = state2->addTransition(button, &QPushButton::clicked, state1);
    transition2->addAnimation(new QPropertyAnimation(button, "geometry"));

    machine->start();
}

Widget::~Widget()
{

}
