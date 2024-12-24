#include <bits/stdc++.h>
using namespace std;

struct Listnode {
    int val;
    Listnode* next;
    Listnode(int x) : val(x), next(nullptr) {}
};

struct Treenode {
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the middle element of the linked list
Listnode* findMiddle(Listnode* head) {
    Listnode* slow = head;
    Listnode* fast = head;
    Listnode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr; // Split the list into two halves
    }

    return slow;
}

// Function to convert sorted linked list to BST
Treenode* sortedListToBST(Listnode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return new Treenode(head->val);

    Listnode* mid = findMiddle(head);
    Treenode* root = new Treenode(mid->val);

    root->left = sortedListToBST(head); // Left half of the list
    root->right = sortedListToBST(mid->next); // Right half of the list

    return root;
}

// Helper function to print the tree (in-order traversal)
void printInOrder(Treenode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create a sorted linked list: -10 -> -3 -> 0 -> 5 -> 9
    Listnode* head = new Listnode(-10);
    head->next = new Listnode(-3);
    head->next->next = new Listnode(0);
    head->next->next->next = new Listnode(5);
    head->next->next->next->next = new Listnode(9);

    Treenode* root = sortedListToBST(head);

    // Print the BST in-order to verify
    printInOrder(root);
    cout << endl;

    return 0;
}