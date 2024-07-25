#pragma once

#include <string>

class ATarget;

class	ASpell
{
	private :
		std::string	_name;
		std::string	_effects;

	public :
		ASpell(const std::string& name, const std::string& effects);
		ASpell(const ASpell& src);
		ASpell&	operator=(const ASpell& src);
		virtual ~ASpell();

		virtual ASpell*	clone() const = 0;
		void	launch(const ATarget& target) const;

		const std::string& getName() const;
		const std::string& getEffects() const;
};