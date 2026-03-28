#include "Global.h"
#include "clsMainScreen.h"


int main()
{
    SystemBoot();
    // Show main screen
    clsMainScreen mainScreen;
    mainScreen.show();

    return 0;
}