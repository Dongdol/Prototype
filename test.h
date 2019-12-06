#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curses.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#define STAGE1_WORD_DOWN_TIME 5
#define WORD_MAX 50
#define STAGE1_MODE 1
#define STAGE2_MODE 2
#define STAGE3_MODE 3
int MODE=STAGE1_MODE;
using namespace std;

typedef struct WordNode* WordNodePointer;
typedef struct WordNode
{
    int row, col;
    char str[WORD_MAX];
    WordNodePointer up, down;

}WordNode;

WordNodePointer ptr;
list<WordNodePointer> WordList;
list<WordNodePointer>::iterator Iter;


class Rain
{
    private:
      char enter[30] = {0};
      int enter_num;
      
      char hp_Bar[10];
      char score_Bar[10];
      char enter_Bar[20] = "	| Enter | : ";
     
  
      int input;

    public:
      void GameComplete();
      void StageChange();
      void Print_UI(); 
      void FindWords(char* str);
      void *Game_Board(void *);
      void Game_Start();
      void Draw(int row, int col, char *str);
      void Print_Words();
      char **Get_Words();
      void Down_Words();
      WordNodePointer Initnode(void);
      WordNodePointer CreateWord(char *str);
      void CreateList();
      void GameOver();
      char *Return_Str();
};
typedef void *(*THREADFUNCPTR)(void *);

char* Return_Str();
void Blank_OutputWord();
void Blank_OutputWord_All();

//Fruit
char* STAGE1[] = {"Banana","Mango","Apple","Watermelon","Orange","Strawberry","Durian","Grape","Citrus","Mangosteen","Plum","Peach","Pineapple","Coconnut","Sugarcane","Blueberry","Pear","flg","Persimmon","Pomegranate"};
//Music
char* STAGE2[] = {"You And I", "Reality", "Workerholic", "Blueming", "Mirotic","Yes or Yes", "Heartshaker", "IDOL","Travel","Good Day","Attention","All falls down","Despacito","Shape of you","DINOSAUR","UmpahUmpah"
 ,"Viva La Vida","What the hell","Alone","2002","Lost Stars","Love$ick","7rings","Speechless","Handclap","We all lie","The Ocean","Move Like Jagger","Reminiscence","HymnForTheWeekend" };
//Disciplines
char* STAGE3[] = {"Mathemtics","Physics", "Quantum Mechanics","Apparel study","Religious studies","Food and Nutrition",
"Quantum Physics","Linguistics","Material engineering", "Chemistry", "Science of law", "Computer Science","Philosophy","Economics","Urban engineering"
,"literature","Psychology","Korean Medicine","Earth science","Pedagogy Education","Astronomy","Medicine","Architecture","Biology","Archaeology",
"Mechanical engineering","Dentistry","Sociology","Humanities","Natural science"};

 pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


int score = 0;
int hp = 20;
char *stageName = new char[10];

#endif