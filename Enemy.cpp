#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"Bullet.h"

namespace
{
	const float SPEED = 1.0f;
	const float PAI = 3.141592653589793;
}

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel(-1)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("StarFox2.fbx");
	assert(hModel >= 0);

	float x = rand() % 101;
	transform_.position_ = { x,0,100};
	//transform_.rotate_.y = 180;

	GameObject* p = FindObject("Player");
	XMFLOAT3 pPos = p->GetPosition();
	XMVECTOR toPlayer = XMLoadFloat3(&pPos) - XMLoadFloat3(&transform_.position_);
	toPlayer = XMVector3Normalize(toPlayer) * SPEED;
	XMStoreFloat3(&velocity_, toPlayer);

	transform_.rotate_.y = 90 - (atan2(velocity_.z, velocity_.x) * 180 / PAI);


	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	transform_.position_.x += velocity_.x;
	transform_.position_.y += velocity_.y;
	transform_.position_.z += velocity_.z;

	if (transform_.position_.z <= -20.0f)KillMe();
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
