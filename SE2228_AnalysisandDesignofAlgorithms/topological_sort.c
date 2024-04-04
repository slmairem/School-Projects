#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s
{
	LINKED_LIST_NODE next; /* Do not change order */
	void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s
{
	LINKED_LIST_NODE head; /* May overlap with next. */
} LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST linked_stack_init()
{
	LINKED_LIST node = NULL;
	node = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
	if (node != NULL)
	{
		node->head = NULL;
	}
	return node;
}

int push(LINKED_LIST stack, void *data)
{
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	if (node != NULL)
	{
		node->data = data;
		node->next = stack->head;
		stack->head = node;
		return 1;
	}
	else
	{
		return 0;
	}
}

int *pop(LINKED_LIST stack)
{
	LINKED_LIST_NODE node;
	void *res = NULL;

	if (stack->head != NULL)
	{
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	}

	return res;
}

void printstack(LINKED_LIST stack, int nodecount)
{
	int i;

	for (i = 0; i < nodecount; i++)
	{
		printf("%d ", pop(stack));
	}
}

void createGraph(int **graph, int nodecount)
{
	int i, j;

	for (i = 0; i < nodecount; i++)
	{
		for (j = 0; j < nodecount; j++)
		{
			graph[i][j] = 0;
		}
	}
}

void printGraph(int **graph, int nodecount)
{
	int i, j;

	for (i = 0; i < nodecount; i++)
	{
		for (j = 0; j < nodecount; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

void addedge(int **graph, int start, int end)
{
	graph[start][end] = 1;
}

void removeVertex(int **graph, int start, int nodecount)
{
	for (int i = 0; i < nodecount; i++)
	{
		graph[i][start] = -1;
	}
}

void DFS(int **graph, int nodecount, int start, LINKED_LIST *stack){ //O(n)
	int i, j;

	for (i = 0; i < nodecount; i++) 
	{
		if (graph[start][i] == 1)
		{
			DFS(graph, nodecount, i, stack);
		}
		removeVertex(graph, start, nodecount);
	}

	push(*stack, start);
}

void topoSort(int **graph, int nodecount){ // O(n^2)
	LINKED_LIST stack = linked_stack_init();

	int i, j, sum = 0;
	for (i = 0; i < nodecount; i++) //O(n)
	{
		for (j = 0; j < nodecount; j++) // O(n^2)
		{
			sum += graph[j][i];
		}
		if (sum == 0)
		{ // nothing before the node
			DFS(graph, nodecount, i, &stack);
		}
		sum = 0;
	}
	printstack(stack, nodecount);
}

void toporemove(int **graph, int start, int nodecount){
	for (int i = 0; i < nodecount; i++)
	{
		graph[start][i] = 0;
	}
}

void topoSortSourceRemovel(int **graph, int nodecount){ //O(n^3)
	int i, j, k, sum = 0;

	for(k=0; k<nodecount; k++){ //O(n)
		for (i = 0; i < nodecount; i++) //O(n^2)
		{
			for (j = 0; j < nodecount; j++){ //O(n^3)
				sum += graph[j][i];
			}

			if (sum == 0){ // nothing before the node
				printf("%d ", i+1);
				toporemove(graph, i, nodecount);
				removeVertex(graph, i, nodecount);
			}
			sum = 0;
		}
	}	
}

int main()
{
	int nodecount, i;
	int **graph;

	/* obtain values for rows & cols */

	/* allocate the array */
	graph = malloc(nodecount * sizeof *graph);
	for (i = 0; i < nodecount; i++)
	{
		graph[i] = malloc(nodecount * sizeof *graph[i]);
	}

	/* use the array */

	createGraph(graph, 10);

	addedge(graph, 6, 0);
	addedge(graph, 6, 2);
	addedge(graph, 6, 5);
	addedge(graph, 4, 2);
	addedge(graph, 4, 5);
	addedge(graph, 5, 7);
	addedge(graph, 3, 7);
	addedge(graph, 3, 1);
	addedge(graph, 1, 9);

	printGraph(graph, 10);
	printf("\n");

	//topoSort(graph, 10);

	topoSortSourceRemovel(graph,10);

	/* deallocate the array */
	for (i = 0; i < nodecount; i++)
	{
		free(graph[i]);
	}
	free(graph);
}