#include <stdio.h>

int main(int arg, char* argc[]){
  	printf("Hello assignment1.\n");
	printf("int: %d  \n", sizeof(int));
	printf("int *: %ld \n", sizeof(int*));
	printf("long: %ld   \n", sizeof(long));
	printf("double *: %ld  \n", sizeof(double*));
	printf("char **: %ld   \n", sizeof(char**));

  return 0;
}
