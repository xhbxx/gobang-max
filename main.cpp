#include "board.h"
#include"ai.h"
#include <conio.h>
#include <cstdlib>  

using namespace std;

int cot = 0;
bool white = true; 
bool two = true;
bool jump = false;
int main() {
    srand((unsigned int)time(NULL));
    initgraph(600, 600);
    // 第一次选择黑白
    int chooseMode = 1;
    while (true) {
        cleardevice();
        settextstyle(30, 0, _T("宋体"));
        outtextxy(160, 260, _T("1.BLACK  2.WHITE"));

        if (_kbhit()) {
            char k = _getch();
            if (k == '1') {
                playerColor = B;
                aiColor = W;
                chooseMode = 0;
                attack = 0.8;
                bool white = true;
                break;           
            }

            if (k == '2') {
                playerColor = W;
                aiColor = B;
                chooseMode = 0;
                 attack = 1.5;
                  white = false;
                break;
            }
        }
    }

  // ========== 游戏主循环 ==========
    while (true) {
        // 每局开始前初始化
        initBoard();
        cleardevice();
        drawBoard();

        // AI 是黑棋就先下
        if (aiColor == B) {
            
            Board[7][7] = aiColor;
            drawPiece(7, 7, aiColor);
            cot++;
        }

        isGameOver = false;

        // ========== 单局循环 ==========
        while (true) {
            // 按 R 键直接重来
            if (_kbhit()) {
                if (_getch() == 'r') {
                    isGameOver = true;
                    break;
                }
            }

            if (isGameOver) {
                settextcolor(BLACK);
                settextstyle(40, 0, _T("宋体"));
                outtextxy(180, 270, _T(" R "));
                continue;
            }

            int row = -1, col = -1;
            getMouseRowCol(row, col);

            if (isValidPos(row, col)) {
                // 玩家下
                Board[row][col] = playerColor;
                drawPiece(row, col, playerColor);
                cot++;
                    if (checkWin(row, col, playerColor)) {
                        isGameOver = true;
                        continue;
                    }
            
                if (aiColor == 2)
                {
                    if (white)
                    {
                        if (two) 
                        {
                            int a = rand() % 4;
                            if (a == 0)
                            {
                                row--;
                                if (row < 0)
                                {
                                    row += 3;
                                }
                            }
                            else if (a == 1)
                            {
                                col++;
                                if (col > 14)
                                {
                                   col -= 3;
                                }
                            }
                            else if (a == 2)
                            {
                                row++;              
                                    if (row > 14)
                                    {
                                        row -= 3;
                                    }                                
                            }
                            else if (a == 3)
                            {
                                col --;
                                if (row < 0)
                                {
                                    row += 3;
                                }
                            }
                            Board[row][col] = aiColor;
                            drawPiece(row, col, aiColor);
                            two = false;
                            jump = true;
                            cot++;
                        }
                    }
                }
                // AI 下
                if (jump) { jump = false; continue; }
                    cout << "wait" << endl;
                    aiMove(1, Board, aiColor);
                    cot++;
                    cout << "over" << endl;
                MessageBeep(MB_OK);
                if (isGameOver == true) {
                    continue;
                }
                
            }
        }
    }

    closegraph();
    return 0;
}
