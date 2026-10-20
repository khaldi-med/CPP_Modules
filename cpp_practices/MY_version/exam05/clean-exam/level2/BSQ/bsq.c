#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

static int parse_header(char *line, int *rows, char *empty, char *wall, char *full)
{
	int used = 0;
	if (sscanf(line, "%d %c %c %c %n", rows, empty, wall, full, &used) == 4)
		while (line[used] == ' ' || line[used] == '\t' ||
			line[used] == '\r' || line[used] == '\n') ++used;
	if (line[used] == '\0') return 1;
	used = 0;
	if (sscanf(line, "%d%c%c%c%n", rows, empty, wall, full, &used) == 4)
		while (line[used] == ' ' || line[used] == '\t' ||
			line[used] == '\r' || line[used] == '\n') ++used;
	return line[used] == '\0';
}

static void free_map(char **map, int rows)
{
	if (map) {
		for (int i = 0; i < rows; ++i) free(map[i]);
		free(map);
	}
}

static int solve(FILE *file)
{
	char *line = 0;
	size_t capacity = 0;
	ssize_t length;
	int rows, width = 0, best = 0, best_row = 0, best_col = 0;
	char empty, wall, full;
	char **map = 0;
	int *dp = 0;

	length = getline(&line, &capacity, file);
	if (length < 1 || line[length - 1] != '\n' ||
		!parse_header(line, &rows, &empty, &wall, &full) || rows < 1 ||
		empty == wall || empty == full || wall == full ||
		empty < 32 || empty > 126 || wall < 32 || wall > 126 ||
		full < 32 || full > 126) {
		free(line); return 0;
	}
	map = calloc((size_t)rows, sizeof(*map));
	if (!map) { free(line); return 0; }
	for (int r = 0; r < rows; ++r) {
		length = getline(&line, &capacity, file);
		if (length < 1 || line[length - 1] != '\n') { free(line); free_map(map, rows); return 0; }
		line[--length] = '\0';
		if (r == 0) width = (int)length;
		if (length < 1 || length != width) { free(line); free_map(map, rows); return 0; }
		for (int c = 0; c < width; ++c)
			if (line[c] != empty && line[c] != wall) { free(line); free_map(map, rows); return 0; }
		map[r] = malloc((size_t)width + 1);
		if (!map[r]) { free(line); free_map(map, rows); return 0; }
		memcpy(map[r], line, (size_t)width + 1);
	}
	free(line);
	dp = calloc((size_t)(width + 1), sizeof(*dp));
	if (!dp) { free_map(map, rows); return 0; }
	for (int r = 1; r <= rows; ++r) {
		int diagonal = 0;
		for (int c = 1; c <= width; ++c) {
			int above = dp[c], value = 0;
			if (map[r - 1][c - 1] == empty) {
				int left = dp[c - 1];
				value = 1 + (left < above ? (left < diagonal ? left : diagonal) : (above < diagonal ? above : diagonal));
				if (value > best) {
					best = value; best_row = r - best; best_col = c - best;
				}
			}
			dp[c] = value;
			diagonal = above;
		}
	}
	for (int r = best_row; r < best_row + best; ++r)
		for (int c = best_col; c < best_col + best; ++c) map[r][c] = full;
	for (int r = 0; r < rows; ++r) {
		fputs(map[r], stdout);
		putchar('\n');
	}
	free(dp); free_map(map, rows);
	return 1;
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		if (!solve(stdin)) fputs("map error\n", stdout);
		return 0;
	}
	for (int i = 1; i < argc; ++i) {
		FILE *file = fopen(argv[i], "r");
		if (!file || !solve(file)) fputs("map error\n", stdout);
		if (file) fclose(file);
		if (i + 1 < argc) putchar('\n');
	}
	return 0;
}
