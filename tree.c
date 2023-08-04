#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Represent a node of binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Represent the root of binary tree
struct node *root = NULL;


struct node *ins(int data)
{
    // Create a new node
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

// Represent a queue
struct queue
{
    int front, rear, size;
    struct node **arr;
};

// createQueue() will create a queue
struct queue *createQueue()
{
    struct queue *newQueue = (struct queue *)malloc(sizeof(struct queue));

    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;

    newQueue->arr = (struct node **)malloc(100 * sizeof(struct node *));

    return newQueue;
}

// Adds a node to queue
void enqueue(struct queue *queue, struct node *temp)
{
    queue->arr[queue->rear++] = temp;
    queue->size++;
}

// Deletes a node from queue
struct node *dequeue(struct queue *queue)
{
    queue->size--;
    return queue->arr[++queue->front];
}

// insertNode() will add new node to the binary tree
void insertNode(int data)
{
    // Create a new node
    struct node *newNode = ins(data);
    // Check whether tree is empty
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    else
    {
        // Queue will be used to keep track of nodes of tree level-wise
        struct queue *queue = createQueue();
        // Add root to the queue
        enqueue(queue, root);

        while (true)
        {
            struct node *node = dequeue(queue);
            // If node has both left and right child, add both the child to queue
            if (node->left != NULL && node->right != NULL)
            {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else
            {
                // If node has no left child, make newNode as left child
                if (node->left == NULL)
                {
                    node->left = newNode;
                    enqueue(queue, node->left);
                }
                // If node has no right child, make newNode as right child
                else
                {
                    node->right = newNode;
                    enqueue(queue, node->right);
                }
                break;
            }
        }
    }
}

// inorder() will perform inorder traversal on binary search tree
void inorderTraversal(struct node *node)
{
    // Check whether tree is empty
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    {

        if (node->left != NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if (node->right != NULL)
            inorderTraversal(node->right);
    }
}


int main()
{
    insertNode(1);
    printf("Binary tree after insertion: \n");
    inorderTraversal(root);

    insertNode(2);
    insertNode(3);
    printf("\nBinary tree after insertion: \n");
    inorderTraversal(root);

    insertNode(4);
    insertNode(5);
    printf("\nBinary tree after insertion: \n");
    inorderTraversal(root);

    insertNode(6);
    insertNode(7);
    printf("\nBinary tree after insertion: \n");
    inorderTraversal(root);

    return 0;
}