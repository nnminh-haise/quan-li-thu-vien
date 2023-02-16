#include "Sach.h"
#include <iostream>
#include "../Helper/Constants.h"

#define BLANK_LINE std::cout << std::endl

Sach::Sach()
	: m_MaSach(Values::UNIDENTIFIED), m_ViTri(Values::UNIDENTIFIED), m_TrangThai(-1)
{
}

Sach::Sach(const char* MaSach, const char* ViTri, int TrangThai)
	: m_MaSach(MaSach), m_ViTri(ViTri), m_TrangThai(TrangThai)
{
}

void Sach::Show()
{
	std::cout << "[ Ma sach    ]: " << this->m_MaSach << std::endl;
	std::cout << "[ Vi tri     ]: " << this->m_ViTri << std::endl;
	std::cout << "[ Trang thai ]: " << this->m_TrangThai << std::endl;
	BLANK_LINE;
}



DauSach::DauSach()
	: m_IBSN(Values::UNIDENTIFIED), m_TenSach(Values::UNIDENTIFIED), m_TacGia(Values::UNIDENTIFIED), m_TheLoai(Values::UNIDENTIFIED), m_SoTrang(-1), m_NamXuatBan(-1), m_DanhMucSach(nullptr)
{
}

DauSach::DauSach(const char* IBSN, const char* TenSach, const char* TacGia, const char* TheLoai, int SoTrang, int NamXuatBan)
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