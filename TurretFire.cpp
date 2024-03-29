#include "TurretFire.hpp"

#include <allegro5/base.h>

#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "BulletFire.hpp"
#include "Enemy.hpp"
#include "Group.hpp"
#include "Point.hpp"
#include "ScenePlay.hpp"
#include "Turret.hpp"
const int TurretFire::Price = 10;
TurretFire::TurretFire(float x, float y) : Turret("play/turret-3.png", x, y, 30, 100, Price, 0.7) {
}
void TurretFire::CreateBullet() {
    Engine::Point diff = Engine::Point(1, 0);
    float rotation = ALLEGRO_PI / 2;
    getPlayScene()->BulletGroup->AddNewObject(new BulletFire(Position, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
