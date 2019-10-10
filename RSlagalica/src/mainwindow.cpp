#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <algorithm>

Game *rslagalica;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    selectedLeft(NULL), selectedRight(NULL)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    connectSignalsToSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSignalsToSlots()
{
    connect(ui->pushButtonConfirmUsername, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(ui->pushButtonCheckWord, SIGNAL(clicked()), this, SLOT(checkWord()));
    connect(ui->lineEditUserWord, SIGNAL(textEdited(const QString &)), SLOT(lineEditToUppercase()));
    connect(ui->pushButtonConfirm, SIGNAL(clicked()), this, SLOT(findLongestWord()));
    connect(ui->pushButtonLWBackspace, SIGNAL(clicked()), this, SLOT(lineEditLWBackspace()));
    connect(ui->pushButtonLWClear, SIGNAL(clicked()), this, SLOT(lineEditLWClear()));
    connect(ui->pushButtonLWNextGame, SIGNAL(clicked()), this, SLOT(setLevelMyNumber()));
    connect(ui->pushButtonGNBackspace, SIGNAL(clicked()), this, SLOT(lineEditGNBackspace()));
    connect(ui->pushButtonGNClear, SIGNAL(clicked()), this, SLOT(lineEditGNClear()));
    connect(ui->pushButtonConfirmExpression, SIGNAL(clicked()), this, SLOT(confirmMyNumber()));
    connect(ui->pushButtonGNNextGame, SIGNAL(clicked()), this, SLOT(setLevelConnectors()));
    connect(ui->pushButtonCONextGame,SIGNAL(clicked()),this,SLOT(setupAssociationsLevel()));
    connect(ui->pushButtonCOFinishLevel, SIGNAL(clicked()), this, SLOT(finishConnectionsLevel()));
    connect(ui->pushButtonTheEnd, SIGNAL(clicked(bool)), this, SLOT(finishGame()));
    connect(ui->pushButtonRestart, SIGNAL(clicked()), this, SLOT(startGame()));
    //konekcija za asocijacije
    connect(ui->A1,SIGNAL(clicked()),this,SLOT(textA1()));
    connect(ui->A2,SIGNAL(clicked()),this,SLOT(textA2()));
    connect(ui->A3,SIGNAL(clicked()),this,SLOT(textA3()));
    connect(ui->A4,SIGNAL(clicked()),this,SLOT(textA4()));

    connect(ui->B1,SIGNAL(clicked()),this,SLOT(textB1()));
    connect(ui->B2,SIGNAL(clicked()),this,SLOT(textB2()));
    connect(ui->B3,SIGNAL(clicked()),this,SLOT(textB3()));
    connect(ui->B4,SIGNAL(clicked()),this,SLOT(textB4()));

    connect(ui->C1,SIGNAL(clicked()),this,SLOT(textC1()));
    connect(ui->C2,SIGNAL(clicked()),this,SLOT(textC2()));
    connect(ui->C3,SIGNAL(clicked()),this,SLOT(textC3()));
    connect(ui->C4,SIGNAL(clicked()),this,SLOT(textC4()));

    connect(ui->D1,SIGNAL(clicked()),this,SLOT(textD1()));
    connect(ui->D2,SIGNAL(clicked()),this,SLOT(textD2()));
    connect(ui->D3,SIGNAL(clicked()),this,SLOT(textD3()));
    connect(ui->D4,SIGNAL(clicked()),this,SLOT(textD4()));

    connect(ui->ResenjeA,SIGNAL(returnPressed()),this,SLOT(resenjeA()));
    connect(ui->ResenjeB,SIGNAL(returnPressed()),this,SLOT(resenjeB()));
    connect(ui->ResenjeC,SIGNAL(returnPressed()),this,SLOT(resenjeC()));
    connect(ui->ResenjeD,SIGNAL(returnPressed()),this,SLOT(resenjeD()));
    connect(ui->konacnoResenje,SIGNAL(returnPressed()),this,SLOT(konacnoResenje()));
// asocijacije
}

void MainWindow::connectLetterButtonsWithLineEdit()
{
    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(ui->pushButtonLetter1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter10, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter11, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonLetter12, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->pushButtonLetter1, ui->pushButtonLetter1->text());
    signalMapper->setMapping(ui->pushButtonLetter2, ui->pushButtonLetter2->text());
    signalMapper->setMapping(ui->pushButtonLetter3, ui->pushButtonLetter3->text());
    signalMapper->setMapping(ui->pushButtonLetter4, ui->pushButtonLetter4->text());
    signalMapper->setMapping(ui->pushButtonLetter5, ui->pushButtonLetter5->text());
    signalMapper->setMapping(ui->pushButtonLetter6, ui->pushButtonLetter6->text());
    signalMapper->setMapping(ui->pushButtonLetter7, ui->pushButtonLetter7->text());
    signalMapper->setMapping(ui->pushButtonLetter8, ui->pushButtonLetter8->text());
    signalMapper->setMapping(ui->pushButtonLetter9, ui->pushButtonLetter9->text());
    signalMapper->setMapping(ui->pushButtonLetter10, ui->pushButtonLetter10->text());
    signalMapper->setMapping(ui->pushButtonLetter11, ui->pushButtonLetter11->text());
    signalMapper->setMapping(ui->pushButtonLetter12, ui->pushButtonLetter12->text());

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(addCharToLineEdit(QString)));
}

