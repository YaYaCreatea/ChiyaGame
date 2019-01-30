#include "ModeSelectCamera.h"

#include "../../Graphics3D/Graphics3D.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"

ModeSelectCamera::ModeSelectCamera()
{
}

ModeSelectCamera::~ModeSelectCamera()
{
}

void ModeSelectCamera::update(float deltaTime)
{
	m_stageRotation *= Matrix::CreateRotationY(deltaTime / 10.0f);
	m_stageRotation.NormalizeRotationMatrix();

	m_position = m_stageRotation.Forward()*900.0f + Vector3{ 0.0f,400.0f,0.0f };
}

void ModeSelectCamera::drawBack()const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	SkyBox::bind(0);
	CollisionMesh::bind(0);
	SkyBox::draw();
	CollisionMesh::draw();

	Graphics3D::view_matrix(
		get_pose().CreateLookAt(m_position, Vector3::Zero, Vector3::Up)
	);

	Graphics3D::projection_matrix(
		Matrix::CreatePerspectiveFieldOfView(45.0f, 1280.0f / 720.0f, 4.0f, 1800.0f)
	);
}

Matrix ModeSelectCamera::get_pose() const
{
	return Matrix(m_stageRotation).Translation(m_position);
}
