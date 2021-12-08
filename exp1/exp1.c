#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdbool.h>
#include <stdlib.h> 


bool Delimiter(char token)
{
	if (token == ' ' || token == '+' || token == '-' || token == '*' ||
		token == '/' || token == ',' || token == ';' || token == '>' ||
		token == '<' || token == '=' || token == '(' || token == ')' ||
		token == '[' || token == ']' || token == '{' || token == '}')
		return (true);
	return (false);
}


bool isOperator(char token)
{
	if (token == '+' || token == '-' || token == '*' ||
		token == '/' || token == '>' || token == '<' ||
		token == '=')
		return (true);
	return (false);
}


bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}


bool isNumber(char* token) {

	int i, len = strlen(token);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (token[i] != '0' && token[i] != '1' && token[i] != '2'
			&& token[i] != '3' && token[i] != '4' && token[i] != '5'
			&& token[i] != '6' && token[i] != '7' && token[i] != '8'
			&& token[i] != '9' && token[i] != '.' ||
			(token[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}

bool validIdentifier(char* token)
{
	if (token[0] == '0' || token[0] == '1' || token[0] == '2' ||
		token[0] == '3' || token[0] == '4' || token[0] == '5' ||
		token[0] == '6' || token[0] == '7' || token[0] == '8' ||
		token[0] == '9' || Delimiter(token[0]) == true)
		return (false);
	return (true);
}


char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void analyze(char* token) 
{
	int left = 0, right = 0;
	int len = strlen(token);

	while (right <= len && left <= right) {
		if (Delimiter(token[right]) == false)
			right++;

		if (Delimiter(token[right]) == true && left == right) {
			if (isOperator(token[right]) == true)
				printf("'%c' IS AN OPERATOR\n", token[right]);

			right++;
			left = right;
		} else if (Delimiter(token[right]) == true && left != right
				|| (right == len && left != right)) {
			char* subStr = subString(token, left, right - 1);

			if (isKeyword(subStr) == true)
				printf("'%s' IS A KEYWORD\n", subStr);

			else if (isNumber(subStr) == true)
				printf("'%s' IS A NUMBER\n", subStr);

			else if (validIdentifier(subStr) == true
					&& Delimiter(token[right - 1]) == false)
				printf("'%s' IS A VALID IDENTIFIER\n", subStr);

			else if (validIdentifier(subStr) == false
					&& Delimiter(token[right - 1]) == false)
				printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
			left = right;
		}
	}
	return;
}

int main() {
	{
	
		printf("\n\n");
		FILE *pg;

		if (pg = fopen("input.txt", "r")) {
			
			char line[256];
			while(fgets(line, sizeof(line), pg)) {

				analyze(line);
				printf("\n%s\n", line);				

			} 

			printf("\n End of Program.\n");

		}

		fclose(pg);
	}
	
	return 0;
}
