#include <stdio.h>
#include <stdbool.h>


int GetInt(void)
{
    char temprem, tempclear;
    int input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%d%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("  - Error: Invalid value for int variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}
