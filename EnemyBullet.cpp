#include"EnemyBullet.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"SphereCollider.h"
#include"SceneManager.h"
#include"Player.h"
#include<cmath>

namespace 
{
	const int DeadLine = -20;
	int rot = 180;
	float MoveX = 0.1f;
	const float pi = 3.14f;
}

EnemyBullet::EnemyBullet(GameObject* parent)
	:GameObject(parent,"EnemyBullet"),hModel_(-1),movevalue(0.0f)
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize()
{
	hModel_ = Model::Load("Assets//Oden.fbx");
	transform_.scale_ = { 0.1,0.1,0.1 };
	transform_.rotate_.x = 180;
	SphereCollider* col = new SphereCollider(0.3f);
	this->AddCollider(col);
}

void EnemyBullet::Update()
{
	Player* player = (Player*)FindObject("Player");//‹¤’Ê

	transform_.position_.y -= 0.3;
	transform_.rotate_.y += 3;

	if (transform_.position_.y <= DeadLine)//‹¤’Ê
	{
		KillMe();
	}
}

void EnemyBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void EnemyBullet::Release()
{
}

void EnemyBullet::OnCollision(GameObject* pTarget)
{
	if (pTarget == FindObject("Player"))
	{
 		KillMe();
		pTarget->KillMe();
	}
}
