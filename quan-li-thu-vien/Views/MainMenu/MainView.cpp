#include "MainView.h"
#include "../../UI-lib/Menu/Menu.h"
#include "../../UI-lib/Elements/Elements.h"
#include "../../UI-lib/Shapes/Shapes.h"
#include "../../Helper/Constants.h"
#include "../../Graphics/graphics.h"
#pragma comment(lib, "../../Graphics/graphics.lib")

#include <iostream>
#include <format>
#include <string>


MainView::MainViewMenu::MainViewMenu()
{
	std::cout << "Created Main menu view!" << std::endl;
}

//void MainView::MainViewMenu::Title()
//{
//	Elements::MessBox messageBox = Elements::MSGBox(
//		std::format("QUAN LI THU VIEN"),
//		Shapes::Coordinate(700, 100)
//	);
//
//	messageBox.set_DisplayBorder(false);
//	messageBox.set_Width(300);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//}
//
//void MainView::MainViewMenu::View_DanhSachDauSach()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("DANH SACH DAU SACH"),
//		Shapes::Coordinate(700, 200)
//	);
//
//	messageBox.set_Width(300);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View Danh sach dau sach!" << std::endl;
//}
//
//void MainView::MainViewMenu::View_DanhSachTheDocGia()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("DANH SACH THE DOC GIA"),
//		Shapes::Coordinate(700, 300)
//	);
//
//	messageBox.set_Width(300);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View Danh sach the doc gia!" << std::endl;
//}
//
//void MainView::MainViewMenu::View_ThongKe()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("THONG KE"),
//		Shapes::Coordinate(700, 400)
//	);
//
//	messageBox.set_Width(300);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View thong ke!" << std::endl;
//}
//
//void MainView::MainViewMenu::View_HuongDan()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("HUONG DAN"),
//		Shapes::Coordinate(500, 600)
//	);
//
//	messageBox.set_Width(200);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View huong dan!" << std::endl;
//}
//
//void MainView::MainViewMenu::View_About()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("ABOUT"),
//		Shapes::Coordinate(1000, 600)
//	);
//
//	messageBox.set_Width(100);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View about!" << std::endl;
//}
//
//void MainView::MainViewMenu::View_Exit()
//{
//	Elements::MSGBox messageBox = Elements::MSGBox(
//		std::format("EXIT"),
//		Shapes::Coordinate(1100, 600)
//	);
//
//	messageBox.set_Width(100);
//	messageBox.set_TextAlignment(Elements::MSGBox::CENTER);
//
//	messageBox.DrawBox();
//	std::cout << "Running View exit!" << std::endl;
//}

void MainView::MainViewMenu::Run()
{
	Shapes::Rectangle background = Shapes::Rectangle(
		Shapes::Coordinate(100, 100), 500, 500
	);


	this->m_numberOfModule = 6;

	/*this->Title();
	this->View_DanhSachDauSach();
	this->View_DanhSachTheDocGia();
	this->View_ThongKe();
	this->View_HuongDan();
	this->View_About();
	this->View_Exit();*/
}