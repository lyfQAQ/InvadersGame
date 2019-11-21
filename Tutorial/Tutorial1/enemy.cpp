#include "enemy.h"
#include "myrect.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game* game;

Enemy::Enemy()
{
    int x = rand() % 700;
    setRect(x, 0, 50, 50);

    QTimer* timer = new QTimer();

    connect(timer, &QTimer::timeout, this, &Enemy::Move);
    timer->start(50);
}

void Enemy::Move()
{
    QList<QGraphicsItem*> collids = collidingItems();
    for(auto item: collids)
    {
        if(typeid (*item) == typeid (MyRect))
        {
            this->scene()->removeItem(this);
            delete this;
            game->health->Decrease();
            return;
        }
    }
    setPos(this->x(), this->y() + 5);
    if(this->y() > this->scene()->height())
    {
        this->scene()->removeItem(this);
        delete this;
    }

}
