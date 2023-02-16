#include "TheDocGia.h"
#include "../Helper/Date-entity/Date.h"
#include "../Helper/Constants.h"
#include <iostream>

#define BLANK_LINE std::cout << std::endl


MuonTra::MuonTra()
	: m_MaSach(Values::UNIDENTIFIED), m_NgayMuon(Date()), m_NgayTra(Date()), m_TrangThai(-1)
{
}

MuonTra::MuonTra(const char* MaSach, Date NgayMuon, Date NgayTra, int TrangThai)
	: m_MaSach(MaSach), m_NgayMuon(NgayMuon), m_NgayTra(NgayTra), m_TrangThai(TrangThai)
{
}

void MuonTra::Show()
{
	std::cout << "[ Ma sach ]   : " << this->m_MaSach << std::endl;
	std::cout << "[ Ngay muon ] : " << this->m_NgayMuon.m_Day << " - " << this->m_NgayMuon.m_Month << " - " << m_NgayMuon.m_Year << std::endl;
	std::cout << "[ NGay tra ]  : " << this->m_NgayTra.m_Day << " - " << this->m_NgayTra.m_Month << " - " << m_NgayTra.m_Year << std::endl;
	std::cout << "[ Trang thai ]: " << this->m_TrangThai << std::endl;

	BLANK_LINE;
}



TheDocGia::TheDocGia()
	: m_MaThe(-1), m_Ho(Values::UNIDENTIFIED), m_Ten(Values::UNIDENTIFIED), m_Phai(false), m_TrangThaiThe(-1), m_DanhSachMuonTra(nullptr)
{
}

TheDocGia::TheDocGia(int MaThe, const char* Ho, const char* Ten, bool Phai, int TrangThaiThe)
	: m_MaThe(MaThe), m_Ho(Ho), m_Ten(Ten), m_Phai(Phai), m_TrangThaiThe(TrangThaiThe)
{
}
