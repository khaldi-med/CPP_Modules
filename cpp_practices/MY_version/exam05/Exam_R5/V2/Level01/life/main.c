#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void free_board(char **board, int height)
{
	if (!board)
		return;
	for (int i = 0; i < height; i++)
		free(board[i]);
	free(board);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return -1;
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	char **board = malloc((height + 1) * sizeof(char *));
	if (!board)
		return -2;
	for (int i = 0; i < height; i++)
	{
		board[i] = malloc((width + 1) * sizeof(char));
		if (!board[i])
		{
			free_board(board, i);
			return -2;
		}
		for (int j = 0; j < width; j++)
			board[i][j] = ' ';
	}

	int x = 0, y = 0, drawn = 0;
	char c;
	int ret;
	while ((ret = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == 'x')
			drawn = !drawn;
		else if (c == 'w')
			y--;
		else if (c == 's')
			y++;
		else if (c == 'a')
			x--;
		else if (c == 'd')
			x++;

		if (drawn && x >= 0 && x < width && y >= 0 && y < height)
			board[y][x] = '0';
	}
	if (ret < 0)
	{
		free_board(board, height);
		return -3;
	}

	char **tmp = malloc((height + 1) * sizeof(char *));
	if (!tmp)
	{
		free_board(board, height);
		return -2;
	}
	for (int i = 0; i < height; i++)
	{
		tmp[i] = malloc((width + 1) * sizeof(char));
		if (!tmp[i])
		{
			free_board(tmp, i);
			free_board(board, height);
			return -2;
		}
	}

	for (int i = 0; i < iter; i++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int count = 0;
				if (x - 1 >= 0 && board[y][x - 1] == '0')
					count++;
				if (x + 1 < width && board[y][x + 1] == '0')
					count++;
				if (y - 1 >= 0 && board[y - 1][x] == '0')
					count++;
				if (y + 1 < height && board[y + 1][x] == '0')
					count++;
				if (y - 1 >= 0 && x - 1 >= 0 && board[y - 1][x - 1] == '0')
					count++;
				if (y - 1 >= 0 && x + 1 < width && board[y - 1][x + 1] == '0')
					count++;
				if (y + 1 < height && x + 1 < width && board[y + 1][x + 1] == '0')
					count++;
				if (y + 1 < height && x - 1 >= 0 && board[y + 1][x - 1] == '0')
					count++;
				if ((board[y][x] == '0' && (count == 2 || count == 3)) || (board[y][x] == ' ' && count == 3))
					tmp[y][x] = '0';
				else
					tmp[y][x] = ' ';
			}
		}
		char **tmp2 = tmp;
		tmp = board;
		board = tmp2;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			putchar(board[i][j]);
		putchar('\n');
	}

	free_board(board, height);
	free_board(tmp, height);
	return 0;
}