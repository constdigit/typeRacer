#ifndef GAME_H
#define GAME_H

#include <QImage>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPainter>
#include <QProgressBar>
#include <QTextStream>
#include <QTime>
#include <QVBoxLayout>
#include <QWidget>
#include <time.h>
#include "abstractgame.h"

//game window
class Game : public QWidget, public AbstractGame
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);

    //highlights the text red when the user makes a mistake
    void highlight();
    //compares current characters
    void compare();
    //show message when the text is completely entered
    void finish();
    //read random text from file
    void getSourceText();
    //get current word for typing
    QString getFirstWordFromSource();
    //progress increases if user didn't make mistakes
    void incProgress();

private:
    //sets to true with first input
    bool modified;
    //amount of characters in text
    unsigned charsAmount;
    //amount of words in text
    unsigned wordsAmount;
    //index of compared characters
    unsigned position;
    //where is mistake
    int mistakePos;

    //for count time
    QTime typingTime;
    //keeps text that user must type
    QString source;
    //keeps text that user typed
    QString current;
    //show source text
    QLabel sourceText;
    //user input
    QLineEdit typing;
    //user input lies under text
    QVBoxLayout layout;
    //see progress
    QProgressBar progress;

public slots:
    //controls each user input
    void checkEdit();
};



#endif // GAME_H
