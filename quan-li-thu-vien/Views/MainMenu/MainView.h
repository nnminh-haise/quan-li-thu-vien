#pragma once

#include "../../UI-lib/Menu/Menu.h"



namespace MainView
{
	class MainViewMenu : public Menu
	{
	public:
		MainViewMenu();

		void Title();

		void View_DanhSachDauSach();
		void View_DanhSachTheDocGia();
		void View_ThongKe();
		void View_HuongDan();
		void View_About();
		void View_Exit();

		void Run();
	};
}
