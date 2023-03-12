
#include <iostream>
#include <thread>
#include <string>
#include <format>
#include <vector>

#include "Sach-entity/Sach.h"
#include "TheDocGia-entity/TheDocGia.h"
#include "Helper/Date-entity/Date.h"
#include "Helper/Constants.h"
#include "UI-lib/Elements/Elements.h"
#include "Views/MainMenu/MainView.h"
#include "Graphics/graphics.h"
#pragma comment(lib, "Graphics/graphics.lib")


int main() {
    Elements::GraphicWindow window (
        WINDOWS::MAX_WIDTH, WINDOWS::MAX_HEIGHT,
        WINDOWS::TITLE
    );

    window.Initialize();

    std::string text = "Hi and wellcome to nnminh";
    Elements::MessBox messageBox(
        text,
        Shapes::Coordinate(200, 200),
        400, 70
    );

    //messageBox.SetVerticalAlignment(Elements::Align::BOTTOM);
    messageBox.SetHorizontalAlignment(Elements::Align::RIGHT);

    messageBox.Draw();

    std::cin.get();

    window.Deconstruct();


    std::cout << "Program working fine!" << std::endl;
    return 0;
}


