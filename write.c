#include <stdio.h>
#include <sqlite3.h>

int writetodb () {

  printf( "Hello World! - From C\n");

  const char* fname = "employee.db";
  FILE *fileptr = fopen(fname, "w"); //open file also used for creating file 
  if(fileptr == NULL){
    fprintf(stderr, "Can't find database\n");
    fclose(fileptr);
    return 1;  
  }
  // database pointer
  sqlite3 *db = NULL;
  int returnnum = sqlite3_open("employee.db", &db);
  if(returnnum != SQLITE_OK) {
    fprintf(stderr, "Open failed: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("Database opened.\n");
  sqlite3_close(db);
  
  fclose(fileptr); //close file
  return 0;
}
