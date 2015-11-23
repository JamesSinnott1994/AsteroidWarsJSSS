#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"

class Player
{
public:
	Player(int windowWidth, int windowHeight);

	void Update();
	void Draw(RenderWindow &window);
private:
	Vector2f m_position;
	Vector2f m_velocity;
	float m_rotation;

	Texture m_playerTexture;
	Sprite m_playerSprite;

	Texture m_squareTexture;
	Sprite m_squareSprite;

	int time;
};

#endif