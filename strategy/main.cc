#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Strategy{
public:
    virtual ~Strategy(){}
    virtual string DoAlgorithm(const vector<string>& data) const = 0;
};

class Context {
private:
    Strategy* strategy_;
public:
    Context(Strategy* strategy = nullptr): strategy_(strategy){}
    ~Context(){ delete this->strategy_;}
    void set_strategy(Strategy* strategy) {
        delete this->strategy_;
        this->strategy_ = strategy_;
    }

    void DoSomeBusinessLogic() const {
        cout << "Context: Sorting data or sth";
        string result = this->strategy_->DoAlgorithm(vector<string>{"a", "c", "e"});
    }
};

class ConcreteStrategyA: public Strategy {
public:
    string DoAlgorithm(const vector<string>& data) const override {
        string result;
        for_each(begin(data), end(data), [&result](const string &letter){
            result += letter;
        });
        sort(begin(result), end(result));
        return result;
    }
};

void ClientCode(){
    Context* context = new Context(new ConcreteStrategyA);
    cout << "Client: Strategy is set for sorting";
    context->DoSomeBusinessLogic();
    cout << "\n";
    delete context;
}

int main() {
    ClientCode();
    return 0;
}