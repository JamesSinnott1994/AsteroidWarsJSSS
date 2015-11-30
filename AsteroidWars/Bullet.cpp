#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vector2f pos, Vector2f vel)
{
	// Load main menu background image
	m_texture.loadFromFile("Pics/Bullet.png");
	m_sprite = sf::Sprite(m_texture);

	// Scale
	m_sprite.setScale(0.25f, 0.25f);

	m_position = pos;
	m_sprite.setPosition(m_position);

	m_speed = 3.0f;

	m_velocity.x = vel.x * m_speed;
	m_velocity.y = vel.y * m_speed;
}

void Bullet::Update()
{
	m_position += m_velocity;
	m_sprite.setPosition(m_position);
}

void Bullet::Draw(RenderWindow &window)
{
	window.draw(m_sprite);
}