void MainWindow::connectNumberButtonsWithLineEdit()
{
    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(ui->pushButtonOneDigNumber1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonOneDigNumber2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonOneDigNumber3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonOneDigNumber4, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(ui->pushButtonTwoDigNumber1, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(ui->pushButtonThreeDigNumber, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(ui->pushButtonMathPlus, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonMathMinus, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonMathMul, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonMathDiv, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonMathOpenBracket, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButtonMathClosedBracket, SIGNAL(clicked()), signalMapper, SLOT(map()));


    signalMapper->setMapping(ui->pushButtonOneDigNumber1, ui->pushButtonOneDigNumber1->text());
    signalMapper->setMapping(ui->pushButtonOneDigNumber2, ui->pushButtonOneDigNumber2->text());
    signalMapper->setMapping(ui->pushButtonOneDigNumber3, ui->pushButtonOneDigNumber3->text());
    signalMapper->setMapping(ui->pushButtonOneDigNumber4, ui->pushButtonOneDigNumber4->text());
    signalMapper->setMapping(ui->pushButtonTwoDigNumber1, ui->pushButtonTwoDigNumber1->text());
    signalMapper->setMapping(ui->pushButtonThreeDigNumber, ui->pushButtonThreeDigNumber->text());
    signalMapper->setMapping(ui->pushButtonMathPlus, ui->pushButtonMathPlus->text());
    signalMapper->setMapping(ui->pushButtonMathMinus, ui->pushButtonMathMinus->text());
    signalMapper->setMapping(ui->pushButtonMathMul, ui->pushButtonMathMul->text());
    signalMapper->setMapping(ui->pushButtonMathDiv, ui->pushButtonMathDiv->text());
    signalMapper->setMapping(ui->pushButtonMathOpenBracket, ui->pushButtonMathOpenBracket->text());
    signalMapper->setMapping(ui->pushButtonMathClosedBracket, ui->pushButtonMathClosedBracket->text());

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(addNumberOrOperatorToLineEdit(QString)));
}

void MainWindow::startGame()
{
    ui->pageLogin->hide();
    ui->lineEditUserWord->setReadOnly(true);
    QString username = ui->lineEditUsername->text();
    rslagalica = new Game();
    rslagalica->setUsername(username);
    setLevelLongestWord();
}

void MainWindow::addCharToLineEdit(QString s)
{
    ui->lineEditUserWord->setText(ui->lineEditUserWord->text().append(s));
    QVector<QString> currentUserWord = dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->userWord();
    currentUserWord.push_back(s);
    dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->setUserWord(currentUserWord);
}

void MainWindow::setLevelLongestWord()
{
    QTimer *timerProgressBar = new QTimer(this);
    QTimer *timerLevel = new QTimer(this);
    connect(timerLevel, SIGNAL(timeout()), this, SLOT(findLongestWord()));
    connect(timerProgressBar, SIGNAL(timeout()), this, SLOT(updateProgressBarLW()));
    timerProgressBar->start(1000);
    timerLevel->start(25600);

    QVector<QString> charactersVector = dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->givenLetters();
    //QString characters = (QString::fromLatin1(reinterpret_cast<char*>(&charactersVector[0])));
    ui->labelLWUsernameValue->setText(rslagalica->username());
    ui->labelLWPointsWon->hide();
    ui->pushButtonLWNextGame->hide();
    ui->labelLWScoreValue->setText(QString::number(rslagalica->currScore()));

    //Assign characters to buttons
    {
        ui->pushButtonLetter1->setText(charactersVector[0]);
        ui->pushButtonLetter2->setText(charactersVector[1]);
        ui->pushButtonLetter3->setText(charactersVector[2]);
        ui->pushButtonLetter4->setText(charactersVector[3]);
        ui->pushButtonLetter5->setText(charactersVector[4]);
        ui->pushButtonLetter6->setText(charactersVector[5]);
        ui->pushButtonLetter7->setText(charactersVector[6]);
        ui->pushButtonLetter8->setText(charactersVector[7]);
        ui->pushButtonLetter9->setText(charactersVector[8]);
        ui->pushButtonLetter10->setText(charactersVector[9]);
        ui->pushButtonLetter11->setText(charactersVector[10]);
        ui->pushButtonLetter12->setText(charactersVector[11]);
        connectLetterButtonsWithLineEdit();
    }

    ui->labelLWTuxTrue->hide();
    ui->labelLWTuxFalse->hide();
    ui->lineEditUserWord->setFocus();
    ui->pageLevelLongestWord->show();
}

void MainWindow::updateProgressBarLW()
{
    ui->progressBarLW->setValue(ui->progressBarLW->value() - 4);
}

void MainWindow::checkWord()
{
    if(wordExists(ui->lineEditUserWord->text().toLower()))
    {
        ui->labelLWTuxFalse->hide();
        ui->labelLWTuxTrue->show();
    } else {
        ui->labelLWTuxTrue->hide();
        ui->labelLWTuxFalse->show();
    }
}

bool MainWindow::wordExists(QString s)
{
    QFile dictionary(":/dic/sr_Latn.dic");
    dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&dictionary);
    while(!in.atEnd())
    {
        QString word = in.readLine();
        if(word == s)
        {
            dictionary.close();
            return true;
        }
    }
    dictionary.close();
    return false;
}

void MainWindow::findLongestWord()
{
    QVector<QString> words;
    QString availableChars(ui->pushButtonLetter1->text());
    {
        availableChars.append(ui->pushButtonLetter2->text());
        availableChars.append(ui->pushButtonLetter3->text());
        availableChars.append(ui->pushButtonLetter4->text());
        availableChars.append(ui->pushButtonLetter5->text());
        availableChars.append(ui->pushButtonLetter6->text());
        availableChars.append(ui->pushButtonLetter7->text());
        availableChars.append(ui->pushButtonLetter8->text());
        availableChars.append(ui->pushButtonLetter9->text());
        availableChars.append(ui->pushButtonLetter10->text());
        availableChars.append(ui->pushButtonLetter11->text());
        availableChars.append(ui->pushButtonLetter12->text());
    }

    //ui->lineEditLongestWord->setText(availableChars);

    QFile dictionary(":/dic/sr_Latn.dic");
    dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&dictionary);
    while(!in.atEnd())
    {
        QString word = in.readLine().toLower();
        if(isWordValid(word.toUpper(), availableChars.toUpper()))
            words.push_back(word);
    }
    dictionary.close();
    std::sort(words.begin(), words.end(), compareStrByLenFunction);
    ui->lineEditLongestWord->setText(words[0].toUpper());
    //ui->pushButtonConfirm->setText(QString::number(words[0].length()));
    QVector<QString> userWordVec = dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->userWord();
    QString userWord;
    foreach (QString letter, userWordVec) {
        userWord += letter;
    }
    if(words.contains(userWord.toLower())) {
        dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->updateScore();
        ui->labelLWTuxTrue->show();
        ui->labelLWTuxFalse->hide();
    } else {
        dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->setScore(0);
        ui->labelLWTuxTrue->hide();
        ui->labelLWTuxFalse->show();
    }
    QString plusSign("+");
    ui->labelLWPointsWon->setText(plusSign.append(QString::number(dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->score())));
    ui->labelLWPointsWon->show();
    ui->labelLWScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->progressBarLW->setValue(0);
    ui->pushButtonLWNextGame->show();
    ui->pushButtonLetter1->setDisabled(true);
    ui->pushButtonLetter2->setDisabled(true);
    ui->pushButtonLetter3->setDisabled(true);
    ui->pushButtonLetter4->setDisabled(true);
    ui->pushButtonLetter5->setDisabled(true);
    ui->pushButtonLetter6->setDisabled(true);
    ui->pushButtonLetter7->setDisabled(true);
    ui->pushButtonLetter8->setDisabled(true);
    ui->pushButtonLetter9->setDisabled(true);
    ui->pushButtonLetter10->setDisabled(true);
    ui->pushButtonLetter11->setDisabled(true);
    ui->pushButtonLetter12->setDisabled(true);
    ui->pushButtonCheckWord->setDisabled(true);
    ui->pushButtonConfirm->setDisabled(true);
    ui->pushButtonLWBackspace->setDisabled(true);
    ui->pushButtonLWClear->setDisabled(true);
}

