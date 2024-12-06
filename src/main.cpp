#include "Jeux_vie.h"
#include "test.h"

using namespace std;

int main()
{
    int choix = 0;
    cout << "Voulez vous faire des tests unitaires 0 = non, 1 = oui ? " << endl;
    cin >> choix;
    if (choix == 0)
    {
        Jeux_vie jeux_vie;
        jeux_vie.run();
    }

    else if (choix == 1)
    {
    test();
    }

    return 0;
}