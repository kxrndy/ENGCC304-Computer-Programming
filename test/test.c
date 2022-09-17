#include <stdio.h>
#include <math.h>

struct employee_info{
  char name[ 100 ] ;
  float salary ;
  int duration ;
}typedef employee_info ;

int input_em_data( int index, employee_info em[] ) {
  char name[ 100 ] ;
  getchar() ;
  printf( "Employee Name : " ) ;
  gets( em[ index ].name) ;
  printf( "Salary (Bath/Month) : " ) ;
  scanf( " %f" , &em[index].salary ) ;
  printf( "Duration (Year) : " ) ;
  scanf( " %d" , &em[index].duration ) ;
}

int input_em( char confrim_em, int index, employee_info em[] ){
  switch ( confrim_em ) {  
    case 'y' :
      input_em_data ( index, em );
      return 1 ;
      break ;
    case 'n' :
      return 0 ;
      break ;
  }
}

void ms( employee_info em[], int index ){
  int count = 0 ;
  int total = 0 ;
  int msi = -1 ;

  while( count < index ) {
    int im = total < em[ count ].salary;
    switch ( im ){
    case 1 :
      msi = count ;
      total = em[ count ].salary ;
      break ;
    }
    count++ ;
  }
    printf( "** Most Salary in this business **\n" ) ;
  printf( "Name : %s (%d Years)\n" , em[ msi ].name , em[ msi ].duration ) ;  
    printf( "Salary : %.2f baht\n" , em[msi].salary ) ;
  }

float sum( employee_info em[], int index ){
  float total = 0 ;
  int count = 0 ;
  while( count < index ) {
    total += em[ count ].salary ;
    count++  ;
  }
  return total ;
}

void summary ( int index, employee_info em[] ) {
  float total = sum( em, index ) ;
  float avg = total / index ;

  printf( "  : %.2f baht\n", avg ) ;
  printf( "Payment of every month :  %.2f baht\n", total ) ;
  ms( em , index ) ;
}

int check_increment( int check_inc ){
  switch ( check_inc ) {
  case 1 :
    return 1 ;
  default :
    return 0 ;
  }
}

int main() {
  int dyw = 1 ;
  int index = 0 ;
  employee_info em[ 100 ] ;
  
  while ( dyw ) {
    char confrim ;
      printf( "Do you want to Enter Employee Information? (y/n) : " ) ;
    scanf( " %c",&confrim ) ;
    dyw = input_em( confrim, index, em ) ;
    index += check_increment( dyw ) ;
  }

  summary( index, em ) ;

  return 0 ;
}
