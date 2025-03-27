#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Contact::Contact(){
		this->first_name = "";
		this->last_name = "";
		this->nickname = "";
		this->phone_number = "";
		this->darkest_secret = "";
}

Contact::~Contact(){

}

void Contact::set_index(int index){
	this->index = index;
}

void Contact::set_first_name(std::string first_name){
	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name){
	this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname){
	this->nickname = nickname;
}

void Contact::set_darkest_secret(std::string darkest_secret){
	this->darkest_secret = darkest_secret;
}

void Contact::set_phone_number(std::string phone_number){
	this->phone_number = phone_number;
}

std::string Contact::get_first_name(bool search){
	if (this->first_name.length() > 10 && search){
		return (this->first_name.substr(0, 9) + ".");
	}
	return (this->first_name);
}

std::string Contact::get_index(bool search){
	std::string index = std::to_string(this->index);
	return (index);
}

std::string Contact::get_last_name(bool search){
	if (this->last_name.length() > 10 && search){
		return (this->last_name.substr(0, 9) + ".");
	}
	return (this->last_name);
}

std::string Contact::get_nickname(bool search){
	if (this->nickname.length() > 10 && search){
		return (this->nickname.substr(0, 9) + ".");
	}
	return (this->nickname);
}

std::string Contact::get_phone_number(bool search){
	if (this->phone_number.length() > 10 && search){
		return (this->phone_number.substr(0, 9) + ".");
	}
	return (this->phone_number);
}

std::string Contact::get_darkest_secret(bool search){
	if (this->darkest_secret.length() > 10 && search){
		return (this->darkest_secret.substr(0, 9) + ".");
	}
	return (this->darkest_secret);
}