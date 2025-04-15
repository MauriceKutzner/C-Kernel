#include <conio.h>
#include <stdio.h>


int main()
{
    char buffer[1000];
    int cur_pos[100][100];
    int i= 0;
    int line =1;
    int pos = 1;    // identifies current 
    printf("type # to end program\n\n");
    printf("%d\t",line++);

    while(1){
    char character = getch();
    //printf("%d", character);
    if (character == 35){break;}    //# as not so much used escape sequence
    if (character == -32){  
        char c = getch();
        if(c == 72){printf("\033[A");line--;}
        if(c == 80){printf("\033[B"); line++;}
        if(c == 'K'){printf("\b");pos--;}
        if(c == 'M'){printf("\033[C");pos++;}
        continue;}
    if(character == 13){printf("\n");   printf("%d\t",line++); buffer[i] = character; continue;}
    if(character == 8){ if (i>0){printf("\b \b");i--; pos--; continue;} 
                        else {continue;}}
    else{printf("%c", character);}
    buffer[i] = character;

    i++;
    }
return 0;
}