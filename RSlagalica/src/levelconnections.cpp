#include "headers/levelconnections.h"

LevelConnections::LevelConnections()
{
}

int LevelConnections::score() const
{
    return m_score;
}

void LevelConnections::updateScore()
{
    m_score = 0;
    QHash<QString, QString>::iterator i;
    for(i = m_solution.begin(); i != m_solution.end(); ++i)
    {
        if(m_leftPicks.indexOf(i.key()) == m_rightPicks.lastIndexOf(i.value()) &&
                m_leftPicks.indexOf(i.key()) != -1)
        {
            m_score += 2;
        }
    }
    //m_score -= (8 - m_leftPicks.length()) * 2;
}

QHash<QString, QString> LevelConnections::solution() const
{
    return m_solution;
}

QVector<QString> LevelConnections::leftPicks()
{
    return m_leftPicks;
}

QVector<QString> LevelConnections::rightPicks()
{
    return m_leftPicks;
}

void LevelConnections::addToLeftPicks(QString s)
{
    m_leftPicks.push_back(s);
}

void LevelConnections::addToRightPicks(QString s)
{
    m_rightPicks.push_back(s);
}

void LevelConnections::addToSolution(QString key, QString value)
{
    m_solution.insert(key, value);
}
