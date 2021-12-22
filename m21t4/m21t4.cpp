#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Entity {
	std::string name = "Unknown";
	int health = 0;
	int armor = 0;
	int damage = 0;
	struct {
		int x = 0;
		int y = 0;
	} pos;
};

bool save(const std::string& path, std::vector<Entity>& charapters) {
	std::ofstream file(path, std::ios::binary);
	if (!file.is_open())
		return false;

	for (int i = 0; i < charapters.size(); ++i) {
		Entity& entity = charapters[i];
		size_t len = entity.name.length();
		file.write((char*)&len, sizeof(len));
		file.write(entity.name.c_str(), len);
		file.write((char*)&entity.health, sizeof(entity.health));
		file.write((char*)&entity.armor, sizeof(entity.armor));
		file.write((char*)&entity.damage, sizeof(entity.damage));
		file.write((char*)&entity.pos.x, sizeof(entity.pos.x));
		file.write((char*)&entity.pos.y, sizeof(entity.pos.y));
	}

	file.close();
	return true;
}

bool load(const std::string& path, std::vector<Entity>& charapters) {
	std::ifstream file(path, std::ios::binary);
	if (!file.is_open())
		return false;

	while (!file.eof()) {
		Entity entity;
		size_t len = 0;
		file.read((char*)&len, sizeof(len));
		if (file.gcount() > 0) {
			entity.name.resize(len);
			file.read((char*)entity.name.c_str(), len);
			file.read((char*)&entity.health, sizeof(entity.health));
			file.read((char*)&entity.armor, sizeof(entity.armor));
			file.read((char*)&entity.damage, sizeof(entity.damage));
			file.read((char*)&entity.pos.x, sizeof(entity.pos.x));
			file.read((char*)&entity.pos.y, sizeof(entity.pos.y));
			charapters.push_back(entity);
		}
	}

	file.close();
	return true;
}

void initGame(std::vector<Entity>& charapters, int countEnemy) {
	Entity player;

	std::cout << "Welcome to Green Wood!" << std::endl;
	std::cout << "Enter your name: ";
	std::cin >> player.name;
	std::cout << "Enter parametrs [Health Armor Damage]: ";
	std::cin >> player.health >> player.armor >> player.damage;
	player.pos = { 19, 19 };

	charapters.push_back(player);
	
	std::cout << "Good! Creationg enemy for you..." << std::endl;

	std::srand((unsigned int)std::time(nullptr));
	for (int i = 0; i < countEnemy; ++i) {
		Entity enemy;
		
		enemy.name = "Enemy #" + std::to_string(i);
		enemy.health = 50 + (std::rand() % 101);
		enemy.armor = std::rand() % 51;
		enemy.damage = 15 + (std::rand() % 16);
		enemy.pos = { std::rand() % 40, std::rand() % 40 };

		charapters.push_back(enemy);
	}

	std::cout << "Created " << charapters.size() - 1 << " enemy. Game started." << std::endl;
}

