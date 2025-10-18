#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class badEgg : public std::exception {
public:
    const char* what() const noexcept override {
        return "EWWWWWW! You ate a BAD egg!";        
    }
};

class egg
{
private:
    string flavor;
    string size;
public:

    egg (string f, string s)
    {
        flavor = f;
        size = s;
    }

    void eatEgg()
    {
        cout << "Yum! You ate a " << flavor << " egg of size " << size << ".";
    }


};

class goodEgg : public egg
{
public:
    goodEgg(string f, string s) : egg(f, s) {}

    void eatEgg()
    {
        egg::eatEgg();
        cout << " That was a good egg!" << endl;
    }

};

class rottenEgg : public egg
{
public:
    rottenEgg(string f, string s) : egg(f, s) {}
    void eatEgg()
    {
        throw badEgg();
    }
};

class chocolateEgg : public egg
{
public:
    chocolateEgg(string f, string s) : egg(f, s) {}
    void eatEgg()
    {
        egg::eatEgg();
        cout << " That was a delicious chocolate egg!" << endl;
    }
};

class carton
{
private:
    vector<egg*> eggs;
public:
    void addEgg(egg* e)
    {
        if (eggs.size() >= 12)
        {
            cout << "Carton is full!" << endl;
            return;
        }else
        {
            eggs.push_back(e);
        }
    }

    void eatNextEgg()
    {
        if (eggs.empty())
        {
            cout << "No more eggs to eat!" << endl;
            return;
        }
        egg* e = eggs.back();
        eggs.pop_back();
        try
        {
            e->eatEgg();
        }
        catch (badEgg& be)
        {
            cout << be.what() << endl;
        }
        delete e;
    }

};

int main()
{
    carton eggCarton;

    eggCarton.addEgg(new goodEgg("vanilla", "large"));
    eggCarton.addEgg(new chocolateEgg("chocolate", "medium"));
    eggCarton.addEgg(new egg("sulfur", "small"));
    eggCarton.addEgg(new rottenEgg("moldy", "small"));
    eggCarton.addEgg(new goodEgg("blueberry", "large"));
    eggCarton.addEgg(new chocolateEgg("white chocolate", "medium"));
    eggCarton.addEgg(new goodEgg("strawberry", "large"));
    eggCarton.addEgg(new rottenEgg("rotten", "small"));
    eggCarton.addEgg(new chocolateEgg("dark chocolate", "medium"));
    eggCarton.addEgg(new goodEgg("pumpkin spice", "large"));
    eggCarton.addEgg(new chocolateEgg("milk chocolate", "medium"));
    eggCarton.addEgg(new egg("lemon", "large"));

    for (int i=0; i < 12; i++)
    {
        eggCarton.eatNextEgg();
    }

    return 0;
}