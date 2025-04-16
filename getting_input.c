#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include<string.h>

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}


int main()
{
    enableANSI();
    char buffer[1000];
    int cur_pos[100][100];
    int i= 0;
    int line =1;
    int curline = 1;
    int pos = 1;    // identifies current 
    printf("type # to end program\n\n");
    printf("%d\t",line++);

    while(1){
    char character = getch();
    //printf("%d", character);
    if (character == 35){break;}    //# as escape sequence



    if (character == -32){  // this part handles arrow key movement
        char c = getch();
        if(c == 72){    //up move
            if(curline ==1){continue;}
            else{printf("\033[A");curline--;}
        }

        if(c == 80){    //down move
            if(curline==line-1){continue;}
            else{printf("\033[B"); curline++;}          
        }                     
        if(c == 'K'){   // left move
            if (pos<2){continue;}
            else{printf("\b"); pos--;}}      
        if(c == 'M'){   //right move
            if(pos==50){continue;}
            else{printf("\033[C");pos++;}}                          
        continue;}

    if(character== 27)      // save file as .txt
    {
        char c = getch();
        if (c == 83 || c == 115){
            char file_name[100];
            char path[] = "C:\\C Programs\\C-Text-editor\\";
            char type_of_file[] = ".txt";
            printf("\n\nEnter filename: ");
            scanf("%s", &file_name);
            printf("%s", file_name);
            strcat(path, file_name );
            strcat(path, type_of_file);
            printf("%s", path);
            
            FILE * text_file = fopen(file_name, "w");
            if (text_file == NULL){printf("this didnt work.");break;}
            fprintf(text_file, buffer);
            /*for(int n = 0; n<i; n++)
            {
                fprintf(text_file, &buffer[n]);
            }*/
            fclose(text_file);
            break;

            
        }
    }

    if(character == 13){printf("\n");   printf("%d\t",line++);curline++;
                        buffer[i] = '\n';
                        if (0 == (line-1)%20){printf("\n\nnew page\n");}  //this creates a new page after 20
                        i++;
                        continue;}// this handles enter

    if(character == 8){ if (i>0){printf("\b \b");i--; pos--;
                        
                        continue;} //this adds deletion with backspace
                        else {continue;}}

    

    
    else{printf("%c", character); pos++;}
    buffer[i] = character;

    i++;
    }
return 0;
}