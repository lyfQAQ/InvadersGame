#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include "enemy.h"
#include "myrect.h"
#include "score.h"
#include "health.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

class Game: public QGraphicsView
{
public:
    Game(QWidget* parent = nullptr);

    QGraphicsScene* scene;
    MyRect* rect;
    Score* score;
    Health* health;
};

#endif // GAME_H
