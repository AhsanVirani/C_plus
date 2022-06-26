#include <iostream>
#include <string>
using namespace std;

// Fur class
class Fur {
    string _quality;
    Fur() {}
protected:
    Fur(const string & f) : _quality(f) {}
public:
    const string & quality() { return _quality; }
};

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
    void speak() const;
    // getters
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
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
class Cat : public Animal, public Fur
{
    int _fed = 0;
public:
    Cat( string n ) : Animal( n, "cat", "meow" ), Fur("Silky"), _fed(0) {};
    int fed() { return ++_fed; }
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

    Morgon.speak();
    cout << "walked: " << Morgon.walk() << endl;
    Lee.speak();
    cout << "fed: " << Lee.fed() << " grooms her: " << Lee.quality() << endl;
    Sam.speak();
    cout << "petted: " << Sam.pet() << endl;

    return 0;
}
