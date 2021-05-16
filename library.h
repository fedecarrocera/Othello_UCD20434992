//
// Created by fedec on 4/12/2021.
//

#ifndef OTHELLO_UCD20434992_LIBRARY_H
#define OTHELLO_UCD20434992_LIBRARY_H
struct Players
{
    char Name[15];

    int score;
};
struct Game
{
    int Board[8][8];

    int SquaresLeft;
};
struct Players player1 ,player2;
struct Game Game;
void BoardPrinter ();
int LeftToRight ();
int RightToLeft ();
int BottomToTop ();
int TopToBottom ();
int TopLeft ();
int TopRight ();
int BottomLeft ();
int BottomRight ();
int Pass ();
#endif //OTHELLO_UCD20434992_LIBRARY_H
