#include <prdog/prdog.hpp>

using namespace prdog;

DiscretTimeRunner::DiscretTimeRunner() {
}

void DiscretTimeRunner::initialize(const map<string, real>& params) {
    mTimeStep = params.at("timeStep");
}

void DiscretTimeRunner::run(real dt) {

}
