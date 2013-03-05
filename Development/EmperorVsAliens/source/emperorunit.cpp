#include "emperorunit.h"

#include <iostream>
using namespace std;

EmperorUnit::EmperorUnit(Field *pos)
: Unit(pos)
{
	dest = NULL;
}

void EmperorUnit::loadBaseAttributes()
{
	backswingTime 		 = EMPEROR_UNIT_BACKSWING_TIME;
	travelTime 			 = EMPEROR_UNIT_TRAVEL_TIME;
	attributes.hitpoints = EMPEROR_UNIT_BASE_HITPOINTS;
	attributes.damage	 = EMPEROR_UNIT_BASE_DAMAGE;
	attributes.defense	 = EMPEROR_UNIT_BASE_DEFENSE;
}

void EmperorUnit::createPath()
{
	if(!dest)
		cout << "SEM DESTINO!" << endl;
	else
		cout << "COM DESTINO!" << endl;
}

void EmperorUnit::move()
{
	Unit::move();
	//TODO: verificar qual a direcao para atribuir valores corretos as velocidades
	speed.x = -EMPEROR_UNIT_SPEED_X;
	speed.y = 0;
}

void EmperorUnit::attack()
{
	Unit::attack();
	
	target->receiveDamage(attributes.damage);
	if(target->status == UNIT_DEAD)
	{
		status = UNIT_IDLE;
		target = NULL;
	}
}

bool EmperorUnit::isAlien()
{
	return false;
}

void EmperorUnit::getTarget()
{
	for(int way=0; way<8; way++)
		if(mPosition->path[way]->habitant && !mPosition->path[way]->locked)
		{
			interact((Unit *)mPosition->path[way]->habitant);
			break;
		}
	//TODO: checar se e uma posicao com "alvo de construcao objetivo" se nao procurar alvos ao redor...
	//cout << "Attacking wall!" << endl;
	//startAttack(this);
}