#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel(-1)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("StarFox2.fbx");
	assert(hModel >= 0);

	transform_.position_ = { 0,0,10};
	transform_.rotate_.y = 180;
	//tr.scale_ = { 0.5f,0.5f,0.5f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();
		KillMe();
	}
}
