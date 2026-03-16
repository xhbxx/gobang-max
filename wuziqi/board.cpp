#include "Board.h"
int Board[BOARD_SIZE][BOARD_SIZE];
bool isGameOver;
int playerColor = 0;
int aiColor = 0;
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Board[i][j] = EMPTY;
        }
    }
    isGameOver = false;
}

void drawBoard() {
    setbkcolor(RGB(240, 240, 240));
    cleardevice();
    setlinecolor(BLACK);
    settextcolor(BLACK);
    settextstyle(12, 0, _T("Arial"));

    // 绘制行号和列号
    for (int i = 0; i < BOARD_SIZE; i++) {
        // 列号（顶部）
        TCHAR colText[10];
        _stprintf_s(colText, _T("%d"), i + 1);
        outtextxy(MARGIN + i * CELL - 5, MARGIN - 20, colText);
        
        // 行号（左侧）
        TCHAR rowText[10];
        _stprintf_s(rowText, _T("%d"), i + 1);
        outtextxy(MARGIN - 20, MARGIN + i * CELL - 5, rowText);
        
        // 绘制棋盘线条
        line(MARGIN, MARGIN + i * CELL, MARGIN + (BOARD_SIZE - 1) * CELL, MARGIN + i * CELL);
        line(MARGIN + i * CELL, MARGIN, MARGIN + i * CELL, MARGIN + (BOARD_SIZE - 1) * CELL);
    }
}

void drawPiece(int row, int col, int color) {
    int x = MARGIN + col * CELL;
    int y = MARGIN + row * CELL;
    if (color == B) {
        setfillcolor(BLACK);
    }
    else {
        setfillcolor(WHITE);
    }
    solidcircle(x, y, CELL / 2 - 2);
}

bool isValidPos(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    return Board[row][col] == EMPTY;
}

bool checkWin(int r, int c, int color) {
    int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
    for (auto& d : dirs) {
        int cnt = 1;
        for (int i = 1; i <= 4; i++) {
            int nr = r + d[0] * i;
            int nc = c + d[1] * i;
            if (nr >= 0 && nr < 15 && nc >= 0 && nc < 15 && Board[nr][nc] == color) cnt++;
            else break;
        }
        for (int i = 1; i <= 4; i++) {
            int nr = r - d[0] * i;
            int nc = c - d[1] * i;
            if (nr >= 0 && nr < 15 && nc >= 0 && nc < 15 && Board[nr][nc] == color) cnt++;
            else break;
        }
        if (cnt >= 5) return true;
    }
    return false;
}

void getMouseRowCol(int& row, int& col) {
    MOUSEMSG m = GetMouseMsg();
    if (m.uMsg == WM_LBUTTONDOWN) {
        col = (m.x - MARGIN + CELL / 2) / CELL;
        row = (m.y - MARGIN + CELL / 2) / CELL;
    }
}
