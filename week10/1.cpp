#include <iostream>
#include <string>
using namespace std;

//Proxy pattern
//step 1: Create an interface
class Image
{
  public:
    virtual void display() = 0;
};

//step2: Create concrete classes implementing the same interface.
//RealImage
class RealImage : public Image
{
  private:
    string fileName;

  public:
    void loadFromDisk(string file_Name)
    {
        cout << "Loading " << file_Name << endl;
    }
    RealImage(string file_name)
    {
        fileName = file_name;
        loadFromDisk(file_name);
    }
    void display()
    {
        cout << "Displaying " << fileName << endl;
    }
};

//ProxyImage
class ProxyImage : public Image
{
  private:
    RealImage *real_image;
    string fileName;

  public:
    ProxyImage(string file_name)
    {
        fileName = file_name;
        real_image = 0;
    }
    ~ProxyImage()
    {
        delete real_image;
    }

    void display()
    {
        if (!real_image)
        {
            real_image = new RealImage(fileName);
        }
        real_image->display();
    }
};

//step 3: verify the output
int main()
{
    Image *image = new ProxyImage("test_10mb.jpg");

    //image will be loaded from disk
    image->display();
    cout << endl;

    //image will not be loaded from disk
    image->display();
    return 0;
}