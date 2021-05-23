#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "BulletPocky.hpp"
#include "Group.hpp"
#include "ScenePlay.hpp"
#include "Point.hpp"

class Turret;

BulletPocky::BulletPocky(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Bullet("play/bullet-2.png", 800, 1, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void BulletPocky::OnExplode(Enemy* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 10);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-2.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
