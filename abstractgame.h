#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#endif // ABSTRACTGAME_H

#include <QString>

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
};
