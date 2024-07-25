#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget(const std::string& type) : _type(type) {}
		
ATarget::ATarget(const ATarget& src) {*this= src;}

ATarget&	ATarget::operator=(const ATarget& src)
{
	this->_type = src.getType();

	return *this;
}
	
ATarget::~ATarget() {}

void	ATarget::getHitBySpell(const ASpell& spell) const 
{
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}

const std::string& ATarget::getType() const {return this->_type;}