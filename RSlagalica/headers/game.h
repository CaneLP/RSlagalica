#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include "headers/level.h"
#include "headers/levellongestword.h"
#include "headers/levelmynumber.h"
#include "headers/levelconnections.h"
#include "headers/levelassociations.h"

class Game
{
public:
    Game();
    QString username() const;
    void setUsername(const QString username);
    QVector<Level*> levels();
    int currScore() const;
private:
    QString m_username;
    QVector<Level*> m_levels;
};

#endif // GAME_H
