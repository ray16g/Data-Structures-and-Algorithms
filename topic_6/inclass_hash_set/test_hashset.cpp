#include"set.h"
#include"hash_set.h"

#include"test.h"

double testValue{55};

size_t hashcode(const double& val)
{
    return *reinterpret_cast<const size_t*>(&val);
}

size_t badhashcode(const double& val)
{
    return 0;
}

void testadd(Set<double>*);
void testaddProbeFail(Set<double>*);
void testremove(Set<double>*);
void testempty(Set<double>*);
void testcontains(Set<double>*);
void testsize(Set<double>*);

int main(int argc, char const *argv[])
{       
    testadd(new HashSet<double>(hashcode));
    testaddProbeFail(new HashSet<double>(badhashcode));
    testremove(new HashSet<double>(hashcode));
    testempty(new HashSet<double>(hashcode));
    testcontains(new HashSet<double>(hashcode));
    testsize(new HashSet<double>(hashcode));
    return 0;
}

void testadd(Set<double>* set)
{
    set->add(0);
    equals<bool>(false, set->empty(), "testadd: new set is not empty, size == 1");
    equals<int>(1, set->size(), "testadd: set size is one");

    for(double i = 1; i < DEFAULT_SIZE + 1; ++i)
    {
        set->add(i);
    }

    equals<int>(DEFAULT_SIZE + 1, set->size(), "testadd: set size is DEFAULT_SIZE + 1");

    try
    {
        set->add(testValue);
        equals<bool>(true, false, "testadd: failed throw exception on duplicate add");
    }
    catch(const std::exception&)
    {
        equals<bool>(true, true, "testadd: thrown exception on duplicate add");
    }
    
}

void testaddProbeFail(Set<double>* set)
{
    try
    {
        for (double i = 0; i <= PROBING_LIMIT; ++i)
            set->add(i);
        equals<bool>(true, false, "testaddProbeFail: failed throw exception on probe fail");
    }
    catch(const std::exception&)
    {
        equals<bool>(true, true, "testaddProbeFail: thrown exception on probe fail");
    }
    
}

void testremove(Set<double>* set)
{
    set->add(testValue);
    set->remove(testValue);

    equals<bool>(true, set->empty(), "testempty: removed last item, set is empty, size == 0");
    equals<int>(0, set->size(), "testsize: set size is zero after removing last item");

    try
    {
        set->remove(testValue);
        equals<bool>(true, false, "testremove: failed throw exception on remove non member");
    }
    catch(const std::exception&)
    {
        equals<bool>(true, true, "testremove: throw exception on remove non member");
    }

}

void testempty(Set<double>* set)
{
    equals<bool>(true, set->empty(), "testempty: new set is empty, size == 0");
}

void testcontains(Set<double>* set)
{
    set->add(testValue);
    equals<bool>(true, set->contains(testValue), "testcontains: set contains testvalue");
    equals<bool>(false, set->contains(testValue + 1), "testcontains: set does not contain testvalue + 1");

}

void testsize(Set<double>* set)
{
    equals<int>(0, set->size(), "testsize: set size is zero");

}
