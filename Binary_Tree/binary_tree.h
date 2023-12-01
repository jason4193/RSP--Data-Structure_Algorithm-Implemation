#ifndef BINARY_TREE
#define BINARY_TREE

#include "iostream"
#include "string"
using namespace std;

struct BTreeNode {
    int item;
    struct BTreeNode* parent;
    struct BTreeNode* child_L;
    struct BTreeNode* child_R;
}; 

class BTree{
    public:

    BTreeNode* tree_root;

    BTree(): tree_root(NULL) {}

    void insertTreeNode(BTreeNode*& current, int item, BTreeNode* parent = NULL);

    BTreeNode* searchTreeNode(BTreeNode* parent, int item);

    void removeTreeNode(BTreeNode*& parent, int item);

    void traversalTree(BTreeNode* parent);

    string processNode(BTreeNode* node);

    BTreeNode* minNode(BTreeNode* parent);

    BTreeNode* maxNode(BTreeNode* parent);

};

void BTree::insertTreeNode(BTreeNode*& current, int item, BTreeNode* parent){
    // cout << "inserting..." << endl;
    if (current == NULL){
        // cout << "creating..." << endl;
        // Create a new node
        BTreeNode* new_node = new BTreeNode();
        // Set up the Node variables
        new_node->item = item;
        new_node->parent = parent;
        new_node->child_L = NULL;
        new_node->child_R = NULL;
        // Link the node to parent
        current = new_node;
        // If first node for BTree
        if (tree_root == NULL) {
            tree_root = new_node;
        }
        return;
    }

    if (item < current->item){
        // Put to the left subtree
        insertTreeNode(current->child_L, item, current);
    } else{
        // Put to the right subtree
        insertTreeNode(current->child_R, item, current);
    }
}

BTreeNode* BTree::searchTreeNode(BTreeNode* parent, int item){
    // Check case if no tree Node or item not found in the tree
    if (tree_root == NULL || parent == NULL){
        cout << "item not found" << endl;
        return NULL;
    }
    // Base case if we found the item in the tree
    if (parent->item == item){
        return parent;
    }
    // Recursive cases
    if (parent->item > item){
        return searchTreeNode(parent->child_L, item);
    } else {
        return searchTreeNode(parent->child_R, item);
    }
}

void BTree::traversalTree(BTreeNode* parent){
    if (parent != NULL){
        traversalTree(parent->child_L);
        cout << processNode(parent) << endl;
        traversalTree(parent->child_R);
    }
}

string BTree::processNode(BTreeNode* node){
    string output;
    if (node != NULL){
        output += "The Node " + to_string(node->item) + " ";
        if (node->parent != NULL){
            output += "Parent : " + to_string(node->parent->item) + " ";    
        } else {
            output += "Parent : N ";    
        }
        if (node->child_L != NULL){
            output += "ChildL : " + to_string(node->child_L->item) + " ";
        } else {
            output += "ChildL : N ";    
        }
        if (node->child_R != NULL){
            output += "ChildR : " + to_string(node->child_R->item) + " ";
        } else {
            output += "ChildR : N ";    
        }
    }
    return output;
    
}

BTreeNode* BTree::minNode(BTreeNode* parent){
    if (parent == NULL){
        return NULL;
    }
    BTreeNode* min = parent;
    while (min->child_L != NULL){
        min = min->child_L;
    }
   return min;
}

BTreeNode* BTree::maxNode(BTreeNode* parent){
    if (parent == NULL){
        return NULL;
    }
    BTreeNode* min = parent;
    while (min->child_R != NULL){
        min = min->child_R;
    }
    return min;
}

void BTree::removeTreeNode(BTreeNode*& parent, int item) {
    BTreeNode* nodeToRemove = searchTreeNode(parent, item);

    if (nodeToRemove == NULL) {
        return;
    }

    // Case 1: Node to remove has no children
    if (nodeToRemove->child_L == NULL && nodeToRemove->child_R == NULL) {
        if (nodeToRemove->parent != NULL) {
            // Node to remove is not the root
            BTreeNode* parentNode = nodeToRemove->parent;
            if (parentNode->child_L == nodeToRemove) {
                parentNode->child_L = NULL;
            } else {
                parentNode->child_R = NULL;
            }
        } else {
            // Node to remove is the root with no children
            tree_root = NULL;
        }
        delete nodeToRemove;
    }
    // Case 2: Node to remove has both children
    else if (nodeToRemove->child_L != NULL && nodeToRemove->child_R != NULL) {
        // Find successor or predecessor
        BTreeNode* successor = minNode(nodeToRemove->child_R); // Or predecessor = maxNode(nodeToRemove->child_L);
        int temp = successor->item;

        removeTreeNode(nodeToRemove, successor->item);
        nodeToRemove->item = temp;
    }
    // Case 3: Node to remove has one child
    else {
        BTreeNode* childNode = (nodeToRemove->child_L != NULL) ? nodeToRemove->child_L : nodeToRemove->child_R;

        if (nodeToRemove->parent != NULL) {
            // Node to remove is not the root
            BTreeNode* parentNode = nodeToRemove->parent;
            if (parentNode->child_L == nodeToRemove) {
                parentNode->child_L = childNode;
            } else {
                parentNode->child_R = childNode;
            }
            childNode->parent = parentNode;
        } else {
            // Node to remove is the root with one child
            tree_root = childNode;
            tree_root->parent = NULL;
        }
        delete nodeToRemove;
    }
}

#endif

