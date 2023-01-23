//
// Created by daniel on 23/01/23.
//

#include "SFML/Graphics.hpp"
#include <vector>
#include "Hero.h"
#include "Enemy.h"

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game !!!", sf::Style::Default);

void spawnEnemy();

sf::Vector2f playerPosition;
bool playerMoving = false;
sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture bgTexture;
sf::Sprite bgSprite;
Hero hero;
std::vector<Enemy*> enemies;

float currentTime;
float prevTime = 0.0f;

void init() {
    skyTexture.loadFromFile("Assets/graphics/sky.png");
    skySprite.setTexture(skyTexture);
    bgTexture.loadFromFile("Assets/graphics/bg.png");
    bgSprite.setTexture(bgTexture);
    hero.init("Assets/graphics/hero.png",
              sf::Vector2f(viewSize.x * 0.25f,viewSize.y * 0.5f),
              200);
    srand((int)time(0));
}

void updateInput() {
    sf::Event event;
    // while there are pending events...
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                hero.jump(750.0f);
            }
        }
        if (event.key.code == sf::Keyboard::Escape || event.type ==
                                                      sf::Event::Closed)
            window.close();
    }
}

void update(float dt) {
    hero.update(dt);
    currentTime += dt;
    // Spawn Enemies
    if (currentTime >= prevTime + 1.125f) {
        spawnEnemy();
        prevTime = currentTime;
    }
    // Update Enemies
    for (int i = 0; i < enemies.size(); i++) {
        Enemy *enemy = enemies[i];
        enemy->update(dt);
        if (enemy->getSprite().getPosition().x < 0) {
            enemies.erase(enemies.begin() + i);
            delete(enemy);
        }
    }
}

void draw() {
    window.draw(skySprite);
    window.draw(bgSprite);
    window.draw(hero.getSprite());
    for (Enemy *enemy : enemies) {
        window.draw(enemy->getSprite());
    }
}

int main() {
    sf::Clock clock;
    window.setFramerateLimit(60);
    init();
    while (window.isOpen()) {
        updateInput();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        window.clear(sf::Color::Red);
        draw();
        window.display();
    }
    return 0;
}

void spawnEnemy() {
    int randLoc = rand() % 3;
    sf::Vector2f enemyPos;
    float speed;
    switch (randLoc) {
        case 0: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
            speed = -400; break;
        case 1: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60f);
            speed = -550; break;
        case 2: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40f);
            speed = -650; break;
        default: printf("incorrect y value \n"); return;
    }
    Enemy* enemy = new Enemy();
    enemy->init("Assets/graphics/enemy.png", enemyPos, speed);
    enemies.push_back(enemy);
}