void MainWindow::finishLevel(int lvlId)
{
    dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(lvlId))->updateScore();
}

void MainWindow::lineEditToUppercase()
{
    ui->lineEditUserWord->setText(ui->lineEditUserWord->text().toUpper());
}

bool MainWindow::isWordValid(QString word, QString chars)
{
    foreach (QChar c, word)
    {
       if (chars.contains(c))
       {
            int pos = chars.indexOf(c);
            chars.remove(pos, 1);
       } else {
           return false;
       }
    }
    return true;
}

void MainWindow::lineEditLWClear()
{
    ui->lineEditUserWord->clear();
    QVector<QString> empty;
    dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->setUserWord(empty);
}

void MainWindow::lineEditLWBackspace()
{
    QVector<QString> currentUserWord = dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->userWord();
    if(currentUserWord.length() > 0)
    {
        currentUserWord.remove(currentUserWord.length()-1);
        dynamic_cast<LevelLongestWord*>(rslagalica->levels().at(0))->setUserWord(currentUserWord);
        QString currToLE;
        foreach (QString l, currentUserWord) {
            currToLE.append(l);
        }
        ui->lineEditUserWord->setText(currToLE);
    }
}

void MainWindow::setLevelMyNumber()
{
    ui->pushButtonGNNextGame->hide();
    ui->labelGNPointsWon->hide();
    ui->labelGNScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->lineEditCalculationArea->setReadOnly(true);
    QTimer *timerProgressBar = new QTimer(this);
    QTimer *timerLevel = new QTimer(this);
    connect(timerLevel, SIGNAL(timeout()), this, SLOT(confirmMyNumber()));
    connect(timerProgressBar, SIGNAL(timeout()), this, SLOT(updateProgressBarGN()));
    timerProgressBar->start(1000);
    timerLevel->start(33500);

    ui->pageLevelLongestWord->hide();
    ui->pageLevelMyNumber->show();
    ui->labelGNUsernameValue->setText(rslagalica->username());

    ui->pushButtonReqNumber->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->reqNumber()));
    ui->pushButtonOneDigNumber1->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->oneDigNumbers().at(0)));
    ui->pushButtonOneDigNumber2->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->oneDigNumbers().at(1)));
    ui->pushButtonOneDigNumber3->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->oneDigNumbers().at(2)));
    ui->pushButtonOneDigNumber4->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->oneDigNumbers().at(3)));
    ui->pushButtonTwoDigNumber1->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->twoDigNumber()));
    ui->pushButtonThreeDigNumber->setText(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->threeDigNumber()));

    connectNumberButtonsWithLineEdit();
}

