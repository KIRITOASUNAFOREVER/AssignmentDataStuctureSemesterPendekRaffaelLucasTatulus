#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct storage{
    int qty;
    char name[25];
    char category[20];
    struct storage *left;
    struct storage *right;
};

struct storage *newNode(const char *name, const char *category){
    struct storage *curr = (struct storage *) malloc(sizeof(struct storage));
    curr->qty = 1;
    strcpy(curr->name, name);
    strcpy(curr->category, category);
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

struct storage *insert(struct storage *root, const char *name, const char *category){
    // [10%] (1) INSERT YOUR CODE HERE
    if (root == NULL){
		return(newNode(name, category));
	}
	if(strcmp(name , root->name) == 0) {
		root->qty += 1;
		return root;
	}else if (strcmp(name, root->name) < 0){
		root->left = insert(root->left, name, category);
	}else if (strcmp(name, root->name) > 0){
		root->right = insert(root->right, name, category);
	}
	
    return root;
}

struct storage *predecessor(struct storage *root){
    // [5%] (2) INSERT YOUR CODE HERE
    struct storage* current = root->left;
    while (current->right != NULL){
    	current = current->right;
	}
	return current;
}

struct storage *successor(struct storage *root){
    // [5%] (3) INSERT YOUR CODE HERE
    struct storage* current = root->right;
    while (current->left != NULL){
    	current = current->left;
	}
	return current;
}

struct storage *deleteKey(struct storage *root, const char *name){
    // [15%] (4) INSERT YOUR CODE HERE
    int check = 0;
    if (root == NULL){
        return root;
	}
  
    if (strcmp(name, root->name) < 0){
    	root->left = deleteKey(root->left, name);
	}else if(strcmp(name, root->name) > 0){
        root->right = deleteKey(root->right, name);
	}else if(strcmp(name, root->name)==0){
		root->qty = root->qty - 1;
		return root;
	}else{
    	if( (root->left == NULL) || (root->right == NULL) ){
            struct storage *temp = root->left ? root->left : root->right;
            if (temp == NULL){
                temp = root;
                root = NULL;
            }else{
            	*root = *temp;
			}
            free(temp);
        	check = 1;
		}
        else
        {
            struct storage* temp = successor(root->right);
            strcpy(root->name, temp->name);
            strcpy(root->category,temp->category);
            root->right = deleteKey(root->right, temp->name);
        }
    }
    return root;
}

void inOrder(struct storage *root){
    if(root){
    // [5%] (5) INSERT YOUR CODE HERE
		inOrder(root->left);
		if(root->qty > 0){
			printf("%s (%d)\n",root->name,root->qty);
		}
		inOrder(root->right);
    }
}

struct storage *freeAll(struct storage *root){
    if(root){
        freeAll(root->left);
        freeAll(root->right);
        free(root);
        root = NULL;
    }
    return root;
}

int main(){
    struct storage *root = NULL;

    root = insert(root, "Sate Ayam", "Daging");
    root = insert(root, "Gulai Kambing", "Daging");
    root = insert(root, "Kangkung", "Sayuran");
    root = insert(root, "Coca Cola", "Minuman");
    root = insert(root, "Sate Kambing", "Daging");
    root = insert(root, "Opor Ayam", "Daging");
    root = insert(root, "Sprite", "Minuman");
    root = insert(root, "Fanta", "Minuman");
    root = insert(root, "Ayam Kalasan", "Daging");
    root = insert(root, "Kangkung", "Sayuran");
    root = insert(root, "Fanta", "Minuman");
    root = insert(root, "Coca Cola", "Minuman");
    root = insert(root, "Opor Ayam", "Daging");

    printf("Predecessor : %s\n", predecessor(root)->name);
    printf("Successor : %s\n", successor(root)->name);

    printf("\nInorder : \n");
    inOrder(root);

    root = deleteKey(root, "Sate Ayam");
    root = deleteKey(root, "Gulai Kambing");
    root = deleteKey(root, "Coca Cola");
    root = deleteKey(root, "Opor Ayam");
    root = deleteKey(root, "Sate Kambing");
    root = deleteKey(root, "Ayam Kalasan");
    printf("\nAfter Del Inorder : \n");
    inOrder(root);
    
    freeAll(root);
    return 0;
}
