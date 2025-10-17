#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>

class badEgg : public std::exception {
public:
    const char* what() const noexcept override {
        return "EWWWWWW! You ate a BAD egg!";        
    }
};

class egg
{

};

class goodEgg : public egg
{

};

class rottenEgg : public egg
{

};

class chocolateEgg : public egg
{

};

class carton
{

};

int main()
{

}