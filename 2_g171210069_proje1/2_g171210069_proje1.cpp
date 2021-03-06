/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:Proje-1
**				ÖĞRENCİ ADI...............:Ahmet Kutay Karacair
**				ÖĞRENCİ NUMARASI.:G171210069
**				DERS GRUBU…………:2.Öğretim B Grubu
****************************************************************************/



#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream> 
#include <iomanip>
using namespace std;

class hotel {
public:
	string odanumarasi;
	int odaucreti;
	string musteriadi;
	string musterisoyadi;
	string musterinumarasi;
	string musteritckimlik;
	string yeniodanumarasi;
	string yenimusterinumarasi;
	string yenimusteriodanumarasi;
	string odanumarasi1;
	string musterinumarasi2;
	string yeniodanumarasi1;
	string yenimusterinumarasi1;
	void hotel1() {      //Otel Menusunu açıyor
		int secim;
		cout << "Otel Islemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Oda islemleri " << endl;
		cout << "2.Musteri Islemleri " << endl;
		cout << "3.Oda Kayit Islemleri " << endl;
		cout << "99.Cikis" << endl;
		cout << "Seciminiz..: ";
		cin >> secim;
		cout << endl;
		system("cls");
		switch (secim)
		{
		case 1:odaislemi();
			break;
		case 2:musteriislemleri();
			break;
		case 3:odakayitislemleri();
			break;
		case 99:Cikis();
			break;
		default:cout << "Hatali Secim" << endl;
			break;
		}
	}

	void odaislemi() {//Oda işlemleri Menusunu açıyor
		int secim1;
		cout << "Oda Islemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Oda Ekle " << endl;
		cout << "2.Oda Sil" << endl;
		cout << "3.Odalari Listele" << endl;
		cout << "99.Ust Menu" << endl;
		cout << "Seciminiz..: ";
		cin >> secim1;
		system("cls");
		switch (secim1)
		{
		case 1:Odaekle();
			break;
		case 2:Odasil();
			break;
		case 3:Odalarilistele();
			break;
		case 99:Ustmenu();
			break;
		default:cout << "Hatali Secim" << endl;
			break;
		}
	}

	void Odaekle() {
		fstream odadosyasi;//dosyayi oluşturuyor
		odadosyasi.open("OdaDosyasi.txt", ios::out | ios::in | ios::app);//dosyayi açıyor

		cout << "Oda Numarasi Giriniz..:";
		cin >> odanumarasi;
		bool okontrol = odakontroletme(odanumarasi);//oda numarasını kontrol ediyor varsa oda bulunmaktadir yazdırıyor yoksa ucretini alıyor
		if (okontrol == true) {
			cout << "Bu Oda Bulunmaktadir.";
		}
		else {
			cout << "Oda Ucreti Giriniz..:";
			cin >> odaucreti;
			cout << endl;
			odadosyasi << odanumarasi << endl << odaucreti;
			odadosyasi << endl;
		}
		odadosyasi.close();//dosyayi kapatıyor
		int menudonme;	
		cout << "Tekrar Oda Eklemek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:Odaekle();
			break;
		case 2:odaislemi();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}

	void Odasil() {
		string Odasecim;
		cout << "Silinecek Oda Numarasi..:";
		cin >> Odasecim;
		ifstream dosyaoku("OdaDosyasi.txt");//dosyamızı açıyor
		ofstream dosyayaz("OdaDosyasi.tmp");//geçici dosya açıyor
		while (dosyaoku.good() && dosyaoku >> odanumarasi >> odaucreti)//dosyaokudan odanumarasini ve ucretini aldım
		{
			if (Odasecim == odanumarasi) {//odasecim odanumarasina eşitse dosyadaki kayıtlari gösteriyor
				cout << "\n Dosyadaki Kayit \n";
				cout << "Oda Numarasi..:" <<  odanumarasi << endl;
				cout << "Oda Ucreti..:" << odaucreti << endl;
			}
			else {
				dosyayaz << odanumarasi << " " << odaucreti << "\n";//geçici dosyaya yazıyor
			}
		}
		dosyayaz.close();//dosya kapatma
		dosyaoku.close();//dosya kapatma
		remove("OdaDosyasi.txt");//
		rename("OdaDosyasi.tmp", "OdaDosyasi.txt");//geçici dosyayı asıl dosyamıza aktarıyor
		int menudonme;
		cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:odaislemi();
			break;
		case 2:hotel1();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}
	
