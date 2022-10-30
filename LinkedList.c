#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// This function helps us to create node so that we don't need to write code again & again
// This would prevent redundancy in our code.
struct Node *createNode(int x)
{
    // Creating a new new
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    // Assigning data to new node.
    tmp->data = x;
    // By default next of any new node should be NULL (not garbage).
    tmp->next = NULL;
}

int length(struct Node *head)
{
    // Counter initialized to zero
    int cnt = 0;
    while (head != NULL)
    {
        // increasing counter untill head reaches NULL.
        cnt++;
        head = head->next;
    }
    // Final count Returned.
    return cnt;
}

void print(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// This function inserts node by taking head as reference
void insertathead(struct Node **head, int x)
{
    //  create a new node temp
    struct Node *temp = createNode(x);
    if (head == NULL)
    {
        *head = temp;
    }
    else
    {
        // inserting the address of head in next of temp
        temp->next = *head;
        //  now make temp as new head
        *head = temp;
    }
}

struct Node *insertAtHead(struct Node *head, int x)
{
    struct Node *temp = createNode(x);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        // inserting the address of head in next of temp
        temp->next = head;
        //  now make temp as new head
        head = temp;
    }
    return head;
}

struct Node *insertAtEnd(struct Node *head, int x)
{
    // If LL is empty
    if (head == NULL)
    {
        head = createNode(x);
    }
    else
    { // If some nodes are present in LL
        struct Node *tmp = head;
        // Traverse LL till next is NULL
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        // Create a new node and add to the next of last node
        struct Node *n = createNode(x);
        tmp->next = n;
    }
    return head;
}

struct Node *insertAtMid(struct Node *head, int x, int pos)
{
    // If head is not present then add at front
    if (head == NULL)
    {
        head = insertAtHead(head, x);
    }
    else if (pos >= length(head))
    { // if length of LL is less than pos than add at last
        head = insertAtEnd(head, x);
    }
    else
    { // if pos is between the LL
        struct Node *tmp = head;
        // taking tmp to a node before the pos at which node is to be inserted
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        struct Node *n = tmp->next;
        // Create New Node
        struct Node *nn = createNode(x);
        // storing tmp -> next in nn -> next
        nn->next = n;
        // storing nn in temp -> next
        tmp->next = nn;
    }
    return head;
}

struct Node *deleteAtFront(struct Node *head)
{
    // If head is not there then NULL returned
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        // If there is only one node in the LL i.e head the free it and
        // make head = NULL so that head should not contain garbage.
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        // Move head one step ahead and the delete tmp node and return new head
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}

struct Node *deleteAtEnd(struct Node *head)
{
    // If no head than NULL returned
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        // If there is only one node in the LL i.e head the free it and
        // make head = NULL so that head should not contain garbage.
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        // We need to maintain two pointers
        // One for last node
        struct Node *c = head->next;
        // Second for second last node to make its next NULL
        struct Node *p = head;
        // Taking both pointers at end.
        while (c->next != NULL)
        {
            c = c->next;
            p = p->next;
        }
        free(c);        // free c
        p->next = NULL; // Making second last node ka next equal to NULL otherwise garbage will there
        return head;
    }
}

struct Node *deleteAtMid(struct Node *head, int pos)
{
    if (pos == 0)
    {
        head = deleteAtFront(head);
    }
    else if (pos >= length(head))
    {
        head = deleteAtEnd(head);
    }
    else
    {
        struct Node *tmp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        struct Node *n = tmp->next;
        tmp->next = n->next;
        free(n);
    }
    return head;
}

int main()
{
    struct Node *head = NULL;

    printf("value of n:\n");
    int n, i, x;
    scanf("%d", &n);

    printf("Enter the no \n");
    for (int i = 0; i < n; i++)
    {
        // printf("Enter the no \n");
        scanf("%d", &x);
        head = insertAtEnd(head, x);
    }

    print(head);

    insertAtMid(head, 6, 2);
    print(head);

    deleteAtMid(head, 4);
    print(head);

    return 0;
}
