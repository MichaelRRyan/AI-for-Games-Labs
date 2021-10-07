#include "WanderBehaviour.h"

SteeringOutput WanderBehaviour::getSteering(SteeringInput t_input, float t_delta)
{
    SteeringOutput steering;

    if (rand() % 4 == 0)
    {
        if (rand() % 2 == 0)
            t_input.me->rotateLeft(t_delta);
        else
            t_input.me->rotateRight(t_delta);
    }

    return steering;
}
