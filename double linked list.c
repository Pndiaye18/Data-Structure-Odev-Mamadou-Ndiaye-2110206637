#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
/* insertion at the begening */
void insertBegin(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

	return 0;
}

/* insertion at the end */

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct));
    struct Node* temp = *head;

    *(newNode->data) = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
/* traversal */
void displayForward(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
/* delete a node with a given values */ 
void deleteValue(struct Node** head, int value) {
    struct Node* temp = *head;

    if (temp == NULL)
        return;

    // If head node holds the value
    if (temp->data == value) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
        return;  // value not found

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    free(temp);
}

