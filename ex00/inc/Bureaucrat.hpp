/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:39:40 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 11:00:02 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const		_name;
		unsigned int	_grade;
	public:
		/* constuctors */
		Bureaucrat();
		Bureaucrat(const std::string &n, const unsigned int g);
		Bureaucrat(const Bureaucrat &src);

		/* destructors */
		~Bureaucrat();

		/* operator */
		Bureaucrat	&operator=(const Bureaucrat &src);

		/* getters */
		std::string		getName() const;
		unsigned int	getGrade() const;

		/* members */
		void			incrementGrade();
		void			decrementGrade();

		/* class */
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _message;
				std::string _bureaucratName;
				std::string _completeMsg;
			public:
			GradeTooHighException(const std::string &m, const std::string &bN);
			virtual ~GradeTooHighException() throw();
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _message;
				std::string _bureaucratName;
				std::string _completeMsg;
			public:
			GradeTooLowException(const std::string &m, const std::string &bN);
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src);

#endif