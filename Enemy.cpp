#include "Enemy.h"
#include"Model.h"
#include"SphereCollider.h"
#include"EnemyBullet.h"
#include"Player.h"

namespace 
{
	int spawncount = 60;
}

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel(-1),SpawnTime_(spawncount)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets//enemy.fbx");
	transform_.position_.y = 2.0f;
	transform_.scale_ = { 0.1f,0.1f,0.1f };
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
}

void Enemy::Update()
{
	static int dt;
	dt += 5;
	float nTime = dt / (60.0f * 10.0f) - 2.0;
	transform_.position_.x = 4.0 * sin(nTime);

	if (--SpawnTime_ < 0)
	{
		SpawnTime_ = spawncount;
		EnemyBullet* pEB = Instantiate<EnemyBullet>(this);
		pEB->SetPosition(transform_.position_);
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
}


