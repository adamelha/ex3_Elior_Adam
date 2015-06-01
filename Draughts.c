#include "Draughts.h"

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	init_board(board);
	print_board(board);
	print_message(WRONG_MINIMAX_DEPTH);
	perror_message("TEST");
	return 0;
}
//little example of using and printing from the data structures:
/*MovesList *movesList = createNewMovesList();
	Point point0 = createPoint(0, 0);
	Point point1 = createPoint(1, 0);
	
	MoveNode *moveNode0 = createMoveNode(point0);
	Move move0 = createEmptyMove();
	appendMoveNodeAtBegining(moveNode0, &move0);
	MovesListNode *movesListNode0 = createMovesListNode(move0);
	appendMoveListNodeAtEnd(movesListNode0, movesList);
	printMovesList(movesList);

	printf("\n");

	MoveNode *moveNode1 = createMoveNode(point1);
	appendMoveNodeAtEnd(moveNode1, &(movesListNode0->move));
	printMovesList(movesList);*/

void print_line(){
	int i;
	printf("  |");
	for (i = 1; i < BOARD_SIZE*4; i++){
		printf("-");
	}
	printf("|\n");
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	int i,j;
	print_line();
	for (j = BOARD_SIZE-1; j >= 0 ; j--)
	{
		printf((j < 9 ? " %d" : "%d"), j+1);
		for (i = 0; i < BOARD_SIZE; i++){
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		print_line();
	}
	printf("   ");
	for (j = 0; j < BOARD_SIZE; j++){
		printf(" %c  ", (char)('a' + j));
	}
	printf("\n");
}



void init_board(char board[BOARD_SIZE][BOARD_SIZE]){
	int i,j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if ((i + j) % 2 == 0){
				if (j <= 3){
					board[i][j] = WHITE_M;
				}
				else if (j >= 6){
					board[i][j] = BLACK_M;
				}
				else{
					board[i][j] = EMPTY;
				}
			}
			else{
				board[i][j] = EMPTY;
			}
		}
	}
}

