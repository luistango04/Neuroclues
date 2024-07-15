// NEurotrees.cpp : Defines the entry point for the application.
//

#include "NEurotrees.h"
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = std::filesystem;


std::unique_ptr<File> processFile(const fs::path& filepath) {
    std::string extension = filepath.extension().string();
    std::vector<std::unique_ptr<File>> files;

    if (SUPPORTED_EXTENSIONS.find(extension) != SUPPORTED_EXTENSIONS.end()) {
        if (extension == ".csv") {
            auto csvFile = std::make_unique<CSVFile>();
            csvFile->store(filepath.string());
            // csvFile->process();
            // std::string processedPath = filepath.replace_extension(".processed.csv").string();
            // csvFile->write(processedPath);
            return (std::move(csvFile));
        }
        else if (extension == ".json") {
            auto jsonFile = std::make_unique<JSONFile>();
            jsonFile->store(filepath.string());
            // jsonFile->process();
            // std::string processedPath = filepath.replace_extension(".xml").string();
            // jsonFile->write(processedPath);
            return std::move(jsonFile);
        }
    }

    return {};
}




int main(int argc, char* argv[]) {
    /*
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <folder>" << std::endl;
        return 1;
    }
    */

    fs::path folderPath = R"(C:\Users\luisc\source\repos\NEurotrees\samplefolder)";
    std::vector<std::unique_ptr<File>> setoffiles;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_regular_file(entry.status())) {

            setoffiles.push_back(processFile(entry.path()));


        }
    }


    for (auto& file : setoffiles) {
        // Check if the file pointer is valid before calling methods
        if (file) {
            file->process();
            file->write("output");  // Assuming write() takes a filename parameter
        }
        else {
            std::cerr << "Invalid file pointer encountered!" << std::endl;
            // Handle error or continue with next file
        }
    }
    return 0;
}