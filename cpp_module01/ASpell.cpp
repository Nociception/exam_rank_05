#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects) : _name(name), _effects(effects) {}
		
ASpell::ASpell(const ASpell& src) {*this= src;}

ASpell&	ASpell::operator=(const ASpell& src)
{
	this->_name = src.getName();
	this->_effects = src.getEffects();

	return *this;
}
	
ASpell::~ASpell() {}

void	ASpell::launch(const ATarget& target) const {target.getHitBySpell(*this);}

const std::string& ASpell::getName() const {return this->_name;}
const std::string& ASpell::getEffects() const {return this->_effects;}