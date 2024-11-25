#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
const int UPPER_INPUT = 100;
int inputCheck(char* value, int LIMIT)
{
	int i = 0, sign = 1, number = 0, m = 0;
	if (value[0] == '-') {
		sign = -1;
		i = 1;
	}
	else if (value[0] == '+') {
		i = 1;
	}
	for (; value[i] != '\0'; i++)
	{
		if (value[i] < '0' || value[i] > '9') {
			printf("Error: Invalid characters have been entered.\n");
			return INT_MAX;
		}
		int digit = value[i] - '0';
		if (sign == 1 && (number > (LIMIT - digit) / 10)) {
			printf("Error: int type overflow.\n");
			return INT_MAX;
		}
		else if (sign == -1 && (number > (LIMIT - digit) / 10)) {
			printf("Error: int type overflow.\n");
			return INT_MAX;
		}
		number = number * 10 + digit;
	}
	number *= sign;
	return number;
}
int input(int LIMIT)
{
	char* value;
	int isCorrect = 0,q=0;
	while (isCorrect == 0)
	{
		value = (char*)malloc(sizeof(char) * 11);
		scanf_s("%11s", value, 12);
		if (getchar() != '\n')
		{
			printf("Error: there are too many elements in the row, or there are spaces\n");
			while (getchar() != '\n');
			value = NULL;
		}
		else if (inputCheck(value, LIMIT) != INT_MAX)
		{
			isCorrect = 1;
		}
		else
		{
			value = NULL;
		}
	}
	return inputCheck(value, LIMIT);
}
int task1()
{
	int numberOfElements = 0, i = 0, j = 0, n = 0,random=0;
	int* arrayOfNumbers;
	srand(time(NULL));
	while (numberOfElements < 1)
	{
		printf_s("Enter the number of elements(it is possible with the leading zeros and the + sign)\n");
		numberOfElements = input(UPPER_INPUT);
		if (numberOfElements < 1)
		{
			printf_s("Please, again\n");
		}
	}
	arrayOfNumbers = (int*)calloc(numberOfElements, sizeof(int));
	printf_s("If you want to use random to fill the array - enter 1\n");
	printf_s("Otherwise - enter 2\n");
	while (random < 1 || random>2)
		{
			random = input(3);
			if (random < 1 || random>2)
			{
				printf_s("Please, again\n");
			}
		}
	if (random == 2) 
		{
		for (i = 0; i < numberOfElements; i++)
			{
				printf_s("Please enter the value of the array element under the number %d\n", i + 1);
				arrayOfNumbers[i] = input(UPPER_INPUT);
			}
		}
	else
	{
		for (i = 0; i < numberOfElements; i++)
			{
				arrayOfNumbers[i] = rand() % 200 - 99;
			}
	}

	printf_s("Your array is \n");
	for (i = 0; i < numberOfElements - n; i++)
		{
			printf_s("%d ", arrayOfNumbers[i]);
		}
	printf_s("\n");
	for (i = 1; i < numberOfElements - n; i++)
	{
		if (arrayOfNumbers[i] < arrayOfNumbers[i - 1])
		{
			for (j = i; j < numberOfElements - n - 1; j++)
			{
				arrayOfNumbers[j] = arrayOfNumbers[j + 1];
			}
			n++;
			i--;
		}
	}
	printf_s("The result array is ");
	for (i = 0; i < numberOfElements - n; i++)
	{
		printf_s("%d ", arrayOfNumbers[i]);
	}
	printf_s("\n");
	free(arrayOfNumbers);
	return 0;
}
int task2()
{
	int k, numberOfRows = 0, numberOfColumns = 0, i, j, a = 1,n = 0,temp2 = 0, random=0;
	int** array2 = NULL;
	int* temp = NULL;
	srand(time(NULL));
	while (numberOfRows < 1)
	{
		printf_s("Enter the number of rows (it is possible with the leading zeros and the + sign)\n");
		printf_s("Write using enter\n");
		numberOfRows = input(UPPER_INPUT);
		if (numberOfRows < 1)
		{
			printf_s("Please, again\n");
		}
	}
	while (numberOfColumns < 1)
	{
		printf_s("Enter the number of columns (it is possible with the leading zeros and the + sign)\n");
		printf_s("Write using enter\n");
		numberOfColumns = input(UPPER_INPUT);
		if (numberOfColumns < 1)
		{
			printf_s("Please, again\n");
		}
	}
	printf_s("Enter k\n");
	k = input(INT_MAX);
	temp = (int*)malloc(sizeof(int) * numberOfColumns);
	for (j = 0; j < numberOfColumns; j++)
	{
		temp[j] = numberOfColumns;
	}
	array2 = (int**)calloc(numberOfRows, sizeof(int*));
	for (i = 0; i < numberOfRows; i++) {
		array2[i] = (int*)malloc(numberOfColumns * sizeof(int));
	}
	printf_s("If you want to use random to fill the matrix - enter 1\n");
	printf_s("Otherwise - enter 2\n");
	while (random < 1 || random>2)
	{
		random = input(UPPER_INPUT);
		if (random < 1 || random>2)
		{
			printf_s("Please, again\n");
		}
	}
	if (random == 2)
	{
		printf_s("Enter the matrix:\n");
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns; j++)
			{
				array2[i][j] = input(INT_MAX);
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns; j++)
			{
				array2[i][j] = rand()%200-100+1;
			}
		}
	}
	printf_s("Your matrix is \n");
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j <numberOfColumns ; j++)
		{
			printf("%d ", array2[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns+n; j++)
		{
			if (array2[i][j] > k)
			{
				n++;
				for (int m = numberOfColumns+n; m > j; m--)
				{
					array2[i][m] = array2[i][m-1];
				}
				
			}
			j++;
		}
		temp[i]=temp[i]+n;
		n = 0;
		
	}
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < temp[i]; j++)
		{
			printf("%d ",array2[i][j]);
		}
		printf("\n");
	}
	
	free(array2);
	free(temp);
	return 0;
}
int task3()
{
	int numberOfRows = 0, numberOfColumns = 0, numberOfColumnsBuf = 0, i = 0, j = 0, delControl = 0, taskOption = 0, random=0;
	int** matrix = NULL;
	int* maxOfRow = NULL;
	int* minOfRow = NULL;
	int* minOfColumn = NULL;
	int* maxOfColumn = NULL;
	srand(time(NULL));
	while (numberOfRows < 1)
	{
		printf_s("Enter the number of rows (it is possible with the leading zeros and the + sign)\n");
		printf_s("Write using enter\n");
		numberOfRows = input(UPPER_INPUT);
		if (numberOfRows < 1)
		{
			printf_s("Please, again\n");
		}
	}
	while (numberOfColumns < 1)
	{
		printf_s("Enter the number of columns (it is possible with the leading zeros and the + sign)\n");
		printf_s("Write using enter\n");
		numberOfColumns = input(UPPER_INPUT);
		if (numberOfColumns < 1)
		{
			printf_s("Please, again\n");
		}
	}
	numberOfColumnsBuf = numberOfColumns;
	matrix = (int**)calloc(numberOfRows, sizeof(int*));
	for (i = 0; i < numberOfRows; i++) 
	{
		matrix[i] = (int*)malloc(numberOfColumns * sizeof(int));
	}
	while (taskOption < 1 || taskOption >2)
	{
		printf_s("If you want to use the task option from the condition - enter 1\n");
		printf_s("If you want to use the correct version of the task - enter 2\n");
		taskOption = input(3);
		if (taskOption < 1 || taskOption >2)
		{
			printf_s("Please, again\n");
		}
	}
	printf_s("If you want to use random to fill the matrix - enter 1\n");
	printf_s("Otherwise - enter 2\n");
	while (random < 1 || random>2)
	{
		random = input(3);
		if (random < 1 || random>2)
		{
			printf_s("Please, again\n");
		}
	}
	if (random == 2)
	{
		printf_s("Enter the matrix:\n");
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns; j++)
			{
				matrix[i][j] = input(INT_MAX);
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns; j++)
			{
				matrix[i][j] = rand() % 200 - 100 + 1;
			}
		}
	}
	printf("You entered matrix is \n");
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	if (taskOption == 1)
	{
		maxOfRow = (int*)malloc(numberOfRows * sizeof(int));
		minOfColumn = (int*)malloc(numberOfColumns * sizeof(int));
		for (i = 0; i < numberOfRows; i++)
		{
			maxOfRow[i] = matrix[i][0];
			for (j = 0; j < numberOfColumns; j++)
			{
				if (maxOfRow[i] < matrix[i][j])
					maxOfRow[i] = matrix[i][j];
			}
		}
		for (i = 0; i < numberOfColumns; i++)
		{
			minOfColumn[i] = matrix[0][i];
			for (j = 0; j < numberOfRows; j++)
			{
				if (minOfColumn[i] > matrix[j][i])
					minOfColumn[i] = matrix[j][i];
			}
		}
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns + delControl; j++)
			{
				if (minOfColumn[j] == maxOfRow[i])
				{
					for (int m = 0; m < numberOfRows; m++)
					{
						for (int l = j; l < numberOfColumns - 1; l++)
						{
							matrix[m][l] = matrix[m][l + 1];
						}
					}
					minOfColumn[j] = INT_MAX;
					numberOfColumns--;
					delControl++;
				}
			}
		}
	}
	if (taskOption == 2)
	{
		minOfRow = (int*)malloc(numberOfRows * sizeof(int));
		maxOfColumn = (int*)malloc(numberOfColumns * sizeof(int));
		for (i = 0; i < numberOfRows; i++)
		{
			minOfRow[i] = matrix[i][0];
			for (j = 0; j < numberOfColumns; j++)
			{
				if (minOfRow[i] > matrix[i][j])
					minOfRow[i] = matrix[i][j];
			}
		}
		for (i = 0; i < numberOfColumns; i++)
		{
			maxOfColumn[i] = matrix[0][i];
			for (j = 0; j < numberOfRows; j++)
			{
				if (maxOfColumn[i] < matrix[j][i])
					maxOfColumn[i] = matrix[j][i];
			}
		}
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns + delControl; j++)
			{
				if (maxOfColumn[j] == minOfRow[i])
				{
					for (int m = 0; m < numberOfRows; m++)
					{
						for (int l = j; l < numberOfColumns - 1; l++)
						{
							matrix[m][l] = matrix[m][l + 1];
						}
					}
					maxOfColumn[j] = INT_MAX;
					numberOfColumns--;
					delControl++;
				}
			}
		}
	}
	if (numberOfColumnsBuf == numberOfColumns)
	{
		printf("The matrix has no saddle elements\n");
	}
	else if (numberOfColumns == 0)
	{
		printf("All columns have been deleted\n");
	}
	else
	{
		printf("The matrix is \n");
		for (i = 0; i < numberOfRows; i++)
		{
			for (j = 0; j < numberOfColumns; j++)
			{
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	free(minOfColumn);
	free(minOfRow);
	free(maxOfColumn);
	free(maxOfRow);
	for (i = 0; i < numberOfRows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
int main()
{
	printf_s("Hello, this is Laba5\nPlease enter the number of task(1,2,3)\n");
	int numberOfTask = 0, userWork=1;
	while (userWork) {
		while (numberOfTask < 1 || numberOfTask>3)
		{
			numberOfTask = input(4);
			if (numberOfTask < 1 || numberOfTask>3)
			{
				printf_s("Please, again\n");
			}
		}
		if (numberOfTask == 1)
		{
			task1();
		}
		else if (numberOfTask == 2)
		{
			task2();
		}
		else
		{
			task3();
		}
		numberOfTask = 0;
		printf_s("If you want to repeat press space,\nelse press any key\n");
		if (_getch() == ' ')
		{
			printf_s("Please enter the number of task(1, 2, 3)\n");
		}
		else
		{
			printf_s("GoodBye");
			userWork = 0;
		}
	}
}
