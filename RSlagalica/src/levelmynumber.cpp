#include "headers/levelmynumber.h"

#include <string>
#include <algorithm>

LevelMyNumber::LevelMyNumber()
{
    srand(time(NULL));
    m_reqNumber = rand()%1000;
    for(int i = 0; i < 4; ++i)
    {
        m_oneDigNumbers.push_back((rand()%9)+1);
    }
    m_twoDigNumber = 25 - 5*(rand()%4);
    m_threeDigNumber = 100 - 25*(rand()%4);
}

void LevelMyNumber::updateScore()
{
    if(m_userSolutionValue < 0) {
        m_score = 0;
    } else {
        int diff = std::abs(m_reqNumber - m_userSolutionValue);
        if (diff < 10) {
            m_score = 20 - diff * 2;
        } else {
            m_score = 0;
        }
    }
}

QVector<int> LevelMyNumber::oneDigNumbers() const
{
    return m_oneDigNumbers;
}

int LevelMyNumber::twoDigNumber() const
{
    return m_twoDigNumber;
}

int LevelMyNumber::threeDigNumber() const
{
    return m_threeDigNumber;
}

int LevelMyNumber::reqNumber() const
{
    return m_reqNumber;
}

int LevelMyNumber::userSolutionValue() const
{
    return m_userSolutionValue;
}

QVector<QString> LevelMyNumber::userExpression()
{
    return m_userExpression;
}

void LevelMyNumber::setUserExpression(QVector<QString> exp)
{
    m_userExpression = exp;
}

void LevelMyNumber::setUserSolutionValue(QVector<QString> expression)
{
    if(!expression.isEmpty()) {
        std::string exp;
        foreach (QString qs, expression) {
            exp += qs.toStdString();
        }
        m_userSolutionValue = evaluateExpression(exp);

    } else {
        m_userSolutionValue = -1;
    }
}

int LevelMyNumber::evaluateExpression(std::string s)
{
    BinaryExpressionBuilder b;
    BinaryOperationNode *root = b.parse(s);
    return root->value();
}

QVector<QString> LevelMyNumber::findBestSolution()
{
    //TODO
    return m_userExpression;
}

int LevelMyNumber::score() const
{
    return m_score;
}
