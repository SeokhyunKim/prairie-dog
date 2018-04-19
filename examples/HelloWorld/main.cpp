#include <prdog/prdog.hpp>
#include <iostream>

using namespace prdog;

class TestAgent {
    public:
        TestAgent(){}
        void initialize(const AgentAddr& selfAddr, const prdog::ParamMap& parmas) {
            mMyAddr = selfAddr;
            cout << "init at " << mMyAddr.toString() << endl;
        }

        void update(SimMediator& simMediator) {
            //cout << "update..." << simMediator.getCurTime() << endl;
            Message::sptr msg = Message::sptr(
                    new StringMessage(1, simMediator.getCurTime(), mMyAddr, AgentAddr(2), "test"));
            simMediator.sendMessage(msg);
        }
            
        list<Event::sptr> getNextEvent() {
            list<Event::sptr> events;
            events.push_back(Event::sptr(nullptr));
            return events;
        }

        void onMessage(Message::sptr msg) {
            StringMessage::sptr ssptr = dynamic_pointer_cast<StringMessage>(msg);
        }

    private:
        AgentAddr mMyAddr;
};


int main(int argc, char* argv[]) {
    using namespace std;

    try {
        prdog::ParamMap params;
        params[ParamKey::NUM_AGENTS] = "3";
        params[ParamKey::UPDATE_PERIOD] = "0.5";
        params[ParamKey::LOG_LEVEL] = "1";
        params[ParamKey::MESSAGE_DELAY] = "0.25";
        prdog::Sim sim;
        sim.initialize<TestAgent>(params);
        sim.run(3);
    } catch (std::exception& e) {
        cout << e.what() << endl;
    }

    cout << "Hello world, I'm PrairieDog." << endl;
    return 0;
}
