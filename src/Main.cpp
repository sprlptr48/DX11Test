#include "HelloWindowApp.hpp"
#include "HiTriangle.hpp"


int main(int argc, char* argv[])
{
    HiTriangle dxwindow{ "DX11 Window!" };
    dxwindow.Run();
    return 0;
}
