#ifndef BAG_H
#define BAG_H

template<typename T>
struct Bag
{
    // adds an item to the bag
    virtual void add(const T&) = 0;

    // removes an item from the bag and returns it
    // throws a runtime exception if the bag is empty or the item is not in the bag
    virtual T remove(const T&) = 0;

    // returns the count of items in the bag
    virtual size_t size() const = 0;

    // returns an arbitrary item from the bag
    // throws a runtime exception if the bag is empty
    virtual T grab() const = 0;

    // returns true if the bag contains the item or false otherwise
    virtual bool contains(const T&) const = 0;
};

#endif