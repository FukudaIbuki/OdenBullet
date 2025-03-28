#include"ChildOden.h"
#include"Engine/GameObject.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"SphereCollider.h"
#include"SceneManager.h"
#include"Engine/Input.h"

ChildOden::ChildOden(GameObject* parent)
    :GameObject(parent, "ChildOden"), hModel(-1)
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
    //pFbx = new Fbx;
    //pFbx->Load("Assets/oden.fbx");
    hModel = Model::Load("Assets/Oden.fbx");
    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;
    transform_.position_.x = 2.0f;
    transform_.position_.y = 1.0f;
    SphereCollider* col = new SphereCollider(0.5f);
    AddCollider(col);
}

void ChildOden::Update()
{
    transform_.rotate_.y += 2.0;
    transform_.position_.y += 0.1;
    Enemy* enemy = (Enemy*)FindObject("Enemy");

    if (transform_.position_.y > 5.0)
    {
        KillMe();
    }

}

void ChildOden::Draw()
{
    //pFbx->Draw(transform_);
    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

void ChildOden::Release()
{
}

void ChildOden::OnCollision(GameObject* pTarget)
{
    if (pTarget == FindObject("Enemy"))
    {
        KillMe();
        pTarget->KillMe();
    }
}