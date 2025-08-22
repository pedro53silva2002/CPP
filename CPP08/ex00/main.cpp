#include "easyfind.hpp"

/* int main( void ) {
    std::vector<int> nbrs;
    nbrs.push_back(1);
    nbrs.push_back(2);
    nbrs.push_back(3);
    nbrs.push_back(4);
    nbrs.push_back(5);
    try
    {
        easyfind(nbrs, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(nbrs, 398);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
} */

#include "easyfind.hpp"

int main()
{
    try {
        int array[] = {5, 3, 3, 4, 5};
        int deque[] = {1, 2, 3, 4, 5};
        int lists[] = {1, 2, 1};
        std::vector<int> arr(array, array + sizeof(array) / sizeof(int));
        std::deque<int> deq(deque, deque + sizeof(deque) / sizeof(int));
        std::list<int> list(lists, lists + sizeof(lists) / sizeof(int));   
        easyfind(arr, 3);
        easyfind(deq, 5);
        easyfind(list, 5);     
        /* std::cout << "Vector is {1, 3, 4, 3, 5, 5}\nSearching for 3 first ocurrence\nResult: " << *(easyfind(arr, 3)) << "\n";
        std::cout << "Deque is {1, 2, 3, 4, 5}\nSearching for 5 first ocurrence\nResult: " << *(easyfind(deq, 5)) << "\n";
        std::cout << "List is {1, 2, 1}\nSearching for 5 first ocurrence\nResult: " << *(easyfind(list, 5)) << "\n"; */
    } catch (std::exception a) {
        std::cout << "Number not in container\n";
    }
}