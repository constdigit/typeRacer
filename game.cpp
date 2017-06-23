#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent), position(0), mistakePos(-1), modified(false), wordsAmount(0)
{
    //get random text from files
    getSourceText();
    //set time to 0
    typingTime.setHMS(0, 0, 0, 0);

    //set text
    sourceText.setTextInteractionFlags(Qt::NoTextInteraction);
    sourceText.setText(source);
    sourceText.setFixedSize(400, 300);
    sourceText.setStyleSheet("selection-color: white; selection-background-color: blue;");
    QFont font = sourceText.font();
    font.setPixelSize(16);
    sourceText.setFont(font);
    charsAmount = source.size();

    //check characters that user is typing
    QObject::connect(&typing, SIGNAL(textEdited(QString)), this, SLOT(checkEdit()));

    //set progress bar
    progress.setRange(0, 100);
    progress.setAlignment(Qt::AlignCenter);
    progress.setFixedSize(400, 20);

    //add to window
    layout.addWidget(&sourceText);
    layout.addWidget(&typing);
    layout.addWidget(&progress);

    setLayout(&layout);
}

//highlights the text red when the user makes a mistake
void Game::highlight()
{

    QPalette palette;

    if (mistakePos != -1)
    {
        //red if mistake exist
        palette.setColor(QPalette::Text, Qt::red);
        typing.setPalette(palette);
    }
    else
    {
        //black if all right
        palette.setColor(QPalette::Text, Qt::black);
        typing.setPalette(palette);
    }

}

//compares current characters
void Game::compare()
{
    //if chars don't match and no mistake before
    if (source[position] != current[current.size() - 1] && mistakePos == -1)
        mistakePos = position;
    else
    {
        //when input is correct
        if (position <= mistakePos || getFirstWordFromSource().contains(current))
            mistakePos = -1;

        if (mistakePos == -1)
        {
            incProgress();
            selectTypedText();
        }

        //go to next word
        if (mistakePos == -1 && source[position] == ' ')
        {
            typing.clear();
            source.remove(0, position + 1);
            position = 0;
            wordsAmount++;
        }
    }

    //change text color
    highlight();
}

//show message when the text is completely entered
void Game::finish()
{
    //count result
    unsigned seconds = typingTime.elapsed() / 1000;
    unsigned charsPerSecond = charsAmount / seconds;
    unsigned wordsPerMinute = (wordsAmount * 60) / seconds;
    QString resultMessage("Ваш результат: " + QString::number(charsPerSecond) + " символов в секунду\n" +
                          QString::number(wordsPerMinute) + " слов в минуту"
                          "\n Хотите сыграть еще?");
    //clear window
    sourceText.setText("");
    typing.setText("");
    //show message
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Финиш", resultMessage, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
        close();
    }
    if(reply == QMessageBox::Yes)
    {
        //new text
        source = "";
        getSourceText();
        //set all to default
        typingTime.setHMS(0, 0, 0, 0);
        sourceText.setText(source);
        mistakePos = -1;
        position = 0;
        modified = false;
        charsAmount = source.size();
        wordsAmount = 0;
        progress.reset();
    }

}

//read random text from file
void Game::getSourceText()
{
    //generate random filename
    srand(time(0));
    QString filename = ":/texts/text.txt";
    filename.insert(12, QString::number(rand() % 10));
    QFile file(filename);

    //try to open
    if (!file.open(QIODevice::ReadOnly))
    {
        source = "Что-то пошло не так.";
        return;
    }

    //read strings from stream
    QTextStream in(&file);
    while (!in.atEnd())
    {
        source += in.readLine();
    }

    file.close();
}

//get current word for typing
QString Game::getFirstWordFromSource()
{
    QString word;
    int i(0);
    while (source[i] != ' ' && i < source.size())
    {
            word += source[i];
            i++;
    }
    word += ' ';

    return word;
}

//progress increases if user didn't make mistakes
void Game::incProgress()
{
    progress.setValue(((charsAmount - source.size() + current.size()) * 100) / charsAmount);
}

//user could see what he already typed
void Game::selectTypedText()
{
    QTextCursor c = sourceText.textCursor();
    c.setPosition(0);
    c.setPosition(charsAmount - source.size() + current.size(), QTextCursor::KeepAnchor);
    sourceText.setTextCursor(c);
}

//controls each user input
void Game::checkEdit()
{
    //start of timer with first inputed character
    if (!modified)
    {
        typingTime.start();
        modified = true;
    }

    //get text from line edit
    current = typing.text();

    //if line edit isn't empty
    if (current.size() > 0)
    {
        //align position
        if (position + 1 > current.size())
        {
            position--;
        }
        if (position + 1 < current.size())
        {
            position++;
        }

        compare();

        //check for end
        if (mistakePos == -1 && position + 1 == source.size())
            finish();
    }
    else
    {
        incProgress();
        selectTypedText();
    }
}