void MainWindow::addNumberOrOperatorToLineEdit(QString s)
{
    ui->lineEditCalculationArea->setText(ui->lineEditCalculationArea->text().append(s));
    QVector<QString> currentExpression = dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->userExpression();
    currentExpression.push_back(s);
    dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->setUserExpression(currentExpression);
}

void MainWindow::lineEditGNClear()
{
    ui->lineEditCalculationArea->clear();
    QVector<QString> empty;
    dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->setUserExpression(empty);
}

void MainWindow::lineEditGNBackspace()
{
    QVector<QString> currentExpression = dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->userExpression();
    if(currentExpression.length() > 0)
    {
        currentExpression.remove(currentExpression.length()-1);
        dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->setUserExpression(currentExpression);
        QString currToLE;
        foreach (QString l, currentExpression) {
            currToLE.append(l);
        }
        ui->lineEditCalculationArea->setText(currToLE);
    }
}

void MainWindow::updateProgressBarGN()
{
    ui->progressBarGN->setValue(ui->progressBarGN->value() - 3);
}

void MainWindow::confirmMyNumber()
{
    dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->setUserSolutionValue(
                dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->userExpression());

    QString finalExp = ui->lineEditCalculationArea->text() + " = " +
            QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->userSolutionValue());
    if(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->userSolutionValue() > 0)
        ui->lineEditCalculationArea->setText(finalExp);
    else
        ui->lineEditCalculationArea->setText("");
    dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->updateScore();
    QString plus = "+";
    ui->labelGNPointsWon->setText(plus.append(QString::number(dynamic_cast<LevelMyNumber*>(rslagalica->levels().at(1))->score())));
    ui->labelGNPointsWon->show();
    ui->pushButtonGNNextGame->show();
    ui->labelGNScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->pushButtonOneDigNumber1->setDisabled(true);
    ui->pushButtonOneDigNumber2->setDisabled(true);
    ui->pushButtonOneDigNumber3->setDisabled(true);
    ui->pushButtonOneDigNumber4->setDisabled(true);
    ui->pushButtonTwoDigNumber1->setDisabled(true);
    ui->pushButtonThreeDigNumber->setDisabled(true);
    ui->pushButtonGNBackspace->setDisabled(true);
    ui->pushButtonGNClear->setDisabled(true);
    ui->pushButtonConfirmExpression->setDisabled(true);
    ui->pushButtonMathPlus->setDisabled(true);
    ui->pushButtonMathMinus->setDisabled(true);
    ui->pushButtonMathMul->setDisabled(true);
    ui->pushButtonMathDiv->setDisabled(true);
    ui->pushButtonMathOpenBracket->setDisabled(true);
    ui->pushButtonMathClosedBracket->setDisabled(true);
    ui->progressBarGN->setValue(0);
    ui->lineEditCalculationArea->setDisabled(true);
}

