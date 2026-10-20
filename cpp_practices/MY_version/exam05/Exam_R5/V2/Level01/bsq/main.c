#include <stdio.h>
#include <stdlib.h>

int min3(int a, int b, int c)
{
	return (a < b && a < c) ? a : (b < c ? b : c);
}

int solve(FILE *f)
{
	char **map, *line = NULL, e, o, x;
	size_t cap = 0;
	ssize_t len;
	int n, w = 0, h = 0, i, j, k, best = 0, bi = 0, bj = 0;
	if (fscanf(f, "%d %c %c %c", &n, &e, &o, &x) != 4
		|| n < 1 || e == o || e == x || o == x
		|| e < 32 || e > 126 || o < 32 || o > 126 || x < 32 || x > 126)
		return 1;
	len = getline(&line, &cap, f);
	free(line);
	if (len != 1)
		return 1;
	map = calloc(n, sizeof(char *));
	if (!map)
		return 1;
	for (h = 0; h < n; h++)
	{
		line = NULL;
		len = getline(&line, &cap, f);
		if (len > 0 && line[len - 1] == '\n')
			line[--len] = 0;
		map[h] = line;
		if (!h)
			w = len;
		for (j = 0; j < len && (line[j] == e || line[j] == o); j++)
			;
		if (len < 1 || w != len || j < w)
			break;
	}
	if (h == n)
	{
		int *dp = calloc((h + 1) * (w + 1), sizeof(int));
		if(!dp)
			h = -1;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				k = (i + 1) * (w + 1) + j + 1;
				if (map[i][j] == e)
				{
					dp[k] = min3(dp[k - 1], dp[k - w - 1], dp[k - w - 2]) + 1;
					if (dp[k] > best)
					{
						best = dp[k];
						bi = i - best + 1;
						bj = j - best + 1;
					}
				}
			}
		}
		free(dp);
		for (i = bi; i < bi + best; i++)
		{
			for (j = bj; j < bj + best; j++)
				map[i][j] = x;
		}
		for (i = 0; i < h; i++)
			fprintf(stdout, "%s\n", map[i]);
	}
	for (i = 0; i < n; i++)
		free(map[i]);
	free(map);
	return h != n;
}

int main(int ac, char **av)
{
	if (ac == 1 && solve(stdin))
		fprintf(stdout, "Error: Invalid map\n");
	for (int i = 1; i < ac; i++)
	{
		FILE *f= fopen(av[i], "r");
		if (!f || solve(f))
			fprintf(stdout, "Error: Invalid map\n");
		if (f)
			fclose(f);
		if (i < ac - 1)
			fprintf(stdout, "\n");
	}
	return 0;
}