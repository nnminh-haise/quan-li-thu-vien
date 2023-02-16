#pragma once

#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"



class MuonTra
{
public:
	const char* m_MaSach;
	Date m_NgayMuon;
	Date m_NgayTra;
	int m_TrangThai;

public:
	MuonTra();
	MuonTra(const char* MaSach, Date NgayMuon, Date NgayTra, int TrangThai);
	void Show();
};

struct node_DanhSachMuonTra
{
	MuonTra value;
	MuonTra* previous, next;
};

typedef node_DanhSachMuonTra* ptr_DanhSachMuonTra;



class TheDocGia
{
public:
	int m_MaThe;
	const char* m_Ho;
	const char* m_Ten;
	bool m_Phai;
	int m_TrangThaiThe;
	ptr_DanhSachMuonTra m_DanhSachMuonTra;

public:
	TheDocGia();
	TheDocGia(int MaThe, const char* Ho, const char* Ten, bool Phai, int TrangThaiThe);
	void Show();
};

