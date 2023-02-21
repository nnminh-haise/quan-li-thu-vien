#include "Sach.h"
#include <iostream>
#include <string>
#include <format>
#include "../Helper/Constants.h"
#include "../Helper/StringLib/StringLib.h"



Sach::TypeViTri::TypeViTri()
	: m_row(0), m_col(0), m_block(0)
{
	return;
}


Sach::TypeViTri::TypeViTri(int row, int col, int block)
	: m_row(row), m_col(col), m_block(block)
{
	return;
}


// TODO: write declaration for methods
int Sach::TypeViTri::Reader()
{
	return -1;
}


std::string Sach::TypeViTri::Stringfy()
{
	return std::format("{}{}{}", STR::ToString(this->m_row, 2), STR::ToString(this->m_col, 2), STR::ToString(this->m_block, 2));
}


std::string Sach::Generate_MaSach(std::string IBSN, int Order)
{
	return IBSN + std::format("{}", STR::ToString(Order, 4)) + this->m_ViTri.Stringfy();
}


Sach::Sach()
	: m_MaSach(VALUES::UNIDENTIFIED), m_ViTri(Sach::TypeViTri()), m_TrangThai(UNSET)
{
	return;
}


Sach::Sach(std::string MaSach, Sach::TypeViTri ViTri, TrangThaiSach TrangThai)
	: m_MaSach(MaSach), m_ViTri(Sach::TypeViTri()), m_TrangThai(TrangThai)
{
	return;
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
	: m_IBSN(VALUES::UNIDENTIFIED), m_TenSach(VALUES::UNIDENTIFIED), m_SoTrang(-1), m_TacGia(VALUES::UNIDENTIFIED), m_NamXuatBan(-1), m_TheLoai(VALUES::UNIDENTIFIED), m_DanhMucSach(nullptr)
{
	return;
}


DauSach::DauSach(std::string IBSN, std::string TenSach, int SoTrang, std::string TacGia, int NamXuatBan, std::string TheLoai, DanhMucSach::pointer DanhMucSach)
	: m_IBSN(IBSN), m_TenSach(TenSach), m_SoTrang(SoTrang), m_TacGia(TacGia), m_NamXuatBan(NamXuatBan), m_TheLoai(TheLoai), m_DanhMucSach(DanhMucSach)
{
}


DauSach::~DauSach()
{
	delete this->m_DanhMucSach;
}

