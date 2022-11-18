#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 15
#define MAX_COL 15
char chessboard[MAX_ROW][MAX_COL];
int y, x;//玩家输入的坐标
int y1, x1;//电脑输入的坐标
int m, n;//检测连续棋子后坐标移动到的位置
void Menu() {
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("请输入您的选择\n");
}
void Init() {//初始化棋盘
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chessboard[row][col] = ' ';
		}
	}
}
void Print() {//打印棋盘
	printf("  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 \n");
	printf(" ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ ＿ \n");
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			printf("| %c", chessboard[row][col]);
		}
		printf("|\n|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|＿|");
		printf("%d\n", row);
	}
}
void PlayerMove() {//玩家落子
	printf("请输入您落子位置的坐标值\n");
	while (1) {
		scanf("%d %d", &y, &x);
		if (y > MAX_ROW - 1 || y < 0 || x > MAX_COL - 1 || x < 0) {
			printf("输入非法,请重新输入！\n");
			continue;
		}
		if (chessboard[y][x] != ' ') {
			printf("此位置已有棋子\n");
			continue;
		}
		break;
	}
	chessboard[y][x] = 'x';
}
int judge(int y, int x) {//判断此位置是否处于有机会连成五子的位置
	int min = -1;
	int max = 0;
	for (int i = y - 4; i <= y + 4; ++i) {//竖向判断
		if (i > 14) {
			break;
		}
		if (min == -1 && i >= 0) {
			min = i;
		}
			max = i;
	}
	if (max - min >= 5) {
		return 1;
	}
	for (int i = x - 4; i <= x + 4; ++i) {//横向判断
		if (i > 14) {
			break;
		}
		if (min == -1 && i >= 0) {
			min = i;
		}
		max = i;
	}
	if (max - min >= 5) {
		return 1;
	}
	return 0;
}
int CheckGameOver(int N, int y, int x, char ch) {//判断是否有连续的N个棋子，并返回其是竖向连接还是横向还是对角线
	int count = 0;
	for (int i = y - 4; i <= y + 4; ++i) {//竖向判断
		if (i < 0) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[i][x] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = x;
			return 1;
		}
	}
	count = 0;
	for (int i = x - 4; i <= x + 4; ++i) {//横向判断
		if (i < 0) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[y][i] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = y;
			n = i;
			return 2;
		}
	}
	count = 0;
	for (int i = y - 4, j = x - 4; i <= y + 4 && j <= x + 4; ++i, ++j) {//对角线判断(左上角到右下角)
		if (i < 0 || j < 0) {
			continue;
		}
		if (i > 14 || j > 14) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = j;
			return 3;
		}
	}
	count = 0;
	for (int i = y - 4, j = x + 4; i <= y + 4 && j >= x - 4; ++i, --j) {//对角线判断(右上角到左下角)
		if (i < 0 || j > 14) {
			continue;
		}
		if (i > 14 || j < 0) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			m = i;
			n = j;
			return 4;
		}
	}
	return 0;
}
int CheckGameOver1(int N, int y, int x, char ch) {//判断此位置周围有几个二子已经连接
	int count = 0;
	int ret = 0;
	for (int i = y - 2; i <= y + 2; ++i) {//竖向判断
		if (i < 0 || i == y) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[i][x] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = x - 2; i <= x + 2; ++i) {//横向判断
		if (i < 0 || i == x) {
			continue;
		}
		if (i > 14) {
			break;
		}
		if (chessboard[y][i] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = y - 2, j = x - 2; i <= y + 2 && j <= x + 2; ++i, ++j) {//对角线判断(左上角到右下角)
		if (i < 0 || j < 0 || (i == y && j == x)) {
			continue;
		}
		if (i > 14 || j > 14) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	count = 0;
	for (int i = y - 2, j = x + 2; i <= y + 2 && j >= x - 2; ++i, --j) {//对角线判断(右上角到左下角)
		if (i < 0 || j > 14 || (i == y && j == x)) {
			continue;
		}
		if (i > 14 || j < 0) {
			break;
		}
		if (chessboard[i][j] != ch) {
			count = 0;
			continue;
		}
		++count;
		if (count == N) {
			ret += 1;
			break;
		}
	}
	return ret;
}
int AI_1(int N, int a) {//在已经连成的N个棋子的前后落子
	if (a == 1) {
		if (m - 5 >= 0 && chessboard[m - N][n] == ' ') {
			chessboard[m - N][n] = 'o';
			y1 = m - N;
			x1 = n;
			return 1;
		}
		if (m + 5 - N < MAX_ROW && chessboard[m + 1][n] == ' ') {
			chessboard[m + 1][n] = 'o';
			y1 = m + 1;
			x1 = n;
			return 1;
		}
	}
	else if (a == 2) {
		if (n - 5 >= 0 && chessboard[m][n - N] == ' ') {
			chessboard[m][n - N] = 'o';
			y1 = m;
			x1 = n - N;
			return 1;
		}
		if (n + 5 - N < MAX_COL && chessboard[m][n + 1] == ' ') {
			chessboard[m][n + 1] = 'o';
			y1 = m;
			x1 = n + 1;
			return 1;
		}
	}
	else if (a == 3) {
		if (n - 5 >= 0 && m - 5 > 0 && chessboard[m - N][n - N] == ' ') {
			chessboard[m - N][n - N] = 'o';
			y1 = m - N;
			x1 = n - N;
			return 1;
		}
		if (n + 5 - N < MAX_COL && m + 5 - N < MAX_ROW && chessboard[m + 1][n + 1] == ' ') {
			chessboard[m + 1][n + 1] = 'o';
			y1 = m + 1;
			x1 = n + 1;
			return 1;
		}
	}
	else if (a == 4) {
		if (n - 5 >= 0 && m + 5 - N < MAX_ROW && chessboard[m + 1][n - 1] == ' ') {
			chessboard[m + 1][n - 1] = 'o';
			y1 = m + 1;
			x1 = n - 1;
			return 1;
		}
		if (m - 5 >= 0 && n + 5 - N < MAX_COL && chessboard[m - N][n + N] == ' ') {
			chessboard[m - N][n + N] = 'o';
			y1 = m - N;
			x1 = n + N;
			return 1;
		}
	}
	return 0;
}

int AI_2(int a, int b, char ch) {//判断 oo o 或  o oo类型的落子(判断 ooo o 或  o ooo类型的落子)
	if (a == 1) {
		if (m + b < MAX_ROW && chessboard[m + 1][n] == ' ' && chessboard[m + b][n] == ch) {
			chessboard[m + 1][n] = 'o';
			y1 = m + 1;
			x1 = n;
			return 1;
		}
		else if (m - b - 1 >= 0 && chessboard[m - b][n] == ' ' && chessboard[m - b - 1][n] == ch) {
			chessboard[m - b][n] = 'o';
			y1 = m - b;
			x1 = n;
			return 1;
		}
	}
	else if (a == 2) {
		if (n + b < MAX_COL && chessboard[m][n + 1] == ' ' && chessboard[m][n + b] == ch) {
			chessboard[m][n + 1] = 'o';
			y1 = m;
			x1 = n + 1;
			return 1;
		}
		if (n - b - 1 >= 0 && chessboard[m][n - b] == ' ' && chessboard[m][n - b - 1] == ch) {
			chessboard[m][n - b] = 'o';
			y1 = m;
			x1 = n - b;
			return 1;
		}
	}
	else if (a == 3) {
		if (n + b < MAX_COL && m + b < MAX_ROW && chessboard[m + 1][n + 1] == ' ' && chessboard[m + b][n + b] == ch) {
			chessboard[m + 1][n + 1] = 'o';
			y1 = m + 1;
			x1 = n + 1;
			return 1;
		}
		if (n - b - 1 >= 0 && m - b - 1 >= 0 && chessboard[m - b][n - b] == ' ' && chessboard[m - b - 1][n - b - 1] == ch) {
			chessboard[m - b][n - b] = 'o';
			y1 = m - b;
			x1 = n - b;
			return 1;
		}
	}
	else if (a == 4) {
		if (m + b < MAX_ROW && n - b >= 0 && chessboard[m + 1][n - 1] == ' ' && chessboard[m + b][n - b] == ch) {
			chessboard[m + 1][n - 1] = 'o';
			y1 = m + 1;
			x1 = n - 1;
			return 1;
		}
		if (n + b - 1 < MAX_COL && m - b - 1 >= 0 && chessboard[m - b][n + b] == ' ' && chessboard[m - b - 1][n + b - 1] == ch) {
			chessboard[m - b][n + b] = 'o';
			y1 = m - b;
			x1 = n + b;
			return 1;
		}
	}
	return 0;
}

int AI_3(int a, int b) {//判断  ooo  类型落子或  oo 型落子
	if (a == 1) {
		if (m + 1 < 15 && m - b >= 0 && chessboard[m + 1][n] == ' ' && chessboard[m - b][n] == ' ') {
			if (m + 5 - b < 15) {
				chessboard[m + 1][n] = 'o';
				y1 = m + 1;
				x1 = n;
				return 1;
			}
			else if (m - b >= 0) {
				chessboard[m - b][n] = 'o';
				y1 = m - b;
				x1 = n;
				return 1;
			}
		}

	}
	else if (a == 2) {
		if (n + 1 < 15 && n - b >= 0 && chessboard[m][n + 1] == ' ' && chessboard[m][n - b] == ' ') {
			if (n + 5 - b < 15) {
				chessboard[m][n + 1] = 'o';
				y1 = m;
				x1 = n + 1;
				return 1;
			}
			else if (n - b >= 0) {
				chessboard[m][n - b] = 'o';
				y1 = m;
				x1 = n - b;
				return 1;
			}
		}
	}
	else if (a == 3) {
		if (n + 1 < 15 && m + 1 < 15 && n - b >= 0 && m - b > 0 && chessboard[m + 1][n + 1] == ' ' && chessboard[m - b][n - b] == ' ') {
			if (n + 5 - b < MAX_COL && m + 5 - b < 15) {
				chessboard[m + 1][n + 1] = 'o';
				y1 = m + 1;
				x1 = n + 1;
				return 1;
			}
			else if (n - b >= 0 && m - b >= 0) {
				chessboard[m - b][n - b] = 'o';
				y1 = m - b;
				x1 = n - b;
				return 1;
			}
			else if (judge(m, n) == 1) {
				if (m + 1 <MAX_ROW && n + 1 < MAX_COL) {
					chessboard[m + 1][n] = 'o';
					y1 = m + 1;
					x1 = n + 1;
					return 1;
				}
				else if (m - b >= 0 && n - b >=0) {
					chessboard[m - b][n] = 'o';
					y1 = m - b;
					x1 = n - b;
					return 1;
				}
			}
		}
	}
	else if (a == 4) {
		if (n + b < 15 && m - b >= 0 && chessboard[m + 1][n - 1] == ' ' && chessboard[m - b][n + b] == ' ') {
			if (m + 5 - b < MAX_ROW && n - 1 >= 0) {
				chessboard[m + 1][n - 1] = 'o';
				y1 = m + 1;
				x1 = n - 1;
				return 1;
			}
			else if (n + 5 - b < MAX_COL && m - b >= 0) {
				chessboard[m - b][n + b] = 'o';
				y1 = m - b;
				x1 = n + b;
				return 1;
			}
			else if (judge(m, n) == 1) {
				if (m + 1  < MAX_ROW && n - 1 >= 0) {
					chessboard[m + 1][n - 1] = 'o';
					y1 = m + 1;
					x1 = n - 1;
					return 1;
				}
				else if (m - b >= 0 && n + b < MAX_COL) {
					chessboard[m - b][n + b] = 'o';
					y1 = m - b;
					x1 = n + b;
					return 1;
				}
			}
		}
	}
	return 0;
}
int AI_5(int i, int j, char ch) {//判断 x/o  x/o 落子到中间
	if (i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j] == ' ' && chessboard[i + 2][j] == ch) {
		chessboard[i + 1][j] = 'o';
		y1 = i + 1;
		x1 = j;
		return 1;
	}
	if (j + 2 < MAX_COL && chessboard[i][j] == ch && chessboard[i][j + 1] == ' ' && chessboard[i][j + 2] == ch) {
		chessboard[i][j + 1] = 'o';
		y1 = i;
		x1 = j + 1;
		return 1;
	}
	if (j + 2 < MAX_COL && i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j + 1] == ' ' && chessboard[i + 2][j + 2] == ch) {
		chessboard[i + 1][j + 1] = 'o';
		y1 = i + 1;
		x1 = j + 1;
		return 1;
	}
	if (j - 2 >= 0 && i + 2 < MAX_ROW && chessboard[i][j] == ch && chessboard[i + 1][j - 1] == ' ' && chessboard[i + 2][j - 2] == ch) {
		chessboard[i + 1][j - 1] = 'o';
		y1 = i + 1;
		x1 = j - 1;
		return 1;
	}
	return 0;
}
int AI_6(char ch) {//防止玩家连成两个三子对角
	for (int i = 2; i < MAX_ROW; ++i) {
		for (int j = 2; j < MAX_COL; ++j) {
			if (chessboard[i][j] == ' ' && CheckGameOver1(2, i, j, ch) > 1) {
				chessboard[i][j] = 'o';
				return 1;
			}
		}
	}
	return 0;
}
int AI_4() {//便利棋盘找出适合落子的位置落子
	srand((unsigned int)time(0));
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(4, CheckGameOver(4, i, j, 'o')) == 1) {//如果有4个连在一起的o则连接第5个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_3(CheckGameOver(3, i, j, 'o'), 3) == 1) {//出现  ooo  连接第四个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_2(CheckGameOver(2, i, j, 'o'), 2, 'o') == 1) {//出现oo o时在空处落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_2(CheckGameOver(2, i, j, 'x'), 2, 'x') == 1) {//出现xx x时在空处落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_3(CheckGameOver(3, i, j, 'x'), 3) == 1) {//出现  xxx  连接第四个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(3, CheckGameOver(3, i, j, 'o')) == 1) {//如果有3个连在一起的o则连接第4个o
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'x' && AI_1(3, CheckGameOver(3, i, j, 'x')) == 1) {//如果有3个连在一起的x则连接第4个o
				return 1;
			}
		}
	}
	if (AI_6('o') == 1) {//防止玩家连成两个三子对角
		return 1;
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'x') == 1) {//若出现x x则落子o在中间
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_3(CheckGameOver(2, i, j, 'o'), 2) == 1) {//如果有 oo 则落子
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (AI_5(i, j, 'o') == 1) {//若出现o o则落子o在中间
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (chessboard[i][j] == 'o' && AI_1(2, CheckGameOver(2, i, j, 'o')) == 1) {// 如果有2个连在一起的o则连接第3个o
				return 1;
			}
		}
	}
	int row = MAX_ROW / 2;
	int col = MAX_COL / 2;
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j < 2 * i - 1; ++j) {
			if (chessboard[row][col++] == 'o') {// 如果有1个o则连接第2个o
				m = row;
				n = col - 1;
				if (AI_1(1, 4) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row++][col] == 'o') {// 如果有1个o则连接第2个o
				m = row - 1;
				n = col;
				if (AI_1(1, 4) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i; ++j) {
			if (chessboard[row][col--] == 'o') {// 如果有1个o则连接第2个o
				m = row;
				n = col + 1;
				if (AI_1(1, rand() % 4 + 1) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			if (chessboard[row--][col] == 'o') {// 如果有1个o则连接第2个o
				m = row + 1;
				n = col;
				if (AI_1(1, rand() % 4 + 1) == 1) {//随机竖向或者横向或者对角线落子
					return 1;
				}
			}
		}
	}
	return 0;
}
void ComputerMove() {
	srand((unsigned int)time(0));
	if (AI_1(4, CheckGameOver(4, y1, x1, 'o')) == 1) {//如果有4个连在一起的o则连接第5个o
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 3, 'x') == 1) {//3子连结堵截(出现xxx x或x xxx时在空处落子)
		return;
	}
	if (AI_1(4, CheckGameOver(4, y, x, 'x')) == 1) {//四子连结堵截
		return;
	}
	if (AI_2(CheckGameOver(2, y, x, 'x'), 2, 'x') == 1) {//二子连结堵截(出现xx x时在空处落子)
		return;
	}
	if (AI_6('x') == 1) {//。。。
		return;
	}
	if (AI_3(CheckGameOver(3, y1, x1, 'o'), 3) == 1) {//出现  ooo  连接第四个o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y1, x1, 'o')) == 1) {//如果有3个连在一起的o则连接第4个o
		return;
	}
	if (AI_1(3, CheckGameOver(3, y, x, 'x')) == 1) {//三子连结堵截
		return;
	}
	if (AI_2(CheckGameOver(2, y1, x1, 'o'), 2, 'o') == 1) {//出现oo o时在空处落子
		return;
	}
	if (AI_4() == 1) {
		return;
	}
	y1 = rand() % 5 + 5;
	x1 = rand() % 5 + 5;
	if (chessboard[y1][x1] == ' ') {
		chessboard[y1][x1] = 'o';
		return;
	}
}

void Game() {
	int num = 0;
	int choic;
	printf("1.玩家先落子\n2.电脑先落子\n请输入您的选择\n");
	scanf("%d", &choic);
	while (choic != 2 && choic != 1) {
		printf("您的输入非法，请重新输入！\n");
		scanf("%d", &choic);
	}
	system("cls");
	Init();//初始化棋盘
	if (choic == 1) {
		while (1) {
			++num;
			Print();//打印棋盘
			PlayerMove();//玩家落子,玩家落子用x表示
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//检测游戏是否结束
				Print();
				printf("\n你赢了！\n");
				break;
			}
			ComputerMove();//电脑落子
			Print();
			system("cls");
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//检测游戏是否结束
				Print();
				printf("\n电脑赢了！\n");
				break;
			}
			if (num == 225) {
				printf("和棋\n");
				break;
			}
		}
	}
	else {
		while (1) {
			++num;
			ComputerMove();//电脑落子
			Print();//打印棋盘
			if (CheckGameOver(5, y1, x1, 'o') != 0) {//检测游戏是否结束
				Print();
				printf("\n电脑赢了！\n");
				break;
			}
			PlayerMove();//玩家落子
			Print();
			system("cls");
			if (CheckGameOver(5, y, x, 'x') != 0) {//检测游戏是否结束
				Print();
				printf("\n你赢了！\n");
				break;
			}
			if (num == 225) {
				printf("和棋\n");
				break;
			}
		}
	}
}
int main() {
	int choic;
	Menu();
	scanf("%d", &choic);
	while (choic != 0 && choic != 1) {
		printf("您的输入非法，请重新输入！\n");
		scanf("%d", &choic);
	}
	if (choic == 1) {
		system("cls");
		Game();
	}
	else {
		printf("再见！\n");
	}
	system("pause");
	return 0;
}