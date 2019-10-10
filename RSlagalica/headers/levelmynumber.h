#ifndef LEVELMYNUMBER_H
#define LEVELMYNUMBER_H

#include <QObject>
#include <QVector>
#include "headers/level.h"
#include "headers/binaryexpressionbuilder.h"
#include "headers/binaryoperationnode.h"
#include "headers/expressionelementnode.h"
#include "headers/numericelementnode.h"

class LevelMyNumber : public Level
{
public:
    LevelMyNumber();
    void updateScore();
    int reqNumber() const;
    QVector<int> oneDigNumbers() const;
    int twoDigNumber() const;
    int threeDigNumber() const;
    QVector<QString> userExpression();
    void setUserExpression(QVector<QString> exp);
    QVector<QString> findBestSolution();
    int evaluateExpression(std::string s);
    void setUserSolutionValue(QVector<QString> expression);
    int userSolutionValue() const;
    int score() const;
private:
    int m_reqNumber;
    QVector<int> m_oneDigNumbers;
    int m_twoDigNumber;
    int m_threeDigNumber;
    QVector<QString> m_userExpression;
    QString m_bestSolution;
    int m_userSolutionValue;
};

#endif // LEVELMYNUMBER_H
