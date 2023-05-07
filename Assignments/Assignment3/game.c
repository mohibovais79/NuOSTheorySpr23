#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <time.h>
#include "Barrier.h"
#include "Cells.h"

//board features

#define board_height 25
#define board_width 25
#define clear_screen() puts ("\033[H\033[J")
#define statistics generation, _cells.alive, _cells.maintained, _cells.died

long int generation=0;
int board[board_height][board_width];
Barrier _barrier;
Cells _cell;

void setBoard(){
    int i,j,val;
    for ( i = 0; i < board_height; i++)
    {
        for ( j = 0; j < board_width; j++)
        {
            if(board[i][j]){printf(" . ");}
            else printf("  ");
            
        }
        printf("\n");
        
    }
    
}
void printBoard(){
    if (generation%500==0) sleep(1);

    clear_screen();
    printf("Generations: %d || Alive: %d || Maintained: %d || Died: %d\n",statistics);
    generation++;
    int i,j;

    for (i = 0; i < board_height; i++) {
        for (j = 0; j < board_width; j++) {
            if (board[i][j]) printf(" . ");
            else printf("  ");
        }
        printf("\n");
    }

 
    
}

int xadd(int i,int a){
    i+=a;
    while (i<0) i+=board_width;
    while (i>=board_width) i -=board_width;
    return i;
   
    
}

int yadd(int i,int a){
    i+=a;
    while (i<0) i+=board_height;
    while (i>=board_height) i -=board_height;
    return i;
   
    
}

int adjacent_to (int i, int j) {
	int	k, l, count;
	count = 0;
	/* go around the cell */
	for (k = -1; k <= 1; k++) {
		for (l = -1; l <= 1; l++) {
		/* only count if at least one of k,l isn't zero */
			if (k || l) {
				if (board[xadd(i,k)][yadd(j,l)]) {
					count++;
				}
			}
		}
	}
	return count;
}

void* thrive(void* param) {
	do {
		int threadrow = (intptr_t) param;
		int	i, j, a;
		int newboard[board_width];
		/* for each cell, apply the rules of Life */
		for (j = 0; j < board_width; j++) {
			a = adjacent_to (threadrow, j);
			if (a == 2) {
				newboard[j] = board[threadrow][j];
				_cells.maintained++;
			}
			if (a == 3) {
				newboard[j] = 1;
				_cells.alive++;
			}
			if (a < 2 || a > 3) {
				newboard[j] = 0; 
				_cells.died++;
			}
		}
		barrierCloseRelease(&_barrier, board_height);
		/* copy the new board back into the old board */
		//CRITICAL SECTION //
		for (j = 0; j < board_width; j++) {
			board[threadrow][j] = newboard[j];
		}
		//CRITICAL SECTION END//
		if (threadrow == 0) printBoard();
		barrierCloseRelease(&_barrier, board_width);
	} while(1);
}



int main () {
	srand(time(NULL));
    pthread_t thread[board_height];
	_barrier = barrierInitialization();
	_cells = cellInitialization();
    setBoard();
    int i;
    for (i = 0; i < board_height; i++) {
        pthread_create(&thread[i], NULL, &thrive, (void*)(intptr_t)i);
	}
	do {;} while(1);
}