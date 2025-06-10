/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:10 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/10 13:10:28 by lgrisel          ###   ########.fr       */
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

void	Contact::set_contact(int type, const std::string information)
{
	if (type == FirstName)
		this->firstName == information;
	if (type == LastName)
		this->lastName == information;
	if (type == NickName)
		this->nickName == information;
	if (type == PhoneNumber)
		this->phoneNumber == information;
	if (type == DarkestSecret)
		this->darkestSecret == information;
}

std::string	Contact::get_contact(int type) const
{
	if (type == FirstName)
		return (this->firstName);
	if (type == LastName)
		return (this->lastName);
	if (type == NickName)
		return (this->nickName);
	if (type == PhoneNumber)
		return (this->phoneNumber);
	if (type == DarkestSecret)
		return (this->darkestSecret);
	return ("");
}
