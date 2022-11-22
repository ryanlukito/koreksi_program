#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mahasiswa
{
public:
    string nama;
    string NIM;
    string jurusan;

    Mahasiswa(string nama, string NIM, string jurusan)
    {
        Mahasiswa::nama = nama;
        Mahasiswa::NIM = NIM;
        Mahasiswa::jurusan = jurusan;
    }

    string stringify()
    {
        return nama + " " + NIM + " " + jurusan;
    }
};

class DBase
{
public:
    ifstream in;
    ofstream out;
    string fileName;

    DBase(const char *fileName)
    {
        DBase::fileName = fileName;
    }

    void save(Mahasiswa data)
    {
        cout << data.nama << endl;
        cout << data.NIM << endl;
        cout << data.jurusan << endl;

        DBase::out.open(DBase::fileName, ios::app);
        DBase::out << data.stringify() << endl;
        DBase::out.close();
    }

    void showAll()
    {
        DBase::in.open(DBase::fileName, ios::in);
        string nama, NIM, jurusan;
        int index = 1;

        while (!DBase::in.eof())
        {
            DBase::in >> nama;
            DBase::in >> NIM;
            DBase::in >> jurusan;
            cout << index++ << ". " << nama << " " << NIM << " " << jurusan << endl;
        }
    }
};

int main()
{
    DBase database = DBase("data.txt");
    database.showAll();

    // input user
    string nama, NIM, jurusan;
    cout << "Masukkan Data Mahasiswa" << endl;
    cout << "Nama: ";
    cin >> nama;
    cout << "NIM: ";
    cin >> NIM;
    cout << "Jurusan: ";
    cin >> jurusan;

    // membuat object-object yang diperlukan
    Mahasiswa data1 = Mahasiswa(nama, NIM, jurusan);

    // save data ke database
    database.save(data1);

    // tampilkan seluruh data di database
    database.showAll();
    return 0;
}