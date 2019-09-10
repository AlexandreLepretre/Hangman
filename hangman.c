#include <stdio.h>
#include <string.h>
#include "hangman.h"

void printHangman(Drawing* drawing)
{
    printf("%s", drawing->line1);
    printf("%s", drawing->line2);
    printf("%s", drawing->line3);
    printf("%s", drawing->line4);
    printf("%s", drawing->line5);
    printf("%s", drawing->line6);
    printf("%s", drawing->line7);
}

void resetHangman(Drawing* drawing)
{
    strcpy(drawing->line1, "          \n");
    strcpy(drawing->line2, "          \n");
    strcpy(drawing->line3, "          \n");
    strcpy(drawing->line4, "          \n");
    strcpy(drawing->line5, "          \n");
    strcpy(drawing->line6, "          \n");
    strcpy(drawing->line7, "          \n");
}

void setMistakeCount(Drawing* drawing, int guessesLeft)
{
    switch (guessesLeft) {
        case 9:
            setMistakeCount1(drawing);
            break;
        case 8:
            setMistakeCount2(drawing);
            break;
        case 7:
            setMistakeCount3(drawing);
            break;
        case 6:
            setMistakeCount4(drawing);
            break;
        case 5:
            setMistakeCount5(drawing);
            break;
        case 4:
            setMistakeCount6(drawing);
            break;
        case 3:
            setMistakeCount7(drawing);
            break;
        case 2:
            setMistakeCount8(drawing);
            break;
        case 1:
            setMistakeCount9(drawing);
            break;
        case 0:
            setDefeat(drawing);
            break;
    }
}

void setMistakeCount1(Drawing* drawing)
{
    drawing->line6[0] = '|';
    drawing->line7[0] = '|';
}

void setMistakeCount2(Drawing* drawing)
{
    drawing->line4[0] = '|';
    drawing->line5[0] = '|';
}

void setMistakeCount3(Drawing* drawing)
{
    drawing->line2[0] = '|';
    drawing->line3[0] = '|';
}

void setMistakeCount4(Drawing* drawing)
{
    drawing->line6[1] = '\\';
    drawing->line7[2] = '\\';
}

void setMistakeCount5(Drawing* drawing)
{
    int i = 0;
    for (i = 0 ; i <= 7 ; i++) {
        drawing->line1[i] = '_';
    }
}

void setMistakeCount6(Drawing* drawing)
{
    drawing->line2[7] = '|';
}

void setMistakeCount7(Drawing* drawing)
{
    drawing->line3[7] = 'o';
}

void setMistakeCount8(Drawing* drawing)
{
    drawing->line4[6] = '-';
    drawing->line4[7] = '-';
    drawing->line4[8] = '-';
}

void setMistakeCount9(Drawing* drawing)
{
    drawing->line5[7] = '|';
}

void setDefeat(Drawing* drawing)
{
    drawing->line6[6] = '/';
    drawing->line6[8] = '\\';
}
