#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using str = std::string; 

class Hero{
public:
    str name; 
    int health;
    virtual void show_stats(){
        cout << "The hero - " << name << endl;
        cout << "Hero health - " << health << endl;
    }

    virtual void useAbility(){
        cout << name << " does something basic." << endl;
    }
    
    virtual ~Hero(){}

};

class Wizard : public Hero{
public:
    int mana;

    void show_stats() override{
        cout << "Hero mana - " << mana << endl;
    }

    void useAbility() override {
        if (mana < 50){
            cout << "[" << name << "] cast a magic swords!" << endl;
        } else{
            cout << "[" << name << "] cast a FIREBALL!" << endl;
        }
    }

    void cast_Spell(){
        cout << "[" << name << "] cast a spell !!!" << endl;
    }

    

};

class Warrior : public Hero{
public:
    int protection;

    void show_stats() override{
        cout << "Hero protection - " << protection << endl;
    }

    void useAbility() override{
        cout << "[" << name << "] use mode 'THE BERSERK!'" << endl;
        protection += 50; 
    };

    void attack(){
        cout << "[" << name << "] slashes with a sword!" << endl;
    }
};

int main(){
    system("cls");

    Wizard human;           Warrior people;      
    human.name = "Alpha";   people.name = "Stiki";
    human.health = 100;     people.health = 120;
    human.mana = 75;        people.protection = 50;

    std::vector<Hero*>party;
    party.push_back(&human); party.push_back(&people);

    /*
    human.show_stats(); people.show_stats();
    human.cast_Spell(); people.attack();

    human.useAbility(); people.useAbility();
    */

    for (Hero* h : party){
        h->show_stats();
        h->useAbility();
    }

}