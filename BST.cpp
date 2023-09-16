#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *root = NULL;

Node *insertNode(Node *root, int data)
{
    // assigning memeory
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // assigning values
    newNode->data = data;
    // making the pointers null
    newNode->left = newNode->right = NULL;
    // checking if the root is null
    if (root == NULL)
    {
        root = newNode;
        // returning the node to keep track of the root
        return newNode;
    }
    // checking if the value is lesser
    if (data < root->data)
    {
        // going to left until we found the left as null
        root->left = insertNode(root->left, data);
    }
    // else the value is greater
    else
    {
        // going to right until we found right is null
        root->right = insertNode(root->right, data);
    }
}
// inorder traversing
void inOrder(Node *root)
{
    // if root is null then return means no more values are remaining
    if (root == NULL)
        return;
    // in inorder we access the left values first
    inOrder(root->left);
    // then the root value is written
    cout << root->data << " ";
    // at last we access the right values
    inOrder(root->right);
}
// postorder traversing
void postOrder(Node *root)
{
    // if root is null then return means no more values are remaining
    if (root == NULL)
    {
        return;
    }
    // in postorder left value is accessed first
    postOrder(root->left);
    // then the right value
    postOrder(root->right);
    // atlast the root value
    cout << root->data << " ";
}
// preorder traversing
void preOrder(Node *root)
{
    // if root is null means no more values are remaining
    if (root == NULL)
    {
        return;
    }
    // we access the root value first
    cout << root->data << " ";
    // then the left value
    preOrder(root->left);
    // then the right value
    preOrder(root->right);
}

int main()
{
    // initializing root as null
    struct Node *root = NULL;
    // storing the first inserted value in root to keep the track for later operations
    root = insertNode(root, 50);
    // then adding the values accordingly no need to tore these values separately
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "InOrder traversal of BST after insertion:\n";
    inOrder(root);
    cout << endl;
    cout << "PostOrder traversal of BST after insertion:\n";
    postOrder(root);
    cout << endl;
    cout << "PreOrder traversal of BST after insertion:\n";
    preOrder(root);
    cout << endl;
    return 0;
}