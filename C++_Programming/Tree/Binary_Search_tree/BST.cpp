#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    // Allocate memory for new node
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void print(struct node *node)
{
    if (node == NULL)
        return;

    // Print (N)
    printf("%d", node->data);
    // Recurse on left subtree (L)
    print(node->left);
    // Recurse on right subtree (R)
    print(node->right);
};

struct node *search(struct node *root, int query)
{
    // Base case: root is null or key is present at root
    if (root == NULL || root->data == query)
        return root;

    // If query is less than root’s key, recurse on left subtree, else recurse on right subtree (R)
    if (query < root->data)
        return search(root->left, query);
    else
        return search(root->right, query);
}

// function to insert a new node with given key in BST
struct node *insert(struct node *node, int key)
{
    // If we reach a NULL pointer, this is the place to insert
    if (node == NULL)
        return newNode(key);
    // Recur down the tree
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        printf("Key %d is already present!\n", key);
    // Return the (unchanged) node pointer
    return node;
}

void printTree(struct node *node, int level)
{
    if (node == NULL)
        return;

    printTree(node->left, level + 1);
    // Print node key and level
    printf("% d[% d]", node->data, level);
    printTree(node->right, level + 1);
}

int getMax(struct node *node)
{
    while (node->right != NULL)
        node = node->right;
    return node->data;
}

struct node *getMin(struct node *node)
{
    if (node->left != NULL)
        return getMin(node->left);
    else
        return node;
}

struct node *Delete(struct node *node, int key)
{
    // key not found
    if (node == NULL)
    {
        return NULL;
    }
    // otherwise, recur down the tree, if smaller then go left, otherwise right
    if (key < node->data)
        node->left = Delete(node->left, key);
    else if (key > node->data)
        node->right = Delete(node->right, key);
    // if key is same as root->key, then this is the node to be deleted
    else
    {
        // if leaf node, remove it
        if ((node->left == NULL) && (node->right == NULL))
        {
            free(node);
            return NULL;
        }
        // if node with left child only
        else if ((node->left != NULL) && (node->right == NULL))
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        // if node with right child only
        else if ((node->left == NULL) && (node->right != NULL))
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        // if two children: replace with min node in right subtree
        if ((node->left != NULL) && (node->right != NULL))
        {
            struct node *temp = getMin(node->right);
            node->data = temp->data;
            // Delete the min node in the right subtree
            node->right = Delete(node->right, temp->data);
        }
    }
    return node;
}

int main()
{
    // create root with data=1
    struct node *root = newNode(1);
    // left and right child of the root
    root->left = newNode(2);
    root->right = newNode(3);
    // left-left child of the root
    root->left->left = newNode(4);

    return 0;
}