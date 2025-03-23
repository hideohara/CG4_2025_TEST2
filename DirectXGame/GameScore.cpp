#include "GameScore.h"

// デストラクタ
GameScore::~GameScore()
{
	for (int32_t i = 0; i < 5; i++) {
		delete sprite_[i];
	}
}

// 初期化
void GameScore::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("number.png");

	// スプライトの生成
	for (int32_t i = 0; i < 5; i++) {
		sprite_[i] = Sprite::Create(textureHandle_, { 100.0f + 32.0f*i, 0 });
	}
}

// 毎フレーム処理
void GameScore::Update()
{
	// スコアアップ
	score_++;

	// ローカル変数にコピー
	int32_t score = score_;
	// 最初に割る数値
	int32_t digit = 10000;
	// 5桁分ループ
	for (int32_t i = 0; i < 5; i++) {
		// 今の桁の数値を取り出す
		int32_t number = score / digit;
		// 残りの桁の数値にする
		score %= digit;
		// 桁をずらす
		digit /= 10;
		// 今の桁の数値の部分を切り出すようにする
		sprite_[i]->SetTextureRect({ sizeX * number,0 }, { sizeX, sizeY });
		sprite_[i]->SetSize({ sizeX, sizeY });
	}
}

// 描画
void GameScore::Draw()
{
	for (int32_t i = 0; i < 5; i++) {
		sprite_[i]->Draw();
	}
}
