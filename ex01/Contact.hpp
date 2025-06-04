/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:11 by lgrisel           #+#    #+#             */
/*   Updated: 2025/06/04 19:40:56 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		enum Field
		{
			FirstName,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};

	public:
		Contact();
		~Contact();

		void		set_contact(int i, const std::string information);
		std::string	get_contact(int i) const;
};

#endif