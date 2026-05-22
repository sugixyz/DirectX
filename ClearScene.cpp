#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hTitlePic_(-1)
{
}

//初期化
void ClearScene::Initialize()
{
	hTitlePic_ = Image::Load("Clear.png");
	assert(hTitlePic_ >= 0);
}

//更新
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

//描画
void ClearScene::Draw()
{
	//transformは、位置、回転、拡縮の情報を持った構造体
	transform_.scale_ = { 1.0,1.0,1.0 }; //画像のサイズを変更
	Image::SetTransform(hTitlePic_, transform_); //画像の位置や向きなどを設定
	Image::Draw(hTitlePic_); //画像を描画
}

//開放
void ClearScene::Release()
{
}
