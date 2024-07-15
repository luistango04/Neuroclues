#ifndef JSONFILE_H
#define JSONFILE_H


#include <iostream>
#include <fstream>
#include <sstream>   // For std::stringstream
#include <iomanip>   // For std::quoted
#include <memory>    // For std::shared_ptr
#include <vector>
#include <unordered_map>
#include <fstream>
#include <jsonparser.hpp>
using json = nlohmann::json;
void recurse_json(const json& j, int depth = 0);


class JSONFile : public File {
public:

    void store(const std::string& filename) override {
        std::ifstream f(filename);
        json data = json::parse(f);
        recurse_json(data);

        
    }

    void process() override {
        std::cout << "Processing JSON data...\n";
        tree.printTree();
        // Implementation specific to processing JSON data
    }

    void write(const std::string& filename) override {
        std::string extension = ".json";
        std::string fullFilename = filename + extension;


        std::cout << "Writing data as JSON file: " << fullFilename << "\n";
        // Implementation specific to writing data as JSON file
        std::ofstream outputFile(fullFilename);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file: " << fullFilename << std::endl;
            return;
        }



        outputFile.close();
    }

private:
    void buildTree(std::shared_ptr<TreeNode>& node, const json& jsonNode) {
        for (auto it = jsonNode.begin(); it != jsonNode.end(); ++it) {
            std::string key = it.key();
            json value = it.value();

            // Assuming you have appropriate logic to extract name, value, and results from JSON
            std::string nodeName = key;
            std::string nodeValue = value["value"].get<std::string>(); // Example assuming "value" field
            double nodeResults = value["results"].get<double>(); // Example assuming "results" field

            std::shared_ptr<TreeNode> child = std::make_shared<TreeNode>(nodeName, nodeValue, nodeResults);
            node->children.push_back(child);

            if (value.is_object()) {
                buildTree(child, value); // Recursively build subtree
            }
            // Handle other JSON value types (arrays, strings, numbers, etc.) if needed
        }
    }
    // Function to recursively build the tree from JSON
    void buildTreeFromJSON(const std::unordered_map<std::string, std::string>& jsonDict, std::shared_ptr<TreeNode> node) {
        for (const auto& pair : jsonDict) {
            std::shared_ptr<TreeNode> child = std::make_shared<TreeNode>(pair.first);
            child->value = (pair.second);
            node->addChild(child);
        }
    }




};

void recurse_json(const json& j, int depth) {
    // Indent the output according to the depth of recursion
    std::string indent(depth * 2, ' ');

    if (j.is_object()) {
        for (auto it = j.begin(); it != j.end(); ++it) {
            std::cout << indent << "Key: " << it.key() << std::endl;
            recurse_json(it.value(), depth + 1);
        }
    }
    else if (j.is_array()) {
        for (std::size_t i = 0; i < j.size(); ++i) {
            std::cout << indent << "Index: " << i << std::endl;
            recurse_json(j[i], depth + 1);
        }
    }
    else if (j.is_string()) {
        std::cout << indent << "String: " << j.get<std::string>() << std::endl;
    }
    else if (j.is_number()) {
        std::cout << indent << "Number: " << j << std::endl;
    }
    else if (j.is_boolean()) {
        std::cout << indent << "Boolean: " << j << std::endl;
    }
    else if (j.is_null()) {
        std::cout << indent << "Null" << std::endl;
    }
}



#endif // JSONFILE_H
