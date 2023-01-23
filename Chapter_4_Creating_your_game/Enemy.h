//
// Created by daniel on 23/01/23.
//
#pragma once
#include "SFML/Graphics.hpp"
#ifndef C___GAME_DEV_ENEMY_H
#define C___GAME_DEV_ENEMY_H

class Enemy
{
public:
    Enemy();
    ~Enemy();
    void init(std::string textureName, sf::Vector2f position, float _speed);
    void update(float dt);
    sf::Sprite getSprite();
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    float m_speed;
};


#endif //C___GAME_DEV_ENEMY_H
