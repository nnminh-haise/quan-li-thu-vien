#include "Sach.h"
#include <iostream>
#include <string>
#include <format>
#include "../Helper/Constants.h"


#define BLANK_LINE std::cout << std::endl



Sach::Sach()
	: m_MaSach(Values::UNIDENTIFIED), m_ViTri(Values::UNIDENTIFIED), m_TrangThai(-1)
{
	return;
}


Sach::Sach(std::string MaSach, std::string ViTri, int TrangThai)
	: m_MaSach(MaSach), m_ViTri(ViTri), m_TrangThai(TrangThai)
{
	return;
}


void Sach::Show()
{
	std::cout << "[ Ma sach    ]: " << this->m_MaSach << std::endl;
	std::cout << "[ Vi tri     ]: " << this->m_ViTri << std::endl;
	std::cout << "[ Trang thai ]: " << this->m_TrangThai << std::endl;

	BLANK_LINE;
}


DanhMucSach::node::node()
	: value(Sach()), next(nullptr)
{
	return;
}


DanhMucSach::node::node(Sach value, node* next)
	: value(value), next(next)
{
	return;
}


DanhMucSach::node::~node()
{
	this->next = nullptr;
}


void DanhMucSach::Initialze(DanhMucSach::pointer& First)
{
	First = nullptr;
}


void DanhMucSach::Traversal(DanhMucSach::pointer First)
{
	for (Sach& nodeValue = First->value; First->next != nullptr; First = First->next)
	{
		nodeValue.Show();

		BLANK_LINE;
	}
}


int DanhMucSach::PushFront(DanhMucSach::pointer& First, Sach value)
{
	First = new DanhMucSach::node(value, First);
	return true;
}


int DanhMucSach::PushBack(DanhMucSach::pointer& First, Sach value)
{
	DanhMucSach::pointer Last = First;
	for (; Last->next != nullptr; Last = Last->next);

	Last->next = new DanhMucSach::node(value, nullptr);

	return true;
}






DauSach::DauSach()
	: m_IBSN(Values::UNIDENTIFIED), m_TenSach(Values::UNIDENTIFIED), m_TacGia(Values::UNIDENTIFIED), m_TheLoai(Values::UNIDENTIFIED), m_SoTrang(-1), m_NamXuatBan(-1), m_DanhMucSach(nullptr)
{
	return;
}

DauSach::DauSach(std::string IBSN, std::string TenSach, std::string TacGia, std::string TheLoai, int SoTrang, int NamXuatBan)
	: m_IBSN(IBSN), m_TenSach(TenSach), m_TacGia(TacGia), m_TheLoai(TheLoai), m_SoTrang(SoTrang), m_NamXuatBan(NamXuatBan)
{
}

void DauSach::Show()
{
	std::cout << "[ IBSN         ]: " << this->m_IBSN << std::endl;
	std::cout << "[ Ten sach     ]: " << this->m_TenSach << std::endl;
	std::cout << "[ Tac gia      ]: " << this->m_TacGia << std::endl;
	std::cout << "[ The loai     ]: " << this->m_TheLoai << std::endl;
	std::cout << "[ So trang     ]: " << this->m_SoTrang << std::endl;
	std::cout << "[ Nam xuat ban ]: " << this->m_NamXuatBan << std::endl;
	BLANK_LINE;
}