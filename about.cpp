#include "about.h"

about::about(QWidget *parent) : QWidget(parent)
{
    //set info text
    setWindowTitle("Об игре");
    info.setText("Эта игра позволяет развить навыки печати на клавиатуре. "
                 "\n Ваша задача - как можно быстрее набрать текст на экране.");
    QFont font = info.font();
    font.setPixelSize(12);
    info.setFont(font);
    info.setAlignment(Qt::AlignCenter);

    //set animation
    typingDots.setFileName(":/animation/dots.gif");
    typingDots.setScaledSize(*(new QSize(400, 300)));
    animation.setMovie(&typingDots);

    //add widgets on window and show
    layout.addWidget(&info);
    layout.addWidget(&animation);

    setLayout(&layout);
    setFixedSize(400, 350);
    show();
    typingDots.start();
}
