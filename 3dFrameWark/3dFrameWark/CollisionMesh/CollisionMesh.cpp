#include "CollisionMesh.h"
#include "../CollisionTriangle/CollisionTriangle.h"
#include <DxLib.h>

//�o�C���h���̃��f��
int CollisionMesh::model_{ -1 };
//���f���A�Z�b�g
ModelAsset CollisionMesh::asset_;

//������
void CollisionMesh::initialize()
{
	finalize();
}

//�I������
void CollisionMesh::finalize()
{
	asset_.clear();
	model_ = -1;
}

//�ǂݍ���
bool CollisionMesh::load(int id, const std::string & file_name, int frame, int div_x, int div_y, int div_z)
{
	auto result = asset_.load(id, file_name);
	if (result)
	{
		//�Փ˔�������\�z
		MV1SetupCollInfo(asset_[id], frame, div_x, div_y, div_z);
	}
	return result;
}

//�폜
void CollisionMesh::erase(int id)
{
	model_ = (model_ == asset_[id]) ? -1 : model_;
	asset_.erase(id);
}

//���b�V���̃o�C���h
void CollisionMesh::bind(int id)
{
	model_ = asset_[id];
}

//�`��
void CollisionMesh::draw()
{
	MV1DrawModel(model_);
}

//�����Ƃ̏Փ˔���
bool CollisionMesh::collide_line(const Vector3 & start, const Vector3 & end, Vector3 * point, Vector3 * normal)
{
	const auto coll_poly = MV1CollCheck_Line(model_, 0, start, end);
	if (coll_poly.HitFlag == TRUE)
	{
		if (point != nullptr)
			*point = coll_poly.HitPosition;
		if (normal != nullptr)
			*normal = coll_poly.Normal;

		return true;
	}

	return false;
}

//���̂Ƃ̏Փ˔���
bool CollisionMesh::collide_sphere(const Vector3 & center, const Vector3&center2, float radius, Vector3 * result)
{
	//���ƃ��b�V���̏Փ˔���
	const auto coll_poly = MV1CollCheck_Capsule(model_, 0, center, center2, radius);
	//�Փ˂��Ă��Ȃ���ΏI��
	if (coll_poly.HitNum == 0)
	{
		//�Փ˔���f�[�^�̍폜
		MV1CollResultPolyDimTerminate(coll_poly);
		return false;
	}
	VECTOR result_center = center;
	//�|���S���̕��ʏ�ɋ��̂̈ʒu��␳����
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		//���ʏ�̍��W�̍ŋߓ_���W�����߂�
		PLANE_POINT_RESULT plane_point_result;
		Plane_Point_Analyse(&coll_poly.Dim[i].Position[0], &coll_poly.Dim[i].Normal, &result_center, &plane_point_result);
		//�O�p�`�̓����ɕ��ʏ�̍��W�̍ŋߓ_���W�����邩�ǂ������ׂ�
		if (CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).is_inside(plane_point_result.Plane_MinDist_Pos))
		{
			//�@���x�N�g���̕����֋��̂������o��
			const auto distance = std::sqrt(plane_point_result.Plane_Pnt_MinDist_Square);
			const auto offset = VScale(coll_poly.Dim[i].Normal, radius - distance);
			result_center = VAdd(result_center, offset);
		}
	}
	//�|���S���̃G�b�W�ɏd�Ȃ��Ă���ꍇ�Ɉʒu��␳����
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).collide_edge_and_sphere(result_center, radius, &result_center);
	}
	//�␳��̍��W��ݒ�
	if (result != nullptr)
	{
		*result = Vector3(result_center.x, result->y, result_center.z);
	}
	//�Փ˔���f�[�^�̍폜
	MV1CollResultPolyDimTerminate(coll_poly);
	return true;
}

bool CollisionMesh::collide_capsule(const Vector3 & center, const Vector3 & center2, float radius, Vector3 * result)
{
	//�J�v�Z���ƃ��b�V���̏Փ˔���
	const auto coll_poly = MV1CollCheck_Capsule(model_, -1, center, center2, radius);
	//�Փ˂��Ă��Ȃ���ΏI��
	if (coll_poly.HitNum == 0)
	{
		//�Փ˔���f�[�^�̍폜
		MV1CollResultPolyDimTerminate(coll_poly);
		return false;
	}
	VECTOR result_center = center;
	//�|���S���̕��ʏ�ɋ��̂̈ʒu��␳����
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		//���ʏ�̍��W�̍ŋߓ_���W�����߂�
		PLANE_POINT_RESULT plane_point_result;
		Plane_Point_Analyse(&coll_poly.Dim[i].Position[0], &coll_poly.Dim[i].Normal, &result_center, &plane_point_result);
		//�O�p�`�̓����ɕ��ʏ�̍��W�̍ŋߓ_���W�����邩�ǂ������ׂ�
		if (CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).is_inside(plane_point_result.Plane_MinDist_Pos))
		{
			//�@���x�N�g���̕����֋��̂������o��
			const auto distance = std::sqrt(plane_point_result.Plane_Pnt_MinDist_Square);
			const auto offset = VScale(coll_poly.Dim[i].Normal, radius - distance);
			result_center = VAdd(result_center, offset);
		}
	}
	//�|���S���̃G�b�W�ɏd�Ȃ��Ă���ꍇ�Ɉʒu��␳����
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).collide_edge_and_sphere(result_center, radius, &result_center);
	}
	//�␳��̍��W��ݒ�
	if (result != nullptr)
	{
		*result = Vector3(result_center.x, result->y, result_center.z);
	}
	//�Փ˔���f�[�^�̍폜
	MV1CollResultPolyDimTerminate(coll_poly);


	return true;
}
