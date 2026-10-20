#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av){
//Part 1:
    if(ac != 4)
        return 1;
    int height = atoi(av[1]);
    int width = atoi(av[2]);
    int iter = atoi(av[3]);
    int board[2][height + 2][width + 2];
    if(height <= 0 || width<=0 || iter < 0) return 1;

//Part 2:
   for(int i= 0; i< 2; i++){
        for(int j= 0; j< height +2; j++){
            for(int k= 0; k< width +2; k++) {
                board[i][j][k] = 0;
                //printf("i:%d j:%d k:%d %d\n", i, j, k, board[i][j][k]);
            }
        }
   }

//Part 3:
    int x= 1, y= 1, pen = 0;
    char cmd;
    while(read(0, &cmd, 1)> 0){
        if(cmd == 'x') pen = !pen;
        else if(cmd == 'w' && x > 1) x--;
        else if(cmd == 'a' && y > 1) y--;
        else if(cmd == 's' && x < height) x++;
        else if(cmd == 'd' && y < width) y++;
        if(pen) board[0][x][y] = 1;
    }

//Part 4:
    for(int i = 0; i < iter; i++){
        for(int h = 1; h < height +1; h++){
            for(int w = 1; w < width+ 1; w++){
                int nb = 0;
                for(int x = -1; x <= 1; x++){ 
                    for(int y = -1; y <= 1; y++){
                        if(!(y== 0 && x== 0)) nb += board[i % 2][h+x][w+y];
                    }
                }
                if(((nb==2 || nb == 3) && board[i % 2][h][w]) || nb==3) board[(i+1)%2][h][w] = 1;
                else
                    board[(i +1)%2][h][w] = 0;
            }
        }
    }

//Part 5:
    for(int h = 1; h < height+1; h++){
        for(int w = 1; w < width+1; w++) putchar(board[iter %2][h][w] ? 'O': ' ');
        putchar('\n');
    }

   return 0;
}
