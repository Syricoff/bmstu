#include "App/App.h"

int main()
{
    App &app = App::createApp();
    return app.start();
}
