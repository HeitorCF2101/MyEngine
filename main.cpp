#include <iostream>
#include <string>

using namespace std;

struct Character{
    string name;
    string sprite;
    int health;
    int damage;

    void renderCharacter(){
        cout << name << "\t" << "Health: " << health << "\n";
        cout << sprite << "\n";
    }

};

void initCharacter(Character &character, string name, string sprite, int health, int damage){
    character.name = name;
    character.sprite = sprite;
    character.health = health;
    character.damage = damage;
}

int main(){
    Character hero, enemy;
    initCharacter(hero, "Hero", "(._.)", 100, 10);
    initCharacter(enemy, "Enemey", "(.o.)", 50, 5);

    hero.renderCharacter();
    cout << "\n";
    enemy.renderCharacter();
    
    return 0;
}