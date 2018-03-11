#include "prdog_common.hpp"

using namespace prdog;

Sim::Sim(unique_ptr<AgentVectorCreator> creator) {
    mAgentVectorCreator.reset(creator.release());
}

Sim::~Sim() {
}

void Sim::initialize(map<string, real> params) {
    mAgents = mAgentVectorCreator->create(params);
    for ( auto& agent : mAgents ) {
        agent->initialize(params);
    }
}

void Sim::initialize(map<string, real> params, Runner::sptr runner) {
    mRunner = runner;
    initialize(params);
}

void Sim::clear() {
    mAgents.clear();
}

void Sim::run(real dt) {
}

int Sim::getSums(list<string>& keys, map<string, real>& sums) {
    for (string& key : keys) {
        real sum = 0.0;
        for ( auto& agent : mAgents ) {
            sum += agent->getValue(key);
        }
        sums[key] = sum;
    }
    return mAgents.size();
}

int Sim::getVars(list<string>& keys, map<string, real>& vars) {
    map<string, real> sums;
    int num = getSums(keys, sums);
    for (string& key : keys) {
        real var = 0.0;
        real avg = sums[key] / (real)num;
        for ( auto& agent : mAgents ) {
            real val = agent->getValue(key);
            var += (avg-val)*(avg-val);
        }
    }
    return mAgents.size();
}

