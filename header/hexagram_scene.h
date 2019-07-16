#ifndef HEXAGRAM_SCENE_H
#define HEXAGRAM_SCENE_H

#include <QObject>
#include <QPainter>
#include <QgraphicsItem>
#include <QGraphicsScene>

class HexagramScene : public QGraphicsScene
{
public:
    HexagramScene(QObject *parent);
};

#endif // HEXAGRAM_SCENE_H