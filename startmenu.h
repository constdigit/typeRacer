#ifndef STARTMENU_H
#define STARTMENU_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "about.h"
#include "game.h"

//menu
class startMenu : public QWidget
{
    Q_OBJECT
public:
    explicit startMenu(QWidget *parent = 0);

private slots:
    void onPlayButtonClicked();
    void onAbuoutButtonClicked();
    void onExitButtonClicked();

private:
    QPushButton playButton;
    QPushButton aboutButton;
    QPushButton exitButton;
    QVBoxLayout layout;
};

#endif // STARTMENU_H
