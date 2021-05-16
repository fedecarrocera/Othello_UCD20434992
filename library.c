//
// Created by fedec on 4/12/2021.
//
#include <stdio.h>
#include <stdbool.h>

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
int LeftToRight (const char move[], int Player , int Opponent,int disp[8][8]);
int RightToLeft(const char move[], int Player , int Opponent,int disp[8][8]);
int BottomToTop(const char move[], int Player , int Opponent,int disp[8][8]);
int TopToBottom (const char move[], int Player , int Opponent,int disp[8][8]);
int TopLeft (const char move[], int Player , int Opponent,int disp[8][8]);
int TopRight (const char move[], int Player , int Opponent,int disp[8][8]);
int BottomLeft (const char move[], int Player , int Opponent,int disp[8][8]);
int BottomRight (const char move[], int Player , int Opponent,int disp[8][8]);
int Pass (int Player, int Opponent);
void BoardPrinter (){
    int i,j;
    player1.score = 0;
    player2.score = 0;
    for(i=0;i<8;i++)
    {
        printf("    --- --- --- --- --- --- --- --- \n %d ", (i+1));
        for(j=0;j<8;j++)
        {
            switch (Game.Board[i][j])
            {
                case 1:
                    printf( "| B ");
                    player1.score = player1.score + 1;
                    break;

                case 2:
                    printf( "| W ");
                    player2.score = player2.score + 1;
                    break;

                default:
                    printf( "|   ");
            }
        }
        printf("|\n");
    }
    printf("    --- --- --- --- --- --- --- --- \n     a   b   c   d   e   f   g   h\n");
    printf("    Score: %s (Black) %d:%d %s (White)\n\n", player1.Name,player1.score,player2.score,player2.Name);
}
int LeftToRight(const char move[], int Player , int Opponent,int disp[8][8])
{
    int i=1, x;
    bool valid = false;
    //printf("LeftToRight valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)//place to put new piece not empty fail
    {
       // printf("LeftToRight valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 49][move[0] - 96] == Opponent)//if next piece is the opponents continue
        {
            for ( x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49][move[0] - 97 + x] == 0)//if piece is empty fail move
                {
                    break;
                }
                if (Game.Board[move[1] - 49][move[0] - 97 + x] == Player)// if the piece is that follows the opponents is your valid move
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                while (Game.Board[move[1] - 49][move[0] - 97 + i] != Player && Game.Board[move[1] - 49][move[0] - 97 + i] != 0)
                {
                    disp[move[1] - 49][move[0] - 97 + i] = Player;
                    i++;
                }
      //          printf("LeftToRight valid: %d\n", valid);
                return 1;
            }
            else
                {
         //           printf("LeftToRight valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
           //     printf("LeftToRight valid: %d\n", valid);
                return 0;
            }
    }
}
int RightToLeft(const char move[], int Player , int Opponent,int disp[8][8]) {
    int i;
    bool valid = false;
    //printf("RightToLeft valid: %d\n", valid);
    if (Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
      //  printf("RightToLeft valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 49][move[0] - 98] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49][(move[0] - 97) - x] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49][(move[0] - 97) - x] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49][move[0] - 97 - i] != Player && Game.Board[move[1] - 49][move[0] - 97 - i] != 0)
                {
                    disp[move[1] - 49][move[0] - 97 - i] = Player;
                    i++;
                }
        //        printf("RightToLeft valid: %d\n", valid);
                return 1;
            }
            else
                {
          //          printf("RightToLeft valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
            //    printf("RightToLeft valid: %d\n", valid);
                return 0;
            }
    }
}

