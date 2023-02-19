
#include "TheDocGia.h"
#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"
#include <iostream>
#include <string>
#include <format>


#define BLANK_LINE std::cout << std::endl



MuonTra::MuonTra()
	: m_MaSach(Values::UNIDENTIFIED), m_NgayMuon(Date()), m_NgayTra(Date()), m_TrangThai(-1)
{
	return;
}


MuonTra::MuonTra(std::string MaSach, Date NgayMuon, Date NgayTra, int TrangThai)
	: m_MaSach(MaSach), m_NgayMuon(NgayMuon), m_NgayTra(NgayTra), m_TrangThai(TrangThai)
{
	return;
}


void MuonTra::Show()
{
	std::cout << std::format("Ma sach   : {}", this->m_MaSach) << std::endl;
	std::cout << std::format("Ngay muon : {}", this->m_NgayMuon.Stringfy()) << std::endl;
	std::cout << std::format("Ngay tra  : {}", this->m_NgayTra.Stringfy()) << std::endl;
	std::cout << std::format("Trang thai: {}", this->m_TrangThai) << std::endl;

	BLANK_LINE;
}


DanhSachMuonTra::node::node()
	: value(MuonTra()), left(nullptr), right(nullptr)
{
	return;
}


DanhSachMuonTra::node::node(MuonTra value, DanhSachMuonTra::node* left, DanhSachMuonTra::node* right)
	: value(value), left(left), right(right)
{
	return;
}


DanhSachMuonTra::node::~node()
{
	delete this->left;
	delete this->right;
}


void DanhSachMuonTra::Initialize(DanhSachMuonTra::pointer& DanhSach)
{
	DanhSach = nullptr;
}


int DanhSachMuonTra::PushFront(DanhSachMuonTra::pointer& First, MuonTra value)
{
	First->left = new node(value, nullptr, First);
	return true;
}


int DanhSachMuonTra::PushBack(DanhSachMuonTra::pointer& Last, MuonTra value)
{
	Last->right = new node(value, Last, nullptr);
	return true;
}


void DanhSachMuonTra::Traveral(DanhSachMuonTra::pointer First)
{
	for (MuonTra& nodeValue = First->value; First->right != nullptr; First = First->right)
	{
		nodeValue.Show();

		BLANK_LINE;
	}
}


void DanhSachMuonTra::BackwardTraversal(DanhSachMuonTra::pointer Last)
{
	for (MuonTra& nodeValue = Last->value; Last->left != nullptr; Last = Last->left)
	{
		nodeValue.Show();

		BLANK_LINE;
	}
}




TheDocGia::TheDocGia()
	: m_MaThe(-1), m_Ho(Values::UNIDENTIFIED), m_Ten(Values::UNIDENTIFIED), m_Phai(false), m_TrangThaiThe(-1), m_DanhSachMuonTra(nullptr)
{
	return;
}


TheDocGia::TheDocGia(int MaThe, std::string Ho, std::string Ten, bool Phai, int TrangThaiThe, DanhSachMuonTra::pointer DanhSachMuonTra)
	: m_MaThe(MaThe), m_Ho(Ho), m_Ten(Ten), m_Phai(Phai), m_TrangThaiThe(TrangThaiThe), m_DanhSachMuonTra(DanhSachMuonTra)
{
	return;
}


TheDocGia::~TheDocGia()
{
	delete this->m_DanhSachMuonTra;
}