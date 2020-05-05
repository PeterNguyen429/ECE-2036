//
// Created by Peter Nguyen on 2018-12-06.
//

#ifndef INC_2036SKELETONCMAKE_REGULARGAMEOBJECT_H
#define INC_2036SKELETONCMAKE_REGULARGAMEOBJECT_H
#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class RegularGameObject : public GameObject {
public:
    RegularGameObject() {}

    bool load(const std::string& filename) override;

    void draw(sf::RenderWindow& window) override;

    void update(float deltaT) override;

    void setPosition(float x, float y) override;

    void move(sf::Vector2f) override;

    sf::Vector2f getPosition() const override;

    float getHeight() const override;

    float getWidth() const override;

    void setScale(float scale) override;


private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;

    float m_speed = 120.0f;
    bool m_left = false;
    bool m_right = false;
    bool m_up = false;
    bool m_down = false;
};

#endif //INC_2036SKELETONCMAKE_REGULARGAMEOBJECT_H
