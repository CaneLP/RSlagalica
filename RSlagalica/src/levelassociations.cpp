#include "headers/levelassociations.h"

LevelAssociations::LevelAssociations()
{
}

int LevelAssociations::score() const
{
    return m_score;
}

void LevelAssociations::updateScore()
{
    m_score = 0;
    if(m_solFinal != ""){
        m_score += 10 - m_colA.length()*2;
        m_score += 10 - m_colB.length()*2;
        m_score += 10 - m_colC.length()*2;
        m_score += 10 - m_colD.length()*2;

        if(m_solColA == "") m_score += 4;
        if(m_solColB == "") m_score += 4;
        if(m_solColC == "") m_score += 4;
        if(m_solColD == "") m_score += 4;

        m_score += 6;
    } else {
        if(m_solColA != "") m_score += 10 - m_colA.length()*2;
        if(m_solColB != "") m_score += 10 - m_colB.length()*2;
        if(m_solColC != "") m_score += 10 - m_colC.length()*2;
        if(m_solColD != "") m_score += 10 - m_colD.length()*2;
    }
}

void LevelAssociations::addToColA(const QString s)
{
    m_colA.push_back(s);
}

void LevelAssociations::addToColB(const QString s)
{
    m_colB.push_back(s);
}

void LevelAssociations::addToColC(const QString s)
{
    m_colC.push_back(s);
}

void LevelAssociations::addToColD(const QString s)
{
    m_colD.push_back(s);
}

void LevelAssociations::setSolColA(const QString s)
{
    m_solColA = s;
}

void LevelAssociations::setSolColB(const QString s)
{
    m_solColB = s;
}

void LevelAssociations::setSolColC(const QString s)
{
    m_solColC = s;
}

void LevelAssociations::setSolColD(const QString s)
{
    m_solColD = s;
}

void LevelAssociations::setSolFinal(const QString s)
{
    m_solFinal = s;
}
