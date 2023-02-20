#include <stdio.h>
#include <string.h>

#define LEN_WORD 17
#define LEN_STR 257
#define OK 0
#define ERR 1
#define MAX_ELE 100
#define ERR_WORD -1
#define LEN_DELIM 10

struct word
{
	char content[LEN_WORD];
	int counter;
};

int split(char str[], struct word *words);
void add_and_count(char str[], struct word *words, int *size);
void print(struct word *words, int n);

int main(void)
{
	char str[LEN_STR];
	struct word words[MAX_ELE];
	int n;
	char *p = fgets(str, LEN_STR, stdin);
	if ((p == NULL) || str[strlen(str) - 1] != '\n')
	{
		printf("input error\n");
		return ERR;
	}
	n = split(str, words);
	if (n == 0 || n == -1)
		return ERR;
	print(words, n);
	return OK;
}

int split(char str[], struct word *words)
{
	int i = 0, j = 0, k = 0;
	char delims[LEN_DELIM] = " ,;:-.!?\n";
	char temp[LEN_WORD];
	while (str[k])
	{
		strcpy(temp, "");
		if (strchr(delims, str[k]) == NULL)
		{
			while (strchr(delims, str[k]) == NULL)
				temp[j++] = str[k++];
			temp[j] = '\0';
			if (j >= LEN_WORD)
				return ERR_WORD;
			j = 0;
			add_and_count(temp, words, &i);
		}
		k++;
	}
	return i;
}

void add_and_count(char str[], struct word *words, int *size)
{
	int exist = 0;
	for (int i = 0; i < *size; i++)
		if (strcmp(words[i].content, str) == 0)
		{
			exist = 1;
			words[i].counter ++;
			break;
		}
	if (exist == 0)
	{
		strcpy(words[*size].content, str);
		words[*size].counter = 1;
		(*size) ++;
	}
}

void print(struct word *words, int n)
{
	printf("Result: \n");
	for (int i = 0; i < n; i++)
		printf("%s %d\n", words[i].content, words[i].counter);
}
