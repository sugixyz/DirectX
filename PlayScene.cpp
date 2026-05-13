#include "PlayScene.h"
#include"Engine/Model.h"

//メンバの初期化に使う
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1),ot_()
{
}

//ゲームの設定に使う初期化
void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
	//タイマー
	static float timer = 0.0f;
	timer += 0.016f;

	//スケール
	ot_.scale_ = { 0.5, 0.5, 0.5 };

	//回転
	//ot_.rotate_.y += 1.0f;
	//ot_.rotate_.x += 0.5f;

	//サインを使って左右に動かす
	float posX = sinf(timer) * 5.0f;
	float posY = cosf(timer * 4.0f) * 2.0f;
	float posZ = 10;
	ot_.position_ = { posX,posY,posZ };
}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
