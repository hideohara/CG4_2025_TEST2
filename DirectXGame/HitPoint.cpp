#include "HitPoint.h"

// デストラクタ
HitPoint::~HitPoint()
{
	delete sprite_;
	delete spriteDark_;
}

// 初期化
void HitPoint::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("green.png");
	textureHandleDark_ = TextureManager::Load("greenDark.png");

	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, { 800, 20 });
	spriteDark_ = Sprite::Create(textureHandleDark_, { 800, 20 });

}

// 毎フレーム処理
void HitPoint::Update()
{
	// スコアアップ
	life_++;
	if (life_ > sizeX) {
		life_ = 0u;
	}

	// サイズを変更
	sprite_->SetSize({ life_, sizeY });
	spriteDark_->SetSize({ sizeX, sizeY });
}

// 描画
void HitPoint::Draw()
{
	spriteDark_->Draw();
	sprite_->Draw();
}
