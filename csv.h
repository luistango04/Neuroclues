#ifndef CSVFILE_H
#define CSVFILE_H

#include "File.h"
#include <iostream>
#include <fstream>  // Include for file operations

class CSVFile : public File {
public:


    void store(const std::string& filename) override {
        std::cout << "Storing data from CSV file into tree: " << filename << "\n";

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            //std::cout << "Line: " << line << "\n";
            // Assume CSV format: name, value
            size_t pos = line.find(',');
            if (pos != std::string::npos) {
                std::string name = line.substr(0, pos);
                std::string value = line.substr(pos + 1);

                // Create TreeNode and insert into tree
                auto newNode = createTreeNode(name, value);
                tree.insertNode("root", newNode);  // Assuming inserting under root for simplicity
            }
        }

        file.close();
    }

    void process() override {
        std::cout << "Processing CSV data...\n";
        tree.printTree();
        // Implementation specific to processing CSV data
    }

    void write(const std::string& filename) override {
        std::string extension = ".csv";
        std::string fullFilename = filename + extension;
        std::ofstream outputFile(fullFilename);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file: " << fullFilename << std::endl;
            return;
        }

        outputFile << "Name,Value,Results\n"; // CSV header

        // Write tree nodes recursively
        writeNodeToCSV(outputFile, tree.getRoot(), 0);

        outputFile.close();
    }


private:

    static void writeNodeToCSV(std::ostream& out, const std::shared_ptr<TreeNode>& node, int level) {
        std::string indent(level * 2, ' ');

        // Write current node's data
        out << indent << "\"" << node->name << "\",\"" << node->value << "\"," << node->results << "\n";

        // Write children recursively
        for (const auto& child : node->children) {
            writeNodeToCSV(out, child, level + 1);
        }
    }
//    Tree tree;  // Instance of Tree to store data
};

#endif // CSVFILE_H
