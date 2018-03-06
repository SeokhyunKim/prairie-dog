#include "Sim.hpp"

using namespace prdog;

Sim::Sim(unique_ptr<AgentPoolCreator> creator) {
    _agentPoolCreator = creator;
}

Sim::~Sim() {
}

void Sim::initialize(map<string, real> params) {
    _agentPool = _agentPoolCreator->create(params);
}

void Sim::clear() {
    _agentPool.reset();
}

void Sim::run(int numSteps, real dt) {
    while (numSteps-- > 0) {
        for (int i=0; i<_agentPool->size(); ++i) {
            _agentPool[i]->update(dt, *_simContext);
        }
    }
}

int Sim::getSums(list<string>& keys, map<string, real>& sums) {
    for (string& key : keys) {
        real sum = 0.0;
        for (int i=0; i<_agentPool->size(); ++i) {
            sum += _agentPool->getValue(key);
        }
        sums[key] = sum;
    }
    return _agentPool->size();
}

int Sim::getVars(list<string>& keys, map<string, real>& vars) {
    map<string, real> sums;
    int num = getSums(keys, sums);
    for (string& key : keys) {
        real var = 0.0;
        real sum = sums[key] / (real)num;
        for (int i=0; i<_agentPool->size(); ++i) {
            real val = _agentPool->getValue(key);
            var += (sum-val)*(sum-val);
        }
    }
    return _agentPool->size();
}

