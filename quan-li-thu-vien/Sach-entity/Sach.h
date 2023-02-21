#pragma once

#include <iostream>
#include <string>



class Sach
{
public:
    std::string m_MaSach;
    std::string m_ViTri;
    int m_TrangThai;

public:
    Sach();
    Sach(std::string MaSach, std::string ViTri, int TrangThai);
    void Show();
};

//* Linked list
namespace DanhMucSach
{
    struct node
    {
    public:
        Sach value;
        node* next;

    public:
        node();
        node(Sach value, node* next);
        ~node();
    };

    typedef node* pointer;


    void Initialze(pointer& First);
    void Traversal(pointer First);
    int PushFront(pointer& First, Sach value);
    int PushBack(pointer& First, Sach value);
}



class DauSach
{
public:
    std::string m_IBSN;
    std::string m_TenSach;
    int m_SoTrang;
    std::string m_TacGia;
    int m_NamXuatBan;
    std::string m_TheLoai;
    DanhMucSach::pointer m_DanhMucSach;

public:
    DauSach();
    DauSach(std::string IBSN, std::string TenSach, int SoTrang, std::string TacGia, int NamXuatBan, std::string TheLoai, DanhMucSach::pointer DanhMucSach);
    ~DauSach();
    void Show();
};

//* Danh sách liên kết đơn
namespace DanhSachDauSach
{

}