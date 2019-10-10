#ifndef LEVELCONNECTIONS_H
#define LEVELCONNECTIONS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHash>
#include "headers/level.h"

class LevelConnections : public Level
{
public:
    LevelConnections();
    int score() const;
    void updateScore();
    QHash<QString, QString> solution() const;
    QVector<QString> leftPicks();
    QVector<QString> rightPicks();
    void addToLeftPicks(QString s);
    void addToRightPicks(QString s);
    void addToSolution(QString key, QString value);
private:
    QHash<QString, QString> m_solution;
    QVector<QString> m_leftPicks;
    QVector<QString> m_rightPicks;
};

#endif // LEVELCONNECTIONS_H