void showMap(std::vector<Entity>& charapters) {
	const int maxSize = 40;
	char map[maxSize][maxSize]{ 0 };
	for (int i = 0; i < maxSize; ++i) {
		for (int j = 0; j < maxSize; ++j) {
			map[i][j] = '.';
		}
	}
	for (int i = 0; i < charapters.size(); ++i) {
		Entity& entity = charapters[i];
		if (entity.health > 0)
			map[entity.pos.y][entity.pos.x] = i == 0 ? 'P' : 'E';
	}
	for (int i = 0; i < maxSize; ++i) {
		for (int j = 0; j < maxSize; ++j) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void entityFight(Entity& who, Entity& whom) {
	whom.armor -= who.damage;
	if (whom.armor < 0)
	{
		whom.health += whom.armor;
		whom.armor = 0;
	}
	if (whom.health < 1) {
		std::cout << who.name << " killed " << whom.name << ". Damage: " << who.damage << "." << std::endl;
		whom.health = 0;
	}
	else
		std::cout << who.name << " attack " << whom.name << ". Damage: " << who.damage << ". " << whom.name << " HP: " << whom.health << std::endl;
}

bool entityMove(Entity& entity, int offset[2]) {
	const int maxSize = 40;

	int moveTo[2] = { entity.pos.x + offset[0], entity.pos.y + offset[1] };
	if (moveTo[0] < 0 || moveTo[0] >= maxSize || moveTo[1] < 0 || moveTo[1] >= maxSize)
		return false;
	entity.pos = { moveTo[0], moveTo[1] };

	return true;
}

void moveEntityOnMap(std::vector<Entity>& charapters, Entity& entity, int offset[2]) {
	int lpos[2]{ entity.pos.x, entity.pos.y };
	bool moved = entityMove(entity, offset);
	if (moved) {
		for (int i = 0; i < charapters.size(); ++i) {
			Entity& ch = charapters[i];
			if (ch.name != entity.name
					&& ch.health > 0
					&& ch.pos.x == entity.pos.x
					&& ch.pos.y == entity.pos.y) {
				if (ch.name == charapters[0].name || entity.name == charapters[0].name)
				{
					ch.pos = { lpos[0], lpos[1] };
					entityFight(entity, ch);
				}
				else
					entity.pos = { lpos[0], lpos[1] };
				break;
			}
		}
	}
}

void enemyMove(std::vector<Entity>& charapters) {
	std::srand((unsigned int)std::time(nullptr));
	for (int i = 1; i < charapters.size(); ++i) {
		if (charapters[i].health > 0) {
			int moveTo[2]{ 0 };
			int vec = std::rand() % 2;
			moveTo[vec] = std::rand() % 2 ? 1 : -1;
			moveEntityOnMap(charapters, charapters[i], moveTo);
		}
	}
}

int aliveEntity(std::vector<Entity>& charapters) {
	int co = 0;
	for (auto& entity : charapters) {
		if (entity.health > 0)
			co++;
	}
	return co;
}

void showEntity(Entity& entity) {
	std::cout << "--- " << entity.name << " ---" << std::endl;
	std::cout << "- Health: " << entity.health << std::endl;
	std::cout << "- Damage: " << entity.damage << std::endl;
	std::cout << "- Armor: " << entity.armor << std::endl;
	std::cout << "- Position: " << entity.pos.x << ", " << entity.pos.y << std::endl;
	std::cout << "--- =========== ---" << std::endl;
}

int main()
{
	const int enemies = 5;
	const std::string saveFile("save.bin");
	std::vector<Entity> charapters;

	std::string act;

	load(saveFile, charapters);

	if (charapters.size() < 2) {
		initGame(charapters, enemies);
	}

	Entity& player = charapters[0];
	showMap(charapters);

	while (aliveEntity(charapters) > 1 && player.health > 0) {
		std::cout << "Action: ";
		std::cin >> act;

		if (act == "save")
		{
			if (save(saveFile, charapters))
				std::cout << "Game saved" << std::endl;
			else
				std::cout << "Failed loading save file" << std::endl;
		}
		else if (act == "load")
		{
			if (load(saveFile, charapters))
				std::cout << "Game loaded" << std::endl;
			else
				std::cout << "Failed loading save file" << std::endl;
		}
		else if (act == "status" || act == "me")
			showEntity(player);
		else if (act == "enemy") {
			for (int i = 1; i < charapters.size(); ++i) {
				if (charapters[i].health > 0)
					showEntity(charapters[i]);
			}
		}
		else {
			int moveTo[2]{ 0 };
			if (act == "left")
				moveTo[0] = -1;
			else if (act == "right")
				moveTo[0] = 1;
			else if (act == "top")
				moveTo[1] = -1;
			else if (act == "bottom")
				moveTo[1] = 1;
			moveEntityOnMap(charapters, player, moveTo);
			enemyMove(charapters);
			showMap(charapters);
		}
	}

	if (player.health < 1)
		std::cout << "Game over! You lose :(" << std::endl;
	else {
		showEntity(player);
		std::cout << "Game over! You won the game!!!" << std::endl;
	}
	charapters.clear();
	save(saveFile, charapters);
}