	void Odalarilistele() {
		fstream odadosyasi;//dosyamız
		odadosyasi.open("OdaDosyasi.txt");//dosyayı açıyor
		string str;
		while (true) {
			odadosyasi >> odanumarasi >> odaucreti;//dosyadan değişkenlerimi alıyorum
			if (odadosyasi.eof())
			{
				break;
			}
			cout << "OdaNumarasi..:" << odanumarasi << endl << "OdaUcreti..:" << odaucreti << endl;
		}
		odadosyasi.close();//dosyayı kapatıyorum
		int menudonme;
		cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:odaislemi();
			break;
		case 2:hotel1();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}

	void Ustmenu() {
		hotel1();//ust menu
	}

	void musteriislemleri() {//musteri işlemleri
		int secim2;
		cout << "Musteri Islemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Musteri Ekle " << endl;
		cout << "2.Musteri Sil" << endl;
		cout << "3.Musteri Listele" << endl;
		cout << "99.Ust Menu" << endl;
		cout << "Seciminiz..: ";
		cin >> secim2;
		system("cls");
		switch (secim2)
		{
		case 1:MusteriEkle();
			break;
		case 2:Musterisil();
			break;
		case 3:Musterilistele();
			break;
		case 99:Ustmenu();
			break;
		default:cout << "Hatali Secim" << endl;
			break;
		}
	}
	
	void MusteriEkle() {
		fstream musteridosyasi;//musteri dosyasi
		musteridosyasi.open("MusteriDosyasi.txt", ios::out | ios::in | ios::app);//musteri dosyasini açıyor
		
		cout << "Musteri Adi Giriniz..: " ;
		cin >> musteriadi;
		cout << endl;
		cout << "Musteri Soyadi Giriniz..:";
		cin >> musterisoyadi;
		cout << endl;
		cout << "Musteri TC Kimlik No Giriniz..: ";// TC kimliği kontrol ediyorum fakat program yanlış girdikten sonra hata olarak müşteriyi silmiyor silmek için ya programı tekrardan başlatıcam yada hiç hata yapmıcam
		cin >> musteritckimlik;
		if (musteritckimlik.length() != 11) {
			cout << "Yanlis TC Girdiniz." << endl;
			int menudonme8;
			cout << "Yeni Kisi Eklemek Ister Misiniz?  (1-e)/(2-h)";
			cin >> menudonme8;
			switch (menudonme8)
			{
			case 1:MusteriEkle();
				break;
			case 2:musteriislemleri();
				break;
			default:cout << "Hatali Secim";
				break;
			}
		}
		cout << "Musteri Numarasi Giriniz..:";
		cin >> musterinumarasi;
		bool mkontrol = musterikontroletme(musterinumarasi);//eğer aynı musteri numarasi varsa bu musteri numarası vardır dedirtiyorum yoksa dosyaya yazıyorum
		if (mkontrol == true) {
			cout << "Bu Musteri Numarasi Vardir.";
		}
		else {
			musteridosyasi << musteriadi << endl << musterisoyadi << endl << musteritckimlik << endl << musterinumarasi << endl;
		}
		musteridosyasi.close();//dosya kapatıyorum
		int menudonme;
		cout << "Kisi Eklemek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:MusteriEkle();
			break;  
		case 2:musteriislemleri();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}
	
