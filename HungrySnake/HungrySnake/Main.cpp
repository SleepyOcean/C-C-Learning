#include"iostream"
#include<windows.h>
#include<time.h>
#include<conio.h>

#define LENGTH_ROW 20
#define LENGTH_COL 20
using namespace std;

struct coordinate
{
	int x;
	int y;
};

class snake {
public:
	coordinate snakeHead;
	coordinate snakeEnd;
	coordinate rice;
	int speed = 600;
	int count = 1;
	int ate = 0;
	char head = '*';
	char end = '*';
	char direction = 100;
	char layout[LENGTH_ROW][LENGTH_COL] = {};

	void initPos(){
		snakeHead.x = rand() % (LENGTH_COL/2)+(LENGTH_COL/4);
		snakeHead.y = rand() % (LENGTH_ROW / 2) + (LENGTH_ROW / 4);
		snakeEnd.x = snakeHead.x;
		snakeEnd.y = snakeHead.y-1;
		layout[snakeHead.x][snakeHead.y] = '*';					//head
		layout[snakeEnd.x][snakeEnd.y] = '*';				//end
		createRice();
		refresh();
	}

	void move(snake &s) {
			if (s.direction == 119) {
				if (s.snakeHead.y == s.snakeEnd.y) {
					s.snakeHead.x--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x--;

				}
				else if (s.snakeHead.y > s.snakeEnd.y) {
					s.snakeHead.x--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y++;
				}
				else {
					s.snakeHead.x--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y--;
				}
			}				//up
			else if (s.direction == 115) {
				if (s.snakeHead.y == s.snakeEnd.y) {
					s.snakeHead.x++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x++;
				}
				else if (s.snakeHead.y > s.snakeEnd.y) {
					s.snakeHead.x++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y++;
				}
				else
				{
					s.snakeHead.x++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y--;
				}
			}				//down
			else if (s.direction == 100) {
				if (s.snakeHead.x == s.snakeEnd.x) {
					s.snakeHead.y++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y++;
				}
				else if (s.snakeHead.x > s.snakeEnd.x) {
					s.snakeHead.y++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x++;
				}
				else
				{
					s.snakeHead.y++;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x--;
				}
			}				//right
			else if(s.direction == 97) {
				if (s.snakeHead.x == s.snakeEnd.x) {
					s.snakeHead.y--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.y--;

				}
				else if (s.snakeHead.x > s.snakeEnd.x) {
					s.snakeHead.y--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x++;
				}
				else
				{
					s.snakeHead.y--;
					s.layout[s.snakeHead.x][s.snakeHead.y] = '*';
					s.layout[s.snakeEnd.x][s.snakeEnd.y] = ' ';
					s.snakeEnd.x--;
				}
			}				//left
		}

	void createRice() {
		rice.x = rand() % (LENGTH_COL / 2) + (LENGTH_COL / 4);
		rice.y = rand() % (LENGTH_ROW / 2) + (LENGTH_ROW / 4);
		layout[rice.x][rice.y] = '.';
	}

	void refresh() {
		system("cls");
		cout << "Your soccer:" << count << endl;
		int row = LENGTH_ROW - 1;
		int column = LENGTH_COL - 1;
		int i;
		for (i = 0; i < LENGTH_ROW; i++) {
			if (column >= i)
			{
				layout[0][i] = '-';
				layout[row][i] = '-';
			}
			if (row >= i)
			{
				layout[i][0] = '|';
				layout[i][column] = '|';
			}
		}
		layout[0][0] = '.';
		layout[0][LENGTH_COL-1] = '.';
		layout[LENGTH_ROW-1][0] = '.';
		layout[LENGTH_ROW-1][LENGTH_COL-1] = '.';
		for (int i = 0; i < LENGTH_ROW; i++)
		{
			for (int j = 0; j < LENGTH_COL; j++)
			{
				cout << layout[i][j]<<"  ";
			}
			cout << endl;
		}
	}
	
};

int main() {
	snake s;
	char input;
	s.initPos();
	int timeSum = 600000;
	for (; timeSum > 0; timeSum--) {
		if (s.layout[s.rice.x][s.rice.y]=='*') { 
			s.createRice(); s.count++;
			if(s.speed>10)
				s.speed-=(s.count*100);
		}
		if (s.snakeHead.x == 0 
			|| s.snakeHead.x == LENGTH_ROW - 1
			|| s.snakeHead.y == 0 
			|| s.snakeHead.y == LENGTH_COL
			|| (s.snakeHead.x == s.snakeEnd.x
				&&s.snakeHead.y == s.snakeEnd.y)) {					//Judge GameOver
			cout << "Game Over" << endl; break;
		}
		long t = clock();
		while ((clock() - t) <= s.speed);
		if (_kbhit()) {
			input = _getch();
			if (s.direction == 119 || s.direction == 115) {
				if (input != 119 && input != 115) {
					s.direction = input;
				}
			}
			else if (s.direction == 97 || s.direction == 100) {
				if (input != 97 &&input != 100) {
					s.direction = input;
				}
			}
			s.move(s);
		}
		else {
			s.move(s);
		}
		s.refresh();
	}

	
	
	system("pause");
	return 0;
}