void MainWindow::setLevelConnectors()
{
    ui->pageLevelMyNumber->hide();
    ui->pushButtonCONextGame->hide();
    ui->pageLevelConnectors->show();
    ui->labelGameConnectorsUsernameValue->setText(rslagalica->username());
    ui->labelCOScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->labelConnectorsPointsWon->hide();

    const int TEST_NUMBER = 8;
    QString test_name = ":/connectors/connections_";
    // set seed
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    // get number
    QString test_num = QString::number((qrand() % TEST_NUMBER) + 1);
    QFile conn_test(test_name + test_num);

    conn_test.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&conn_test);
    QString question = in.readLine();
    // set question text
    ui->pushButtonTextOfTheProblem->setText(question);

    QVector<QString> left, right;
    const int OBJECT_CNT = 8;
    for (int i=0; i < OBJECT_CNT*2; ++i) {
        if (i < OBJECT_CNT)
            left.push_back(in.readLine());
        else
            right.push_back(in.readLine());
    }
    for (int i=0; i < OBJECT_CNT; ++i)
    {
        connectorsSolution[left.at(i)] = right.at(i);
        dynamic_cast<LevelConnections*>(rslagalica->levels().at(2))->addToSolution(left.at(i), right.at(i));
    }
    std::random_shuffle(left.begin(),left.end());
    std::random_shuffle(right.begin(),right.end());
    conn_test.close();

    for (int i=0; i < OBJECT_CNT; ++i) {
        QWidget *leftButtonW = ui->verticalLayoutLeft->itemAt(i)->widget();
        QWidget *rightButtonW = ui->verticalLayoutRight->itemAt(i)->widget();
        QPushButton* leftButton = static_cast<QPushButton*>(leftButtonW);
        QPushButton* rightButton = static_cast<QPushButton*>(rightButtonW);
        connect(leftButton, &QPushButton::clicked, this, &MainWindow::leftButtonSelected);
        connect(rightButton, &QPushButton::clicked, this, &MainWindow::rightButtonSelected);
        leftButton->setText(left[i]);
        rightButton->setText(right[i]);
    }

    startLevelConnectors();
}

