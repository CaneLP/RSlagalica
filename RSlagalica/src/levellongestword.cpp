#include "headers/levellongestword.h"

const int num_of_letters = 12;
const int alphabet_size = 44;

LevelLongestWord::LevelLongestWord()
{
    m_score = 0;
    letters = {"A", "A", "A", "B", "C", "D", "D", "E", "E", "F", "G", "H", "I", "I", "I", "J", "K", "L", "Lj",
                 "M", "M", "N", "N", "Nj", "O", "O", "P", "P", "R", "R", "S", "S", "T","T", "U", "U", "V", "Z",
                 QChar(0x010C), //ch
                 QChar(0x0106), //tj
                 QChar(0x0110), //dj
                 QChar(0x0160), //sh
                 "D" + QString(QChar(0x017E)), //dz
                 QChar(0x017D), //zh
                 };

    srand(time(NULL));
    for(int i = 0; i < num_of_letters; ++i)
    {
        m_givenLetters.push_back(letters[rand()%alphabet_size]);
    }
//    QFile dictionary("://sr_Latn.game.dic");
//    dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
//    QTextStream in(&dictionary);
//    QVector<QString> words;
//    while(!in.atEnd())
//    {
//        QString word = in.readLine();
//        //if(word.length() >= 8)
//            words.push_back(word);
//    }
//    dictionary.close();
//    QVector<QString> lettersToAdd;
//    int wordToAddPos = rand()%words.length();
//    int n = words[wordToAddPos].length();
//    for(int i = 0; i < n; ++i)
//    {
//        lettersToAdd.push_back(QString(words[wordToAddPos][i]));
//    }

//    for(int i = n; i < num_of_letters; ++i)
//    {
//        lettersToAdd.push_back(letters[rand()%alphabet_size]);
//    }

//    for(int i = 0; i < num_of_letters; ++i)
//    {
//        m_givenLetters.push_back(lettersToAdd[rand()%alphabet_size]);
//    }
}

QVector<QString> LevelLongestWord::givenLetters() const
{
    return m_givenLetters;
}

void LevelLongestWord::setUserWord(const QVector<QString> word)
{
    m_userWord = word;
}

QVector<QString> LevelLongestWord::userWord()
{
    return m_userWord;
}

void LevelLongestWord::updateScore()
{
    m_score = m_userWord.length() * 2;
}

int LevelLongestWord::score() const
{
    return m_score;
}

void LevelLongestWord::setScore(const int pts)
{
    m_score = pts;
}

QVector<QString> LevelLongestWord::longestWord() const
{
    return m_longestWord;
}

void LevelLongestWord::setLongestWord(const QVector<QString> word)
{
    m_longestWord = word;
}
