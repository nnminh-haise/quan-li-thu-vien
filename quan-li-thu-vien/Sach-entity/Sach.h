#pragma once

#include <iostream>
#include <string>


class Sach
{
//* Supporting struct and enum
private:
    enum TrangThaiSach {
        UNSET = -1,
        CHO_MUON_DUOC = 0,
        DA_CO_DOC_GIA_MUON = 1,
        DA_THANH_LY = 2
    };

    struct TypeViTri
    {
    private:
        int m_row;    //* Hàng
        int m_col;    //* Cột
        int m_block;  //* Tủ sách

    public:
        TypeViTri();
        TypeViTri(int row, int col, int block);

        int Reader();
        std::string Stringfy();
    };


//* Class attributes
private:
    std::string m_MaSach;
    TypeViTri m_ViTri;
    TrangThaiSach m_TrangThai;


//* Class support methods
private:
    std::string Generate_MaSach(std::string IBSN, int Order);


//* Class main methods
public:
    Sach();
    Sach(std::string MaSach, TypeViTri ViTri, TrangThaiSach TrangThai);
    void Show();

    void set_MaSach(std::string MaSach);
    void set_ViTri(TypeViTri ViTri);
    void set_TrangThai(TrangThaiSach TrangThai);

    std::string get_MaSach();
    TypeViTri get_ViTri();
    TrangThaiSach get_TrangThai();
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
private:
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

    void set_IBSN(std::string IBSN);
    void set_TenSach(std::string TenSach);
    void set_SoTrang(int SoTrang);
    void set_TacGia(std::string);
    void set_NamXuatBan(int NamXuatBan);
    void set_TheLoai(std::string TheLoai);
    void set_DanhMucSach(DanhMucSach::pointer DanhMucSach);

    std::string get_IBSN();
    std::string get_TenSach();
    int get_SoTrang();
    std::string get_TacGia();
    int get_NamXuatBan();
    std::string get_TheLoai();
    DanhMucSach::pointer get_DanhMucSach();
};

//* Danh sách liên kết đơn
namespace DanhSachDauSach
{

}