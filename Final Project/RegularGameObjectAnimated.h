//
// Created by Peter Nguyen on 2018-12-06.
//

#ifndef INC_2036SKELETONCMAKE_REGULARGAMEOBJECTANIMATED_H
#define INC_2036SKELETONCMAKE_REGULARGAMEOBJECTANIMATED_H
#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class RegularGameObjectAnimated : public GameObject{
public:
    RegularGameObjectAnimated() {}

    bool load(const std::string& filename) override;

    void draw(sf::RenderWindow& window) override;

    void update(float deltaT) override;

    void setPosition(float x, float y) override;

    void move(sf::Vector2f) override;

    sf::Vector2f getPosition() const override;

    float getHeight() const override;

    float getWidth() const override;

    void setScale(float scale) override;

    bool updateMario(float deltaT);

private:
    int STATE = 0; //idle state
    std::vector<sf::Sprite*> m_sprites;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;
};

#endif //INC_2036SKELETONCMAKE_REGULARGAMEOBJECTANIMATED_H
