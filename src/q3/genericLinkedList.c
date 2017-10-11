#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data , size);
  e->data = dataPointer;
  e->printFunction = printFunction;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->printFunction(current->data);
    current = current->next;
  }
}

void printChar(void* data){
  printf("%c\n", *(char*)data);
}

void printString(void* data){
  printf("%s\n", (char*)data);
}

void printInt(void* data){
  printf("%d\n", *(int*) data);
}

void printFloat(void* data){
  printf("%f\n", *(float*) data);
}

void printDouble(void* data){
  printf("%f\n", *((double*)data));
}

void printLong(void* data){
  printf("%d\n", *(long*)data);
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

 int length(listElement* list){
   	
	int n= 0;
  	listElement* current= list;
  	while(current != NULL){
    		current = current -> next;
  		  n++;
	  }             
 	 return n;
}

void push(listElement** list, char* data, size_t size){
	listElement* tmp = createEl(data, size);
	tmp -> next = *list;
	*list = tmp;
}

listElement* pop(listElement** list){
	listElement* tmp = *list;
	(*list)=(*list) -> next;
	return tmp;
}
void enqueue(listElement** list, char* data, size_t size){
	listElement* tmp = createEl(data, size);
	tmp -> next = *list;
	*list = tmp;
}

listElement* dequeue(listElement* list){
	listElement* current = list;
 	 	while(current->next->next != NULL){
  	  	current = current -> next;
  		}  
  	listElement* temp = current -> next;
  	current -> next = NULL;
  	return temp;
}

