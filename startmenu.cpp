#include "startmenu.h"


startMenu::startMenu(QWidget *parent) :QWidget(parent)
{
    setWindowTitle("Меню");

    //set text for each button
    playButton.setText("Начать игру");
    aboutButton.setText("Об игре");
    exitButton.setText("Выход");

    //connect clicked signal with slots
    QObject::connect(&playButton, SIGNAL(clicked()), this, SLOT(onPlayButtonClicked()));
    QObject::connect(&aboutButton, SIGNAL(clicked()), this, SLOT(onAbuoutButtonClicked()));
    QObject::connect(&exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));

    //one size for all button
    playButton.setFixedSize(200, 80);
    aboutButton.setFixedSize(200, 80);
    exitButton.setFixedSize(200, 80);

    //add to window
    layout.addWidget(&playButton);
    layout.addWidget(&aboutButton);
    layout.addWidget(&exitButton);

    setLayout(&layout);
}

//start game
void startMenu::onPlayButtonClicked()
{
    //open game window
    Game * g = new Game();
    g->show();
    close();
}

//get about message
void startMenu::onAbuoutButtonClicked()
{
    about * a = new about();
}

//close
void startMenu::onExitButtonClicked()
{
    //ask user before closing
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Выход", "Вы действительно хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        close();
    }
}
