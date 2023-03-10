//
// Created by daniel on 23/01/23.
//

#include "Hero.h"

Hero::Hero(){
}

Hero::~Hero(){
}

void Hero::init(std::string textureName, sf::Vector2f position, float mass)
{
    m_position = position;
    m_mass = mass;
    m_grounded = false;
    m_playerMovingRight = false;
    m_playerMovingLeft = false;
    m_x_speed = 120.0f;
    // Load a Texture
    m_texture.loadFromFile(textureName.c_str());
    // Create Sprite and Attach a Texture
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_texture.getSize().x / 2,
                       m_texture.getSize().y / 2);
}

void Hero::init(std::string textureName,
                int frameCount,
                float animDuration,
                sf::Vector2f position,
                float mass)
{
    m_position = position;
    m_mass = mass;
    m_grounded = false;
    m_frameCount = frameCount;
    m_animDuration = animDuration;
    // Load a Texture
    m_texture.loadFromFile(textureName.c_str());
    m_spriteSize = sf::Vector2i(92, 126);
    // Create Sprite and Attach a Texture
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,
                                        0,
                                        m_spriteSize.x,
                                        m_spriteSize.y));
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_texture.getSize().x / 2,
                       m_texture.getSize().y / 2);
}

void Hero::update(float dt){
    // Animate Sprite
//    m_elapsedTime += dt;
//    int animFrame = static_cast<int> ((m_elapsedTime / m_animDuration) * m_frameCount) % m_frameCount;
//    m_sprite.setTextureRect(sf::IntRect(animFrame * m_spriteSize.x,
//                                        0, m_spriteSize.x, m_spriteSize.y));
    // Update position
    m_velocity -= m_mass * m_gravity * dt;
    m_position.y -= m_velocity * dt;
    m_sprite.setPosition(m_position);
    if (m_position.y >= 768 * 0.75f) {
        m_position.y = 768 * 0.75f;
        m_velocity = 0;
        m_grounded = true;
        jumpCount = 0;
    }
    if (m_playerMovingRight) {
        m_sprite.move(m_x_speed * dt, 0);
        m_position.x += m_x_speed * dt;
    }
    if (m_playerMovingLeft) {
        m_sprite.move(-m_x_speed * dt, 0);
        m_position.x -= m_x_speed * dt;
    }
}

void Hero::jump(float velocity){
    if (jumpCount < 2) {
        jumpCount++;
        m_velocity = velocity;
        m_grounded = false;
    }
}

sf::Sprite Hero::getSprite(){
    return m_sprite;
}

void Hero::MoveLeft()
{
    m_playerMovingLeft = true;
}

void Hero::MoveRight()
{
    m_playerMovingRight = true;
}

void Hero::StopMovingLeft()
{
    m_playerMovingLeft = false;
}

void Hero::StopMovingRight()
{
    m_playerMovingRight = false;
}