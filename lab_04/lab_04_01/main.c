#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_WORD 17
#define LEN_STR 257
#define OK 0
#define ERR 1
#define MAX_ELE 100
#define ERR_WORD -1
#define LEN_DELIM 9

char *my_strpbrk(char *str1, char *str2);
size_t my_strspn(char *str1, char *str2);
size_t my_strcspn(char *str1, char *str2);
char *my_strchr(char *str, int c);
char *my_strrchr(char *str, int c);

int main(void)
{
	int count = 0;
	printf("Test for LAB_04_01: \n");

	if (strpbrk("iamstrong", "letsmesee") != my_strpbrk("iamstrong", "letsmesee"))
		count++;

	if (strspn("iamstrong", "letsmesee") != my_strspn("iamstrong", "letsmesee"))
		count++;

	if (strcspn("iamstrong", "letsmesee") != my_strcspn("iamstrong", "letsmesee"))
		count++;

	if (strchr("iamstrong", 98) != my_strchr("iamstrong", 98))
		count++;

	if (strrchr("iamstrong", 98) != my_strrchr("iamstrong", 98))
		count++;

	printf("количество проваленных сравнений: %d\n", count);
	return OK;
}

char *my_strpbrk(char *str1, char *str2)
{
	for (int i = 0; str1[i]; i++)
		for (int j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
				return &str1[i];
	return NULL;
}

size_t my_strspn(char *str1, char *str2)
{
	int count = 0;
	for (int i = 0; str1[i]; i++)
	{
		int flag = 0;
		for (int j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
			{
				flag = 1;
				count ++;
				break;
			}
		if (flag == 0)
			return count;
	}
	return count;
}

size_t my_strcspn(char *str1, char *str2)
{
	int count = 0;
	for (int i = 0; str1[i]; i++)
	{
		for (int j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
				return count;
		count ++;
	}
	return count;
}

char *my_strchr(char *str, int c)
{
	size_t i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return str + i;
	}
	if (str[i] == c)
		return str + i;
	return NULL; 
}

char *my_strrchr(char *str, int c)
{
	char *ans = NULL;
	size_t i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			ans = str + i;
	}
	if (str[i] == c)
		ans = str + i;
	return ans;
}