#include "ProjectileManager.h"
#include <algorithm>
#include <iostream>

//void ProjectileManager::CreateProjectile(sf::Vector2f position)
//{
//		//projectiles_.emplace_back();
//
//		//projectiles_.back().Load("data/PNG/Lasers/laserBlue05.png", { 0, -1 }, 600);
//		//projectiles_.back().SetPosition(position);
//}
//
//void ProjectileManager::Update(float dt, sf::RenderWindow& window)
//{
//	//erase_if(projectiles_, [&window](Projectile& p)
//	//	{
//	//		return p.getPosition().y < 0 || p.getPosition().y > window.getSize().y;
//	//	});
//
//	//for(auto& p : projectiles_)
//	//{
//	//	p.Move(dt);
//	//}
//}
//
//void ProjectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	//for (auto& projectile : projectiles_)
//	//{
//	//	target.draw(projectile);
//	//}
//}