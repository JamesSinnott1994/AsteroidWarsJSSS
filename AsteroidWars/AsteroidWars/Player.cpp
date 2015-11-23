#include "stdafx.h"
#include "Player.h"

Player::Player(int windowWidth, int windowHeight)
{
	// Load main menu background image
	m_playerTexture.loadFromFile("Pics/PlayerSpaceship.png");
	m_playerSprite = sf::Sprite(m_playerTexture);

	m_squareTexture.loadFromFile("Pics/Square.png");
	m_squareSprite = sf::Sprite(m_squareTexture);

	// Set position
	m_position.x = windowWidth / 2;
	m_position.y = windowHeight / 2;
	m_playerSprite.setPosition(m_position);

	// Set velocity
	m_velocity.x = 0.1f;
	m_velocity.y = 0.1f;

	// Set origin
	m_playerSprite.setOrigin(
		m_position.x - 10,
		m_position.y + 10
		);

	// Scale
	m_playerSprite.setScale(0.125f, 0.125f);

	// Rotation
	m_rotation = 0.25f;

	time = 0;
}

void Player::Update()
{
	// Keyboard input
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		m_rotation = -0.25f;
		m_playerSprite.rotate(m_rotation);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		m_rotation = 0.25f;
		m_playerSprite.rotate(m_rotation);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		m_position += m_velocity;
		m_playerSprite.setPosition(m_position);
	}

	// Set velocity
	m_velocity.x = (float)cos(m_playerSprite.getRotation()) * 2;
	m_velocity.y = (float)sin(m_playerSprite.getRotation()) * 2;

	time++;
	if (time > 100)
	{
		/*cout << "m_velocity.x: " << m_velocity.x << endl;
		cout << "m_velocity.y: " << m_velocity.y << endl;
		time = 0;*/
		
		cout << m_playerSprite.getRotation() << endl;
	}

	m_squareSprite.setPosition(m_playerSprite.getPosition());
}

void Player::Draw(RenderWindow &window)
{
	window.draw(m_playerSprite);
	window.draw(m_squareSprite);
}