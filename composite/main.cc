#include<algorithm>
#include<iostream>
#include<list>
#include<string>

class Component {
protected:
    Component* parent_;
public:
    virtual ~Component() {};
    void SetParent(Component* parent) {
        this->parent_ = parent;
    }
    Component* GetParent() const{
        return this->parent_;
    }
    virtual void Add(Component* component) {}
    virtual void Remove(Component*) {}

    virtual bool isComposite() const {return false;}
    virtual std::string Operation() const = 0;
};

class Leaf: public Component {
public:
    std::string Operation() const override {return "Leaf";}
};

class Composite: public Component {
protected:
    std::list<Component* > children_;
public:
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }

    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    bool isComposite() const override {return true;}

    std::string Operation() const override {
        std::string result;
        for(auto c: children_) {
            if(c == children_.back()) result += c->Operation();
            else result += c->Operation() + "+";
        }
        return "Branch(" + result + ")";
    }
};

void ClientCode(Component* component) {
    std::cout << "RESULT: " << component->Operation();
}

void ClientCode2(Component* component1, Component* component2) {
    if(component1->isComposite()) component1->Add(component2);
    std::cout << "RESULT: " << component1->Operation();
}

int main() {
    Component* simple = new Leaf;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";

    Component* tree = new Composite;
    Component* branch1 = new Composite;

    
}