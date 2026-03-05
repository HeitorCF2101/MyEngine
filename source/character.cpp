#include <iostream>
#include <string>
#include <thread>
#include <limits>

using namespace std;

// Character class to hold character properties and methods
class Character{
    public:
        string name;
        string sprite;
        int health;

        // Method to initialize a character
        void init(const string &characterName, const string &characterSprite, int characterHealth){
            name = characterName;
            sprite = characterSprite;
            health = characterHealth;
            
        }

        // Method to render character with its current health
        void renderCharacter(){
            cout << name << "\t" << "Health: " << health << "\n";
            cout << sprite << "\n";
        }

        // Method to check if the character is alive
        bool isAlive() const {
            return health > 0;
        }

};

class Attack{
    public:
        Character* attacker;
        string name;
        int damage;
        string type;

        // Method to initialize an attack
        void init(Character* attacker, const string &attackName, int attackDamage, const string &attackType){
            this->attacker = attacker;
            name = attackName;
            damage = attackDamage;
            type = attackType;
        }

        // Method to execute the attack on a target character
        void attackTarget(Character &target){
            cout << "\n" << name << " uses " << name << "!\n" << "and deals " << damage << " " << type << " damage to " << target.name << "!\n";
            target.health -= damage;
        }

};