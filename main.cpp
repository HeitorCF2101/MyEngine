#include <iostream>
#include <string>
#include <thread>

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
    // create characters
    Character hero, enemy;
    initCharacter(hero, "Hero", "(._.)", 100, 10);
    initCharacter(enemy, "Enemy", "(o-o)", 50, 5);
    
    //create references to characters
    Character &heroRef = hero;
    Character &enemyRef = enemy;

    // Initial render
    cout << "Hero vs Enemy\n";
    hero.renderCharacter();
    cout << "\n";
    enemy.renderCharacter();

    // Combat loop
    while(enemy.health > 0 && hero.health > 0){
        // Pause for 2 seconds to simulate time between actions
        this_thread::sleep_for(chrono::seconds(2));
        hero.attack(enemy);
        enemy.attack(hero);
        // another pause before updating the scene
        this_thread::sleep_for(chrono::seconds(2));
        //function to update the scene in the loop
        update(heroRef, enemyRef);
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