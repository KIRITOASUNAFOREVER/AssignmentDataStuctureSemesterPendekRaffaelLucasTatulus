#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Employee{
	char name[20];
	char jobPos[15];
	int grade;
	int age;
	Employee *next;
}*head = NULL, *tail = NULL;

bool isValid(char *name, char *jobPos, int grade, int age){
	// [15%] (1) INSERT YOUR CODE HERE
   struct Employee *emp=head;
	while(emp!=NULL){
       if((strcmp(name,emp->name)==0)&&(strcmp(jobPos,emp->jobPos)==0)&&(grade==emp->grade)&&(age==emp->age)){
           return 0;
       }
       emp = emp->next;
   }
   return 1;
}

void push(char *name, char *jobPos, int grade, int age){
	struct Employee *curr = (struct Employee *) malloc(sizeof(Employee));
	// [10%] (2) INSERT YOUR CODE HERE
	if(isValid(name,jobPos,grade,age)){  
       strcpy(curr->name,name);
       strcpy(curr->jobPos,jobPos);
       curr->grade = grade;
       curr->age = age;
      
       if(head==NULL || tail==NULL){  
           curr->next = NULL;
           head=tail=curr;
       }else{
	       curr->next = head;
	       head = curr;
       }
	}else{
	    free(curr);
		printf("The inputted data is duplicated!\n");
	}
}

void pop(){
	struct Employee * curr = head;
	// [15%] (3) INSERT YOUR CODE HERE
	curr = tail;
   if(head==NULL || tail==NULL){  
       printf("the list is empty!\n");
   }else{
       if(head==tail){
           head=tail=NULL;
       }else{
           struct Employee * tmp = head;
           while(tmp->next!=tail){
               tmp=tmp->next;
           }
           tail = tmp;
           tail->next=NULL;
       }
       free(curr);
   }
} 

void printAll(){
	printf("\n\n");
	struct Employee * curr = head;
	int empCtr = 0;
	if(!curr){
	    printf("the list is empty!");
	}else{
		// [10%] (4) INSERT YOUR CODE HERE
       printf("=======================================================\n");
       printf("| %-5s | %-20s | %7s | %-5s |\n","Name","Job Position","Grade","Age");
       printf("=======================================================\n");
       while(curr!=NULL){
           printf("| %-5s | %-20s | %7d | %-5d |\n",curr->name,curr->jobPos,curr->grade,curr->age);
           empCtr++;
           curr = curr->next;
       }
       printf("=======================================================\n");
       printf("Total Employee : %d\n",empCtr);
       printf("=======================================================\n");
	}
}

int main(){
	pop();
	printAll();
	push("Hanry", "Supervisor", 12, 27);
	push("Yen", "Manager", 13, 40);
	pop();
	push("Derwin", "Manager", 15, 31);
	push("Andry", "Manager", 15, 30);
	pop();
	push("Saka", "Manager", 15, 32);
	pop();
	push("Afan", "Manager", 16, 35);
	push("Fredy", "Senior Manager", 18, 45);
	pop();
	printAll();
	return 0;
}
