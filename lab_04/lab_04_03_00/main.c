#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_WORD 17
#define LEN_STR 257
#define OK 0
#define ERR 1
#define MAX_ELE 100
#define ERR_WORD -1
#define LEN_DELIM 11

int split_and_write(char str[], char writer[][LEN_WORD]);
void rm_and_cat(char word[], char temp[]);
void collect(char writer[][LEN_WORD], char temp[], int n);
void print(char ans[]);

int main(void)
{
	char str[LEN_STR];
	char writer[MAX_ELE][LEN_WORD];
	char ans[LEN_STR] = "";
	int n;
	char *p = fgets(str, LEN_STR, stdin);
	if ((p == NULL) || str[strlen(str) - 1] != '\n')
	{
		printf("Input error");
		return ERR;
	}
	n = split_and_write(str, writer);
	if (n == 0)
	{
		printf("Input error");
		return ERR;
	}
	collect(writer, ans, n);
	print(ans);
	return OK;
}

int split_and_write(char str[], char writer[][LEN_WORD])
{
	char delims[LEN_DELIM] = " ,/;:-.!?\n"; 
	int count = 0;
	char *p;

	for (p = strtok(str, delims); p != NULL; p = strtok(NULL, delims))
	{
		strncpy(writer[count], p, LEN_WORD);
		count++;
	}

	return count;
}

void rm_and_cat(char word[], char temp[])
{
	size_t n = strlen(word);
	size_t i = 1;
	while (i < n)
	{
		if (word[i] == word[0])
		{
			size_t j = i;
			for (j = i; j < n - 1; j++)
				word[j] = word[j + 1];
			n--;
			word[n] = '\0';
			i--;
		}
		i++;
	}
	strcat(temp, word);
	strcat(temp, " ");
}

void collect(char writer[][LEN_WORD], char temp[], int n)
{
	int i;
	for (i = n - 2; i >= 0; i--)
	{
		if (strcmp(writer[i], writer[n - 1]))
			rm_and_cat(writer[i], temp);
	}
}

void print(char ans[])
{
	if (strlen(ans))
		printf("Result: %s\n", ans);
}