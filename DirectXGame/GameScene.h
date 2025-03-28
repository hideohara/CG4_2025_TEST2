#pragma once

#include <KamataEngine.h>


#include "Particle.h"
#include "Effect.h"
#include "GameScore.h"
#include "HitPoint.h"
#include "ShipLeft.h"

using namespace KamataEngine;
using namespace MathUtility;

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene
{
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	// テクスチャハンドル プレイヤー 
	//uint32_t textureHandlePlayer_ = 0;


	// カメラ
	Camera camera_;

	// 各クラス
	GameScore* gameScore_ = nullptr;
	HitPoint* hitPoint_ = nullptr;
	ShipLeft* shipLeft_ = nullptr;

	// 3Dモデル パーティクル 
	Model* modelParticle_ = nullptr;
	// パーティクル
	std::list<Particle*> particles_;
	// パーティクル移動の速さ
	static inline const float particleSpeed = 0.1f;
	// パーティクル発生
	void ParticleBorn(Vector3 position);

	// 3Dモデル エフェクト
	Model* modelEffect_ = nullptr;
	// エフェクト
	std::list<Effect*> effects_;
	// エフェクト発生
	void EffectBorn(Vector3 position);
};

