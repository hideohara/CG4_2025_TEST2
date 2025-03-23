#include "Particle.h"

using namespace MathUtility;

// デストラクタ
Particle::~Particle()
{
}

// 初期化
void Particle::Initialize(Model* model, uint32_t textureHandle, Vector3 position)
{
	// システム
	input_ = Input::GetInstance();

	// 引数として受け取ったデータをメンバ変数に記録する
	textureHandle_ = textureHandle;
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	worldTransform_.translation_ = position;
}

// 更新
void Particle::Update()
{
	// キャラクターの移動速さ
	const float kCharacterSpeed = 0.1f;
	// キャラクターの移動ベクトル
	Vector3 move = { 0, kCharacterSpeed, 0 };

	worldTransform_.translation_ += move;
	//worldTransform_.rotation_.y = 3.14f;

	worldTransform_.UpdateMatrix();
}

// 描画
void Particle::Draw(Camera& camera)
{
	//model_->Draw(worldTransform_, camera, textureHandle_);
	model_->Draw(worldTransform_, camera);
}
