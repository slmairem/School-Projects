#include <stdio.h>


void DrawRectangle(int arr[20][20], int row, int column, int width, int height) 
{
    int i = 0;
    int j = 0;
    for (i = 0; i < height; i++)
	{
        if (i == 0 || i == height-1)
		{
            for (j = 0; j < width; j++) 
			{
                arr[i + row][j + column] = 1;
            }
        }
        else 
		{
            arr[i + row][column] = 1;
            arr[i + row][column + width - 1] = 1;
        }
    }
}



int FillRectangle(int arr[20][20], int row, int column, int width, int height)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < height; i=i+1) 
	{
        for (j = 0; j < width; j=j+1) 
		{
            arr[i + column][j + row] = 1;
        }
    }
    
    return 0;
}


int DrawHLine(int arr[20][20], int row, int column, int lenght)
{
	int i=0;
	for(i = 0; i<lenght ; i=i+1)
	{
		arr[column][i+row] = 1;
	}

	return 0;
}


int DrawVLine(int arr[20][20], int row, int column, int lenght)
{
	int i=0;
	for(i = 0; i<lenght ; i=i+1)
	{
		arr[i+column][row] = 1;
	}

	return 0;
}


int ClearScreen(int arr[20][20])
{
	int i = 0;
    int j = 0;
    for (i = 0; i <20; i=i+1) 
	{
        for (j = 0; j < 20; j=j+1) 
		{
            arr[i][j] = 0;
        }
    }
    
    return 0;
}


int PrintScreen(int arr[20][20])
{
	int i;
	int j;
	for (i = 0; i <= 21; i++)
	{
		for(j=0; j <= 21;j++)
		{
			if(i==0 || i==21)
			{
				printf("- ");
			}
			else
			{
				if(j==0||j==21)
				{
					printf("| ");
				}
				else
				{
					if(arr[i-1][j-1]==1)
					{
						printf("* ");
					}
					else
					{
						printf("  ");
					}
				}
			}
		}
	printf("\n");	
    }
    
}


int main()
{
	int arr [20][20]={0};

	DrawRectangle(arr,1,2,3,4);
	FillRectangle(arr,8,8,3,4);
	DrawHLine(arr,1,11,5);
	DrawVLine(arr,10,1,5);
	PrintScreen(arr);
	
	return 0;
}

