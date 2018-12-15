#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  ROW 5
#define  COL 5

void create();
void render();
int winner();

int board[ROW][COL];
int display[ROW][COL];
int fixed[ROW][COL];
int total;

int main()
{
    int x, y, number;
    create();
    while(1){
        render();
        printf("Enter row column location and number [ to exit enter -1 -1 -1]\n");
        scanf("%d %d %d", &x, &y, &number);
        if(x==-1 || y==-1)
            break;
        if(x==0 || y==0)
            continue;
        if(x<=ROW && y<=COL)
        {
            if(!fixed[y-1][x-1])
                display[y-1][x-1] = number;
        }
        if(winner()){
            printf("Congratulations !!!!.. You have completed the game.\n");
            return 0;
        }
        system("cls");
    }
    printf("come Again ! :)\n");
    return 0;
}

int winner() {
    int i, j;
    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
            if(board[i][j] != display[i][j])
                return 0;
    return 1;
}

void render() {
    int i, j;
    printf("\n\n\t WELCOME TO NUMBER GAME !!!!!\n\n");
    for(i=0;i<ROW;i++){
        printf("\t");
        for(j=0;j<COL;j++){
            printf("  %2d  ", display[i][j]);
        }
        printf("\n\n");
    }
    printf("total should be : %d\n\n", total);
}

void create(){
    int i, j, x, y, number;
    srand(time(NULL));
    x = rand()%COL;
    y = rand()%ROW;
    number = rand()%10;
    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
        {
            board[y][x] = number;
            y = (y-1 + ROW)%ROW;
            x = (x+1)%COL;
            if(board[y][x] != 0)
            {
                x = (x+ COL - 1)%COL;
                y = (y + 2)%ROW;
            }
            number++;
        }

    for(i=0;i<ROW;i++) {
        for(j=0;j<2*COL/3;j++){
            x = rand()%6;
            y = rand()%6;
            if(display[y][x])
                j--;
            else {
                display[y][x] = board[y][x];
                fixed[y][x] = 1;
            }
        }
        total += board[0][i];
    }
}
