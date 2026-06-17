#pragma once

#include "Entities/Entity.h"

class Enemy : public Entity {

	protected:
		float health_;
		float damage_;
		float speed_;
};