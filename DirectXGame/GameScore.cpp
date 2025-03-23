#include "GameScore.h"

// デストラクタ
GameScore::~GameScore()
{
}

// 初期化
void GameScore::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("number.png");

	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, { 0, 0 });
}

// 毎フレーム処理
void GameScore::Update()
{
}

// 描画
void GameScore::Draw()
{
	sprite_->Draw();
}
