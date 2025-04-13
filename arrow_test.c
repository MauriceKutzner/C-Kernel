#include <conio.h>
#include <stdio.h>

int main(){
    while(1)
    {
        char character = getch();
        
        if (character == 35){break;}
        printf("%d", character);
        if (character == -32){  char c = getch();
                                if(c == 72){printf("up");}
                                if(c == 80){printf("down");}
                                if(c == 'K'){printf("left");}
                                if(c == 'M'){printf("rigth");}}


        else{printf("%c", character);}

    }
    return 0;
}