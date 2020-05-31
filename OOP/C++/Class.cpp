#include <iostream>
#include <vector>
#include <string>

using namespace std;

class player
{
public:
  string name;
  int health;
  int xp;

  void talk(string);
  bool is_dead();
  void display()
  {
    cout << name << endl;
    cout << health << endl;
    cout << xp << endl;
  }
};

int main()
{
  player frank, hero;
  player *memory {nullptr};
  memory = new player;

  frank.name = "frank";
  frank.health = 120;
  frank.xp = 23;

  frank.display();

    player ply[] {frank, hero};

    ply[0].health = 20;

    ply[0].display();

    return 0;
}
