#include <iostream>
#include <string>
using namespace std;

// Animal Class (base)
class Animal {
    // private members - only available to Animal class
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal() {}
protected:
    // protected constructor for use by derived classes
    Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}
public:
    // virtual tells the base that a dervied class version of overloaded method may exist and look for it
    virtual void speak() const;
    // getters
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }

    // if virtual defined then requires custom destructor
    virtual ~Animal() {}
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
};

// Dog class - derived from Animal
class Dog : public Animal
{
    int _walked = 0;
public:
    Dog( string n ) : Animal( n, "dog", "woof" ), _walked(0) {};
    int walk() { return ++_walked; }
};

// Cat class - derived from Animal
class Cat : public Animal
{
    int _fed = 0;
public:
    Cat( string n ) : Animal( n, "cat", "meow" ), _fed(0) {};
    int fed() { return ++_fed; }
    // calls this and animal version for cat pointer
    void speak() const { Animal::speak(); puts("Purrrrrr"); }
};

// Pig class - derived from Animal
class Pig : public Animal
{
    int _petted = 0;
public:
    Pig( string n ) : Animal( n, "pig", "oink" ), _petted(0) {};
    int pet() { return ++_petted; }
};

int main() 
{
    Dog Morgon = Dog("Morgon");
    Cat Lee = Cat("Lee");
    Pig Sam = Pig("Sam");

    // Morgon.speak();
    // cout << "walked: " << Morgon.walk() << endl;
    // Lee.speak();
    // cout << "fed: " << Lee.fed() << endl;
    // Sam.speak();
    // cout << "petted: " << Sam.pet() << endl;

    // only animal version of speak called out unless market virtual
    Animal * an[] = { &Morgon, &Lee, &Sam };
    for(auto animal: an) {
        animal->speak();
    }

    return 0;
}
