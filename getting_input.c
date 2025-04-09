#include <conio.h>
#include <stdio.h>
int main()
{
    int i= 0;
    while(i<20){
    char character = getch();

    if(character == 13){printf("\n");}
    if(character == 127){printf(" ");}
    else{printf("%c", character);}
    i++;
    }
return 0;
}