	void Musterisil() {
		string silinendeger;
		cout << "Silinecek Kisinin Numarasi..:";
		cin >> silinendeger;
		ifstream dosyaoku("MusteriDosyasi.txt");
		ofstream dosyayaz("MusteriDosyasi.tmp");
		while (dosyaoku.good() && dosyaoku >> musteriadi >> musterisoyadi >> musteritckimlik >> musterinumarasi) {//dosyadan değişkenleri alıyorum
			if (silinendeger == musterinumarasi) {//silinendeğer musterinumarasina eşitse dosyadaki kayıtı gösterip siliyorum
				cout << "\nDosyadaki Kayit \n";
				cout << "Musteri Adi..:" << musteriadi << endl;
				cout << "Musteri Soyadi..:" << musterisoyadi << endl;
				cout << "Musteri Tc..:" << musteritckimlik << endl;
				cout << "Musteri Numara..:" << musterinumarasi << endl;
			}
			else {
				dosyayaz << musteriadi << "  " << musterisoyadi << "  " << musteritckimlik << "  " << musterinumarasi << "\n"; //geçici dosyaya akratıyorum değişkenleri
			}
		}
		dosyayaz.close();//dosyayı kapatıyorum
		dosyaoku.close();//dosyayı kapatıyorum
		remove("MusteriDosyasi.txt");//
		rename("MusteriDosyasi.tmp", "MusteriDosyasi.txt");//
		int menudonme1;
		cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme1;
		switch (menudonme1)
		{
		case 1:musteriislemleri();
			break;
		case 2:hotel1	();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}
	
	void Musterilistele() {
		fstream musteridosyasi;//dosya
		musteridosyasi.open("MusteriDosyasi.txt");//dosyayı açıyorum
		while (true) {
			musteridosyasi >> musteriadi >> musterisoyadi >> musteritckimlik >> musterinumarasi;//değişkenlerimi dosyadan alıyorum
			if (musteridosyasi.eof())
			{
				break;
			}
			cout << "MusteriAdi..:" << musteriadi << endl << "MusteriSoyadi..:" << musterisoyadi << endl << "MusteriTc..:" << musteritckimlik << endl << "MusteriNumarasi..:" << musterinumarasi << endl;//ekrana yazdıyorum
		}
		musteridosyasi.close();//dosyayı kapatıyorum
		int menudonme;
		cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:musteriislemleri();
			break;
		case 2:hotel1();
			break;
		default:cout << "Hatali Secim";
			break;
		}

	
	}
	
	void odakayitislemleri() {//odakayit menusu
		int secim3;
		cout << "Oda Kayit Islemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Musteri-Oda Ekle " << endl;
		cout << "2.Musteri-Oda Sil" << endl;
		cout << "3.Musteri-Oda Listele" << endl;
		cout << "99.Ust Menu" << endl;
		cout << "Seciminiz..: ";
		cin >> secim3;
		system("cls");
		switch (secim3)
		{
		case 1:musteriodaekle();
			break;
		case 2:musteriodasil();
			break;
		case 3:musteriodalistele();
			break;
		case 99:Ustmenu();
			break;
		default:cout << "Hatali Secim" << endl;
			break;
		}

	}
	
