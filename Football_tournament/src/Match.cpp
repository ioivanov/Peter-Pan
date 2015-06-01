#include "Match.h"

Match::Match(Team _team1, Team _team2) :
		A(_team1), B(_team2), ball(60, 45), game() {
}

void Match::setStartPosition(Team A_, Team B_) {

}

void Match::setZones() {
	A.players[0].setZone(105, 25, 120, 65);
	A.players[1].setZone(105, 45, 120, 90);
	A.players[2].setZone(105, 0, 120, 45);
	A.players[3].setZone(80, 45, 105, 90);
	A.players[4].setZone(80, 0, 105, 45);
	A.players[5].setZone(40, 67, 80, 90);
	A.players[6].setZone(40, 45, 80, 67);
	A.players[7].setZone(40, 23, 80, 45);
	A.players[8].setZone(40, 0, 80, 23);
	A.players[9].setZone(0, 45, 40, 90);
	A.players[10].setZone(0, 0, 40, 45);

	B.players[0].setZone(0, 25, 25, 65);
	B.players[1].setZone(0, 65, 25, 90);
	B.players[2].setZone(0, 0, 25, 45);
	B.players[3].setZone(25, 45, 50, 90);
	B.players[4].setZone(25, 0, 50, 45);
	B.players[5].setZone(50, 67, 90, 90);
	B.players[6].setZone(50, 45, 90, 67);
	B.players[7].setZone(50, 23, 90, 45);
	B.players[8].setZone(50, 0, 90, 23);
	B.players[9].setZone(90, 45, 120, 90);
	B.players[10].setZone(90, 0, 120, 45);
}

bool Match::playerIsCloseToTheBall(Player p) {
	if (p.zone(ball))
		return true;
	return false;
}

int Match::ballStatus(Player p) {
	if (A.hasPlayer(p)) {
		for (int i = 0; i < 11; i++) {
			if (ball == A.players[i].getPosition())
				return 1;
		}
	} else {
		for (int i = 0; i < 11; i++) {
			if (ball == B.players[i].getPosition())
				return 1;
		}
	}
	return 0;
}

void Match::move(Player p) {
	if (ball == p.getPosition()) {
		ball = p.whatToDoWithTheBall();
	} else if (ballStatus(p) == 1) {
		p.run(WITH_THE_TEAM);
	} else {
		if (playerIsCloseToTheBall(p))
			p.run(TO_THE_BALL);
		else
			p.run(CHILL);
	}

}

void Match::playMatch() {
	for (int min = 1; min <= 90; min++) {
		for (int i = 0; i < 11; i++) {
			move(A.players[i]);
			move(B.players[i]);
		}
	}
}
