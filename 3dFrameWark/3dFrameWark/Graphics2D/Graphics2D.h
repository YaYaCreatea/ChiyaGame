#ifndef _GRAPHICS_2D_H_
#define _GRAPHICS_2D_H_

#include "../Utility/Vector2/Vector2.h"
#include "../AnimatedSprite/AnimatedSprite.h"

#include <string>
#include <unordered_map>

class Graphics2D
{
public:
	//������
	static void initialize();

	//�摜�t�@�C���̓ǂݍ���
	static void load_sprite(int id, const std::string& file_name);

	//�摜�t�@�C���ǂݍ���(�����w�肠��)
	static void load_sprite(int id, const std::string& file_name, int row, int column);

	//�`��(�摜�S��)
	static void draw_sprite(int id, const Vector2& position);

	//�`��(�摜��1������`��)
	static void draw_sprite_rect(int id, const Vector2& position, int x, int y, int w, int h);

	//�`��(��`�E���S�E�T�C�Y)
	static void draw_sprite_RCS(int id, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::Zero, const Vector2& scale = Vector2::One);

	//�`��(��`�E���S�E�T�C�Y�E�A���t�@�l)
	static void draw_sprite_RCS_Alpha(int id, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::Zero, const Vector2& scale = Vector2::One, int m_alpha = 255);

	//�`��(�t���[���p)
	static void draw_sprite_Frame(int id, const Vector2& position, const Vector2& scale = Vector2::One);

	//�`��(�t���[���p)
	static void draw_sprite_Frame4(int id, const Vector2& position, const Vector2& scale = Vector2::One);

	//�`��(�����ԍ��w��)
	static void draw_sprite(int id, int div_no, const Vector2& position, const Vector2& center = Vector2::Zero, const Vector2& scale = Vector2::One, float rotation = 0.0f);

	//�`��(�A�j���[�V�����w��)
	static void draw_sprite(int id, int animation, float time, const Vector2& position, const Vector2& center = Vector2::Zero, const Vector2& scale = Vector2::One, float rotation = 0.0f);

	//�A�j���[�V�����̒ǉ�
	static void add_sprite_animation(int id, int animation, int start, int end, float time);

	//�L�[�t���[����ǉ�
	static void add_sprite_key_frame(int id, int animation, float time, int div_no);

	//�L�[�t���[����ǉ�
	static void add_sprite_key_frame(int id, int animation, float time, int x, int y, int w, int h);

	//�X�v���C�g�폜
	static void delete_sprite(int id);

	//�A�j���[�V�����I�����Ԃ��擾
	static float get_sprite_animation_end_time(int id, int animation);

	//�����J���[�̐ݒ�
	static void clear_color(float r, float g, float b);

	//�O���t�B�b�N�X�̏I������
	static void finalize();

private:
	static std::unordered_map<int, AnimatedSprite>sprite_map_;
};

#endif