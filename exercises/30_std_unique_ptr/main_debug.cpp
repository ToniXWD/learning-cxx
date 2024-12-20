#include "../exercise.h"
#include <memory>
#include <string>
#include <vector>
#include <cstring>

// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        std::cout << "record(" << record << ")" << std::endl;
        _records.push_back(record);
    }

    Resource() {
        std::cout << "Resource()" << std::endl;
    }

    ~Resource() {
        std::cout << "~Resource()" << std::endl;
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    std::cout << "reset(ptr)" << std::endl;
    if (ptr) {
        std::cout << "reset(ptr) record('r')" << std::endl;
        ptr->record('r');
    }
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    std::cout << "drop(ptr)" << std::endl;
    if (ptr) {
        std::cout << "drop(ptr) record('d')" << std::endl;
        ptr->record('d');
    }
    return nullptr;
}
Unique forward(Unique ptr) {
    std::cout << "forward(ptr)" << std::endl;
    if (ptr) {
        std::cout << "forward(ptr) record('f')" << std::endl;
        ptr->record('f');
    }
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    return 0;
}
