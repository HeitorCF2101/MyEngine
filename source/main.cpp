#include <iostream>
#include <string>
#include <thread>
#include <limits>

using namespace std;

// Character structure to hold character properties and methods
struct Character{
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
}

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
    initCharacter(hero, "Hero", "(._.)", 100, 10);
    initCharacter(enemy, "Enemy", "(.o.)", 50, 5);

    //create player input variable
    string playerInput;
    
    //create references to characters
    Character &heroRef = hero;
    Character &enemyRef = enemy;

    // Initial render
    update(heroRef, enemyRef);

    // main game loop
    while(running == true){
        cout << "Enter 'a' to attack or 'q' to quit: ";
        cin >> playerInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        if(playerInput == "a"){
            hero.attack(enemy);
            if(enemy.health > 0){
                enemy.attack(hero);
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