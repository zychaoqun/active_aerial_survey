#pragma once
#include <memory>
#include "planner/behaviour_planner.h"

namespace asn
{

class mav;

class behaviour_controller
{
public:
    typedef std::shared_ptr<behaviour_controller> ptr;

public:
    behaviour_controller(mav &m);
    virtual ~behaviour_controller();

    void update(const double &dt);
    void draw();

private:
    mav & mav_;
    behaviour_planner::ptr behaviour_planner_;

    waypoint::ptr waypoint_;
    Vector3f last_sensing_pos_;
    bool sensing_;

};
}
