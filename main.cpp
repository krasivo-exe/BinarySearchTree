#include <iostream>

#include <iostream>
#include <fstream>
#include "BinSearchTree.hpp"

int main(int argc, char *argv[]) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(1);
    }
    auto *tree = new BinSearchTree();
    auto *tree2 = new BinSearchTree();
    int v;
    while (inputStream >> v) {
        tree->iterInsert(v);
        tree2->insert(v);
    }

    std::cout<<"Items inputted" << std::endl;
    std::cout << tree->iterFind(9) << std::endl;
    std::cout << tree->iterFind(197145) << std::endl;
    std::cout << tree->iterFind(324) << std::endl;
    std::cout<<tree->size()<<std::endl;
    std::cout<<tree2->size();
    //tree->inorderDump(); (it works, yay :))
    std::cout << "max depth = " << tree->maxDepth() << std::endl;
    std::cout << "max depth iterative = " << tree->iterMaxDepth()<<std::endl;
    std::cout << tree->areIdentical(tree);
    tree->levelOrderDump();
    return 0;
}
