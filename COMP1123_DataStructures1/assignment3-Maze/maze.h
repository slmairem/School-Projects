#include "linkedstack.h"


typedef struct {
	int R;
	int C;
} POS_t[1], *POS;


void solve_maze() {
	
	int M[8][8] = {
		/* R\C   0  1  2  3  4  5  6  7 */
		/* 0 */ {0, 0, 0, 1, 0, 0, 0, 0},
		/* 1 */ {0, 1, 1, 1, 0, 0, 1, 0},
		/* 2 */ {0, 1, 0, 1, 0, 0, 1, 0},
		/* 3 */ {0, 1, 0, 1, 1, 1, 1, 0},
		/* 4 */ {0, 1, 0, 0, 0, 0, 1, 1},
		/* 5 */ {0, 1, 1, 0, 1, 1, 1, 0},
		/* 6 */ {0, 0, 0, 0, 1, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 1, 0, 0, 0},
	};
	
	int I, J, R = 0, C = 3;
	LINKED_STACK stack;
	POS pos = (POS)malloc(sizeof(POS));
	int flag;
	stack = linked_stack_init();
	
	do
	{
		POS nextPos = (POS)malloc(sizeof(POS));
		
		if (M[R][C] != 2){
			pos[0].C = C;
			pos[0].R = R;
			M[R][C] = 2;
			linked_stack_push(stack, &pos[0]);
		}
		
		if ( M[R+1][C]==1){
			I = R+1;
			J = C;
			nextPos[0].C = J;
			nextPos[0].R = I;
			linked_stack_push(stack, &nextPos[0]);
			M[I][J] = 2;
		}
		
		if ( M[R][C+1]==1){
			I = R;
			J = C+1;
			nextPos[0].C = J;
			nextPos[0].R = I;
			linked_stack_push(stack, &nextPos[0]);
			M[I][J] = 2;
		}
		
		if ( M[R-1][C]==1){
			I = R-1;
			J = C;
			nextPos[0].C = J;
			nextPos[0].R = I;
			linked_stack_push(stack, &nextPos[0]);
			M[I][J] = 2;
		}
		
		if ( M[R][C-1]==1){
			I = R;
			J = C-1;
			nextPos[0].C = J;
			nextPos[0].R = I;
			linked_stack_push(stack, &nextPos[0]);
			M[I][J] = 2;
		}
		
		else{
			M[R][C]= -1;
			linked_stack_pop(stack);
		}
		
		pos = linked_stack_top(stack);
		C = pos[0].C;
		R = pos[0].R;
		
	} while (R != 7 && C != 7 && R != 0 && C != 0);
}

