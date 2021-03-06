#ifndef _STALKER_HH_
# define _STALKER_HH_

#include "Unit.hh"
#include "Stats.hh"

class Stalker : public Unit
{
public:
    UnitField getField() const override;
    unsigned int getCost() const override;
    unsigned int getAttackRange() const override;
    unsigned int getAttackMinRange() const override;
    unsigned int getAttackArea() const override;
    static Stats const& getBaseStats();
    void resetStats() override;
    void resetActions() override;
};

#endif
