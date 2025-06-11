/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:15 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/11 12:51:57 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_index = 0;
	this->contact_count = 0;
	std::cout << "\033[1;32mPhonebook created\033[0m" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[1;32mPhonebook destroyed\033[0m" << std::endl;
}

int	PhoneBook::_is_valid_number(const std::string &str) const
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '+'))
			return (std::cout << "\033[1;31mOnly numbers, spaces and '+' is authorized\033[0m" << std::endl ,0);
	}
	return (1);
}

int	PhoneBook::_is_valid_name(const std::string &str) const
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '-'))
			return (std::cout << "\033[1;31mOnly letters and '-' is authorized\033[0m" << std::endl ,0);
	}
	return (1);
}

int	PhoneBook::_get_next_index() const
{
	static int index = 0;
	if (this->contacts[0].get_contact(FirstName).empty())
		return (0);
	index++;
	if (index == 8)
		index = index % 8;
	return (index);
}

int	PhoneBook::add()
{
	std::string	question[5] = {
		"Enter first name",
		"Enter last name",
		"Enter nick name",
		"Enter Phone number",
		"Enter darkest secret"
	};
	if (this->contact_index == 8)
		this->contact_index = this->contact_index % 8;
	std::cout << "\033[1;34mAdding contact at index " << this->contact_index + 1 << "\033[0m" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (this->_ask(question[i], this->contacts[this->contact_index], i))
			return (1);
	}
	this->contact_index++;
	return (0);
}

int	PhoneBook::_ask(std::string question, Contact &contact, int index)
{
	std::string	input;

	while (1)
	{
		std::cout << question << " > ";
		getline(std::cin, input);
		if (std::cin.eof())
			return (std::cout << "^D" << std::endl, 1);
		if (index == 0)
		{
			if (!_is_valid_name(input))
				continue;
			contact.set_contact(FirstName, input);
			break;
		}
		else if (index == 1)
		{
			if (!_is_valid_name(input))
				continue;
			contact.set_contact(LastName, input);
			break;
		}
		else if (index == 2 && !input.empty())
		{
			contact.set_contact(NickName, input);
			break;
		}
		else if (index == 3)
		{
			if (!_is_valid_number(input))
				continue;
			contact.set_contact(PhoneNumber, input);
			break;
		}
		else if (index == 4 && !input.empty())
		{
			contact.set_contact(DarkestSecret, input);
			break;
		}
	}
	return (0);
}

int	PhoneBook::search()
{
	if (this->contacts[0].get_contact(FirstName).empty())
		return (std::cout << "\033[1;31mPhonebook is empty\033[0m" << std::endl, 0);
	PhoneBook::_display_lobby();
	std::string	index;
	std::cout << "Enter index > ";
	while (index.empty())
	{
		if (std::cin.eof())
			return (std::cout << "^D" << std::endl, 1);
		getline(std::cin, index);
	}
	if (index.length() != 1 || index[0] < '1' || index[0] > '8')
		return (std::cout << "\033[1;31mInvalid index\033[0m" << std::endl, 0);
	int	i = std::atoi(index.c_str()) - 1;
	if (this->contacts[i].get_contact(FirstName).empty())
		return (std::cout << "\033[1;31mInvalid index\033[0m" << std::endl, 0);
	std::cout << "\033[1;34mDisplaying contact " << i + 1 << "\033[0m" << std::endl;
	std::cout << "Firstname: " << this->contacts[i].get_contact(FirstName) << std::endl;
	std::cout << "Lastname: " << this->contacts[i].get_contact(LastName) << std::endl;
	std::cout << "Nickname: " << this->contacts[i].get_contact(NickName) << std::endl;
	std::cout << "Phone number: " << this->contacts[i].get_contact(PhoneNumber) << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i].get_contact(DarkestSecret) << std::endl;
	return (0);
}

std::string PhoneBook::_display_info(const std::string str)
{
	return (str.length() < 10) ? str : str.substr(0, 9) + ".";
}

void PhoneBook::_display_lobby()
{
	int index = 0;
	if (this->contacts[index].get_contact(FirstName).empty())
	{
		std::cout << "\033[31mPhonebook is empty\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;34mDisplaying contacts\033[0m" << std::endl;
	std::cout << std::setw(45) << std::setfill('-') << "" << std::endl << std::setfill(' ');
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "firstname";
	std::cout << "|" << std::setw(10) << "lastname";
	std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << std::setw(45) << std::setfill('-') << "" << std::endl << std::setfill(' ');
	while (index < 8)
	{
		if (this->contacts[index].get_contact(FirstName).empty())
			break ;
		std::cout << "|" << std::setw(10) << index + 1;
		std::cout << "|" << std::setw(10) << _display_info(this->contacts[index].get_contact(FirstName));
		std::cout << "|" << std::setw(10) << _display_info(this->contacts[index].get_contact(LastName));
		std::cout << "|" << std::setw(10) << _display_info(this->contacts[index].get_contact(NickName));
		std::cout << "|" << std::endl;
		std::cout << std::setw(45) << std::setfill('-') << "" << std::endl << std::setfill(' ');
		index++;
	}
}
