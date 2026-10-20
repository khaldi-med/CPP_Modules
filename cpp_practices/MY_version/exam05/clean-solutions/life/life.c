#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void clear(char *board) { free(board); }

int main(int argc, char **argv)
{
	if (argc != 4) return 1;
	int width = atoi(argv[1]), height = atoi(argv[2]), generations = atoi(argv[3]);
	if (width <= 0 || height <= 0 || generations < 0) return 1;
	int size = width * height;
	char *board = malloc((size_t)size), *next = malloc((size_t)size);
	if (!board || !next) { clear(board); clear(next); return 1; }
	for (int i = 0; i < size; ++i) board[i] = ' ';
	int x = 0, y = 0, drawing = 0;
	char command;
	while (read(STDIN_FILENO, &command, 1) > 0) {
		if (command == 'x') drawing = !drawing;
		else if (command == 'w' && y > 0) --y;
		else if (command == 'a' && x > 0) --x;
		else if (command == 's' && y + 1 < height) ++y;
		else if (command == 'd' && x + 1 < width) ++x;
		if (drawing) board[y * width + x] = '0';
	}
	for (int step = 0; step < generations; ++step) {
		for (y = 0; y < height; ++y) for (x = 0; x < width; ++x) {
			int neighbours = 0;
			for (int dy = -1; dy <= 1; ++dy) for (int dx = -1; dx <= 1; ++dx)
				if ((dx || dy) && x + dx >= 0 && x + dx < width && y + dy >= 0 && y + dy < height &&
					board[(y + dy) * width + x + dx] == '0') ++neighbours;
			int live = board[y * width + x] == '0';
			next[y * width + x] = (neighbours == 3 || (live && neighbours == 2)) ? '0' : ' ';
		}
		char *swap = board; board = next; next = swap;
	}
	for (y = 0; y < height; ++y) {
		write(STDOUT_FILENO, board + y * width, (size_t)width);
		write(STDOUT_FILENO, "\n", 1);
	}
	clear(board); clear(next);
	return 0;
}
