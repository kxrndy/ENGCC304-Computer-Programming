#include <stdio.h>
#include <string.h>

void demo1(){
  char str[] = "30,150,20";
  char *delim = ",";
  char *token ;
  token = strtok(str, delim);
  
  // printf(" %s year , %s months", token);

   while ( token != NULL ){
      printf(" %s baht\n", token);
    token = strtok(NULL, delim);
  } 
}

int main(){
  demo1();
  return 0 ;
}