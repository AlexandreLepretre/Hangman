#ifndef DEF_HANGMAN
#define DEF_HANGMAN

#define DRAWING_WIDTH 10

typedef struct Drawing Drawing;
struct Drawing {
    char line1[DRAWING_WIDTH + 2],
         line2[DRAWING_WIDTH + 2],
         line3[DRAWING_WIDTH + 2],
         line4[DRAWING_WIDTH + 2],
         line5[DRAWING_WIDTH + 2],
         line6[DRAWING_WIDTH + 2],
         line7[DRAWING_WIDTH + 2];
};

void printHangman(Drawing* drawing);
void resetHangman(Drawing* drawing);
void setMistakeCount(Drawing* drawing, int guessesLeft);
void setMistakeCount1(Drawing* drawing);
void setMistakeCount2(Drawing* drawing);
void setMistakeCount3(Drawing* drawing);
void setMistakeCount4(Drawing* drawing);
void setMistakeCount5(Drawing* drawing);
void setMistakeCount6(Drawing* drawing);
void setMistakeCount7(Drawing* drawing);
void setMistakeCount8(Drawing* drawing);
void setMistakeCount9(Drawing* drawing);
void setDefeat(Drawing* drawing);

#endif
