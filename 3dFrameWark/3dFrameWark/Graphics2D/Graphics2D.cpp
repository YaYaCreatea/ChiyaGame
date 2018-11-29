#include "Graphics2D.h"
#include <DxLib.h>

std::unordered_map<int, AnimatedSprite> Graphics2D::sprite_map_;

void Graphics2D::initialize()
{
	sprite_map_.clear();
}

void Graphics2D::load_sprite(int id, const std::string & file_name)
{
	sprite_map_[id].load(file_name);
}

void Graphics2D::load_sprite(int id, const std::string & file_name, int row, int column)
{
	sprite_map_[id].load(file_name, row, column);
}

void Graphics2D::draw_sprite(int id, const Vector2 & position)
{
	sprite_map_[id].draw(position);
}

void Graphics2D::draw_sprite(int id, const Vector2 & position, int x, int y, int w, int h)
{
	sprite_map_[id].draw(position, x, y, w, h);
}

void Graphics2D::draw_sprite(int id, int div_no, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float rotation)
{
	sprite_map_[id].draw(div_no, position, center, scale, rotation);
}

void Graphics2D::draw_sprite(int id, int animation, float time, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float rotation)
{
	sprite_map_[id].draw(animation, time, position, center, scale, rotation);
}

void Graphics2D::add_sprite_animation(int id, int animation, int start, int end, float time)
{
	sprite_map_[id].add_animation(animation, start, end, time);
}

void Graphics2D::add_sprite_key_frame(int id, int animation, float time, int div_no)
{
	sprite_map_[id].add_key_frame(animation, time, div_no);
}

void Graphics2D::add_sprite_key_frame(int id, int animation, float time, int x, int y, int w, int h)
{
	sprite_map_[id].add_key_frame(animation, time, x, y, w, h);
}

void Graphics2D::delete_sprite(int id)
{
	sprite_map_.erase(id);
}

float Graphics2D::get_sprite_animation_end_time(int id, int animation)
{
	return sprite_map_[id].animation_end_time(animation);
}

void Graphics2D::clear_color(float r, float g, float b)
{
	SetBackgroundColor(int(r*255.0f), int(g*255.0f), int(b*255.0f));
}

void Graphics2D::finalize()
{
	initialize();
}
