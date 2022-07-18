#include <stdio.h>

int main(){
	int employees_id;
	int hrs;
	float salary;
	printf("Input the Employees ID (Max. 10chars) : ");
	scanf("%d", &employees_id);
	printf("Input the working hrs : ");
	scanf("%d", &hrs);
	printf("Salary amount/hr (Bath) : ");
	scanf("%f", &salary);
	
	printf("---\n");
	printf("Expected Output : \n");
	printf("Employees ID = %d \n", employees_id);
	printf("Amount/day = %.2f Bath(s)", salary*hrs);
	return 0;
}