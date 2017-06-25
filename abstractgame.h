#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#endif // ABSTRACTGAME_H

#include <QString>
#include <QTime>

//why there is an abstract class?
//because it was necessary in the task
class AbstractGame {
protected:
    //highlights the text red when the user makes a mistake
    virtual void highlight() = 0;
    //compares current characters
    virtual void compare() = 0;
    //show message when the text is completely entered
    virtual void finish() = 0;
    //read random text from file
    virtual void getSourceText() = 0;
    //get current word for typing
    virtual QString getFirstWordFromSource() = 0;
    //progress increases if user didn't make mistakes
    virtual void incProgress() = 0;
    //user could see what he already typed
    virtual void selectTypedText() = 0;
};
