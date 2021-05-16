/*Program by Federico Carrocera Student Number 20434992*/
#include "library.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
struct Players player1 ,player2;
struct Game Game;
int main() {
    FILE *WinnerWinnerChickenDinner;
    int Allowed = 0;
    int PassedRow = 0;
    int played = 0;
    char move[3];
    int i,j;
    int disp[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 2, 1, 0, 0, 0},
            {0, 0, 0, 1, 2, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
    };
    puts("\t*** Welcome to Othello! ***\t\n");
    puts("Game will end if there are no places to play left or if both players pass consecutively\n");
    puts("Player 1 please write your name. You will be playing black.");
    scanf(" %s", player1.Name);
    player1.score = 2;
    puts("Player 2 please write your name. You will be playing white.");
    scanf(" %s", player2.Name);
    player2.score = 2;
    memcpy(Game.Board, disp, sizeof(disp));
    ///print function
    BoardPrinter();
    ///moves
    Game.SquaresLeft = 36 - player2.score - player1.score;
    while( Game.SquaresLeft != 0 && PassedRow < 1)
    {
        fflush(stdin);
        played = 0 ;//reset to haven't played
        while(played == 0)
        {
            printf("%s's Turn\n", player1.Name);
            puts("Press p to pass otherwise input the square you wish to play in e.g a4 or b5");
            scanf(" %s", move);
            if(move[0] =='p')
            {
                played = Pass(1, 2);
                if(played == 0)
                {
                    puts("There is a playable move.");
                }
                else
                {
                    PassedRow++;//add to passed in a row
                }
            }
            else//run allowed moves
            {
                Allowed = 0;
                Allowed += RightToLeft(move, 1, 2,disp);
                Allowed += LeftToRight(move, 1, 2,disp);
                Allowed += BottomToTop(move, 1, 2,disp);
                Allowed += TopToBottom(move, 1, 2,disp);
                Allowed += TopLeft(move, 1, 2,disp);
                Allowed += TopRight(move, 1, 2,disp);
                Allowed += BottomLeft(move, 1, 2,disp);
                Allowed += BottomRight(move, 1, 2,disp);
                if (Allowed == 0 || (move[0] < 'a' || move[0] > 'h') && (move[1]< '1' || move[1]> '8' ))//if moves not allowed or wrong square
                {
                    puts("Invalid Move");
                }
                else
                {
                    memcpy(Game.Board, disp, sizeof(disp));//copy made moves onto the struct to avoid changing the board during the turn
                    BoardPrinter();
                    PassedRow = 0;
                    played = 1;
                }
            }
        }
        Game.SquaresLeft = 64 - player2.score - player1.score;
        played = 0;
        while(played == 0)
        {
            printf("%s's Turn\n", player2.Name);
            puts("Press p to pass otherwise input the square you wish to play in e.g a4 or b5");
            scanf(" %s", move);
            if(move[0] =='p')
            {
             played = Pass(2, 1);
             if(played == 0)
             {
                 puts("There is a playable move.");
             }
             else
             {
                 PassedRow++;
             }
            }
            else
            {
                Allowed = 0;
                Allowed += RightToLeft(move, 2, 1,disp);
                Allowed += LeftToRight(move, 2, 1,disp);
                Allowed += BottomToTop(move, 2, 1,disp);
                Allowed += TopToBottom(move, 2, 1,disp);
                Allowed += TopLeft(move, 2, 1,disp);
                Allowed += TopRight(move, 2, 1,disp);
                Allowed += BottomLeft(move, 2, 1,disp);
                Allowed += BottomRight(move, 2, 1,disp);
                if (Allowed == 0 || (move[0] < 'a' || move[0] > 'h') && (move[1]< '1' || move[1]> '8' ))
                {
                    puts("Invalid Move");
                }
                else
                {
                    memcpy(Game.Board, disp, sizeof(disp));
                    BoardPrinter();
                    PassedRow = 0;
                    played = 1;
                }
            }
        }
    }
    player1.score = 0;
    player2.score = 0;
    WinnerWinnerChickenDinner = fopen("C:\\Users\\fedec\\Desktop\\Othello_UCD20434992\\Othello_Winner.txt", "a");
    if(WinnerWinnerChickenDinner == NULL)
    {
        printf("Unable to open file");
    }
    else
    {
        puts("File Found !!");
        for(i=0;i<8;i++)
        {
            fprintf( WinnerWinnerChickenDinner,"    --- --- --- --- --- --- --- --- \n %d ", (i+1));
            for(j=0;j<8;j++)
            {
                switch (Game.Board[i][j])
                {
                    case 1:
                        fprintf(WinnerWinnerChickenDinner, "| B ");
                        player1.score = player1.score + 1;
                        break;

                    case 2:
                        fprintf(WinnerWinnerChickenDinner, "| W ");
                        player2.score = player2.score + 1;
                        break;

                    default:
                        fprintf(WinnerWinnerChickenDinner, "|   ");
                }
            }
            fprintf(WinnerWinnerChickenDinner,"|\n");
        }
        fprintf(WinnerWinnerChickenDinner,"    --- --- --- --- --- --- --- --- \n     a   b   c   d   e   f   g   h\n");
        fprintf(WinnerWinnerChickenDinner,"    Score: %s (Black) %d:%d %s (White)\n\n", player1.Name,player1.score,player2.score,player2.Name);
        if(player1.score < player2.score)
        {
            fprintf(WinnerWinnerChickenDinner, "\n %s won the Game\n", player2.Name);
        }
        else
        {
            fprintf(WinnerWinnerChickenDinner, "\n %s won the Game\n", player1.Name);
        }
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        char s[64];
        assert(strftime(s, sizeof(s), "%c", tm));
        fprintf(WinnerWinnerChickenDinner,"%s\n", s);
    }
    return 0;
}