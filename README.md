Preface: 
I interpreted your task as if the method for adding a new file type should be easy enough that the back end doesn't need substantial changing. Computers are not fortune tellers; as such, instruction needs to be given for each new file type.
I chose to use a tree structure to help process the data. CSV traditionally has no dictionary style architecture. But the child parent relationship comes in useful. 
The exercise I chose to do was a salary expectations game where I multiply my salary expectations by the length of the value of each node. 
I got a little bit lazy and decided to implement my classes inside the header files themselves to reduce the number of files. Honestly, I wish the syntax was this way as it makes it easier for me as outside to know where to go when something is wrong. 

Issues Currently:
I had difficult converting the JSON file to a Proper Tree structure in the limited available time. 

Overview

The project consists of the following components:

    File: Base class defining operations for reading, storing, processing, and writing files.
    CSVFile: Class implementing file operations specific to CSV files.
    XMLFile: Class implementing file operations specific to XML files.
    main.cpp: Example usage of CSVFile and XMLFile classes.

How to add newfile types. 
    All File data is stored in a tree structure which can then be written into the appropriate file types.
    To add new file type(i.e. JSON) add the json.h file and include it in the config.h file
    all children types need 

Requirements

    C++ compiler that supports C++11 or later.
    CMake (minimum version 3.0) for building the project.

Building the Project

    Clone the repository:

    bash

git clone https://github.com/your/repository.git
cd repository

Create a build directory and navigate into it:

bash

mkdir build
cd build

Generate build files with CMake and build the project:

bash

cmake ..
cmake --build .

Execute the compiled executable:
