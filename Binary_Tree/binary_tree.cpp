#include "binary_tree.h"

int main(){
    BTree t;
    cout << t.searchTreeNode(t.tree_root, 2) << endl;
    t.insertTreeNode(t.tree_root, 1);
    t.insertTreeNode(t.tree_root, 0);
    t.insertTreeNode(t.tree_root, 3);
    t.insertTreeNode(t.tree_root, 2);
    t.insertTreeNode(t.tree_root, 4);
    t.insertTreeNode(t.tree_root, 5);
    t.traversalTree(t.tree_root);
    cout  << t.searchTreeNode(t.tree_root, 0) << endl;
    cout  << t.searchTreeNode(t.tree_root, 4) << endl;
    cout << t.minNode(t.tree_root)->item << endl;
    cout << t.maxNode(t.tree_root)->item << endl;
    t.removeTreeNode(t.tree_root, 5);
    t.traversalTree(t.tree_root);
    return 0;
}