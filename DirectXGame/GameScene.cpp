#include "GameScene.h"
#include <random>


std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

// コンストクラタ
GameScene::GameScene()
{
}

// デストラクタ
GameScene::~GameScene() {
	delete modelPlayer_;

	for (Particle* particle : particles_) {
		delete particle;
	}

	delete gameScore_;
	delete hitPoint_;
	delete shipLeft_;
}

// 初期化
void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ファイル名を指定してテクスチャを読み込む
	textureHandlePlayer_ = TextureManager::Load("mario.jpg");

	// 3Dモデルの生成
	//modelPlayer_ = Model::Create();
	//modelPlayer_ = Model::CreateFromOBJ("plane",true);
	//modelPlayer_ = Model::CreateFromOBJ("deathParticle", true);
	modelPlayer_ = Model::CreateSphere(4, 4);

	// 乱数初期化
	srand((unsigned int)time(NULL));

	// カメラ初期化
	camera_.Initialize();

	// 各クラス
	gameScore_ = new GameScore();
	gameScore_->Initialize();
	hitPoint_ = new HitPoint();
	hitPoint_->Initialize();
	shipLeft_ = new ShipLeft();
	shipLeft_->Initialize();
}

// 更新
void GameScene::Update() {

	// パーティクル発生
	//if (input_->TriggerKey(DIK_SPACE)) {
	if (rand()%20 == 0) {
		// パーティクル発生
		Vector3 position = { distribution(randomEngine), distribution(randomEngine), 0 };
		position *= 10;
		ParticleBorn(position);
	}

	// 各クラス
	for (Particle* particle : particles_) {
		particle->Update();
	}
	gameScore_->Update();
	hitPoint_->Update();
	shipLeft_->Update();

	// デスフラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
		});
}

// 描画
void GameScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	// 各クラス
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}

	// 3Dオブジェクト描画後処理
	Model::PostDraw();

	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	gameScore_->Draw();
	hitPoint_->Draw();
	shipLeft_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

}

// パーティクル発生
void GameScene::ParticleBorn(Vector3 position)
{
	for (int32_t i = 0; i < 100; i++) {
		Particle* particle = new Particle();
		Vector3 velocity = { distribution(randomEngine), distribution(randomEngine), 0 };
		Normalize(velocity);
		velocity *= distribution(randomEngine) * particleSpeed;
		particle->Initialize(modelPlayer_, textureHandlePlayer_, position, velocity);
		// 敵を登録する
		particles_.push_back(particle);
	}
}
