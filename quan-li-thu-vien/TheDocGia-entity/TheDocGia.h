#pragma once

#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"



class MuonTra
{
private:
	enum TrangThaiMuonTra {
		UNSET = -1,
		DANG_MUON = 0,
		CHUA_TRA = 1,
		MAT_SACH = 2
	};

private:
	std::string m_MaSach;
	Date m_NgayMuon;
	Date m_NgayTra;
	TrangThaiMuonTra m_TrangThai;

public:
	MuonTra();
	MuonTra(std::string MaSach, Date NgayMuon, Date NgayTra, TrangThaiMuonTra TrangThai);
	void Show();

	void set_MaSach(std::string MaSach);
	void set_NgayMuon(Date NgayMuon);
	void set_NgayTra(Date NgayTra);
	void set_TrangThai(TrangThaiMuonTra TrangThai);

	std::string get_MaSach();
	Date get_NgayMuon();
	Date get_NgayTra();
	TrangThaiMuonTra get_TrangThai();
};

//* Double linked list
namespace DanhSachMuonTra
{
	struct node
	{
	public:
		MuonTra value;
		node* left;
		node* right;

	public:
		node();
		node(MuonTra value, node* left, node* right);
		~node();
	};

	typedef node* pointer;


	void Initialize(pointer& First);
	int PushFront(pointer& First, MuonTra value);
	int PushBack(pointer& Last, MuonTra value);
	void Traveral(pointer First);
	void BackwardTraversal(pointer Last);
}



class TheDocGia
{
private:
	enum TrangThaiThe {
		UNSET = -1,
		KICH_HOAT = 0,
		DA_KHOA = 1
	};

private:
	int m_MaThe;
	std::string m_Ho;
	std::string m_Ten;
	bool m_Phai;
	TrangThaiThe m_TrangThaiThe;
	DanhSachMuonTra::pointer m_DanhSachMuonTra;

private:
	int Generate_MaThe(); // Recode into a unique random method

public:
	TheDocGia();
	TheDocGia(int MaThe, std::string Ho, std::string Ten, bool Phai, TrangThaiThe TrangThaiThe, DanhSachMuonTra::pointer DanhSachMuonTra);
	~TheDocGia();

	void set_MaThe(int);
	void set_Ho(std::string);
	void set_Ten(std::string);
	void set_Phai(bool);
	void set_TrangThaiThe(TrangThaiThe);
	void set_DanhSachMuonTra(DanhSachMuonTra::pointer);

	int get_MaThe();
	std::string get_Ho();
	std::string get_Ten();
	bool get_Phai();
	TrangThaiThe get_TrangThaiThe();
	DanhSachMuonTra::pointer get_DanhSachMuonTra();
};

//* AVL Tree
namespace DanhSachTheDocGia
{
	struct node
	{
		TheDocGia info;
		int bf;
		node* left;
		node* right;
	};

	typedef node* pointer;
}
