#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
	int random_number = std::rand();
	if (random_number % 3 == 0) {
		return new A;
	} 
	else if (random_number % 2 == 0) {
		return new B;
	}
	else {
		return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Point to A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Point to B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Point to C" << std::endl;
	}
	//std::cout << "Object pointed to: " << p << std::endl;
}

void identify(Base& p) {
	try {
        A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference to A" << std::endl;
    }
    catch (std::exception& e) {
        //std::cout << "Something went wrong in A" << std::endl;
    }
	try {
        B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference to B" << std::endl;
    }
    catch (std::exception& e) {
       // std::cout << "Something went wrong in B" << std::endl;
    }
	try {
        C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference to C" << std::endl;
    }
    catch (std::exception& e) {
        // std::cout << "Something went wrong in C" << std::endl;
    }
	//std::cout << "Object referenced by: " << &p << std::endl;
}


int main() {
	Base *s = generate();
	identify(s);
	std::cout << std::endl;
	identify(*s);
	delete s;
	/* // Create and initialize a Data object
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
	std::cout << "Restored pointer: " << restored << std::endl; */

	return 0;
}