void MainWindow::startLevelConnectors()
{
    ui->progressBar->setValue(100);
    QTimer *timerConnectors = new QTimer(this);
    timerConnectors->start(1000);
    connect(timerConnectors, SIGNAL(timeout()), this, SLOT(connectorsCountSecond()));
}

void MainWindow::connectorsCountSecond()
{
    const double TOTAL_TIME = 60;
    const double UNIT = ui->progressBar->maximum() / TOTAL_TIME;
    ui->progressBar->setValue(ui->progressBar->value() - UNIT);
    if (ui->progressBar->value() == ui->progressBar->minimum()) {
        finishConnectionsLevel();
    }
}

void MainWindow::finishConnectionsLevel()
{
    dynamic_cast<LevelConnections*>(rslagalica->levels().at(2))->updateScore();
    QString plusSign = "+";
    ui->labelConnectorsPointsWon->setText(
                plusSign.append(QString::number(dynamic_cast<LevelConnections*>(rslagalica->levels().at(2))->score())));
    ui->labelConnectorsPointsWon->show();
    ui->labelCOScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->pushButtonCONextGame->show();
    ui->progressBar->setValue(0);
}

void MainWindow::leftButtonSelected()
{
    QPushButton* buttonClicked = static_cast<QPushButton*>(sender());
    if (buttonClicked->isEnabled())
    {
        selectedLeft = buttonClicked;
        dynamic_cast<LevelConnections*>(rslagalica->levels().at(2))->addToLeftPicks(selectedLeft->text());
    }
}

void MainWindow::rightButtonSelected()
{
    QPushButton* buttonClicked = static_cast<QPushButton*>(sender());
    if (buttonClicked->isEnabled())
    {
        selectedRight = buttonClicked;
        dynamic_cast<LevelConnections*>(rslagalica->levels().at(2))->addToRightPicks(selectedRight->text());
    }
    if (selectedLeft != NULL) {
        // do the check
        if (connectorsSolution[selectedLeft->text()] == selectedRight->text()) {
            // TODO: color both buttons green
            selectedLeft->setStyleSheet("background-color: green;");
            selectedRight->setStyleSheet("background-color: green;");
            selectedLeft->setEnabled(false);
            selectedRight->setEnabled(false);

            selectedLeft = NULL;
        } else {
            // TODO: show error - paint right button red
            selectedLeft->setStyleSheet("background-color: red;");
            selectedLeft->setEnabled(false);
            selectedRight = NULL;
        }
    }
}

