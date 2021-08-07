#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define tableSize 29

struct storage{
	int key;
	int qty;
	char name[25];
	char category[20];
	struct storage *next;
};

struct hashPool{
	struct storage *head;
	struct storage *tail;
};
struct hashPool hashTable[tableSize];

void init(){
	for(int i=0; i<tableSize; i++){
		hashTable[i].head = NULL;
		hashTable[i].tail = NULL;
	}
}

int generateKey(char *name){
	int key = 0;
	int len = strlen(name);
	int sum = 0;
	for(int i=0; i<len; i++){
		sum += (int)(name[i]);
	}
	key = sum%tableSize;
	return key;
}

struct storage *newNode(char *name, char *category){
	struct storage *curr = (struct storage *)malloc(sizeof(struct storage));
	curr->key = generateKey(name);
	curr->qty = 1;
	strcpy(curr->name, name);
	strcpy(curr->category, category);
	curr->next = NULL;
	return curr;
}

struct storage *searchNode(struct storage *node){
	struct storage *search= hashTable[node->key].head;
	struct storage *temp = NULL;
	// [10%] (2) INSERT YOUR CODE HERE
	temp = search;
	while(temp!=NULL && strcmp(temp->name, node->name)){
		temp = temp->next;
	}
	return temp;
}

void push(struct storage *node){
	// [10%] (3) INSERT YOUR CODE HERE
	int key = node->key;
	if(hashTable[key].head == NULL){
		hashTable[key].head = hashTable[key].tail = node;
		return;
	}
	struct storage *tmp = searchNode(node);
	if(tmp==NULL){
		hashTable[key].tail->next = node;
		hashTable[key].tail = node;
	}
	else
		tmp->qty++;
}

void printAll(){
	for(int i=0; i<tableSize; i++){
		printf("[%2d] : ", i);
		struct storage *curr = hashTable[i].head;
		while(curr != NULL){
			printf("%-10s (%-3d) -> ", curr->name, curr->qty);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main(){
	init();
	push(newNode("Sate Ayam", "Daging"));
	push(newNode("Sate Ayam", "Daging"));
	push(newNode("Gulai Kambing", "Daging"));
	push(newNode("Kangkung", "Sayuran"));
	push(newNode("Sate Ayam", "Daging"));
	push(newNode("Coca Cola", "Minuman"));
	push(newNode("Sate Ayam", "Daging"));
	push(newNode("Coca Cola", "Minuman"));
	push(newNode("Gulai Kambing", "Daging"));
	push(newNode("Sate Kambing", "Daging"));
	push(newNode("Opor Ayam", "Daging"));
	push(newNode("Sate Kambing", "Daging"));
	push(newNode("Sate Kambing", "Daging"));
	printAll();
	return 0;
}
