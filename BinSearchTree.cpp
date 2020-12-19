#include<vector>
#include<iostream>
#include "BinSearchTree.hpp"
#include <queue>
void BinSearchTree::insert(int v )
{
    // You will have to write a solution to find in order to use this function.

    if( ! iterFind(v)) root = insert(root, v);
}
TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( insert( root->leftSubtree(), v ) );
    return root;
}
bool BinSearchTree::find(int v) {
    return find(root,v);
}
bool BinSearchTree::find(TreeNode* start, int v) {

    if (start == nullptr ) return false; //base
    if( start->value() == v) return true;
    if (start->value() < v) return find(start->rightSubtree(), v);
    return find(start->leftSubtree(), v);
}
bool BinSearchTree::iterFind(int v)
{
    TreeNode* spotter;
    if(root == nullptr) return false;
    spotter = root;
    while(spotter != nullptr)
    {
        if(spotter->value()>v  ) spotter = spotter->leftSubtree();
        else if(spotter->value()<v) spotter = spotter->rightSubtree();
        else return true;
    }
    return false;
}
void BinSearchTree::iterInsert(int v)
{
    if(root == nullptr)
    {
        root = new TreeNode(v);
        return;
    }
    else if(!find(v))
    {
        TreeNode* iterator = root;
        TreeNode* shadow = nullptr;
        while(iterator!= nullptr)
        {
            shadow = iterator;
            if( iterator->value() >v) iterator = iterator->leftSubtree();
            else iterator = iterator->rightSubtree();
        }
        if(v < shadow->value()) shadow->leftSubtree(new TreeNode(v));
        else shadow->rightSubtree(new TreeNode(v));
    }
}
int BinSearchTree::size() {
    return size(root);
}
int BinSearchTree::size(TreeNode *node)
{
    if(node == nullptr) return 0;
    else return(size(node->leftSubtree())+1+size(node->rightSubtree()));
}
void BinSearchTree::inorderDump()
{
    inorderDump(root);
}
void BinSearchTree::inorderDump(TreeNode* looper)
{
    if(looper == nullptr) return;
    inorderDump(looper->leftSubtree());
    std::cout << looper->value() << ", " << std::endl;
    inorderDump(looper->rightSubtree());

}
int BinSearchTree::iterMaxDepth()
{
   if (root == nullptr) return 0;
   std::queue<TreeNode *> line;
    line.push(root);
    int height = 0;
    while (1)
    {
        int nodeCount = line.size();
        if (nodeCount == 0) return height;
        height++;
        while (nodeCount > 0)
        {
            TreeNode* temp = line.front();
            line.pop();
            if (temp->leftSubtree() != nullptr)
                line.push(temp->leftSubtree());
            if (temp->rightSubtree() != nullptr)
                line.push(temp->rightSubtree());
            nodeCount--;
        }
    }
}
int BinSearchTree::maxDepth() {
    return maxDepth(root);
}
int BinSearchTree::maxDepth(TreeNode* iterator)
{
    if (iterator == nullptr)
        return 0;
    else
    {
        int left = maxDepth(iterator->leftSubtree());
        int right = maxDepth(iterator->rightSubtree());
        if (left > right) return(left + 1);
        else return(right + 1);
    }
}
void BinSearchTree::levelOrderDump()
{
    if (root == nullptr) return;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int nodeCount = queue.size();
        while (nodeCount > 0)
        {
            TreeNode* temp = queue.front();
            std::cout << temp->value() << " "<<std::endl;
            queue.pop();
            if (temp->leftSubtree() != nullptr) queue.push(temp->leftSubtree());
            if (temp->rightSubtree() != nullptr)
                queue.push(temp->rightSubtree());
            nodeCount--;
        }
        std::cout << std::endl;
    }
}
bool BinSearchTree::areIdentical(BinSearchTree *bst) {
    return areIdentical(root,bst->root);
}
bool BinSearchTree::areIdentical(TreeNode* root, TreeNode* root_friend) {
    if (root == nullptr && root_friend == nullptr) return true;
    else if (root != nullptr && root_friend == nullptr) return false;
    else if (root == nullptr && root_friend != nullptr) return false;
    else return (root->value() == root_friend->value()) &&
               (areIdentical(root->leftSubtree(), root_friend->leftSubtree()))
               && (areIdentical(root->rightSubtree(), root_friend->rightSubtree()));

}
BinSearchTree::BinSearchTree()
{
    root = nullptr;
}
BinSearchTree::~BinSearchTree()
{
    if (root == nullptr)
    {
        std::queue<TreeNode*> queue;
        queue.push(root);
        TreeNode *curr = nullptr;
        while (!queue.empty())
        {
            curr = queue.front();
            queue.pop();
            if (curr->leftSubtree()) queue.push(curr->leftSubtree());
            if (curr->rightSubtree()) queue.push(curr->rightSubtree());
            delete curr;
        }
        root = nullptr;
    }
}
