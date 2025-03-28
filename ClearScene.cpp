#include "ClearScene.h"
#include"SceneManager.h"
#include"Input.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hImage_(-1),spr_(nullptr)
{
}

void ClearScene::Initialize()
{
	spr_ = new Sprite();
	hImage_ = spr_->Load("Assets//GameClear.png");
}

void ClearScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)){
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScene::Draw()
{
	Transform trs;
	trs.position_ = { 0,0,0 };
	trs.scale_ = {1,1,1};
	spr_->Draw(trs);
}

void ClearScene::Release()
{
}
