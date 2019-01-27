#ifndef _ANIMATED_SPRITE_H_
#define _ANIMATED_SPRITE_H_

#include <unordered_map>
#include <vector>

#include "../Utility/Vector2/Vector2.h"

//�A�j���[�V�����t���X�v���C�g�N���X
class AnimatedSprite
{
public:
	//�R���X�g���N�^
	AnimatedSprite() = default;

	//�f�X�g���N�^
	~AnimatedSprite();

	//�摜�t�@�C���̓ǂݍ���
	void load(const std::string& file_name);

	//�摜�t�@�C���̓ǂݍ���
	void load(const std::string& file_name, int row, int column);

	//�`��(�摜�S��)
	void draw(const Vector2& position)const;

	//�`��(�摜�̈ꕔ����`��)
	void draw(const Vector2& position, int x, int y, int width, int height)const;

	//�`��(��`�{���S�{�T�C�Y)
	void draw(const Vector2& position, int x, int y, int width, int height, const Vector2& center, const Vector2& scale)const;

	//�`��(�����ԍ��w��)
	void draw(int no, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;

	//�`��(�A�j���[�V�����w��)
	void draw(int animation, float time, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;

	//�A�j���[�V�����ǉ�
	void add_animation(int animation, int start, int end, float time);

	//�L�[�t���[����ǉ�
	void add_key_frame(int animation, float time, int graph_no);

	//�L�[�t���[����ǉ�
	void add_key_frame(int animation, float time, int x, int y, int width, int height);

	//�A�j���[�V�����I�����Ԃ��擾
	float animation_end_time(int animation)const;

	//����
	void clear();

	//�R�s�[�֎~
	AnimatedSprite(const AnimatedSprite& other) = delete;
	AnimatedSprite& operator=(const AnimatedSprite& other) = delete;

private:
	//�����摜
	using DivGraphs = std::vector<int>;

	//�L�[�t���[��
	using KeyFrame = std::pair<float, int>;

	//�L�[�t���[���z��
	using KeyFrames = std::vector<KeyFrame>;

	//�A�j���[�V�����z��
	using Animations = std::unordered_map<int, KeyFrames>;

private:
	//�L�[�t���[������
	const KeyFrame& find_key_frame(int animation, float time)const;

private:
	//���摜
	int graph_{ -1 };

	//�����摜
	DivGraphs div_graphs_;

	//�A�j���[�V�����f�[�^
	Animations animations_;

};

#endif