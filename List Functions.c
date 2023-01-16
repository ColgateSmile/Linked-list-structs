#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to remove a node from the beginning of the list
struct Node* removeNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to remove the last node from the list
struct Node* remove_last_node(struct Node* head){
    if (head == NULL) {
        printf("List is empty.\n");
    } else if(head->next == NULL){
        free(head);
        head = NULL;
    }else{
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    return head;
}

// Function to count the length of the list
int count(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to print the list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int hasCycle(struct Node* head)
{


    struct Node *check, *stand;
    int NodeCounter=0;

    //in case of an empty list or an 1 node list//
    if (head == NULL || head->next == NULL){
         return 0;
    }


    stand = head->next;
    check = head->next->next;


    while (check != NULL && check->next != NULL)
    {

        //if so there is a loop in the list check will be pointing at the same node as stand//
        if (check == stand){
             return 1;
        }


        NodeCounter++;//checks how many nodes from head i have passed//
        stand = stand->next;
        check = check->next->next;
    }

    return 0;
}




int main() {
    struct Node* head = NULL;
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    int check = hasCycle(head);

    if(check){
        printf("\n the list has a cycle! \n");
    }
    printf("the list has NO! cycle!  \n\n");
    printf("Length of list: %d\n\n", count(head));
    printf("List is:");

    print_list(head);


    head = removeNode(head);
    // List now contains: [2, 1]

    printf("List after remove is:");

    print_list(head);

    head = remove_last_node(head);
    printf("List after removing last node: ");
    print_list(head);
    return 0;
}