//asocijacije
void MainWindow::setupAssociationsLevel(){

    ui->pageLevelConnectors->hide();
    ui->pageLevelAsociations->show();
    ui->labelASUsernameValue->setText(rslagalica->username());
    ui->labelASScoreValue->setText(QString::number(rslagalica->currScore()));
    ui->labelASPointsWon->hide();
    ui->labelASColAPts->hide();
    ui->labelASColBPts->hide();
    ui->labelASColCPts->hide();
    ui->labelASColDPts->hide();
    ui->pushButtonTheEnd->hide();

    const int TEST_NUMBER = 5;
    QString test_name = ":/games_data/";
    // set seed
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    // get number
    QString test_num = QString::number((qrand() % TEST_NUMBER) + 1);
    assocFilename =(test_name + test_num +".txt");

    startLevelAsoc();
}

void MainWindow::startLevelAsoc()
{
    ui->asocProgressBar->setValue(100);
    QTimer *timerConnectors = new QTimer(this);
    timerConnectors->start(1000);
    connect(timerConnectors, SIGNAL(timeout()), this, SLOT(CountSecondAsoc()));
}

void MainWindow::CountSecondAsoc()
{
    const double TOTAL_TIME = 80;
    const double UNIT = ui->progressBar->maximum() / TOTAL_TIME;
    ui->asocProgressBar->setValue(ui->asocProgressBar->value() - UNIT);
    if (ui->asocProgressBar->value() == ui->asocProgressBar->minimum()) {
        // disable all features
        disconnect(sender(), SIGNAL(timeout()), this, SLOT(CountSecondAsoc()));
        ispisKonacno();

        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->updateScore();
        ui->labelASPointsWon->setText(
                    QString::number(dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->score()));
        QString plusSign = "+";
        ui->labelASPointsWon->setText(plusSign.append(
                    QString::number(dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->score())));
        ui->labelASPointsWon->show();
        ui->labelASScoreValue->setText(QString::number(rslagalica->currScore()));
        ui->pushButtonTheEnd->show();
    }
}

void MainWindow::textA1()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word = in.readLine();
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColA(word);
    ui->A1->setText(word);
}

void MainWindow::textA2()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<2;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColA(word);
    ui->A2->setText(word);
}

void MainWindow::textA3()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<3;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColA(word);
    ui->A3->setText(word);
}

void MainWindow::textA4()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<4;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColA(word);
    ui->A4->setText(word);
}

void MainWindow::textB1()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<6;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColB(word);
    ui->B1->setText(word);
}

void MainWindow::textB2()
{
    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<7;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColB(word);
    ui->B2->setText(word);
}

void MainWindow::textB3()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<8;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColB(word);
    ui->B3->setText(word);
}

void MainWindow::textB4()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<9;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColB(word);
    ui->B4->setText(word);
}

void MainWindow::textC1()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<11;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColC(word);
    ui->C1->setText(word);
}

void MainWindow::textC2()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<12;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColC(word);
    ui->C2->setText(word);
}

void MainWindow::textC3()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<13;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColC(word);
    ui->C3->setText(word);
}

void MainWindow::textC4()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<14;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColC(word);
    ui->C4->setText(word);
}

void MainWindow::textD1()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<16;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColD(word);
    ui->D1->setText(word);
}

void MainWindow::textD2()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<17;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColD(word);
    ui->D2->setText(word);
}

void MainWindow::textD3()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<18;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColD(word);
    ui->D3->setText(word);
}

void MainWindow::textD4()
{

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<19;i++){
        word = in.readLine();
    }
    dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->addToColD(word);
    ui->D4->setText(word);
}

void MainWindow::resenjeA(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<5;i++){
        word = in.readLine();
    }

    QString attempt=ui->ResenjeA->text();
    int x=QString::compare(word,attempt,Qt::CaseInsensitive);
    if(x==0){
        ui->ResenjeA->setText(word);
        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->setSolColA(word);
        ispisiA();
    }
    else
        ui->ResenjeA->setText("Netacno!");
}

void MainWindow::resenjeB(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<10;i++){
        word = in.readLine();
    }

    QString attempt=ui->ResenjeB->text();
    int x=QString::compare(word,attempt,Qt::CaseInsensitive);
    if(x==0){
        ui->ResenjeB->setText(word);
        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->setSolColB(word);
        ispisiB();
    }
    else
        ui->ResenjeB->setText("Netacno!");

}

