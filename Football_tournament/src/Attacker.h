/*
 * Attacker.h
 *
 *  Created on: May 24, 2015
 *      Author: ivko
 */

#ifndef ATTACKER_H_
#define ATTACKER_H_

#include "Player.h"

class Attacker : Player
{
	virtual ~Attacker();
	void act(Player*, Player*, Point);
};

#endif /* ATTACKER_H_ */
