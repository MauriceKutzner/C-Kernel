#include <conio.h>
#include <stdio.h>
int main()
{
    char buffer[1000];
    int i= 0;
    printf("type # to end program\n\n");
    while(1){
    char character = getch();
    //printf("%d", character);
    if (character == 35){break;}    //# as not so much used escape sequence

    if(character == 13){printf("\n");}
    if(character == 8){for(int n=0;n<i-1;n++){printf("%c", buffer[n]);}}
    else{printf("%c", character);}
    buffer[i] = character;

    i++;
    }
return 0;
}