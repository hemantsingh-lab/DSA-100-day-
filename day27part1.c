#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Add node at end
struct Node* add(struct Node* head, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLen(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
void find(struct Node* head1, struct Node* head2) {
    int len1 = getLen(head1);
    int len2 = getLen(head2);

    int diff = abs(len1 - len2);

    // Move longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Compare both
    while (head1 != NULL && head2 != NULL) {
        if (head1->val == head2->val) {
            printf("%d", head1->val);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = add(list1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = add(list2, x);
    }

    find(list1, list2);

    return 0;
}