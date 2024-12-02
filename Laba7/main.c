#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


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
			printf("Error: overflow.\n");
			return INT_MAX;
		}
		else if (sign == -1 && (number > (LIMIT - digit) / 10)) {
			printf("Error: overflow.\n");
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
	int isCorrect = 0, q = 0;
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
void check1(char* string)
{
	int i = 0;
		while (string[i]!='\0')
		{
			if (string[i] >= 'a' && string[i] <= 'z' && ((string[i-1]==' ') || (i==0)))
			{
				string[i] -= 32;
			}
			i++;
		}
	}
void task1()
{

	char* string;
	int isCorrect = 0,i=0;
	string = (char*)malloc(sizeof(char) * 100);
	printf_s("Enter the string\n");
	gets(string);
	check1(string);
	printf_s("The string is\n");
	printf("%s\n", string);

}
int string_length(char* str) 
{
	int length = 0;
	while (str[length] != '\0') 
	{
		length++;
	}
	return length;
}
void MyStrcat(char* s1, char* s2, int n1, int n2, char* result)
{
	int i = 0, j = 0;
	for (i = 0; i < n1; i++)
	{
		result[i] = s1[i];
	}
	j = string_length(s2) - n2;
	for (; i < n1+n2; i++)
	{
		result[i] = s2[j];
		j++;
	}
	printf_s("%s\n", result);
}
void task2()
{
	int n1=0, n2=0;
	char* s1;
	char* s2;
	char* result;
	s1 = (char*)malloc(sizeof(char) * 100);
	s2 = (char*)malloc(sizeof(char) * 100);
	while (n1 < 1)
	{
		printf_s("Enter the number of characters from 1 line(it is possible with the leading zeros and the + sign)\n");
		n1 = input(UPPER_INPUT);
		if (n1 < 1)
		{
			printf_s("Please, again\n");
		}
	}
	while (n2 < 1)
	{
		printf_s("Enter the number of characters from 2 line(it is possible with the leading zeros and the + sign)\n");
		n2 = input(UPPER_INPUT);
		if (n2 < 1)
		{
			printf_s("Please, again\n");
		}
	}
	while (1)
	{
		printf_s("Enter 1 line\n");
		gets(s1);
		if (string_length(s1) >= n1)
		{
			break;
		}
		else
		{
			printf_s("Please, again\n");
		}
	}
	while (1)
	{
		printf_s("Enter 2 line\n");
		gets(s2);
		if (string_length(s2) >= n2)
		{
			break;
		}
		else
		{
			printf_s("Please, again\n");
		}
	}
	result = (char*)malloc(sizeof(char) * (n1+n2)/2);
	MyStrcat(s1, s2, n1, n2, result);
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j < high; j++) {
		if (arr[j] >= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int* arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int maxWordLength(char* str) {
	int maxLen = 0;
	int currentLen = 0;
	while (*str) {
		if (*str == ' ') {
			if (currentLen > maxLen) {
				maxLen = currentLen;
			}
			currentLen = 0;
		}
		else {
			currentLen++;
		}
		str++;
	}
	if (currentLen > maxLen) {
		maxLen = currentLen;
	}
	return maxLen;
}
void task3()
{
	int numberOfStrings = 0, i = 0, j = 0;
	char** arrayOfString = NULL;
	arrayOfString = (char**)calloc(numberOfStrings, sizeof(char*));
	int* arrayOfMaxWordLen = NULL;
	int* arrayOfMaxWordLen2 = NULL;
	arrayOfMaxWordLen = (int*)calloc(numberOfStrings + 1, sizeof(int));
	arrayOfMaxWordLen2 = (int*)calloc(numberOfStrings + 1, sizeof(int));
	while (numberOfStrings < 1)
	{
		printf_s("Enter the number of strings\n");
		numberOfStrings = input(UPPER_INPUT);
		if (numberOfStrings < 1)
		{
			printf_s("Please, again\n");
		}
	}
	for (i = 0; i < numberOfStrings; i++) {
		arrayOfString[i] = (char*)malloc(100 * sizeof(char));
	}
	for (i = 0; i < numberOfStrings; i++)
	{
		printf_s("Enter the string number %d:\n", i + 1);
		gets(arrayOfString[i]);
		printf("\n");
	}


	for (i = 0; i < numberOfStrings; i++)
	{
		arrayOfMaxWordLen[i] = maxWordLength(arrayOfString[i]);
		arrayOfMaxWordLen2[i] = arrayOfMaxWordLen[i];
	}
	quickSort(arrayOfMaxWordLen, 0, numberOfStrings - 1);
	for (i = 0; i < numberOfStrings; i++)
	{
		for (j = 0; j < numberOfStrings; j++)
		{
			if (arrayOfMaxWordLen[i] == arrayOfMaxWordLen2[j])
			{
				printf("%s\n", arrayOfString[j]);
				arrayOfMaxWordLen2[j] = 1000;
			}
		}
	}
}
int main()
{
	printf_s("Hello, this is Laba7\nPlease enter the number of task(1,2,3)\n");
	int numberOfTask = 0, userWork = 1;
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