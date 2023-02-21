
#include "TheDocGia.h"
#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"
#include <iostream>
#include <string>
#include <format>
#include <time.h>


#define BLANK_LINE std::cout << std::endl



MuonTra::MuonTra()
	: m_MaSach(VALUES::UNIDENTIFIED), m_NgayMuon(Date()), m_NgayTra(Date()), m_TrangThai(UNSET)
{
	return;
}


MuonTra::MuonTra(std::string MaSach, Date NgayMuon, Date NgayTra, TrangThaiMuonTra TrangThai)
	: m_MaSach(MaSach), m_NgayMuon(NgayMuon), m_NgayTra(NgayTra), m_TrangThai(TrangThai)
{
	return;
}


void MuonTra::set_MaSach(std::string MaSach)
{
	this->m_MaSach = MaSach;
}


void MuonTra::Show()
{
	std::cout << std::format("Ma sach   : {}", this->m_MaSach) << std::endl;
	std::cout << std::format("Ngay muon : {}", this->m_NgayMuon.Stringfy()) << std::endl;
	std::cout << std::format("Ngay tra  : {}", this->m_NgayTra.Stringfy()) << std::endl;

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
	: m_MaThe(this->Generate_MaThe()), m_Ho(VALUES::UNIDENTIFIED), m_Ten(VALUES::UNIDENTIFIED), m_Phai(false), m_TrangThaiThe(UNSET), m_DanhSachMuonTra(nullptr)
{
	return;
}


TheDocGia::TheDocGia(int MaThe, std::string Ho, std::string Ten, bool Phai, TrangThaiThe TrangThaiThe, DanhSachMuonTra::pointer DanhSachMuonTra)
	: m_MaThe(MaThe), m_Ho(Ho), m_Ten(Ten), m_Phai(Phai), m_TrangThaiThe(TrangThaiThe), m_DanhSachMuonTra(DanhSachMuonTra)
{
	return;
}


TheDocGia::~TheDocGia()
{
	delete this->m_DanhSachMuonTra;
}

/*
! This method only generate a random integer number base on the current time.
TODO: Fix this method to generate random unique integer number. Represent the primary key for each object.
*/
int TheDocGia::Generate_MaThe()
{
	time_t timer;
	time(&timer);

	return timer % MAX_SIZE::DANH_SACH_THE_DOC_GIA + 1;
}
