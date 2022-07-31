/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class Observer;


class Subject
{
 private:
 list<Observer *> views;
 int value;
 
 public:
 void attach(Observer *s1)
 {
     views.push_back(s1);
 }
 void setValue(int v)
  {
      value=v;
      notify();
  }
  void notify();
  
  int getValue()
  {
      return value;
  }
};
class Observer
{
    private:
    Subject *s1;
    int data;
    
    protected:
    Subject* getSubject()
    {
        return s1;
    }
    int getDatum()
    {
        return data;
    }
    public:
    Observer(Subject *s2, int theData)
    {
        s1=s2;
        data = theData;
        s1->attach(this);
    }
    virtual void update() =0;
};

class MyObserver : public Observer
{
    public:
    MyObserver(Subject* s1, int d) : Observer(s1, d) {}
    void update()
    {
            int v = getSubject()->getValue();
            int d = getDatum();
            std::cout<<"V ="<<v<<", data ="<<d<<"\n";
    }
};

void Subject::notify()
  {
      list<Observer *>::iterator iterator = views.begin();
    while (iterator != views.end()) {
      (*iterator)->update();
      ++iterator;
    }
  }
  




int main()
{
    Subject s1;
    MyObserver Ob1(&s1, 3);
    MyObserver Ob2(&s1, 4);
    s1.setValue(11);
    return 0;
}
