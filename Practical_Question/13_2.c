#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find the middle of the linked list
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct Node* secondHalfStart = reverseList(slow);

    // Step 3: Compare the first and second halves
    struct Node* firstHalfStart = head;
    struct Node* secondHalfIter = secondHalfStart;
    bool isPalindrome = true;
    while (secondHalfIter != NULL) {
        if (firstHalfStart->data != secondHalfIter->data) {
            isPalindrome = false;
            break;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalfIter = secondHalfIter->next;
    }

    // Optional: Step 4: Restore the original list
    reverseList(secondHalfStart);

    return isPalindrome;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes to create a palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}
