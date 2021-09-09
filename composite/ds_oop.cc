#include<iostream>
#include<iterator>
#include<list>

template<typename Watt, typename Currency>
class Equipment {
public:
    virtual ~Equipment();

    const char* Name() {return _name;}

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DiscountPrice();

    virtual void Add(Equipment*);
    virtual void Remove(Equipment*);
    virtual Iterator<Equipment*>* CreateIterator();

protected:
    Equipment(const char*);
private:
    const char* _name;
};

template<typename Watt, typename Currency>
class FloppyDisk: public Equipment {
public:
    FloppyDisk(const char*);
    virtual ~FloppyDisk();
};

template<typename Watt, typename Currency>
class CompositeEquipment: public Equipment {
public:
    virtual ~CompositeEquipment();
protected:
    CompositeEquipment(const char*);
private:
    List<Equipment*> _equipment;
}