int BottomToTop(const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
   // printf("BottomToTop valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
      //  printf("BottomToTop valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 48][move[0] - 97] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 + x][move[0] - 97] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 + x][move[0] - 97] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 + i][move[0] - 97] != Player && Game.Board[move[1] - 49 + i][move[0] - 97] != 0)
                {
                    disp[move[1] - 49 + i][move[0] - 97] = Player;
                    i++;
                }
        //        printf("BottomToTop valid: %d\n", valid);
                return 1;
            }
            else
                {
          //          printf("BottomToTop valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
            //    printf("BottomToTop valid: %d\n", valid);
                return 0;
            }
    }
}
int TopToBottom (const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
    //printf("TopToBottom valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
      //  printf("TopToBottom valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 50][move[0] - 97] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 - x][move[0] - 97] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 - x][move[0] - 97] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 - i][move[0] - 97] != Player && Game.Board[move[1] - 49 - i][move[0] - 97] != 0)
                {
                    disp[move[1] - 49 - i][move[0] - 97] = Player;
                    i++;
                }
        //        printf("TopToBottom valid: %d\n", valid);
                return 1;
            }
            else
                {
          //          printf("TopToBottom valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
            //    printf("TopToBottom valid: %d\n", valid);
                return 0;
            }
    }
}
int TopLeft (const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
   // printf("TopLeft valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
     //   printf("TopLeft valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 48][move[0] - 96] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 + x][move[0] - 97 + x] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 + x][move[0] - 97 + x] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 + i][move[0] - 97 + i] != Player && Game.Board[move[1] - 49 + i][move[0] - 97 + i] != 0)
                {
                    disp[move[1] - 49 + i][move[0] - 97 + i] = Player;
                    i++;
                }
             //   printf("TopLeft valid: %d\n", valid);
                return 1;
            }
            else
                {
               //     printf("TopLeft valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
                //printf("TopLeft valid: %d\n", valid);
                return 0;
            }
    }
}
int TopRight (const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
   // printf("TopRight valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
     //   printf("TopRight valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 48][move[0] - 98] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 + x][move[0] - 97 - x] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 + x][move[0] - 97 - x] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 + i][move[0] - 97 - i] != Player && Game.Board[move[1] - 49 + i][move[0] - 97 - i] != 0)
                {
                    disp[move[1] - 49 + i][move[0] - 97 - i] = Player;
                    i++;
                }
       //         printf("TopRight valid: %d\n", valid);
                return 1;
            }
            else
                {
         //           printf("TopRight valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
           //     printf("TopRight valid: %d\n", valid);
                return 0;
            }
    }
}
int BottomLeft (const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
    //printf("BottomLeft valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
      //  printf("BottomLeft valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 50][move[0] - 96] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 - x][move[0] - 97 + x] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 - x][move[0] - 97 + x] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 - i][move[0] - 97 + i] != Player && Game.Board[move[1] - 49 - i][move[0] - 97 + i] != 0)
                {
                    disp[move[1] - 49 - i][move[0] - 97 + i] = Player;
                    i++;
                }
        //        printf("BottomLeft valid: %d\n", valid);
                return 1;
            }
            else
                {
          //          printf("BottomLeft valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
            //    printf("BottomLeft valid: %d\n", valid);
                return 0;
            }
    }
}
int BottomRight (const char move[], int Player , int Opponent,int disp[8][8])
{
    int i;
    bool valid = false;
    //printf("BottomRight valid: %d\n", valid);
    if(Game.Board[move[1] - 49][move[0] - 97] != 0)
    {
      //  printf("BottomRight valid: %d\n", valid);
        return 0;
    }
    else
        {
        if (Game.Board[move[1] - 50][move[0] - 98] == Opponent)
        {
            for (int x = 2; x < 8; x++)
            {
                if (Game.Board[move[1] - 49 - x][move[0] - 97 - x] == 0)
                {
                    break;
                }
                if (Game.Board[move[1] - 49 - x][move[0] - 97 - x] == Player)
                {
                    valid = true;
                    break;
                }
            }
            if (valid == true)
            {
                disp[move[1] - 49][move[0] - 97] = Player;
                i = 1;
                while (Game.Board[move[1] - 49 - i][move[0] - 97 - i] != Player && Game.Board[move[1] - 49 - i][move[0] - 97 - i] != 0)
                {
                    disp[move[1] - 49 - i][move[0] - 97 - i] = Player;
                    i++;
                }
        //        printf("BottomRight valid: %d\n", valid);
                return 1;
            }
            else
                {
          //          printf("BottomRight valid: %d\n", valid);
                    return 0;
                }
        }
        else
            {
            //    printf("BottomRight valid: %d\n", valid);
                return 0;
            }
    }
}
int Pass (int Player, int Opponent) {
    int  x, y;
    bool valid = false;
    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 8; x++)
        {
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x][y + j] == Player)
                    {
                        valid = true;
                        break;
                    }
                    if (Game.Board[x][y + j] == 0)
                    {
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x][y - j] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x][y - j] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x + j][y] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x+j][y] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x - j][y] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x-j][y] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x + j][y + j] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x + j][y + j] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x + j][y - j] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x + j][y - j] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x - j][y + j] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x - j][y + j] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            if (Game.Board[x][y] == Opponent)
            {
                for (int j = 2; j < 8; j++)
                {
                    if (Game.Board[x - j][y - j] == 0)
                    {
                        break;
                    }
                    if (Game.Board[x - j][y - j] == Player)
                    {
                        valid = true;
                        break;
                    }
                }
            }
        }
    }
    if (valid == true)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}