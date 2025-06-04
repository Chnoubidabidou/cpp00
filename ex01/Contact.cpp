/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:10 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/04 17:42:06 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	if (this->firstName.empty() == false)
		std::cout << "Deleting " << this->firstName << std::endl;
	else
		std::cout << "Deleting an empty contact" << std::endl;
}

void	Contact::set_contact(int i, const std::string information)
{
	if (i == FirstName)
		this->firstName == information;
	if (i == LastName)
		this->lastName == information;
	if (i == NickName)
		this->nickName == information;
	if (i == PhoneNumber)
		this->phoneNumber == information;
	if (i == DarkestSecret)
		this->darkestSecret == information;
}

std::string	Contact::get_contact(int i) const
{
	if (i == FirstName)
		return (this->firstName);
	if (i == LastName)
		return (this->lastName);
	if (i == NickName)
		return (this->nickName);
	if (i == PhoneNumber)
		return (this->phoneNumber);
	if (i == DarkestSecret)
		return (this->darkestSecret);
}
