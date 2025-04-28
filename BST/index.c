#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

// Insert operation for BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (key < root->info) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    
    return root;
}

// Find minimum value in BST
struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Find maximum value in BST
struct Node* findMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    
    return current;
}

// Delete a node from BST
struct Node* delete(struct Node* root, int key) {
    // Base case: If tree is empty
    if (root == NULL) {
        return root;
    }
    
    // Recursive case: Navigate to the node to delete
    if (key < root->info) {
        root->left = delete(root->left, key);
    } else if (key > root->info) {
        root->right = delete(root->right, key);
    } else {
        // Case 1: Node is a leaf node (no children)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has only one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else {
            // Find inorder successor (smallest node in right subtree)
            struct Node* temp = findMin(root->right);
            
            // Copy the successor's data to this node
            root->info = temp->info;
            
            // Delete the successor
            root->right = delete(root->right, temp->info);
        }
    }
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->info);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->info);
    }
}

// Main function for testing
int main() {
    struct Node* root = NULL;
    
    // Insert operations
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Traversals
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\nPreorder: ");
    preorderTraversal(root);
    printf("\nPostorder: ");
    postorderTraversal(root);
    
    // Min and Max
    printf("\nMinimum: %d", findMin(root)->info);
    printf("\nMaximum: %d", findMax(root)->info);
    
    // Delete operation
    printf("\nDeleting 30");
    root = delete(root, 30);
    printf("\nInorder after deletion: ");
    inorderTraversal(root);
    
    return 0;
}