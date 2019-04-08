#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW  3
#define LINE 3
void Initboard(char board[ROW][LINE], int row, int line);
void Printfboard(char board[ROW][LINE], int row, int line);
void Player_Runboard(char board[ROW][LINE], int row, int line);
void computer_Runboard(char board[ROW][LINE], int row, int line);
char judgeboard(char board[ROW][LINE], int row, int line);

#endif  //__GAME_H__