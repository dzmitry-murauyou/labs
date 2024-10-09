#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void task1()
{
	int matrix[100][100], strokaPr[100], i, j, size = 0, buferMaxValue = 0, maxValue = 0, l = 1, correctInput = 0;
	int isCorrect = 0;
	srand(time(NULL));
	printf_s("Enter size in format n*n, n>1\n");
	while (!correctInput || size <= 1)
	{
		if (!scanf_s("%d", &size) || size < 1)
		{
			printf_s("Please, try again\n");
			while (getchar() == '\0');
		}
		else
		{
			correctInput = 1;
		}
	}
	correctInput = 0;
	for (j = 0; j < size; j++)
		strokaPr[j] = 1;
	printf_s("If you want enter the matrix randomly - press 1,\nelse press any key");
	if (_getch() == '1')
	{
		for (i = 0; i < size; i++)
		{
			printf_s("\n");
			for (j = 0; j < size; j++)
			{
				matrix[i][j]=rand() % 200 - 100;
				printf_s("%d ", matrix[i][j]);
			}
		}
		printf_s("\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				correctInput = 0;
				while (!correctInput)
				{
					if (!scanf_s("%d", &matrix[i][j]))
					{
						printf_s("Please, try again\n");
						while (getchar() == '\0');
					}
					else
					{
						correctInput = 1;
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (matrix[i][j] < 0) 
			{
				strokaPr[i] = -1; 
				break;
			}
			else
				strokaPr[i] *= matrix[i][j];
		}
	}
	while(i!=0 && j!=size-1)
	{
		i = 0;
		for (j = l; j < size; j++)
		{
			buferMaxValue += matrix[i][j];
			i++;
		}
		if (maxValue < buferMaxValue)
			maxValue = buferMaxValue;
		l++;
		buferMaxValue = 0;
	}
	l = 1;
	while (j != 0 && i != size - 1)
	{
		j = 0;
		for (i = l; i < size; i++)
		{
			buferMaxValue += matrix[i][j];
			j++;
		}
		if (maxValue < buferMaxValue)
			maxValue = buferMaxValue;
		l++;
		buferMaxValue = 0;
	}
	for (i = 0; i < size; i++)
	{
		if (strokaPr[i] >= 0)
			printf_s("Multiply of line number %d is %d\n",i+1, strokaPr[i]);
	}
	printf_s("Max summ is %d\n", maxValue);
}
void task2()
{
	const int q = 2;
	double matrix[100][100];
	int i, j, size, number = 1, byfer = -1, correctInput = 0;
	printf_s("Enter size in format n*n\n");
	while (!correctInput)
	{
		if (!scanf_s("%d", &size))
		{
			printf_s("Please, try again\n");
			while (getchar() == '\0');
		}
		else
		{
			correctInput = 1;
		}
	}
	printf_s("If you want enter the matrix randomly - press 1,\nelse press any key");
	if (_getch() == '1')
	{
		for (i = 0; i < size; i++)
		{
			printf_s("\n");
			for (j = 0; j < size; j++)
			{
				matrix[i][j] = rand() % 200 - 100;
				printf_s("%lf ", matrix[i][j]);
			}
		}
		printf_s("\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				correctInput = 0;
				while (!correctInput)
				{
					if (!scanf_s("%lf", &matrix[i][j]))
					{
						printf_s("Please, try again\n");
						while (getchar() == '\0');
					}
					else
					{
						correctInput = 1;
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		if (matrix[i][0] == 0) {
			for (j = 1; j < size; j++)
			{
				if (matrix[i][j] == 0) {
					number++;
				}
				else
				{
					break;
				}
			}
			if (number == size)
				byfer = i; break;
		}
	}
	if (byfer != -1) {
		for (i = 0; i < size; i++)
		{
			matrix[i][byfer] = matrix[i][byfer] / q;
		}
	}
	printf_s("Matrix is\n");
	for (i = 0; i < size; i++)
	{
		if(i>0)
		printf_s("\n");
		for (j = 0; j < size; j++)
		{
			printf_s("%.2lf ", matrix[i][j]);
		}
	}
	printf_s("\n");
}
void task3()
{
	int matrix[100][100], i, j, size = 0, a = 0, resultByfer = 0, sizeBufer, correctInput = 0;;
	printf_s("Enter size in format n*n\n");
	while (correctInput < 1)
	{
		if (!scanf_s("%d", &size))
		{
			printf_s("Please, try again\n");
			while (getchar() == '\0');
		}
		else
		{
			correctInput = 1;
		}
	}
	sizeBufer = size;
	printf_s("If you want enter the matrix randomly - press 1,\nelse press any key");
	if (_getch() == '1')
	{
		for (i = 0; i < size; i++)
		{
			printf_s("\n");
			for (j = 0; j < size; j++)
			{
				matrix[i][j] = rand() % 200 - 100;
				printf_s("%d ", matrix[i][j]);
			}
		}
		printf_s("\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				correctInput = 0;
				while (!correctInput)
				{
					if (!scanf_s("%d", &matrix[i][j]))
					{
						printf_s("Please, try again\n");
						while (getchar() == '\0');
					}
					else
					{
						correctInput = 1;
					}
				}
			}
		}
	}
	for (j = 0; j < size + (size % 2 == 0 ? 0 : 1); j++)
	{
		for (i = a; i < sizeBufer; i++)
		{
			if (matrix[i][j] % 2 != 0 && matrix[i][j] > resultByfer)
				resultByfer = matrix[i][j];
		}
		a++;
		sizeBufer--;
	}
	printf_s("Result is %d\n", resultByfer);
}
int main()
{
	int correctInput = 0, a;
	printf_s("Hello, this is Laba4\nPlease enter the number of task(1,2,3)\n");
	while (!correctInput)
	{
		if (!scanf_s("%d", &a) || a>3 || a<1)
		{
			printf_s("Please, try again\n");
			while (getchar() == '\0');
		}
		else
		{
			correctInput = 1;
			if (a == 1)
			{
				task1();
			}
			else if (a == 2)
			{
				task2();
			}
			else
			{
				task3();
			}
			printf_s("If you want to repeat press space,\nelse press any key\n");
			if (_getch() == ' ')
			{
				correctInput = 0; 
				printf_s("Please enter the number of task(1, 2, 3)\n");
			}
			else {
				printf_s("GoodBye");
			}
		}
	}
}
