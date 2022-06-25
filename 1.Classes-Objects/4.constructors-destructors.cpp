#include <cstdio>
#include <string>
using namespace std;


const string unk = "unknown";
const string clone_prefix = "clone-";

// interface
class Animal {
    string _type  = "";
    string _name  = "";
    string _sound = "";
    // Animal(); prevents calling empty default constructor
public:
    Animal();   // default constructor
    Animal(const string & type, const string & name, const string & sound); 
    Animal(const Animal &); // copy constructor
    Animal & operator = (const Animal &);   // copy operator
    ~Animal(); // destructor

    void print() const;
};

// Implementation
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
    : _type(type), _name(name), _sound(sound) {
    puts("copy constructor");
}

Animal::Animal(const Animal & rhs) {
    puts("copy constructor");
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator = (const Animal & rhs) {
    puts("copy constructor operator");
    if(this != &rhs) {
        _name  = clone_prefix + rhs._name;
        _type  = rhs._type;
        _sound = rhs._sound;
    }
    return *this;
}

int main() {
    // contructor ran as unkown
    Animal a;
    a.print();

    const Animal b("cat", "fluffy", "meow");
    b.print();

    const Animal c(b);
    c.print();

    // unknown construct ran first time, running operator now
    a = c;
    a.print();

    // normal contruct because declaration and assignment in one line
    const Animal d = b;
    
    return 0;
}