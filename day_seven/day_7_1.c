#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
	char name[10];
	struct LinkedList *root;
	struct LinkedList **children;
};

int update_root(struct LinkedList *root, struct LinkedList *root_item, char *name) {

	int found = 0;
	int i = 0;

	while (!found && root->children[i] != NULL) {
		// Check the name of its children
		//printf("Comparing %s at root %s\n", name, root->children[i]->name);
		if (strcmp(root->children[i]->name, name) == 0) {
			found = 1;
			// Remove for children and then update the root of the children
			struct LinkedList *temp = root->children[i];
			int j = i;
		//	printf("Found %s at root %s\n", name, root->name);
			while (root->children[j+1] != NULL) {
			    root->children[j] = root->children[j+1];
			    j++;
			}
			root->children[j] = NULL;
			temp->root = root_item;
			int k = 0;
			while (root_item->children[k] != NULL) {
			    k++;
			}
			root_item->children[k] = temp;
			
		} else {
			found = update_root(root->children[i], root_item, name);
		}
		i++;
	}

	return found;
}

int find_node(struct LinkedList *root, char *name, struct LinkedList **result) {
    
    int i = 0;
    int found = 0;
    
    if (strcmp(root->name, name) == 0) {
        found = 1;
        *result = root;
    }
    
    while (!found && root->children[i] != NULL) {
        found = find_node(root->children[i], name, result);
        i++;
    }
    return found;
    
}

void dbg_print(struct LinkedList *root) {
    int i = 0;
    printf("%s ", root->name);
    while (root->children != NULL && root->children[i] != NULL) {
        dbg_print(root->children[i]);
        i++;
    }
}

int main() {

	struct LinkedList *dummy_root;
	char arr[10];
	int end;
	char ch;
	dummy_root = (struct LinkedList*) malloc (sizeof(struct LinkedList));
	dummy_root->children = malloc (sizeof(struct LinkedList) * 3000);
	int i = 0;
	int state = 0;
	struct LinkedList *root_item;
    int temp = 0;
    struct LinkedList *new_item;
    
	do {
		do {
			end = scanf("%s%c", arr, &ch);
			//printf("Scanning %s, %d, %c\n", arr, end, ch);

			if (arr[0] == '(') {	
				// do nothing
			} else if (arr[0] == '-') {
				state = 1;
					//printf("root item is %s\n", root_item->name);

			} else {
				switch (state) {
					case 0:
					    //printf("What %s\n", root_item->name);
					    if (!find_node(dummy_root, arr, &root_item)) {
    						new_item =  malloc (sizeof(struct LinkedList));
    						strcpy(new_item->name, arr);
    						new_item->root = dummy_root;
    						new_item->children = malloc (sizeof(struct LinkedList) * 3000);
    						//dummy_root->children[i++] = new_item;
    						
    						int k = 0;
                			while (dummy_root->children[k] != NULL) {
                			    k++;
                			}
                			dummy_root->children[k] = new_item;
    						
    						root_item = new_item;
					    }
					    //printf("What2 %s\n", root_item->name);
    					break;

					case 1:
					     //dbg_print(dummy_root);
						// Update root
						if (arr[strlen(arr) - 1] == ',') {
						    arr[strlen(arr) - 1] = '\0';
						}
    						temp = update_root(dummy_root, root_item, arr);
    						
    						if (!temp) {
                        		// Make new node
                        		struct LinkedList *new_item2 = (struct LinkedList*) malloc (sizeof(struct LinkedList));
                        		new_item2->children = malloc (sizeof(struct LinkedList) * 3000);
                        		strcpy(new_item2->name, arr);
                        		//printf("root item is %s\n", root_item->name);
                        		new_item2->root = root_item;
                        		int k = 0;
                    			while (root_item->children[k] != NULL) {
                    			    k++;
                    			}
                    			root_item->children[k] = new_item2;
                        	}
                        	
						
						if (ch == '\n') {
						   
							state = 0;
						}
				}
			}
		} while (ch != '\n' && end != EOF);
	} while (end != EOF);
    // dbg_print(dummy_root);
	if (dummy_root->children[1] != NULL) {
		printf("something is wrong\n");
	} else {
		printf("\nRoot is %s\n", dummy_root->children[0]->name);
	}

	return 0;

}