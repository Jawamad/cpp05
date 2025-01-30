/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:32 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/30 11:39:05 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int	main()
{
	std::cout << std::endl << "----########-test bureaucrat-########----"<< std::endl << std::endl;
	try
	{
		std::cout << std::endl << "########-test no error-########"<< std::endl << std::endl;
		Bureaucrat robert("robert", 45);
		std::cout << robert << std::endl;
		std::cout << "decrement Grade" << std::endl;
		robert.decrementGrade();
		std::cout << robert.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		robert.incrementGrade();
		std::cout << robert.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error bad 1st grade (too low)-########"<< std::endl << std::endl;
		Bureaucrat Regis("Regis", 151);
		std::cout << Regis << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Regis.decrementGrade();
		std::cout << Regis.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Regis.incrementGrade();
		std::cout << Regis.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error bad 1st grade (too high)-########"<< std::endl << std::endl;
		Bureaucrat raymond("raymond", 0);
		std::cout << raymond << std::endl;
		std::cout << "decrement Grade" << std::endl;
		raymond.decrementGrade();
		std::cout << raymond.getGrade() << std::endl;
		std::cout << "increment Grade" << std::endl;
		raymond.incrementGrade();
		std::cout << raymond.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error cannot increment grade-########"<< std::endl << std::endl;
		Bureaucrat Bertrand("Bertrand", 1);
		std::cout << Bertrand << std::endl;
		std::cout << "increment Grade" << std::endl;
		Bertrand.incrementGrade();
		std::cout << Bertrand.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Bertrand.decrementGrade();
		std::cout << Bertrand.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error cannot decrement grade-########"<< std::endl << std::endl;
		Bureaucrat Boris("Boris", 150);
		std::cout << Boris << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Boris.decrementGrade();
		std::cout << Boris.getGrade() << std::endl;
		std::cout << "increment Grade" << std::endl;
		Boris.incrementGrade();
		std::cout << Boris.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << std::endl << "----########-test sign form-########----"<< std::endl << std::endl;
	try
	{
		std::cout << std::endl << "########-test no error sign form-########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 150);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		AForm stage("stage form",150, 150);
		std::cout << stage << std::endl;
		Bernard.signForm(stage);
		std::cout << stage << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test no error: grade too low sign form-########"<< std::endl << std::endl;
		Bureaucrat Maurice("Maurice", 150);
		std::cout << Maurice << std::endl;
		std::cout << "new stage form" << std::endl;
		AForm stage("stage form", 149, 150);
		std::cout << stage << std::endl;
		Maurice.signForm(stage);
		std::cout << stage << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error: grade too low sign form-########"<< std::endl << std::endl;
		Bureaucrat Marc("Marc", 150);
		std::cout << Marc << std::endl;
		std::cout << "new stage form" << std::endl;
		AForm stage("stage form", 149, 150);
		std::cout << stage << std::endl;
		stage.beSigned(Marc);
		std::cout << stage << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test no error sign form already sign-########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 150);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		AForm stage("stage form",150, 150);
		std::cout << stage << std::endl;
		Bernard.signForm(stage);
		std::cout << stage << std::endl;
		Bernard.signForm(stage);
		std::cout << stage << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test  error bad grade form -########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 150);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		AForm stage("stage form",151, 150);
		std::cout << stage << std::endl;
		Bernard.signForm(stage);
		std::cout << stage << std::endl;
		Bernard.signForm(stage);
		std::cout << stage << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << std::endl << "----########-test exec special form-########----"<< std::endl << std::endl;
	try
	{
		std::cout << std::endl << "########-test no error exec shrubbery-########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 1);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		ShrubberyCreationForm shrubbery("field");
		std::cout << shrubbery << std::endl;
		Bernard.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		Bernard.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		shrubbery.execute(Bernard);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test no error exec presidential pardon-########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 1);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		PresidentialPardonForm pardon("regis");
		std::cout << pardon << std::endl;
		Bernard.signForm(pardon);
		std::cout << pardon << std::endl;
		Bernard.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(Bernard);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test no error exec robotomy-########"<< std::endl << std::endl;
		Bureaucrat Bernard("Bernard", 1);
		std::cout << Bernard << std::endl;
		std::cout << "new stage form" << std::endl;
		RobotomyRequestForm random("alive");
		std::cout << random << std::endl;
		Bernard.signForm(random);
		std::cout << random << std::endl;
		Bernard.signForm(random);
		std::cout << random << std::endl;
		random.execute(Bernard);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}