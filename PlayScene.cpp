#include "PlayScene.h"
#include"Engine/SceneManager.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Engine/Model.h"

//メンバの初期化に使う
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

//ゲームの設定に使う初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	//Instantiate<Bullet>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr) {
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
