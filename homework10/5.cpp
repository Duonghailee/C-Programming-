#include <iostream>
#include <string>
using namespace std;

class Iterator
{
  public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;
};

class Container
{
  public:
    virtual Iterator *getIterator() = 0;
};

class NameRepository : public Container
{
  public:
    string names[4] = {"Robert", "John", "Julie", "Lora"};
    friend class NameIterator;
    Iterator *getIterator();
};

class NameIterator : public Iterator
{
  private:
    int index = 0;
    NameRepository *nr;

  public:
    NameIterator(NameRepository *nr);
    bool hasNext();
    string next();
};
NameIterator::NameIterator(NameRepository *nr)
{
    this->nr = nr;
}
bool NameIterator::hasNext()
{
    int length = sizeof(nr->names) / sizeof(nr->names[0]);
    if (index < length)
    {
        return true;
    }
    return false;
}
string NameIterator::next()
{
    if (hasNext())
    {
        return nr->names[index++];
    }
    return "";
}
Iterator *NameRepository::getIterator()
{
    return new NameIterator(this);
}

int main()
{
    NameRepository nameRepository;
    Iterator *it = nameRepository.getIterator();
    while (it->hasNext())
    {
        cout << "Name: " << it->next() << "\n";
    }
}