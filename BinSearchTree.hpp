#include<stdlib.h>
#include "TreeNode.hpp"

class BinSearchTree {
public:
    BinSearchTree();
    void insert( int v );
    void iterInsert( int v );
    bool find( int v );
    bool find(TreeNode* r,int v);
    bool iterFind( int v );
    int size();
    void inorderDump();
    int iterMaxDepth();   
    int maxDepth();   
    void levelOrderDump();   
    bool areIdentical( BinSearchTree *bst );
    ~BinSearchTree();
    TreeNode* getRoot(){ return root;};//I hope this is not considered changing the interface, I simply needed this for the areidentical function
private:
    int size(TreeNode* node);
    TreeNode *insert( TreeNode *, int );
    TreeNode *root;

    int maxDepth(TreeNode *iterator);

    void inorderDump(TreeNode *roller);

    bool areIdentical(TreeNode *root, TreeNode *root_friend);
};
