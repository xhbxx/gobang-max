#include "board.h"
#include"ai.h"
#include <conio.h>
#include <cstdlib>  

using namespace std;

int cot = 0;
string five = "1";

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
                attack = 0.7;
                bool white = true;
                five = "22222";

                break;           
            }

            if (k == '2') {
                playerColor = W;
                aiColor = B;
                chooseMode = 0;
                 attack = 1.5;
                 five = "11111" ;

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
            
               
                // AI 下
                    cout << "wait" << endl;
                    aiMove(3,aiColor);
                    cot++;
                    cout << "over" << endl;
               // MessageBeep(MB_OK);
                if (isGameOver == true) {
                    continue;
                }
                
            }
        }
    }

    closegraph();
    return 0;
}
