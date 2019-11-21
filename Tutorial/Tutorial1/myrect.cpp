#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>

extern Game* game;

MyRect::MyRect()
{

    this->setBrush(QBrush(QPixmap(":/img/plane.jpeg").scaled(100, 100)));
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MyRect::CreateEnemy);
    timer->start(1000);
}

void MyRect::CreateEnemy()
{
    Enemy* enemy = new Enemy();
    enemy->setBrush(QBrush(QPixmap(":/img/images.jpeg").scaled(50,50)));
    enemy->setPos(rand() % 700, 0);
    this->scene()->addItem(enemy);
}

void MyRect::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(this->x() >= 0)
            setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(this->x() < (this->scene()->width() - this->rect().width()))
            setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setBrush(QBrush(Qt::red));
        bullet->setPos(x(), y());
        this->scene()->addItem(bullet);
    }
}

