#ifndef TREENODETREE_H
#define TREENODETREE_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>



#include <string>
#include <vector>
#include <memory>
#include <iostream>

class TreeNode {
private:


public:
    //moved to publish so I could write files more easily. perhaps getter functions should be better
    std::string name;
    std::string value;
    double results;
    std::vector<std::shared_ptr<TreeNode>> children;
    // Define the salary expectation as a constant
    static constexpr double SALARY_EXPECTATIONS = 5000;  // example value

    // Constructors
    TreeNode(const std::string& name, const std::string& value = "")
        : name(name), value(value), results(static_cast<double>(value.length())* SALARY_EXPECTATIONS) {}

    TreeNode(const std::string& name, const std::string& value, double results)
        : name(name), value(value), results(results) {}

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getValue() const { return value; }
    double getResults() const { return results; }
    const std::vector<std::shared_ptr<TreeNode>>& getChildren() const { return children; }

    // Methods
    void addChild(const std::shared_ptr<TreeNode>& child) {
        children.push_back(child);
    }

    void printNode(int level = 0) const {
        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }
        std::cout << "TreeNode(name=" << name << ", value=" << value << ", results=" << results << ")\n";
        for (const auto& child : children) {
            child->printNode(level + 1);
        }
    }
};


class Tree {
private:
    std::shared_ptr<TreeNode> root;

public:
    Tree() : root(std::make_shared<TreeNode>("root")) {}

    std::shared_ptr<TreeNode> getRoot() const {
        return root;
    }


    void insertNode(const std::string& parentName, const std::shared_ptr<TreeNode>& newNode) {
        auto parentNode = findNode(root, parentName);
        if (parentNode) {
            parentNode->addChild(newNode);
            std::cout << "Added node \"" << newNode->getName() << "\" under parent \"" << parentName << "\".\n";
        }
        else {
            std::cout << "Parent node with name \"" << parentName << "\" not found. Node \"" << newNode->getName() << "\" not added.\n";
        }
    }

    std::shared_ptr<TreeNode> findNode(const std::shared_ptr<TreeNode>& currentNode, const std::string& name) {
        if (currentNode->getName() == name) {
            return currentNode;
        }
        for (const auto& child : currentNode->getChildren()) {
            auto result = findNode(child, name);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }

    void printTree() const {
        std::cout << "Printing Tree...\n";
        root->printNode();
        std::cout << "Tree Printing Complete.\n";
    }
};

#endif // TREE_H