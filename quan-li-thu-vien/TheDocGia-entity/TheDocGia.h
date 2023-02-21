#pragma once

#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"



class MuonTra
{
public:
	std::string m_MaSach;
	Date m_NgayMuon;
	Date m_NgayTra;
	int m_TrangThai;

public:
	MuonTra();
	MuonTra(std::string MaSach, Date NgayMuon, Date NgayTra, int TrangThai);
	void Show();
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
public:
	int m_MaThe;
	std::string m_Ho;
	std::string m_Ten;
	bool m_Phai;
	int m_TrangThaiThe;
	DanhSachMuonTra::pointer m_DanhSachMuonTra;

private:
	int Generate_MaThe();

public:
	TheDocGia();
	TheDocGia(int MaThe, std::string Ho, std::string Ten, bool Phai, int TrangThaiThe, DanhSachMuonTra::pointer DanhSachMuonTra);
	~TheDocGia();
};

//* Balance binary search tree
namespace DanhSachTheDocGia
{

}
