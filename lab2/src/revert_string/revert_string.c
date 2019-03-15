#include "revert_string.h"
#include "swap.h"
#include "stdio.h"
void RevertString(char *str)
{
	// your code here
	char* endPtr = str;
	while(*(endPtr+1) != '\0')
	   endPtr++;
	   
	int bound =( endPtr-str)%2 == 0 ? (endPtr-str)/2 : (endPtr-str)/2+1;
	for(int i = 0;i< bound ; i++){
        Swap(endPtr-i,str+i);	   
	}
}

