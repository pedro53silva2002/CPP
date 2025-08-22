#include "iter.hpp"
void ft_toUpper(std::string &c)
{
    for (size_t i = 0; i < c.length(); i++)
    {
        c[i] = std::toupper(static_cast<unsigned char>(c[i]));
    }
}

void ft_toLower(std::string &c)
{
    for (size_t i = 0; i < c.length(); i++)
    {
        c[i] = std::tolower(static_cast<unsigned char>(c[i]));
    }
}

void ft_addTwo(int &n)
{
    n += 2;
}


int main( void ) {
    std::string arr[] = {"ParIs", "JoAna", "BaNAna"};
	::iter(arr, 3, ft_toUpper);
    std::cout << "Upper:" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
    std::cout << std::endl << std::endl;
	::iter(arr, 3, ft_toLower);
    std::cout << "Lower:" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
    int arr2[] = {1,3,5,7,9};
    ::iter(arr2, 5, ft_addTwo);
    std::cout << "Incremented integers:" << std::endl;
    for (size_t i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		std::cout << arr2[i] << std::endl;
	}
	return (0);
}