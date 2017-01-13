#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Iterator pattern
//step 1: Create interface

class Iterator
{
  public:
    virtual bool hasNext() = 0;
    virtual const char *const next() = 0;
};
class Container
{
  public:
    virtual Iterator *getIterator() = 0;
};

//step 2: Create concrete class implementing the Container interface.
//This class has inner class NameIterator implementing the Iterator interface.
class NameRepository : public Container
{

  protected:
    static const char *const arr[4];

  public:
    Iterator *getIterator();
};
const char *const NameRepository::arr[4] = {"Robert", "John", "Julie", "Lora"};

class NameIterator : public Iterator, public NameRepository
{
    static int index;
    NameRepository *nameRepository;

  public:
    bool hasNext()
    {

        return index < 4;
    }

    const char *const next()
    {
        if (this->hasNext())
        {
            return nameRepository->arr[index++];
        }
        return NULL;
    }
};
int NameIterator::index = 0;

Iterator *NameRepository::getIterator()
{
    return new NameIterator;
};

//step 3: check result
int main()
{
    NameRepository *namesRepository = new NameRepository();
    for (Iterator *iter = namesRepository->getIterator(); iter->hasNext();)
    {
        const char *const name = iter->next();
        cout << "Name: " << name << endl;
    }

    return 0;
}