void MainWindow::resenjeC(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<15;i++){
        word = in.readLine();
    }

    QString attempt=ui->ResenjeC->text();
    int x=QString::compare(word,attempt,Qt::CaseInsensitive);
    if(x==0){
        ui->ResenjeC->setText(word);
        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->setSolColC(word);
        ispisiC();
    }
    else
        ui->ResenjeC->setText("Netacno!");

}

void MainWindow::resenjeD(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<20;i++){
        word = in.readLine();
    }

    QString attempt=ui->ResenjeD->text();
    int x=QString::compare(word,attempt,Qt::CaseInsensitive);
    if(x==0){
        ui->ResenjeD->setText(word);
        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->setSolColD(word);
        ispisiD();
    }
    else
        ui->ResenjeD->setText("Netacno!");

}

void MainWindow::konacnoResenje(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<21;i++){
        word = in.readLine();
    }

    QString attempt=ui->konacnoResenje->text();
    int x=QString::compare(word,attempt,Qt::CaseInsensitive);
    if(x==0){
        ui->konacnoResenje->setText(word);
        ispisiA();
        ispisiB();
        ispisiC();
        ispisiD();
        dynamic_cast<LevelAssociations*>(rslagalica->levels().at(3))->setSolFinal(word);
        ui->asocProgressBar->setValue(0);
    }
    else
        ui->konacnoResenje->setText("Netacno!");

}

void MainWindow::ispisiA(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    word=in.readLine();
    ui->A1->setText(word);
    word=in.readLine();
    ui->A2->setText(word);
    word=in.readLine();
    ui->A3->setText(word);
    word=in.readLine();
    ui->A4->setText(word);
    word=in.readLine();
    ui->ResenjeA->setText(word);

}

void MainWindow::ispisiB(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<6;i++){
        word=in.readLine();
    }

    ui->B1->setText(word);
    word=in.readLine();
    ui->B2->setText(word);
    word=in.readLine();
    ui->B3->setText(word);
    word=in.readLine();
    ui->B4->setText(word);
    word=in.readLine();
    ui->ResenjeB->setText(word);
}

void MainWindow::ispisiC(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<11;i++){
        word=in.readLine();
    }

    ui->C1->setText(word);
    word=in.readLine();
    ui->C2->setText(word);
    word=in.readLine();
    ui->C3->setText(word);
    word=in.readLine();
    ui->C4->setText(word);
    word=in.readLine();
    ui->ResenjeC->setText(word);

}

void MainWindow::ispisiD(){

    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<16;i++){
        word=in.readLine();
    }

    ui->D1->setText(word);
    word=in.readLine();
    ui->D2->setText(word);
    word=in.readLine();
    ui->D3->setText(word);
    word=in.readLine();
    ui->D4->setText(word);
    word=in.readLine();
    ui->ResenjeD->setText(word);
}

void MainWindow::ispisKonacno(){


    QFile associations(assocFilename);
    associations.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&associations);
    QString word;
    for(int i=0;i<21;i++){
        word = in.readLine();
    }

    ui->konacnoResenje->setText(word);
    ispisiA();
    ispisiB();
    ispisiC();
    ispisiD();

}
//asocijacije

void MainWindow::finishGame()
{
    //fillHighScoreTable();
    ui->pageLevelAsociations->hide();
    ui->pageEndGame->show();
    ui->labelEndUsernameValue->setText(rslagalica->username());
    ui->labelEndScoreValue->setText(QString::number(rslagalica->currScore()));
}

void MainWindow::fillHighScoreTable()
{
    QFile hs("/home/cane/Workspace/RS05-rslagalica/RSlagalica/resources/games_data/highscore.txt");
    hs.open(QIODevice::ReadWrite | QIODevice::Text);
    //QTextStream in(&hs);
    QString userDataQStr;
    userDataQStr.append(rslagalica->username()).append(QChar(' ')).append(QString::number(rslagalica->currScore()));
    QByteArray b;
    const char* userData = b.data();
    hs.write(userData, qstrlen(userData));
    hs.close();
}
