#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employees {
    char name[100] ;
    char date[100] ;
    char not_num[100];
    int days_work ;
    
} typedef  E ;

int cal_age_work ( E e[] , int index ) {
  int translay[100][100] ;
  int count = 0 ;
  for( int i = 0; i < index;  i++ ) {
    char *date = e[i].date ;
    char *piece = strtok( date,"-" ) ;
    while ( piece != NULL ){
      translay[i][count] = atoi (piece) ;
      piece = strtok(NULL, "-") ;
      count++ ;
    } // End while
    count = 0 ;
  } // end for
  for(int i = 0 ; i < index ; i++) {
    e[i].days_work = ( 2018-translay[i][0])*365+(6-translay[i][1])*30+(21-translay[i][2] ) ;
    printf ( "%s %d Years, %d Months\n", e[i].name , e[i].days_work/365 , (e[i].days_work%365)/30 ) ;
  } // End for
} // end cal_age_work

int MaxandMin (E e[] , int index) {
  int maximum = -9999999 ;
  int minimum = 9999999 ;
  char *maxname ;
  char *minname ;
  for (int i = 0; i < index; i++) {
    if(e[i].days_work > maximum){
      maximum = e[i].days_work ;
      maxname = e[i].name ;
    } // end if

    if(e[i].days_work < minimum) {
      minimum = e[i].days_work ;
      minname = e[i].name ;
    } // end if
  } // end for
  printf ("Max : %s [%d Years, %d Months]\n" , maxname, maximum/365, maximum%365/30);
  printf ("Min : %s [%d Years, %d Months]\n" , minname, minimum/365, minimum%365/30);
} // end MaxandMin

int FileManager (E e[100]) {
  int index = 0 ;
  FILE *fp ;
    fp = fopen ( "data.txt" , "r" ) ;
  if ( fp == NULL ) {
    printf ( "Error opening data.txt file.\n" ) ;
    exit( 0 ) ;
  }//end if

  char killer[100] ;
  fscanf(fp, "%s\t%s\t\t%s\n" , killer , killer , killer) ;

  while ( fscanf ( fp, "%s\t%s\t\t%s\n", e[index].not_num ,e[index].name, e[index].date) != EOF ) {
     printf ( "%s\t%s\t\t%s\n" , e[index].not_num , e[index].name , e[index].date) ;
     index++;
  }  //end while
  fclose ( fp );
  return index ;
} // end of function FileManager

int main() {
  E e[100];
  int total = FileManager(e) ;
  printf ("---------------------------------------------------------\n") ;
  cal_age_work ( e, total ) ;
  MaxandMin ( e , total ) ;
}