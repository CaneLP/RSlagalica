#ifndef LEVELASSOCIATIONS_H
#define LEVELASSOCIATIONS_H

#include <QObject>
#include <QVector>
#include "headers/level.h"

class LevelAssociations : public Level
{
public:
    LevelAssociations();
    int score() const;
    void updateScore();
    QVector<QString> colA();
    QString solColA();
    QVector<QString> colB();
    QString solColB();
    QVector<QString> colC();
    QString solColC();
    QVector<QString> colD();
    QString solColD();
    QString solFinal();
    void addToColA(const QString s);
    void addToColB(const QString s);
    void addToColC(const QString s);
    void addToColD(const QString s);
    void setSolColA(const QString s);
    void setSolColB(const QString s);
    void setSolColC(const QString s);
    void setSolColD(const QString s);
    void setSolFinal(const QString s);
public slots:
    void textA1();
    void textA2();
    void textA3();
    void textA4();
    void textB1();
    void textB2();
    void textB3();
    void textB4();
    void textC1();
    void textC2();
    void textC3();
    void textC4();
    void textD1();
    void textD2();
    void textD3();
    void textD4();
    void resenjeA();
    void resenjeB();
    void resenjeC();
    void resenjeD();
    void konacnoResenje();
    void ispisiA();
    void ispisiB();
    void ispisiC();
    void ispisiD();
    void startLevelAsoc();
    void CountSecondAsoc();
    void ispisKonacno();
private:
    QVector<QString> m_colA;
    QString m_solColA;
    QVector<QString> m_colB;
    QString m_solColB;
    QVector<QString> m_colC;
    QString m_solColC;
    QVector<QString> m_colD;
    QString m_solColD;
    QString m_solFinal;
};

#endif // LEVELASSOCIATIONS_H
