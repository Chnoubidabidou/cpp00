/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:15 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/04 20:11:33 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	std::cout << "\033[1;32mPhonebook created\033[0m" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\033[1;32mPhonebook destroyed\033[0m" << std::endl;
}

void	PhoneBook::add()
{

}

void	PhoneBook::search()
{
	if (this->contacts[0].get_contact(FirstName).empty())
	{
		std::cout << "\033[1;31mPhonebook is empty\033[0m" << std::endl;
		return ;
	}
}
