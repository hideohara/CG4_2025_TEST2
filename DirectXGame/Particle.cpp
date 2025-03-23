#include "Particle.h"

using namespace MathUtility;
#include <algorithm>

// デストラクタ
Particle::~Particle()
{
}

// 初期化
void Particle::Initialize(Model* model, uint32_t textureHandle, Vector3 position, Vector3 velocity)
{
	// システム
	input_ = Input::GetInstance();

	// 引数として受け取ったデータをメンバ変数に記録する
	textureHandle_ = textureHandle;
	model_ = model;
	velocity_ = velocity;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	worldTransform_.translation_ = position;
	worldTransform_.scale_ = { 0.2f, 0.2f, 0.2f };

	objectColor_.Initialize();
	color_ = { 1, 1, 0, 1 };
}

// 更新
void Particle::Update()
{
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// キャラクターの移動速さ
	//const float kCharacterSpeed = 0.1f;
	// キャラクターの移動ベクトル
	//Vector3 move = { 0, kCharacterSpeed, 0 };

	worldTransform_.translation_ += velocity_;
	//worldTransform_.rotation_.y = 3.14f;

	worldTransform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	objectColor_.SetColor(color_);

}

// 描画
void Particle::Draw(Camera& camera)
{
	//model_->Draw(worldTransform_, camera, textureHandle_);
	model_->Draw(worldTransform_, camera, &objectColor_);
}
