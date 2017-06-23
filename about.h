#ifndef ABOUT_H
#define ABOUT_H

#include <QLabel>
#include <QLayout>
#include <QMovie>
#include <QWidget>

//reference window
class about : public QWidget
{
    Q_OBJECT
public:
    explicit about(QWidget *parent = nullptr);

private:
    QLabel info;
    QLabel animation;
    QVBoxLayout layout;
    QMovie typingDots;
};

#endif // ABOUT_H
