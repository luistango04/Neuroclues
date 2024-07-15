#ifndef XMLFILE_H
#define XMLFILE_H

#include "File.h"
#include <iostream>
#include <fstream>  // Include for file operations

class XMLFile : public File {
public:

    void store(const std::string& filename) override {
        std::cout << "Storing data from XML file into tree: " << filename << "\n";

        // Parse XML file and store data into tree
        parseXMLFile(filename);
    }

    void process() override {
        std::cout << "Processing XML data...\n";
        // Implementation specific to processing XML data
    }

    void write(const std::string& filename) override {
        std::cout << "Writing data as XML file: " << filename << "\n";
        // Implementation specific to writing data as XML file
    }

private:
    Tree tree;  // Instance of Tree to store data

    // Helper function to parse XML file and store data into tree
    void parseXMLFile(const std::string& filename) {
        // Open XML file
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        // Here you would implement XML parsing logic
        // For demonstration, let's assume a simple parsing and storing logic
        std::string line;
        while (std::getline(file, line)) {
            // Example parsing logic:
            // Assuming XML format: <node name="..." value="..."/>
            size_t nameStart = line.find("name=\"");
            size_t nameEnd = line.find("\"", nameStart + 6);
            size_t valueStart = line.find("value=\"");
            size_t valueEnd = line.find("\"", valueStart + 7);

            if (nameStart != std::string::npos && nameEnd != std::string::npos &&
                valueStart != std::string::npos && valueEnd != std::string::npos) {
                std::string name = line.substr(nameStart + 6, nameEnd - nameStart - 6);
                std::string value = line.substr(valueStart + 7, valueEnd - valueStart - 7);

                // Create TreeNode and insert into tree
                auto newNode = createTreeNode(name, value);
                tree.insertNode("root", newNode);  // Assuming inserting under root for simplicity
            }
        }

        file.close();
    }
};

#endif // XMLFILE_H
