#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
	char name[10];
	int value;
	struct LinkedList *root;
	struct LinkedList **children;
};

int get_val(char *in) {
	int result = 0;
	int i = 1;
    while ((in[i] >= '0') && (in[i] <= '9'))
    {
      result = (result * 10) + ((in[i]) - '0');
      i++;
    }

    return result;
}

int perform_check(struct LinkedList *root) {
	int result = 0;
	int i = 0;
	int val[3000] = {-1};
	while (root->children[i] != NULL) {
		val[i] = perform_check(root->children[i]);
		i++;
	}

	int prev = 0;
	for(int j = 0; j < i; j++) {
		result += val[j];
		if (j == 0) {
			prev = val[j];
		} else {
			if (prev != val[j]) {
				printf("Something is wrong in %s with value %d\n", root->name, root->value);
				for(int j = 0; j < i; j++) {
					printf("%s(%d) ", root->children[j]->name, val[j]);
				}
				printf("\n");
				break;
			}
		}
	}

	return (result + root->value);

}


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
				int val = 0;
				
				val = get_val(arr);
				root_item->value = val;
				//printf("value is %d from %s\n", val, arr);

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

	printf("Performing checking\n");
	int test = perform_check(dummy_root);


	return 0;

}