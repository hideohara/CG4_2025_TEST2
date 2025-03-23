#include "ShipLeft.h"

// デストラクタ
ShipLeft::~ShipLeft()
{
	for (int32_t i = 0; i < 5; i++) {
		delete sprite_[i];
	}
}

// 初期化
void ShipLeft::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");

	// スプライトの生成
	for (int32_t i = 0; i < 5; i++) {
		sprite_[i] = Sprite::Create(textureHandle_, {400.0f + 60.0f * i, 20.0f});
		// サイズを変更
		sprite_[i]->SetSize({sizeX, sizeY});
	}
}

// 毎フレーム処理
void ShipLeft::Update()
{
	// ライフを減らす
	timer_++;
	if (timer_ >= 50) {
		timer_ = 0;
		life_--;
		if (life_ < 0) {
			life_ = 5u;
		}
	}
}

// 描画
void ShipLeft::Draw()
{
	for (int32_t i = 0; i < life_; i++) {
		sprite_[i]->Draw();
	}
}

