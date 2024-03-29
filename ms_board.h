#ifndef MS_BOARD_H
#define MS_BOARD_H

#include <QWidget>
#include <QGridLayout>
//#include <QVector>

#include "ms_button.h"

//These are template vectors that will be used to store
//the actual buttons and the new state of the buttons.
typedef QVector<MSButton*> MSButtonVec;
typedef QVector<int> MSArray;

class MSBoard : public QWidget
{
  Q_OBJECT

  public:
    MSBoard (QWidget* parent);
    ~MSBoard ();
    void newGame ();
    void assignMines ();

    bool timerIsActive;

    //Defines possible outcomes
    enum State { Win, Lose };

  signals:
    void finished (MSBoard::State s);
    void flagsChanged (int change);
    void beginTimer ();

  private slots:
    void buttonLeftClicked ();
    void buttonRightClicked ();

  private:
    void updateButtons ();
    int checkBoard ();
    void gameLost ();
    void gameWon ();
    //gameIsOver is used to prevent the board from being changed
    //by clicking buttons once the game is over
    bool gameIsOver;
    int height;
    int width;

    MSButtonVec* buttons;  //Stores the actual buttons
    MSArray* msArray;      //Stores the current state of the buttons
    QGridLayout* grid;
};

#endif
