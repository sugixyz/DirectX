#include "Bullet.h"
#include"Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel(-1),speed(2.0f)
{
}

void Bullet::Initialize()
{
	hModel = Model::Load("Bullet.fbx");
	assert(hModel >= 0);

	transform_.scale_ = { 0.2f,0.2f,0.2f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.3f);
	AddCollider(collider);
}

void Bullet::Update()
{
	transform_.position_.z += speed;
	if (transform_.position_.z >= 100.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Bullet::Release()
{
}
