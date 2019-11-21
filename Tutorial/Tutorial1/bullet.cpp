#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game* game;

Bullet::Bullet()
{
    // drew the rec
    setRect(45, 0, 10, 40);

    // connect
    QTimer* timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Bullet::Move);
    timer->start(50);
}

void Bullet::Move()
{
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    foreach(auto item, collidingItems)
    {

        if(typeid (*item) == typeid (Enemy))
        {
                    game->score->Increase();
            this->scene()->removeItem(item);
            this->scene()->removeItem(this);
            delete item;
            delete this;
            return;
        }
    }
    this->setPos(this->x(), this->y() - 10);

    if(this->y() < -(this->rect().height()))
    {
        this->scene()->removeItem(this);
        delete this;
    }
}
