#pragma once

class Sach
{
public:
    const char* m_MaSach;
    const char* m_ViTri;
    int m_TrangThai;

public:
    Sach();
    Sach(const char* MaSach, const char* ViTri, int TrangThai);
    void Show();
};

struct node_DanhMucSach
{
    Sach value;
    Sach* next;
};

typedef node_DanhMucSach* ptr_DanhMucSach;



class DauSach
{
public:
    const char* m_IBSN;
    const char* m_TenSach;
    const char* m_TacGia;
    const char* m_TheLoai;
    int m_SoTrang;
    int m_NamXuatBan;
    ptr_DanhMucSach m_DanhMucSach;

public:
    DauSach();
    DauSach(const char* IBSN, const char* TenSach, const char* TacGia, const char* TheLoai, int SoTrang, int NamXuatBan);
    void Show();
};