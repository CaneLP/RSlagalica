#ifndef LEVELLONGESTWORD_H
#define LEVELLONGESTWORD_H

#include <QObject>
#include <QScopedArrayPointer>
#include <QVector>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QChar>
#include <QIODevice>
#include "headers/level.h"

class LevelLongestWord : public Level
{
public:
    LevelLongestWord();
    QVector<QString> givenLetters() const;
    QVector<QString> userWord();
    void setUserWord(const QVector<QString> word);
    QVector<QString> letters;
    void calculateScore();
    void updateScore();
    int score() const;
    void setScore(const int pts);
    QVector<QString> longestWord() const;
    void setLongestWord(const QVector<QString> word);
private:
    QVector<QString> m_givenLetters;
    QVector<QString> m_userWord;
    QVector<QString> m_longestWord;
};

#endif // LEVELLONGESTWORD_H
