#include "bits/stdc++.h"
using namespace std;

class ICharacter {
	public:
	virtual string getAbility() = 0;
    virtual ~ICharacter() {}
};

class Mario : public ICharacter {
	string ch;
	public:
	Mario() {
		this->ch = "Mario ";
	}
	string getAbility() override {
		return ch;
	}
};

class CharacterDecorator : public ICharacter {
protected:
    ICharacter* ch;
public:
    CharacterDecorator(ICharacter* ch) : ch(ch) {}
};


class IDecorator : public ICharacter{
    protected:
    ICharacter *ch;
	public:
    IDecorator(ICharacter *ch) {
        this->ch = ch;
    }
	virtual string getAbility() = 0;
};

class HeightUPDeco : public IDecorator {

	string power;
	public:
	HeightUPDeco(ICharacter *ch)
        :IDecorator(ch)
    {
		this->power = "Height Up";
	}
	
	string getAbility() override {
		return ch->getAbility() + power;
	}
};

class GunPowerDeco : public IDecorator {
	// ICharacter *ch;
	string power;
	public:
	GunPowerDeco(ICharacter *ch)
    :IDecorator(ch)
    {
		this->power = "Gun power";
	}
	
	string getAbility() override {
		return ch->getAbility() + power;
	}
};

class StarPowerDeco : public IDecorator {
	// ICharacter *ch;
	string power;
	public:
	StarPowerDeco(ICharacter *ch)
     :IDecorator(ch) {
		this->power = "Star power";
	}
	
	string getAbility() override {
		return ch->getAbility() + power;
	}
};


int main() {
	class ICharacter *mar = new Mario();
	class IDecorator *powDec = new StarPowerDeco(new GunPowerDeco(new Mario()));
	cout<<powDec->getAbility()<<endl;
	
}
