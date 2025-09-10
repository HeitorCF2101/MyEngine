#include <iostream>
#include <string>

using namespace std;

// Character class to hold character properties and methods
class Character{
    public:
        string name;
        string sprite;
        int health;

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

class Hero : public Character{
    public:
        void init(const string &heroName, const string &heroSprite, int heroHealth){
            name = heroName;
            sprite = heroSprite;
            health = heroHealth;
        }
};
