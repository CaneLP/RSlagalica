#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

class Level
{
public:
    Level();
    virtual ~Level() {}
    virtual int score() const;
    virtual void updateScore();
protected:
    int m_score;
};

#endif // LEVEL_H
