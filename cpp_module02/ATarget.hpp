#pragma once

#include <string>

class ASpell;

class	ATarget
{
	private :
		std::string	_type;

	public :
		ATarget(const std::string& type);
		ATarget(const ATarget& src);
		ATarget&	operator=(const ATarget& src);
		virtual ~ATarget();

		virtual ATarget*	clone() const = 0;
		void	getHitBySpell(const ASpell& spell) const;

		const std::string& getType() const;
};