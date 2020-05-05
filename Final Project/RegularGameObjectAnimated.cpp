//
// Created by Peter Nguyen on 2018-12-06.
//

#include "RegularGameObjectAnimated.h"


bool RegularGameObjectAnimated::load(const std::string& filename) {
    if (m_texture.loadFromFile(filename)) {
        m_filename = filename;
        m_sprite.setTexture(m_texture);
        m_valid = true;
        std::string dragon = "/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/dragonsprites.png";
        std::string mario = "/Users/peternguyen/Desktop/ECE2036/2036SkeletonCmake/build/mariosprites.jpeg";
        if (dragon == filename) {
            sf::IntRect rectSourceSprite(0, 0, 90, 100);
            m_sprite.setTextureRect(rectSourceSprite);
        }
        else if(mario == filename){
            sf::IntRect rectSourceSprite(0, 0, 64, 130);
            m_sprite.setTextureRect(rectSourceSprite);
        }

        return true;
    }
    return false;
}

void RegularGameObjectAnimated::draw(sf::RenderWindow& window) {
    if (m_valid)
        window.draw(m_sprite);
}

void RegularGameObjectAnimated::update(float deltaT) {
//    printf("DeltaT: %f\n", deltaT);
    if (deltaT > 1.0f) {
        if (m_sprite.getTextureRect().left > 200) {
            int left = 0;
            sf::IntRect rectSourceSprite(left, 0, 90, 100);
            m_sprite.setTextureRect(rectSourceSprite);
        } else {
            int left = m_sprite.getTextureRect().left + 105;
            sf::IntRect rectSourceSprite(left, 0, 90, 100);
            m_sprite.setTextureRect(rectSourceSprite);
        }
    }
}

void RegularGameObjectAnimated::move(sf::Vector2f loc) {
    if (m_valid)
        m_sprite.move(loc);
}

void RegularGameObjectAnimated::setPosition(float x, float y) {
    if (m_valid)
        m_sprite.setPosition(x, y);
}

sf::Vector2f RegularGameObjectAnimated::getPosition() const {
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float RegularGameObjectAnimated::getHeight() const {
    return m_sprite.getLocalBounds().height;
}

float RegularGameObjectAnimated::getWidth() const {
    return m_sprite.getLocalBounds().width;
}

void RegularGameObjectAnimated::setScale(float scale) {
    if (m_valid)
        m_sprite.setScale(scale, scale);
}

bool RegularGameObjectAnimated::updateMario(float deltaT) {
//    printf("DeltaT: %f\n", deltaT);
    if (deltaT > 0.70f) {
        //do something for animation idk
        if (m_sprite.getTextureRect().left > 89) {
            int left = 0;
            sf::IntRect rectSourceSprite(left, 0, 64, 130);
            m_sprite.setTextureRect(rectSourceSprite);
        } else {
            int left = m_sprite.getTextureRect().left + 70;
            sf::IntRect rectSourceSprite(left, 0, 64, 130);
            m_sprite.setTextureRect(rectSourceSprite);
        }
    }
}