// Create a binary tree and find the traversal using recursion
#include <stdio.h>
#include <stdlib.h>

// ONLY FOR VS CODE OR TERMINAL USERS :- input.txt file is used to give input so that we do not have to type again again

// Sample Input : 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

// Node is a user defined data type like we have predefined int, char and bool
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// createNode function is used to create a new node this reduces writing of code repeatedly
struct node *createNode(int d)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;
}

// Recursive fucntion for creating tree
struct node *createTree()
{
    // input value
    int d;
    scanf("%d", &d);
    // check if it is equal to -1 than NULL is returned
    if (d == -1)
    {
        return NULL;
    }
    // If not -1 
    // we create the root node and ask recursion to make the left and right subtree
    struct node *root = createNode(d);
    root->left = createTree();
    root->right = createTree();

    return root;
}

// Structure of recursive funtion :-
/* 
datatype funtion_name(){
    // Base Case
    Base case condition is used to tell recursion where to stop otherwise it keeps on running
    // Recursive Case
    Actual work that is to be performed is defined here
}
*/
// In all three printing functions we only print root node rest of the tree is printed by recursion
// PreOrder function will always be of void type as it is not returning anything just printing the tree
// PreOrder printing order :- N(root) L R
void preorder(struct node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// InOrder function will always be of void type as it is not returning anything just printing the tree
// InOrder printing order :- L N(root) R
void inorder(struct node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// PostOrder function will always be of void type as it is not returning anything just printing the tree
// PostOrder printing order :- L R N(root)
void postorder(struct node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main Function
int main()
{

    struct node *root = createTree();
    printf("\nPREORDER: \n");
    preorder(root);
    printf("\nINORDER:\n");
    inorder(root);
    printf("\nPOSTORDER: \n");
    postorder(root);
    return 0;
}