#include <prdog/prdog.hpp>
#include <iostream>

using namespace prdog;

class TestAgent {
    public:
        TestAgent(){}
        void initialize(const prdog::ParamMap& parmas) {
            cout << "init..." << endl;
        }

        void update(SimMediator& simMediator) {
            //cout << "update..." << simMediator.getCurTime() << endl;
        }
            
        Event::sptr getNextEvent() {
            return Event::sptr(nullptr);
        }

        void onMessage(Message::sptr) {
        }
};


int main(int argc, char* argv[]) {
    using namespace std;

    try {
        prdog::ParamMap params;
        params[ParamKey::NUM_AGENTS] = "3";
        params[ParamKey::UPDATE_PERIOD] = "0.5";
        params[ParamKey::LOG_LEVEL] = "1";
        prdog::Sim sim;
        sim.initialize<TestAgent>(params);
        sim.run(3);
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "Hello world, I'm PrairieDog." << endl;
    return 0;
}
