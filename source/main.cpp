#include <iostream>
#include <string>
#include <thread>
#include <limits>

using namespace std;

// Character structure to hold character properties and methods
/*struct Character{
    string name;
    string sprite;
    int health;
    int damage;

    // Method to render character with its current health
    void renderCharacter(){
        cout << name << "\t" << "Health: " << health << "\n";
        cout << sprite << "\n";
    }

    // Method for attacking another character
    void attack(Character &target){
        cout << name << " attacks " << target.name << " and deals " << damage << " damage!\n";
        target.health -= damage;
    }

};

// Function to initialize a character
void initCharacter(Character &character, string name, string sprite, int health, int damage){
    character.name = name;
    character.sprite = sprite;
    character.health = health;
    character.damage = damage;
}*/

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

// Function to update and render all characters in the scene
void update(Character &character1, Character &character2){
    system("clear"); // Use "cls" for windows and "clear" for Linux/MacOS
    cout << "Hero vs Enemy\n";
    character1.renderCharacter();
    cout << "\n";
    character2.renderCharacter();
}

int main(){
    // loop variable
    bool running = true;

    // create characters
    Character hero, enemy;
    hero.init("Hero", "(._.)", 100);
    enemy.init("Enemy", "(.o.)", 50);

    //create player input variable
    string playerInput;
    
    //create references to characters
    Character &heroRef = hero;
    Character &enemyRef = enemy;

    // create hero's attacks
    Attack heroAttacks[3];
    heroAttacks[0].init(nullptr, "magical slash", 20, "raw magic");
    heroAttacks[1].init(nullptr, "thunderbolt", 20, "electric");
    heroAttacks[2].init(nullptr, "fireball", 20, "fire");

    // create enemy's attacks
    Attack enemyAttacks[1];
    enemyAttacks[0].init(nullptr, "claw swipe", 10, "physical");

    // Initial render
    update(heroRef, enemyRef);

    // main game loop
    while(running == true){
        cout << "Enter 'a' to attack or 'q' to quit: ";
        cin >> playerInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        if(playerInput == "a"){
            cout << "\nChoose an attack:\n";
            for(int i = 0; i < 3; i++){
                cout << i+1 << ". " << heroAttacks[i].name << " (Damage: " << heroAttacks[i].damage << ", Type: " << heroAttacks[i].type << ")\n";
            }
            int attackChoice;
            cin >> attackChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            if(attackChoice >= 1 && attackChoice <= 3){
                this_thread::sleep_for(chrono::seconds(2)); // Pause for a moment before attacks
                heroAttacks[attackChoice - 1].attackTarget(enemy);
                if(enemy.health > 0){
                    enemyAttacks[0].attackTarget(hero);
                } else {
                    cout << enemy.name << " has been defeated!\n";
                    running = false;
                    break;
                }
                if(hero.health <= 0){
                    cout << hero.name << " has been defeated!\n";
                    running = false;
                    break;
                }
            } 
            else {
                cout << "Invalid attack choice. Please try again.\n";
                this_thread::sleep_for(chrono::seconds(1)); // Pause for a moment before re-rendering
            }
        //function to update the scene in the loop
        update(heroRef, enemyRef);
    }
    if(playerInput == "q" || hero.health <= 0 || enemy.health <= 0){
            running = false;
            break;
        }
    }

    update(heroRef, enemyRef);

    // Announce the result of the battle
    if(enemy.health <= 0){
        cout << enemy.name << " has been defeated!\n";
    }
    if(hero.health <= 0){
        cout << hero.name << " has been defeated!\n";
    }
    
    return 0;
}