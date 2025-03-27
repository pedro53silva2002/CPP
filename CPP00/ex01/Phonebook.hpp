#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
/* # include "Phonebook.cpp"
# include "Contact.cpp" */

class Phonebook
{
	private:
		int index;
		int len;
		Contact contacts[8];
	public:
		Phonebook();
		~Phonebook();
		void ft_add();
		void ft_search();
		void ft_print();
		std::string ft_getline(std::string prompt);
};

#endif