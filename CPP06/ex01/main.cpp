#include "Serializer.hpp"

int main() {
	// Create and initialize a Data object
	Data original;
	original.string = "CPP Module 06";
	original.value = 42;

	std::cout << "Original Data:" << std::endl;
	std::cout << "  name:  " << original.string << std::endl;
	std::cout << "  value: " << original.value << std::endl;

	// Serialize the pointer
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized address (uintptr_t): " << raw << std::endl;

	// Deserialize it back
	Data* restored = Serializer::deserialize(raw);
	std::cout << "\nRestored Data:" << std::endl;
	std::cout << "  name:  " << restored->string << std::endl;
	std::cout << "  value: " << restored->value << std::endl;

	// Confirm it's the same address
	std::cout << "\nOriginal pointer: " << &original << std::endl;
	std::cout << "Restored pointer: " << restored << std::endl;

	return 0;
}