	void musteriodaekle() {
		fstream musterioda;//dosyam
		musterioda.open("Musteri-OdaDosyasi.txt", ios::in | ios::out | ios::app);//dosyamı açıyorum
		cout << "Oda Numarasini Giriniz..:";
		cin >> odanumarasi1;
		bool ovkontrol = odavarmikontrol(odanumarasi1);//oda dosyamda girdiği oda yoksa o odayı yazdırmıyor
		bool mokontrol = musteriodakontrol(odanumarasi1);//oda numarasindan bir tane oluşturarak 1 odaya başka musteri girmesini engelliyorum
		if (ovkontrol == true)
		{
			if (mokontrol == true) {//odan numarasını kontrol ediyorum eger true ise oda doludur değilse musteri numarasini alıyorum
				cout << "Bu Oda Doludur.";
			}
			else {
				cout << "Musteri Numarasini Giriniz..:";
				cin >> musterinumarasi2;
				bool mvkontrol = musterivarmıkontrol(musterinumarasi2);//musteri numarasını kontrol ediyor yoksa dosyaya yazmıyor varsa yazıyor
				if (mvkontrol == true) {
					musterioda << odanumarasi1 << endl << musterinumarasi2 << endl;//dosyaya yazıyorum
				}
				else {
					cout << "Musteri Numarasini Hatali Girdiniz Ya Da Bu Musteri Numarasi Yoktur." << endl;
				}
			}
		}
		else
		{
			cout << "Bu Oda Numarasi Yoktur. ";
		}
		musterioda.close();//dosyayı kapatıyorum
		int menudonme3;
		cout << "Tekrar Oda Eklemek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme3;
		switch (menudonme3)
		{
		case 1:musteriodaekle();
			break;
		case 2:odakayitislemleri();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}

	void musteriodasil(){
		string musterisecim;//değişkenim
		cout <<"Silinecek Musteri Numarasi..:" ;
		cin >> musterisecim;//musteri numarasini alıyorum
		ifstream dosyaoku("Musteri-OdaDosyasi.txt");//dosyayı okuyorum
		ofstream dosyayaz("Musteri-OdaDosyasi.tmp");//geçici dosyam
		while (dosyaoku.good() && dosyaoku >> odanumarasi >> musterinumarasi) {//dosyamdan değişkenimi alıyorum
			if (musterisecim == musterinumarasi) {//değişkenlerim eşitse dosyadaki kayiti gösterip siliyor
				cout << "\n Dosyadaki Kayit \n";
				cout << "Oda Numarasi..:" << odanumarasi << endl;
				cout << "Musteri Numarasi..:" << musterinumarasi << endl;
			}
			else {
				dosyayaz << odanumarasi << "  " << musterinumarasi << "\n";
			}
		}
			dosyayaz.close();//dosyayi kapatıyorum
			dosyaoku.close();//dosyayi kapatıyorum
			remove("Musteri-OdaDosyasi.txt");//
			rename("Musteri-OdaDosyasi.tmp", "Musteri-OdaDosyasi.txt");//
			int menudonme5;
			cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
			cin >> menudonme5;
			switch (menudonme5)
			{
			case 1:odakayitislemleri();
				break;
			case 2:hotel1();
				break;
			default:cout << "Hatali Secim";
				break;
			}
		}
	
	void musteriodalistele(){
		fstream musteriodadosyasi;//dosyam
		musteriodadosyasi.open("Musteri-OdaDosyasi.txt");//dosyamı açıyorum
		while (true) {
			musteriodadosyasi >> odanumarasi1 >> musterinumarasi;//değişkenlerimi alıyorum
			if (musteriodadosyasi.eof())
			{
				break;
			}
			cout << "OdaNumarasi..:" << odanumarasi1 << endl << "MusteriNumarasi..:" << musterinumarasi << endl;//değişkenlerimi ekrana yazdıyorum
		}
		musteriodadosyasi.close();//dosyayi kapatıyorum
		int menudonme6;
		cout << "Menuye Donmek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme6;
		switch (menudonme6)
		{
		case 1:odakayitislemleri();
			break;
		case 2:hotel1();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}
	
	void Cikis() {//cıkış
		exit(0);
	}
	
	bool odakontroletme(string odanumarasi) {
		fstream odadosyasi("OdaDosyasi.txt");//dosyam	
		while (odadosyasi.good() && odadosyasi >> yeniodanumarasi) {//dosyadan değişkenlerimi alıyorum
			if (odanumarasi == yeniodanumarasi) {//değişkenler eşitse true değilse false dönüyor
				return true;
			}
		}
		return false;
		odadosyasi.close();//dosyayi kapatıyorum
	}
	
	bool musterikontroletme(string musterinumarasi) {
		fstream musteridosyasi("MusteriDosyasi.txt",ios::in);//dosyam
		while (musteridosyasi.good() && musteridosyasi >> yenimusterinumarasi) {//dosyamdan değişkenleri alıyorum
			if (musterinumarasi== yenimusterinumarasi) {//değişkenlerim eşitse true değilse false döndürüyor
				return true;
			}
		}
		return false;
		musteridosyasi.close();//dosyayı kapatıyor
	}

	bool musteriodakontrol(string musteriodanumarasi) {
		fstream musteriodadosyasi("Musteri-OdaDosyasi.txt");//dosyam
		while (musteriodadosyasi.good() && musteriodadosyasi >>yenimusteriodanumarasi) {//değişkenlerimi alıyorum
			if (musteriodanumarasi == yenimusteriodanumarasi)//değişkenlerim eşitse true değilse false döndürüyor
			{
				return true;
			}
		}
		return false;
		musteriodadosyasi.close();//dosyayi kapatıyor
	}

	bool odavarmikontrol(string odakontrolnumarasi) {
		fstream odadosyasi("OdaDosyasi.txt");//dosyam	
		while (odadosyasi.good() && odadosyasi >> yeniodanumarasi1) {//dosyadan değişkenlerimi alıyorum
			if (odakontrolnumarasi == yeniodanumarasi1) {//değişkenler eşitse true değilse false dönüyor
				return true;
			}
		}
		return false;
		odadosyasi.close();//dosyayi kapatıyorum
	}

	bool musterivarmıkontrol(string musterinumarasikontrol){	
		fstream musteridosyasi("MusteriDosyasi.txt");//dosyam	
		while (musteridosyasi.good() && musteridosyasi >> musteriadi >> musterisoyadi >> musteritckimlik >> musterinumarasi) {//dosyadan değişkenlerimi alıyorum
			if (musterinumarasikontrol == musterinumarasi) {//değişkenler eşitse true değilse false dönüyor
				return true;
			}
		}
		return false;
		musteridosyasi.close();//dosyayi kapatıyorum
	}

};

int main()
{
	hotel hotelim;
	hotelim.hotel1();
	system("pause");
    return 0;
}