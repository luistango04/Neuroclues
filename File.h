#ifndef FILE_H
#define FILE_H

#include <string>
#include <memory>
#include <iostream>
#include "Tree.h"  // Include TreeNodeTree.h for TreeNode and Tree classes

class File {
public:
    virtual ~File() {}


    virtual void store(const std::string& filename) = 0;
    virtual void process() = 0;
    virtual void write(const std::string& filename) = 0;



protected:
    Tree tree;  // Protected member so derived classes can access it

    // Helper function to create a TreeNode
    std::shared_ptr<TreeNode> createTreeNode(const std::string& name, const std::string& value) {
        double salaryExpectations = 1000.0;  // Example salary expectation value
        double results = value.length() * salaryExpectations;
        return std::make_shared<TreeNode>(name, value, results);
    }

private:

    
};


#endif // FILE_H