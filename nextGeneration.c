//find next generation
#include<stdlib.h>
#include<stdio.h>

int nextGen(int myArray[8][6],int row,int colum);
void print2DArray(int myArray[8][6]);
int main()
{
    int myArray[8][6];
    int i,j,nextG,row,colum;
    for(i = 0;i < 8;i++)
    {
        for(j = 0;j < 6;j++)
        {
            myArray[i][j]=(rand()%8)+1;
        }
    }
    print2DArray(myArray);
    printf("\n");

    printf("Enter Row (0-7) & Colum number (0-5): ");
    scanf("%d %d",&row,&colum);
    nextG = nextGen(myArray,row,colum);
    printf("\nNext generatuin is %d\n",nextG);
    return 0;
}

void print2DArray(int myArray[8][6])
{
    int i,j;
    for(i = 0;i < 8;i++)
    {
        for(j = 0;j < 6;j++)
        {
            printf("%d ",myArray[i][j]);
        }
        printf("\n");
    }
}

int nextGen(int myArray[8][6],int row,int colum)
{
    int i = 0,nextG,neighbour[8];

	if(colum >= 0 && colum <= 4)
	{
			if(row != 7 && colum != 0)
			{
				colum++;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				row++;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				if(colum != 0)
				{
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					row--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}
				if(row != 0)
				{
					row--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}
			}
			else if(colum != 0)
			{
				colum++;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				row--;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				colum--;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				if(colum > 0 && colum < 5)
				{
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					row++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}

			}
			else if(colum == 0)
			{
				colum++;
				printf("%d ",neighbour[i] = myArray[row][colum]);
				i++;
				if(row >= 1 && row < 7)
				{
					row++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					row = row-2;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}
				if(row == 0)
				{
					row++;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}
				else if(row == 7)
				{
					row--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
					colum--;
					printf("%d ",neighbour[i] = myArray[row][colum]);
					i++;
				}
			}

	}
	else if(colum == 5)
	{
		if(row >=0 && row <= 6)
		{
			row++;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			colum--;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			row--;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			if(row >= 1 && row <= 6)
			{
			row--;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			colum++;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			}
		}
		else
		{
			colum--;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			row--;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
			colum++;
			printf("%d ",neighbour[i] = myArray[row][colum]);
			i++;
		}
	}

	int x,max = 1,count,j;
	x = i--;
	nextG = neighbour[0];
	for(i=0;i < x;i++)
    {
        count = 0;
        for(j=0;j < x;j++)
        {
			if(neighbour[i] == neighbour[j])
                count++;
        }

        if(count > max)
        {
            max = count;
			nextG = neighbour[i];
        }
    }


    return nextG;
}
