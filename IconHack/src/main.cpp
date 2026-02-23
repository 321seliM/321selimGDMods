 /**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

/**
 * `$modify` lets you extend and modify GD's classes.
 * To hook a function in Geode, simply $modify the class
 * and write a new function definition with the signature of
 * the function you want to hook.
 *
 * Here we use the overloaded `$modify` macro to set our own class name,
 * so that we can use it for button callbacks.
 *
 * Notice the header being included, you *must* include the header for
 * the class you are modifying, or you will get a compile error.
 *
 * Another way you could do this is like this:
 *
 * struct MyMenuLayer : Modify<MyMenuLayer, MenuLayer> {};
 */
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <set>
std::set<int> unobtainCubes = { 156, 157, 169, 170, 182, 183, 187, 193, 194, 195, 197, 198, 201, 208, 209, 210, 211, 214, 215, 216, 219, 220, 223, 224, 234, 241, 243, 248, 251, 252, 254, 257, 258, 260, 262, 266, 277, 279, 283, 286, 288, 292, 297, 304, 305, 306, 307, 310, 311, 320, 321, 324, 327, 332, 337, 339, 343, 346, 347, 351, 354, 357, 362, 363, 364, 369, 370, 372, 375, 378, 379, 381, 387, 390, 399, 400, 401, 411, 412, 413, 416, 417, 422, 423, 424, 427, 430, 433, 434, 435, 439, 440, 442, 444, 445, 447, 448, 449, 451, 452, 454, 455, 458, 460, 462, 468, 469, 470, 472, 473, 475, 477, 479, 481, 484 };
std::set<int> unobtainShips = { 54, 56, 57, 61, 67, 68, 74, 76, 84, 86, 92, 93, 95, 100, 101, 102, 104, 106, 107, 109, 113, 115, 117, 118, 120, 125, 128, 133, 139, 145, 147, 149, 151, 152, 153, 154, 155, 157, 158, 159, 165, 167 };
std::set<int> unobtainBalls = { 47, 48, 50, 51, 59, 63, 73, 74, 86, 95, 97, 99, 100, 108, 114 };
std::set<int> unobtainUfos = { 41, 43, 44, 46, 48, 49, 50, 51, 54, 55, 57, 59, 60, 62, 64, 65, 66, 68, 69, 70, 72, 76, 82, 88, 89, 90, 92, 96, 98, 101, 105, 109, 110, 111, 112, 113, 114, 115, 116, 120, 122, 124, 125, 129, 130, 131, 133, 134, 139, 145, 147 };
std::set<int> unobtainWaves = { 39, 40, 44, 48, 55, 61, 67, 69, 70, 83, 86, 88, 95 };
std::set<int> unobtainRobots = {};
std::set<int> unobtainSpiders = { 27, 30, 31, 33, 37, 40, 68 };
std::set<int> unobtainSwings = { 5, 24, 33 };
std::set<int> unobtainJetpacks{ 7 };


class $modify(GameManager) {
	bool isIconUnlocked(int id, IconType type) {
		auto unobtains = Mod::get()->getSettingValue<bool>("Unobtainable Icons");

		if (unobtains) {
			if (unobtainCubes.contains(id) && type == IconType::Cube)
			{
				return true;
			}
			if (unobtainShips.contains(id) && type == IconType::Ship)
			{
				return true;
			}
			if (unobtainBalls.contains(id) && type == IconType::Ball)
			{
				return true;
			}
			if (unobtainUfos.contains(id) && type == IconType::Ufo)
			{
				return true;
			}
			if (unobtainWaves.contains(id) && type == IconType::Wave)
			{
				return true;
			}
			if (unobtainRobots.contains(id) && type == IconType::Robot)
			{
				return true;
			}
			if (unobtainSpiders.contains(id) && type == IconType::Spider)
			{
				return true;
			}
			if (unobtainSwings.contains(id) && type == IconType::Swing)
			{
				return true;
			}
		}
		auto cubes = Mod::get()->getSettingValue<bool>("Cubes");
		if (cubes) { if (type == IconType::Cube) { return true; } }
		auto ships = Mod::get()->getSettingValue<bool>("Ships");
		if (ships) { if (type == IconType::Ship) { return true; } }
		auto balls = Mod::get()->getSettingValue<bool>("Balls");
		if (balls) { if (type == IconType::Ball) { return true; } }
		auto ufos = Mod::get()->getSettingValue<bool>("Ufos");
		if (ufos) { if (type == IconType::Ufo) { return true; } }
		auto waves = Mod::get()->getSettingValue<bool>("Waves");
		if (waves) { if (type == IconType::Wave) { return true; } }
		auto robots = Mod::get()->getSettingValue<bool>("Robots");
		if (robots) { if (type == IconType::Robot) { return true; } }
		auto spiders = Mod::get()->getSettingValue<bool>("Spiders");
		if (spiders) { if (type == IconType::Spider) { return true; } }
		auto swings = Mod::get()->getSettingValue<bool>("Swings");
		if (swings) { if (type == IconType::Swing) { return true; } }
		auto jetpacks = Mod::get()->getSettingValue<bool>("Jetpacks");
		if (jetpacks) { if (type == IconType::Jetpack) { return true; } }
		auto trails = Mod::get()->getSettingValue<bool>("Trails");
		if (trails) { if (type == IconType::Special) { return true; } }
		auto shipFires = Mod::get()->getSettingValue<bool>("Ship Fires");
		if (shipFires) { if (type == IconType::ShipFire) { return true; } }
		auto deathEffects = Mod::get()->getSettingValue<bool>("Death Effects");
		if (deathEffects) { if (type == IconType::DeathEffect) { return true; } }

		return GameManager::isIconUnlocked(id, type);
	}

	bool isColorUnlocked(int id, UnlockType type) {
		auto colors = Mod::get()->getSettingValue<bool>("Colors");
		if (colors) { return true; }


		return GameManager::isColorUnlocked(id, type);
	};
};

class $modify(GameStatsManager) {
	bool isItemUnlocked(UnlockType type, int id) {
		auto animations = Mod::get()->getSettingValue<bool>("Animations");
		if ((id >= 18 && id <= 20 ) && animations) {
			return true;
		}

		
		return GameStatsManager::isItemUnlocked(type, id);
	}
};

