#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define STRLEN_MAX 256

//Global variables
int cod = 0;
int option = 0;
int value = 0;
char name[STRLEN_MAX];

typedef struct records{
   int code; //autoincrement id
   char name[STRLEN_MAX];
   struct records *next; //list pointer
}records;

struct records *start, *auxiliar, *end; //statement of the linked list pointers

int main() {
   //Locale for brazilian names
   setlocale(LC_ALL, "pt_BR");

   // Start Pointers
   start = NULL;
   auxiliar = NULL;
   end = NULL;

   system("clear");

   //Call menu
   menu();
   return 0;
}

void menu(){

   do {
      printf("%s\n", "1.\tAppend");
      printf("%s\n", "2.\tIn");
      printf("%s\n", "3.\tIndex");
      printf("%s\n", "4.\tRemove");
      printf("%s\n", "5.\tShow");
      printf("%s\n", "6.\tExit system");

      printf("%s\n", "choose");
      scanf("%i", &option);

   } while(option > 7);

      switch (option) {
         case 1:
            append();
            break;
         case 2:
            in();
            break;
         case 3:
            _index();
            break;
         case 4:
            remove();
            break;
         case 5:
            show();
            break;
         case 6:
            exit(0);
      }

}

//Funtion to append element to list (memory allocation)
void append(){

   if(start == NULL){
      auxiliar = (records*)malloc(sizeof(records));
      auxiliar -> next = NULL;
      start = auxiliar;
      end = auxiliar;
      cod ++; //code of struct

      enterdata();

   } else {
      auxiliar = (records*)malloc(sizeof(records));
      end -> next = auxiliar;
      auxiliar -> next = NULL;
      cod ++; //code of struct

      enterdata();
   }

}

//Function to recive values
void enterdata(){

   printf("%s\n", "Write the name:");
   scanf("%s",&auxiliar->name);
   auxiliar->code = cod;

   menu();
}

//Boolean (countains)
void in(){
   auxiliar = start;

   printf("%s\n", "insert the code:");
   scanf("%i", &value);

   while (auxiliar != NULL) {

      if (auxiliar->code == value){
         printf("%s:\t%s\n", "True", auxiliar->name);
         auxiliar = auxiliar -> next;

      } else {
         auxiliar = auxiliar -> next;
      }
   }
   menu();
}

//return first position (if name == search)
void _index(){
   auxiliar = start;

   printf("%s\n", "insert the name:");
   scanf("%s", &name);

   while (auxiliar != NULL) {

      if (auxiliar->name == name){
         printf("%s\n", auxiliar->code);

         break;
      } else {
         auxiliar = auxiliar -> next;
      }
   }
   printf("%s\n", "Name don't exists");
}

//Remove only list element
void remove(){


}
//return all elements
void show(){

}
