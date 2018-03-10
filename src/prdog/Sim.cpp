#include "prdog_common.hpp"

using namespace prdog;

Sim::Sim(unique_ptr<AgentVectorCreator> creator) {
    mAgentVectorCreator.reset(creator.release());
}

Sim::~Sim() {
}

void Sim::initialize(map<string, real> params) {
    mAgentPtrs = mAgentVectorCreator->create(params);
    for ( auto& agentPtr : mAgentPtrs ) {
        agentPtr->initialize(params);
    }
}

void Sim::initialize(map<string, real> params, RunnerPtr runner) {
    mRunnerPtr = runner;
    initialize(params);
}

void Sim::clear() {
    mAgentPtrs.clear();
}

void Sim::run(real dt) {
}

int Sim::getSums(list<string>& keys, map<string, real>& sums) {
    for (string& key : keys) {
        real sum = 0.0;
        for ( auto& agentPtr : mAgentPtrs ) {
            sum += agentPtr->getValue(key);
        }
        sums[key] = sum;
    }
    return mAgentPtrs.size();
}

int Sim::getVars(list<string>& keys, map<string, real>& vars) {
    map<string, real> sums;
    int num = getSums(keys, sums);
    for (string& key : keys) {
        real var = 0.0;
        real avg = sums[key] / (real)num;
        for ( auto& agentPtr : mAgentPtrs ) {
            real val = agentPtr->getValue(key);
            var += (avg-val)*(avg-val);
        }
    }
    return mAgentPtrs.size();
}

