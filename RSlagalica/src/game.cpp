#include "headers/game.h"

Game::Game()
{
    m_levels.push_back(new LevelLongestWord());
    m_levels.push_back(new LevelMyNumber());
    m_levels.push_back(new LevelConnections());
    m_levels.push_back(new LevelAssociations());
}

QString Game::username() const
{
    return m_username;
}

QVector<Level*> Game::levels()
{
    return m_levels;
}

void Game::setUsername(const QString username)
{
    m_username = username;
}

int Game::currScore() const
{
    int scoreSum = 0;
    foreach(Level* lvl, m_levels)
    {
        scoreSum += lvl->score();
    }
    return scoreSum;
}
