#pragma once

#include <string>

class	Warlock
{
	private :
		std::string	_name;
		std::string	_title;

		Warlock(const Warlock& src);
		Warlock&	operator=(const Warlock& src);

	public :
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		void	introduce() const;

		const std::string& getName() const;
		const std::string& getTitle() const;
		void	setTitle(const std::string& title);
};