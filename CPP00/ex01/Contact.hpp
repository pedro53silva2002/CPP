#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		void set_index(int index);
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);
		std::string get_first_name(bool search);
		std::string	get_index(bool search);
		std::string get_last_name(bool search);
		std::string	get_nickname(bool search);
		std::string	get_phone_number(bool search);
		std::string	get_darkest_secret(bool search);
};

#endif