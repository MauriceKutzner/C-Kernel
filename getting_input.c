#include <conio.h>
#include <stdio.h>
int main()
{
    char buffer[1000];
    int i= 0;
    int line =1;
    printf("type # to end program\n\n");
    printf("%d\t",line++);

    while(1){
    char character = getch();
    //printf("%d", character);
    if (character == 35){break;}    //# as not so much used escape sequence

    if(character == 13){printf("\n");   printf("%d\t",line++); buffer[i] = character; continue;}
    if(character == 8){ if (i>0){printf("\b \b");i--;continue;} 
                        else {continue;}}
    else{printf("%c", character);}
    buffer[i] = character;

    i++;
    }
return 0;
}