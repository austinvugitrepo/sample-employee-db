#include <stdio.h>

int writetodb () {

  printf( "Hello World! - From C\n");

  const char* fname = "employee.db";
  FILE *fileptr = fopen(fname, "w"); //open file also used for creating file 
  if(fileptr == NULL){
    fprintf(stderr, "Can't find database\n");
    fclose(fileptr);
    return 1;  
  }

  fclose(fileptr); //close file
  return 0;
}
