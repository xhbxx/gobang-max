#include"ai.h"

int attack = 0;
vector<pair<string,double>> score = {
	{"11111",20000000},

	{"011110",500000},

    {"11110", 10000}, 
    {"01111", 10000},
    {"10111", 10000},
    {"11011", 10000},
    {"11101", 10000},

	{"001110",1000},
	{"011100",1000},
	{"010110",1000},
	{"011010",1000},
	{"001112",500},
	{"010112",500},
	{"011012",500},
	{"211100",500},
	{"211010",500},
	{"001100",100},
	{"011000",100},
	{"000110",100},
	{"011200",50},
	{"001120",50},
	{"002110",50},
	{"021100",50},
	{"001010",50},
	{"010100",50},
	{"001200",11},
	{"002100",11},
	{"020100",11},
	{"000210",11},
	{"000120",11},
};
struct MODEL {
	vector<string>huosi = { "011110" };
	vector<string>chongsi = {
		"11110", "01111", "10111", "11011", "11101"
	};
	vector<string>huosan = {
		"001110", "011100", "010110", "011010"
	};
	vector<string>miansan = {
		"001112", "010112", "011012", "211100", "211010"
	};
	vector<string>huoer = {
		"001100", "011000", "000110"
	};
};
double positionValues[15][15] = {
	{1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1},
	{1, 1, 2, 2, 3, 3, 4,  4, 4, 3, 3, 2, 2, 1},
	{1, 2, 2, 3, 4, 4, 5,  5, 5, 4, 4, 3, 2, 1},
	{1, 2, 3, 3, 4, 5, 6,  6, 6, 5, 4, 3, 2, 1},
	{1, 2, 4, 5, 6, 7, 7,  8, 7, 6, 5, 4, 2, 1},
	{1, 2, 4, 5, 7, 8, 9,  9, 9, 8, 5, 4, 2, 1},
	{1, 2, 5, 6, 7, 8, 9, 10, 9, 8, 7, 4, 2, 1},
	{1, 2, 5, 6, 7, 8, 9, 10, 9, 8, 7, 4, 2, 1},
	{1, 2, 5, 6, 7, 8, 9, 10, 9, 8, 7, 4, 2, 1},
	{1, 2, 4, 5, 7, 8, 9,  9, 9, 8, 5, 4, 2, 1},
	{1, 2, 3, 3, 4, 5, 6,  6, 6, 5, 4, 3, 2, 1},
	{1, 2, 2, 3, 4, 4, 5,  5, 5, 4, 4, 3, 2, 1},
	{1, 1, 2, 2, 2, 2, 2,  2, 2, 1, 1, 2, 2, 1},
	{1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1}
};
int dirs[8][2] = {
	{-1, 0},   // 上
	{1, 0},    // 下
	{0, -1},   // 左
	{0, 1},    // 右
	{-1, -1},  // 左上
	{-1, 1},   // 右上
	{1, -1},   // 左下
	{1, 1}     // 右下
};
int position[15][15] = {0};

void aiMove(int depth, int realboard[15][15], int aiColor)
{
	if(cot<5)
	{
		bool con=start();
		if (!con)
		{
			return;
		}
	}
	moverange();
	int flexible = 0;
	int newflexible = 0;
	int r = 0;
	int l = 0;
	double alpha = -DBL_MAX;
	double beta = DBL_MAX;
	double val = -DBL_MAX;
	int oldval = val;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (position[i][j] == 0)
			{
				continue;
			}
			position[i][j] -= 1;
			realboard[i][j] = aiColor;
			cout << i << " " << j<<" ";
			double a = minmax(depth, realboard, playerColor, i, j, alpha, beta);
			cout << a << "a" << val << "val" << endl;
			if (a > val)
			{
				
				flexible=countnear(i, j);
				r = i, l = j;
				val=a;
			}
			else if (a == val)
			{				
				newflexible=countnear(i, j);
				if (newflexible > flexible)
				{
					r = i, l = j;
				}
			}
			realboard[i][j] = 0;
		}
	}

	realboard[r][l] = aiColor;
	drawPiece(r, l, aiColor);
	if (checkWin(r, l, aiColor))
	{
		isGameOver = true;
	};
	
}

double minmax(int depth, int board[15][15], int Color, int r, int l, double alpha, double beta)
{
	bool isAI;
	double val;
	if (Color == aiColor)
	{
		isAI = true;
		val = -DBL_MAX;
	}
	else
	{
		isAI = false;
		val = DBL_MAX;
	}
	if (depth == 0)
	{		
		val = evaluateall();
		
		return val;
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (board[i][j] != 0)
			{
				continue;
			}
			board[i][j] = Color;
			if (isAI)
			{
				int newdepth = depth - 1;
				val = max(val, minmax(newdepth, board, 3 - Color, i, j, alpha, beta));
				alpha = max(val, alpha);
			}
			else
			{
				int newdepth = depth - 1;
				val = min(val, minmax(newdepth, board, 3 - Color, i, j, alpha, beta));
				beta = min(val, beta);

			}
			board[i][j] = 0;
			if (alpha >= beta)
			{
				break;
			}
		}
		if (alpha >= beta)
		{
			break;
		}
	};
	cout << val << "minmax" << endl;
	return val;
}
double evaluateall()
{
	double ai = 0;
	double man = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (Board[i][j] == 0)
			{
				continue;
			}
			if (Board[i][j] == aiColor)
			{
				ai+=evaluate(Board, aiColor, i, j);
				ai+= positionValues[i][j];
			}
			else
			{
				man+= evaluate(Board, 3- aiColor, i, j);
				man+= positionValues[i][j];
			}
		}
	}
	return ai*attack - man;
}
double evaluate(int board[15][15], int Color, int r, int l)
{
	double val = 0;
	int huosi = 0;
	int chongsi = 0;
	int huosan = 0;
	int miansan = 0;
	int huoer = 0;
	MODEL model;
	for (int i = 0; i < 4; i++)
	{
		string chess = getchess(board, i, r, l, Color);
		for (auto& key : score)
		{
			const string& a = key.first;
			if (chess.find(a) != string::npos)
			{
				if (checkposition(a, model.huosi))
				{
					if (Color == playerColor)
					{
						val += key.second / 2;
					}
					huosi++;
				}
				else if (checkposition(a, model.chongsi))
				{
					chongsi++;
				}
				else if (checkposition(a, model.huosan))
				{
					huosan++;
				}
				else if (checkposition(a, model.miansan))
				{
					miansan++;
				}
				else if (checkposition(a, model.huoer))
				{
					huoer++;
				}
				val += key.second;
				break;
			}
		}
	}
	if (chongsi >= 2)
	{
		val += 200000;
	}
	else if (chongsi > 0 && huosan > 0)
	{
		val +=180000 ;
	}
	else if ( huosan > 1)
	{
		val +=80000 ;
	}
	else if (miansan >= 1 && huosan >=1 )
	{
		val +=15000 ;
	}
	else if (miansan >1)
	{
		val +=6000 ;
	}
	else if (huoer > 1)
	{
		val +=2000 ;
	}
	return val;
}

