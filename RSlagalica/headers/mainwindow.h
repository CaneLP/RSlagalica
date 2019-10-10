#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QGraphicsScene>
#include <QString>
#include <QSignalMapper>
#include <QRegExp>
#include <QRegExpValidator>
#include <QtAlgorithms>
#include <QTimer>
#include <QMetaObject>
#include <QPushButton>
#include "headers/game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool wordExists(QString s);
    bool isWordValid(QString word, QString chars);
    static bool compareStrByLenFunction(const QString &s1, const QString &s2)
    { return s1.length() > s2.length(); }
    void connectLetterButtonsWithLineEdit();
    void connectNumberButtonsWithLineEdit();
    void finishLevel(int lvlId);
    void fillHighScoreTable();
private slots:
    void connectSignalsToSlots();
    void startGame();
    void addCharToLineEdit(QString s);
    void setLevelLongestWord();
    void checkWord();
    void lineEditToUppercase();
    void findLongestWord();
    void lineEditLWClear();
    void lineEditLWBackspace();
    void updateProgressBarLW();
    void setLevelMyNumber();
    void addNumberOrOperatorToLineEdit(QString s);
    void lineEditGNClear();
    void lineEditGNBackspace();
    void updateProgressBarGN();
    void confirmMyNumber();
    void setLevelConnectors();
    void startLevelConnectors();
    void connectorsCountSecond();
    void leftButtonSelected();
    void rightButtonSelected();
    void finishConnectionsLevel();
    void finishGame();
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
    void setupAssociationsLevel();
    void startLevelAsoc();
    void CountSecondAsoc();
    void ispisKonacno();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QMap<QString, QString> connectorsSolution;
    QPushButton *selectedLeft, *selectedRight;
    QString assocFilename;

};

#endif // MAINWINDOW_H
