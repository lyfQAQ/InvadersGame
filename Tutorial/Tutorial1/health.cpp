#include "health.h"
#include <QFont>
#include <QMessageBox>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem (parent), health(5)
{
    setPlainText(QString("Health : ") + QString::number(health));
    setPos(0, 50);
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::Decrease()
{
    if(health > 0)
    {    health--;

        setPlainText(QString("Health : ") + QString::number(health));
    }
}

int Health::GetHealth() const
{
    return health;
}

