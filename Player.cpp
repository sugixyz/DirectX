#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Bullet.h"
#include"Engine/Collider.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel(-1)
{
}

void Player::Initialize()
{
	hModel = Model::Load("StarFox.fbx");
	assert(hModel >= 0);

	hp = 5;

	transform_.position_ = { transform_.position_.x,0.0f,-3.0f };
	//transform_.scale_ = { 0.5f,0.5f,0.5f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.2f;
		transform_.rotate_.y -= 2.0f;
	}

	//右移動
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.2f;
		transform_.rotate_.y += 2.0f;
	}

	//弾の発射
	if (Input::IsKeyDown(DIK_SPACE))
	//if(Input::IsKey(DIK_SPACE))
	{
		Bullet* b = Instantiate<Bullet>(this->GetParent());
		b->SetPosition(transform_.position_);
		b->SetRotate(transform_.rotate_);
		float radY = XMConvertToRadians(transform_.rotate_.y);
		velocity_ = XMFLOAT3(sinf(radY), 0.0f, cosf(radY));
		b->SetVelocity(velocity_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy" || pTarget->GetObjectName() == "Enemy")
	{
		pTarget->KillMe();
		hp--;
	}
}
