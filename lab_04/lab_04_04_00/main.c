#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 0
#define ERROR 1

#define MAX_WORD_LEN 17
#define STR_LEN 257
#define NO 0
#define YES 1
#define MAX_ELEMENTS 100
#define MAX_NUM_DIGIT 3
#define MAX_OF_NUM 255
#define LEN_DELIM 2
#define AMOUNT_OF_NUM_IN_IP 4

int split(char str[], char writer[][STR_LEN]);
void delete_forward_blank_space(char str[]);
void delete_behind_blank_space(char str[]);
int is_number(char str[]);
int is_ip_address(char str[]);

int main(void)
{
	char str[STR_LEN];
	char *p;
	
	p = fgets(str, STR_LEN, stdin);

	if (p == NULL || str[strlen(str) - 1] != '\n')
		return ERROR;

	if (is_ip_address(str) == NO)
		printf("NO");
	else
		printf("YES");

	return OK;
}

int split(char str[], char writer[][STR_LEN])
{
	int count = 0;
	char *p;
	char delims[LEN_DELIM] = ".";

	for (p = strtok(str, delims); p != NULL; p = strtok(NULL, delims))
	{
		strncpy(writer[count], p, MAX_WORD_LEN);
		count++;
	}

	return count;
}

void delete_forward_blank_space(char str[])
{
	int n = strlen(str);

	while (isspace(*str))
	{
		for (int i = 0; i < n; i++)
			str[i] = str[i + 1];
		n--;
	}		
}

void delete_behind_blank_space(char str[])
{
	int n = strlen(str);
	char *s1 = str + n - 1;

	while (isspace(*s1))
		s1--;
	*(s1 + 1) = '\0';
}

int is_number(char str[])
{
	int n = strlen(str);

	for (int i = 0; i < n; i++)
		if (!isdigit(str[i]))
			return NO;

	return YES;
}

int is_ip_address(char str[])
{
	int n;
	char writer[MAX_ELEMENTS][STR_LEN];
	delete_forward_blank_space(str);
	delete_behind_blank_space(str);
	n = split(str, writer);

	if (n != AMOUNT_OF_NUM_IN_IP)
		return NO;

	for (int i = 0; i < n; i++)
	{
		if (strlen(writer[i]) > MAX_NUM_DIGIT || atol(writer[i]) > MAX_OF_NUM || !is_number(writer[i]))
			return NO;
	}

	return YES;
}