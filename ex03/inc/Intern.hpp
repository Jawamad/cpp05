/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:00:00 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/05 14:12:58 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern 
{
	public:
		/* constructors */
		Intern();
		~Intern();
		Intern(const Intern & src);
		/* operators */
		Intern&	operator=(const Intern & src);
		/* members */
		AForm *makeForm(std::string name, std::string target);
		/* exceptions */
		class FormDoesntExistException : public std::exception
		{
			private:
				std::string _message;
				std::string _formName;
				std::string _completeMsg;
			public:
			FormDoesntExistException(const std::string &m, const std::string &fN);
			virtual ~FormDoesntExistException() throw();
			virtual const char* what() const throw();
		};
};

#endif