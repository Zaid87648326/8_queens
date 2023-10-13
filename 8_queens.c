#include<stdio.h>

int abs(int n)
{
	return ((n >= 0) ? n : (-n));
}

int check(int b[8][8],int x,int y) // function that check a queen if it's in danger or not ,if is in danger the function returns 1, otherwise, it  returns 0 
{
    int    i;
    int    j;

    i = 0;
    while (i < 8)
    {
        j = 0;
        while (j < 8)
        {
            if (abs(i - x) == abs(j - y) && b[i][j] != 0 && (i != x
                    && j != y)) // diagonally check
                return (1);
            j++;
        }
	if (b[x][i] != 0 && i != y) // vertical check
        	return (1);
     	if (b[i][y] != 0 && i != x) // horizontal check
      		return (1);
        i++;
    }
    		return (0);
}

void    disp(int board[8][8],int *cnt) // function for displaying the solutions and for each display count a solution 
{
    int        i;
    int        j;

    i = 0;
    while (i < 8)
    {
        j = 0;
        while (j < 8)
        {
            if (board[i][j] == 1)
                printf("Q ");
	    else
		printf(". ");
            j++;
        }
	printf("\n");
        i++;
    }
    printf("\n\n");
    (*cnt)++; //increment the count of solutions
}

void putQ(int b[8][8],int y,int *count) // main function for finding solution ,and help  for counting number of solution
{
	int x = 0;
	if (y == 8)
	{
		disp(b,count); // Display the solution
	}
	else 
	{
		while(x < 8)
		{
			if (!check(b,y,x))
			{
				b[y][x] = 1;  // place a queen
				putQ(b,y+1,count); // recursively solve the next row
				b[y][x] = 0; // Backtrack by removing the queen
			}
			x++;
		}
	}
}

int main()
{
	int b[8][8];
	int row = 0;
	int c = 0; // c is the counter of solutions

        while (row < 8) // board initialization with 0
	{
        int col = 0;
        while (col < 8) {
            b[row][col] = 0;
            col++;
        }
        row++;
    	}
	putQ(b,0,&c); // start solving the problem
	printf("number of solution is : %d \n",c); // display number of solutions
	return 0;
}
