#include"ai.h"
int attack = 0;
vector<pair<string,double>> score = {
	{"11111",2000000000},

	{"011110",50000},

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
<<<<<<< Updated upstream
<<<<<<< Updated upstream


void aiMove(int depth, int realboard[15][15], int aiColor)
{	
=======
int position[15][15] = {0};
int killi=0,killj=0;
struct Point {
	int y, x;
	int priority; 
	bool operator<(const Point& other) const {
		return this->priority > other.priority;
	};
};
// 排序规则：分数高的排在 vector 前面

void aiMove(int depth, int Color)
{
	
>>>>>>> Stashed changes
=======
int position[15][15] = {0};
int killi=0,killj=0;
struct Point {
	int y, x;
	int priority; 
	bool operator<(const Point& other) const {
		return this->priority > other.priority;
	};
};
// 排序规则：分数高的排在 vector 前面

void aiMove(int depth, int Color)
{
	
>>>>>>> Stashed changes
	if(cot<5)
	{
		bool con=start();
		if (!con)
		{
			return;
		}
	}
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
	/*f (cot > 5)
	{
		bool a=evaluatekill(3);
		if (a)
		{

			Board[killi][killj] = aiColor;
			drawPiece(killi, killj, aiColor);
			if (checkWin(killi, killj, aiColor))
			{
				isGameOver = true;
			};
			show();
			return;
		};		
	}*/
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
	int flexible = 0;
	int newflexible = 0;
	int r = 0;
	int l = 0;
	double alpha = -DBL_MAX;
	double beta = DBL_MAX;
	double val = -DBL_MAX;
	int oldval = val;
	vector<Point> list = getSortMoves();
	int max = min(12, sizeof(list));
	for(int i=0;i<max;i++)
	{		
			
		Board[list[i].y][list[i].x] = Color;
		double a = minmax(depth,playerColor, list[i].y, list[i].x, alpha, beta);
		//cout << a << "a" << val << "val" << endl;
		if (a > val)
		{
<<<<<<< Updated upstream
<<<<<<< Updated upstream
			if (realboard[i][j] != 0)
			{
				continue;
			}
			realboard[i][j] = aiColor;
			cout << i << " " << j<<" ";
			double a = minmax(depth, realboard, playerColor, i, j, alpha, beta);
			cout << a << "a" << val << "val" << endl;
			if (a > val)
			{
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
				
			flexible=countnear(list[i].y, list[i].x);
			r = list[i].y, l = list[i].x;
			val=a;
		}
		else if (a == val)
		{				
			newflexible=countnear(list[i].y, list[i].x);
			if (newflexible > flexible)
			{
				r = list[i].y, l = list[i].x;
			}
		}
		Board[list[i].y][list[i].x] = 0;
		}	
	Board[r][l] = aiColor;
	show();
	drawPiece(r, l, aiColor);
	if (checkWin(r, l, aiColor))
	{
		isGameOver = true;
	};
	
}

double minmax(int depth, int Color, int r, int l, double alpha, double beta)
{
	bool isAI;
	double val;
	if (depth == 0)
	{
		val = evaluateall();

		return val;
	};

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
	
	vector<Point> list = getSortMoves();
	int max = min(12, sizeof(list));
	for (int i = 0; i < max; i++)
	{

		Board[list[i].y][list[i].x] = Color;
		if (isAI)
		{
			
			val = max(val, minmax(depth-1, 3 - Color, list[i].y, list[i].x, alpha, beta));
			alpha = max(val, alpha);
		}
		else
		{
			
			val = min(val, minmax(depth-1, 3 - Color, list[i].y, list[i].x, alpha, beta));
			beta = min(val, beta);

		}
		Board[list[i].y][list[i].x]= 0;

		if (alpha >= beta)
		{
			break;
		}
	}
	cout << val << "minmax" << endl;
	return val;
};
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
		if(Color==aiColor)
		val +=100000 ;
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
	/*if (Color == playerColor)
	{
		if (huosi == 1)
		{
			val+=200000000;
		}
		else if (chongsi == 1 || huosi == 1)
		{
			val += 50000;
		}
		
	}*/
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
		if (Color == W)
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
		//竖列
	case 0:
		y -= offset;
		break;
		//横向
	case 1:
		x -= offset;
		break;
		//右斜
	case 2:
		y -= offset;
		x -= offset;
		break;
		//左斜
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

<<<<<<< Updated upstream
//vector<pair<int, int>> moverange(int board[15][15])
//{
//	vector<pair<int, int>> range;
//	bool visited[15][15] = { false };  // 用于去重
//	for (int i = 0; i < 15; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			if (board[i][j] == 0)
//			{
//				continue;
//			}
//			// 搜索周围两格范围内的所有位置
//			for (int di = -2; di <= 2; di++)
//			{
//				for (int dj = -2; dj <= 2; dj++)
//				{
//					int ni = i + di;
//					int nj = j + dj;
//					if (ni >= 0 && ni < 15 && nj >= 0 && nj < 15 && board[ni][nj] == 0 && !visited[ni][nj])
//					{
//						range.emplace_back(ni, nj);
//						visited[ni][nj] = true;
//					}
//				}
//			}
//		}
//	}
//	return range;
//}
=======
void moverange()
{	
	memset(position, 0, sizeof(position));
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
>>>>>>> Stashed changes
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
				totle += 2;
			}
			else if (Board[nr][nc] == aiColor)
			{
				totle += 1;
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
bool evaluatekill(int depth)
{

	if (depth == 0)
	{
		return false;
	}
	vector<Point> list = getSortMoves();
	int max = min(12, sizeof(list));
	for (int i = 0; i < max; i++)
	{

		Board[list[i].y][list[i].x] = playerColor;
		MODEL modle;
		for (int direction = 0; direction < 4; direction++)
		{
			string chess = getchess(Board, direction, list[i].y, list[i].x, playerColor);
			if (chess.find(five) != string::npos)
			{

				Board[list[i].y][list[i].x] = 0;
				if (depth == 3)
				{
					killi = list[i].y;
					killj = list[i].x;
					return true;
				}
				return false;
			}
			Board[list[i].y][list[i].x] = aiColor;
			chess = getchess(Board, direction, list[i].y,list[i].x, aiColor);
			if (chess.find(five) != string::npos)
			{

				Board[list[i].y][list[i].x] = 0;
				if (depth == 3)
				{
					killi = list[i].y;
					killj = list[i].x;
				}
				return true;
			}

			for (auto key : modle.chongsi)
			{
				if (chess.find(key) != string::npos)
				{

					bool a = defend(list[i].y, list[i].x, direction, depth - 1);
					if (a)
					{
						Board[list[i].y][list[i].x] = 0;
						if (depth == 3)
						{
							killi = list[i].y;
							killj = list[i].x;
						}
						return true;
					}

				}
			}
			Board[list[i].y][list[i].x] = 0;
		}
	}
	return false;
};

bool defend(int y, int x, int direction, int depth)
{
	int changey;
	int changex;
	int down;
	int left;
	int right;
	
	//竖横右左
	switch (direction)
	{
	case 0:
		changey = max(0, y - 4);
		down = min(14, y + 4);
		changex = x;
		for (; changey <= down; changey++)
		{
			if (position[changey][changex] == 1)
			{
				Board[changey][changex] = aiColor;
				position[changey][changex] = 0;
				string chess = getchess(Board, direction, changey, changex, playerColor);
				
				if (chess.find(five) != string::npos)
				{
					Board[changey][changex] = playerColor;
					position[changey][changex] = 0;
					moverange();
					bool a = evaluatekill(depth);
					Board[changey][changex] = 0;
					position[changey][changex] = 1;
					if (a)
					{
						return true;
					}
					return false;
				}
				Board[changey][changex] = 0;
				position[changey][changex] = 1;
			}
		}
		break;
	case 1:
		changex = max(0, x - 4);
		right = min(14, x + 4);
		changey = y;
		for (; changex <= right; changex++)
		{
			if (position[changey][changex] == 1)
			{
				Board[changey][changex] = aiColor;
				position[changey][changex] = 0;
				string chess = getchess(Board, direction, changey, changex, playerColor);
				if (chess.find(five) != string::npos)
				{
					Board[changey][changex] = playerColor;
					position[changey][changex] = 0;
					moverange();
					bool a = evaluatekill( depth);

					Board[changey][changex] = 0;
					position[changey][changex] = 1;
					if (a)
					{
						return true;
					}
					return false;
				}
				Board[changey][changex] = 0;
				position[changey][changex] = 1;
			}
		}
		break;
	case 2:
		changey = max(0, y - 4);
		down = min(14, y + 4);
		changex = max(0, x - 4);
		right = min(14, x + 4);
		for (; changey <= down && right >= changex; changey++, changex++)
		{
			if (position[changey][changex] == 1)
			{
				Board[changey][changex] = aiColor;
				position[changey][changex] = 0;
				string chess = getchess(Board, direction, changey, changex, playerColor);
				if (chess.find(five) != string::npos)
				{
					Board[changey][changex] = playerColor;
					position[changey][changex] = 0;
					moverange();
					bool a = evaluatekill(depth);

					Board[changey][changex] = 0;
					position[changey][changex] = 1;
					if (a)
					{
						return true;
					}
					return false;
				}
				Board[changey][changex] = 0;
				position[changey][changex] = 1;
			}		
		}
		break;
	case 3:
		changey = max(0, y - 4);
		down = min(14, y + 4);
		changex = max(0, x - 4);
		right = min(14, x + 4);
		for (; changey <= down && changex <= right; changey++, changex++)
		{
			if (position[changey][changex] == 1)
			{
				Board[changey][changex] = aiColor;
				position[changey][changex] = 0;
				string chess = getchess(Board, direction, changey, changex, playerColor);
				if (chess.find(five) != string::npos)
				{
					Board[changey][changex] = playerColor;
					position[changey][changex] = 0;
					moverange();
					bool a = evaluatekill( depth);
					Board[changey][changex] = 0;
					position[changey][changex] = 1;
					if (a)
					{
						return true;
					}
					return false;
				}
				Board[changey][changex] = 0;
				position[changey][changex] = 1;
			}
		}
		break;
	}	
	return false;
};
int quickEvaluate(int y, int x, int color) {
	int score = 0;
	const int dy[] = { 1, 0, 1, 1 };
	const int dx[] = { 0, 1, 1, -1 };

	for (int direction = 0; direction < 4; direction++) {
		int count = 1; // 假设落子后的长度

		// 正向数
		for (int step = 1; step <= 4; step++) {
			int cy = y + dy[direction] * step;
			int cx = x + dx[direction] * step;
			if (cy >= 0 && cy < 15 && cx >= 0 && cx < 15 && Board[cy][cx] == color) count++;
			else break;
		}
		// 反向数
		for (int step = 1; step <= 4; step++) {
			int cy = y - dy[direction] * step;
			int cx = x - dx[direction] * step;
			if (cy >= 0 && cy < 15 && cx >= 0 && cx < 15 && Board[cy][cx] == color) count++;
			else break;
		}

		// 根据连子数给优先级分数（这只是为了排序，不是最终得分）
		if (count >= 5) score += 10000;
		else if (count == 4) score += 1000;
		else if (count == 3) score += 100;
		else if (count == 2) score += 10;
	}
	return score;
};
vector<Point> getSortMoves() {
	vector<Point> moveList;
	// 1. 依然使用之前的 15x15 遍历
	for (int y = 0; y < 15; y++) 
	{
		for (int x = 0; x < 15; x++) 
		{
			if (Board[y][x] == 0)
			{
				continue;
			}
			// 搜索周围两格范围内的所有位置
			for (int di = -2; di <= 2; di++)
			{
				for (int dj = -2; dj <= 2; dj++)
				{
					int ni = y + di;
					int nj = x + dj;
					if (ni >= 0 && ni < 15 && nj >= 0 && nj < 15 && Board[ni][nj] == 0)
					{
						int p = quickEvaluate(ni, nj, aiColor) + quickEvaluate(ni, nj, playerColor);
						moveList.push_back({ ni, nj , p });
					}
				}
			}
				
		}
	}
	// 3. 排序：这是胜率质变的关键
	sort(moveList.begin(), moveList.end());
	return moveList;
}