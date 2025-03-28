#include "Effect.h"

#include <algorithm>

void Effect::Initialize(Model* model, Vector3 position, float rotate, float size)
{

// 引数として受け取ったデータをメンバ変数に記録する
	//textureHandle_ = textureHandle;
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	worldTransform_.translation_ = position;
	worldTransform_.rotation_.z = rotate;
	worldTransform_.scale_ = { 0.2f, size, 1.0f };

	objectColor_.Initialize();
	color_ = { 1, 1, 1, 1 };

}

void Effect::Update()
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

	worldTransform_.rotation_.y = 3.14f;

	// 色変更オブジェクトに色の数値を設定する
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	objectColor_.SetColor(color_);

	//worldTransform_.rotation_.z += 0.1f;

	worldTransform_.UpdateMatrix();


}

void Effect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, &objectColor_);

}