string getchess(int board[15][15], int direction, int r, int l, int Color)
{
	int chess[9];
	chess[0] = getpiece(board, direction, r, l, 4);
	chess[1] = getpiece(board, direction, r, l, 3);
	chess[2] = getpiece(board, direction, r, l, 2);
	chess[3] = getpiece(board, direction, r, l, 1);
	chess[4] = board[r][l];
	direction += 4;
	chess[5] = getpiece(board, direction, r, l, 1);
	chess[6] = getpiece(board, direction, r, l, 2);
	chess[7] = getpiece(board, direction, r, l, 3);
	chess[8] = getpiece(board, direction, r, l, 4);
	string result;
	for (int i = 0; i < 9; i++) {
		if (board[r][l] == W)
		{
			if (chess[i] == 1 || chess[i] == 2)
			{
				chess[i] = 3 - chess[i];
			}
		}
		result += (char)('0' + chess[i]);
	}
	return result;
}

int getpiece(int board[15][15], int direction, int y, int x, int offset)
{
	switch (direction)
	{
	case 0:
		y -= offset;
		break;
	case 1:
		x -= offset;
		break;
	case 2:
		y -= offset;
		x -= offset;
		break;
	case 3:
		y -= offset;
		x += offset;
		break;
	case 4:
		y += offset;
		break;
	case 5:
		x += offset;
		break;
	case 6:
		x += offset;
		y += offset;
		break;
	case 7:
		x -= offset;
		y += offset;
		break;
	}

	if (x > 14 || y > 14 || x < 0 || y < 0)
	{
		return 3;
	}

	return board[y][x];
}

bool checkposition(string position, vector<string> model)
{
	for (auto key : model)
	{
		if (position == key)
		{
			return true;
		}
	}
	return false;
}

void moverange()
{	

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (Board[i][j] == 0)
			{
				continue;
			}
			// 搜索周围两格范围内的所有位置
			for (int di = -2; di <= 2; di++)
			{
				for (int dj = -2; dj <= 2; dj++)
				{
					int ni = i + di;
					int nj = j + dj;
					if (ni >= 0 && ni < 15 && nj >= 0 && nj < 15 && Board[ni][nj] == 0 )
					{
						position[ni][nj] = 1;
					}
				}
			}
		}
	}
}
void show()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int countnear( int r, int l)
{
	int totle = 0;
	for (int i = 0; i < 8; i++) {
		int nr = r + dirs[i][0];
		int nc = l + dirs[i][1];

		
		if (nr < 0 || nr >= 15 || nc < 0 || nc >= 15) {
			continue;
		}
		else {
			if (Board[nr][nc] == 0)
			{
				totle += 1;
			}
			else if (Board[nr][nc] == aiColor)
			{
				totle += 2;
			}
			else if (Board[nr][nc] == playerColor)
			{
				totle -= 1;
			}
		}
	}
	return totle;
}
bool start()
{
	if (aiColor == 1 && cot == 3)
	{
		if (Board[8][8] == 2)
		{
			Board[8][7] = 1;
			drawPiece(8, 7, aiColor);
			return false;
		}
		else if (Board[8][7] == 2)
		{
			Board[8][8] = 1;
			drawPiece(8, 8, aiColor);
			return false;
		}
		else if (Board[6][6] == 2)
		{
			Board[6][7] = 1;
			drawPiece(6, 7, aiColor);
			return false;
		}
		else if (Board[6][7] == 2)
		{
			Board[7][8] = 1;
			drawPiece(7, 8, aiColor);
			return false;
		}
		else if (Board[7][8] == 2)
		{
			Board[8][8] = 1;
			drawPiece(8, 8, aiColor);
			return false;
		}
		else if (Board[7][6] == 2)
		{
			Board[6][6] = 1;
			drawPiece(6, 6, aiColor);
			return false;
		}
		
	}
	else
	{
		if (Board[8][8] == 1)
		{
			if (cot == 2) {
				Board[8][8] = 2;
				drawPiece(8, 8, aiColor);
				return false;
			}
			if (cot == 4 && Board[8][7] == 1)
			{
				Board[9][6] = 2;
				drawPiece(9, 6, aiColor);
				return false;
			}
		}
	}
	return true;
}