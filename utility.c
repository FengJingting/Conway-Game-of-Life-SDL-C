#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Name: clear
   Input: None
   Function: use to clear redundant scanf
*/
void clear()
{
	char b;
	do
	{
	scanf("%c",&b);
	}
	while(b !='\n');
}

/* Name: check_input()
   Function: init game
*/
int check_input(char* input){
	if(strlen(input)!=1){
		printf("Invalid input!");
		clear();
		return 1;
	}
	if(strcmp(input,"a")==0||strcmp(input,"b")==0){
		return 0;
	}
	printf("Invalid input!");
	clear();
	return 1;
}

