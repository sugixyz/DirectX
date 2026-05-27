#include "PlayScene.h"
#include"Engine/SceneManager.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"

namespace
{
	const int ENEMY_CREATE_INTERVAL = 1.0f;
	const int CLEAR_TIME = 5.0f;
}

//メンバの初期化に使う
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

//ゲームの設定に使う初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	//Instantiate<Enemy>(this);

	//Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	//Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	counter++;
	gGameCounter++;
	//指定間隔ごとに敵を生成
	if (counter >= ENEMY_CREATE_INTERVAL * 60)
	{
		Instantiate<Enemy>(this);
		counter = 0;
	}
	//指定時間耐久したうえ、敵を全滅させればクリア
	if (gGameCounter >= CLEAR_TIME * 60 && FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
