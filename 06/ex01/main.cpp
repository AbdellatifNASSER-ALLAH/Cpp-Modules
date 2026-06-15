#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "TheName";
    data.content = "Serialization test data";

    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << "Data ID: " << data.id << ", Name: " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::hex << " (0x" << raw << ")" << std::dec << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptr << std::endl;

    if (ptr == &data) {
        std::cout << "SUCCESS: Pointers match!" << std::endl;
        std::cout << "Deserialized Data ID: " << ptr->id << ", Name: " << ptr->name << ", Content: " << ptr->content << std::endl;
    } else {
        std::cout << "FAILURE: Pointers do NOT match!" << std::endl;
        return 1;
    }

    return 0;
}
