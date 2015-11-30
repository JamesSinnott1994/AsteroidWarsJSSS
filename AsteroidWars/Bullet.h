#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
	Bullet(Vector2f pos, Vector2f vel);

	void Update();
	void Draw(RenderWindow &window);
private:
	Vector2f m_position;
	Vector2f m_velocity;

	Texture m_texture;
	Sprite m_sprite;

	float m_speed;
};

#endif