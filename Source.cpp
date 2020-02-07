#include<iostream>
#include<fstream>
#include<string>
#include<time.h>

#define aylikkira 600
#define kiracidepozito 600

using namespace std;
//fstream dosya("proje.txt", ios::in | ios::out);
string ay[12] = { "ocak","subat","mart","nisan","mayis","haziran","temmuz","agustos","eylul","ekim","kasim","aralik" };
typedef enum {
	erkek,
	kadin
}cinsiyet;
typedef struct ogrenci {

	int id;
	string tc;
	string ad_soyad;
	string cinsiyet ;
	string dogum_tarihi;
	string telefon;
	string eposta;
	string giris_tarihi;
	string  cikis_tarihi;
	string girisayi;
	int depozito;
	int kiradurumu[12] = { 0 };
	int elektrikfaturasidurumu[12] = { 0 };
	int aylikendeks[12] = { 0 };
	int endeksfarki[12] = { 0 };
	int cikanelektrikborcu[12] = { 0 };



}ogrenci;

ogrenci musteri[20];
int tumendeksfarklaritoplami[12];
int apartfatura[12];
struct ogrenci temp;
int kontrol[20] = { 0 };


int deger = 0;

void faturaoku()
{
	fstream fatura;
	fatura.open("fatura.txt");
	
	for (int i = 0; i < 12; i++)
	{
		fatura >> apartfatura[i];
	}

	fatura.close();


}

void faturayaz()
{
	fstream fatura;
	fatura.open("fatura.txt", ios::out);

	for (int i = 0; i < 12; i++)
	{
		fatura << apartfatura[i] << " ";
	}

	fatura.close();

}

void toplamfatura()
{
	for (int i = 0; i < 12; i++)
	{
		cout << ay[i] << " ayi icin apart faturasini girin:" << endl;
		cin >> apartfatura[i];
	}
	faturayaz();
}

void dosyayayazdir()
{
	fstream dosya;
	dosya.open("proje.txt", ios::out);
	char *p;
	if (dosya.is_open() == true)
	{
		for (int i = 0; i < deger; i++)
		{
			if (kontrol[i] == 1)
			{
				dosya << musteri[i].id << " ";
				dosya << musteri[i].tc << " ";
				p = &musteri[i].ad_soyad[0];
				for (int j = 0; j < musteri[i].ad_soyad.length(); j++)
				{
					if (*p == ' ')
					{
						*p = '_';
					}
					p++;
				}

				dosya << musteri[i].ad_soyad << " ";
				dosya << musteri[i].cinsiyet << " ";
				dosya << musteri[i].dogum_tarihi << " ";
				dosya << musteri[i].telefon << " ";
				dosya << musteri[i].eposta << " ";
				dosya << musteri[i].giris_tarihi << " ";
				dosya << musteri[i].cikis_tarihi << " ";
				dosya << musteri[i].girisayi << " ";
				dosya << musteri[i].depozito << " ";

				for (int m = 0; m < 12; m++)
				{
					dosya << musteri[i].kiradurumu[m] << " ";
				}

				for (int n = 0; n < 12; n++)
				{
					dosya << musteri[i].elektrikfaturasidurumu[n] << " ";
				}
				for (int k = 0; k < 12; k++)
				{
					dosya << musteri[i].aylikendeks[k] << " ";
				}
				for (int l = 0; l < 12; l++)
				{
					dosya << musteri[i].endeksfarki[l] << " ";
				}
				for (int r = 0; r < 12; r++)
				{
					dosya << musteri[i].cikanelektrikborcu[r] << " ";
				}


				dosya << endl;
			}
		}
	}

}

void kiraode()
{
	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	int endekskiraciID;
	int hangiaydayiz;
	char tercih;
	string girisayi;
	int borcvarmi = 0;
	cout << "Kira odemek istediginiz kiracinin ID'sini girin " << endl;
	cin >> endekskiraciID;

			

	cout << "Hangi aydayiz? Ocak icin 1 Aralik icin 12" << endl;
	cin >> hangiaydayiz;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{

			if (musteri[i].id == endekskiraciID)
			{
				girisayi = musteri[i].girisayi;

				if (stoi(girisayi) > hangiaydayiz)
				{

					for (int p = stoi(girisayi) - 1; p < 12; p++)
					{
						if (musteri[i].kiradurumu[p] == 0)
						{
							borcvarmi = 1;
							cout << ay[p] << " ayi icin kira odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].kiradurumu[p] = 1;
							//	system("cls");
								cout << "Odeme yapildi."<<endl<<endl;
							}
						}

					}

					for (int r = 0; r < hangiaydayiz; r++)
					{
						if (musteri[i].kiradurumu[r] == 0)
						{
							borcvarmi = 1;
							cout << ay[r] << " ayi icin kira odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].kiradurumu[r] = 1;
							//	system("cls");
								cout << "Odeme yapildi."<<endl<<endl;
							}
						}
					}
				}

				else if (stoi(girisayi) <= hangiaydayiz)
				{

					for (int o = stoi(girisayi) - 1; o < hangiaydayiz; o++)
					{
						if (musteri[i].kiradurumu[o] == 0)
						{
							borcvarmi = 1;
							cout << ay[o] << " ayi icin kira odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].kiradurumu[o] = 1;
							//system("cls");
								cout << "Odeme yapildi."<<endl<<endl;
							}
						}
					}

				}
				dosyayayazdir();
				if (borcvarmi == 0)
				{
					cout << "musterinin kira borcu bulunmamaktadir. :)" << endl;
				}
			}
			
			
		}
	}


}

void guncelle()
{


	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	int id;
	char secenek;
	cout << "Guncellenecek musteri id yi gir" << endl;
	cin >> id;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{

			if (musteri[i].id == id)
			{

				cout << "Tc numarasi guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni Tc numarasi:";
					cin.ignore();
					getline(cin, musteri[i].tc);
				}

				cout << "Ad soyad guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni Ad soyad:";
					cin.ignore();
					getline(cin, musteri[i].ad_soyad);
				}

				cout << "Cinsiyeti guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni cinsiyeti:";
					cin.ignore();
					getline(cin, musteri[i].cinsiyet);
				}
				cout << "Dogum tarihi guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni dogum tarihi:";
					cin.ignore();
					getline(cin, musteri[i].dogum_tarihi);
				}
				cout << "Telefonu guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni telefon numarasi:";
					cin.ignore();
					getline(cin, musteri[i].telefon);
				}
				cout << "E-posta adresi guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni e-posta adresi:";
					cin.ignore();
					getline(cin, musteri[i].eposta);
				}
				cout << "Giris tarihi guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni giris tarihi:";
					cin.ignore();
					getline(cin, musteri[i].giris_tarihi);
				}
				cout << "Cýkýs tarihi guncellensin mi: (y / n)";
				cin >> secenek;
				if (secenek == 'y')
				{
					cout << "Yeni cýkýs tarihi:";
					cin.ignore();
					getline(cin, musteri[i].cikis_tarihi);
				}


				cout << "guncellendi :)" << endl;

			}
			else
			{
				cout << "bu id ye sahip kiraci bulunmamaktadir." << endl;
				break;
			}
		}
		dosyayayazdir();
	}
}

void dosyaoku()
{
	fstream dosya;

	dosya.open("proje.txt");
	if (dosya.is_open() == true)
	{
		string id;
		string tc;
		string ad_soyad;
		string cinsiyet;
		string dogum_tarihi;
		string telefon;
		string eposta;
		string giris_tarihi;
		string  cikis_tarihi;
		string depozito;
		string girisayi;
		ogrenci geciciogrenci;
		char *p;

		while (dosya >> id >> tc >> ad_soyad >> cinsiyet >> dogum_tarihi >> telefon >> eposta >> giris_tarihi >> cikis_tarihi >> girisayi >>depozito)
		{
			for (int m = 0; m < 12; m++)
			{
				dosya >> geciciogrenci.kiradurumu[m];
			}

			for (int n = 0; n < 12; n++)
			{
				dosya >> geciciogrenci.elektrikfaturasidurumu[n];
			}
			for (int k = 0; k < 12; k++)
			{
				dosya >> geciciogrenci.aylikendeks[k];
			}
			for (int l = 0; l < 12; l++)
			{
				dosya >> geciciogrenci.endeksfarki[l];
			}
			for (int r = 0; r < 12; r++)
			{
				dosya >> geciciogrenci.cikanelektrikborcu[r];
			}



			geciciogrenci.id = stoi(id);
			geciciogrenci.tc = tc;

			p = &ad_soyad[0];
			for (int i = 0; i < ad_soyad.length(); i++)
			{
				if (*p == '_')
				{
					*p = ' ';
				}
				p++;
			}
			geciciogrenci.ad_soyad = ad_soyad;


			geciciogrenci.cinsiyet = cinsiyet;
			geciciogrenci.dogum_tarihi = dogum_tarihi;
			geciciogrenci.telefon = telefon;
			geciciogrenci.eposta = eposta;
			geciciogrenci.giris_tarihi = giris_tarihi;
			geciciogrenci.cikis_tarihi = cikis_tarihi;
			geciciogrenci.girisayi = girisayi;
			geciciogrenci.depozito = kiracidepozito;


			kontrol[deger] = 1;
			musteri[deger] = geciciogrenci;
			deger++;
		}
	}

	
}

void verial()
{
	fstream dosya;
	char gecicicinsiyet;
	string gun, ay, yil;
	string girist,cikist;
	dosya.open("proje.txt");
	int flag = 0;
	if (deger == 20)
	{
		cout << "apartimiz doludur :)" << endl;
		return;
	}

	if (dosya.is_open()==true)
	{
		srand(time(NULL));
		musteri[deger].id = rand() % 8999 + 1000;

		cout << "id numarasi:" << musteri[deger].id;
		//cin >> musteri[deger].id;
		cin.ignore();
		cout << endl;
		cout << "Tc numarasi:";
		getline(cin, musteri[deger].tc);

		for (int i = 0; i < deger; i++)
		{
			if (musteri[i].tc == musteri[deger].tc)
			{
				flag =1;
				break;
			}
		}

		while (flag == 1)
		{
			flag = 0;
			cout << "tc no unique olmali yeni deger giriniz." << endl;
			cout << "Tc numarasi:";
			getline(cin, musteri[deger].tc);
			for (int i = 0; i < deger; i++)
			{
				if (musteri[i].tc == musteri[deger].tc)
				{
					flag = 1;
					break;
				}
			}
		}

		cout << "Ad-Soyad:";
		getline(cin,musteri[deger].ad_soyad);
		cout<< "Cinsiyet(e/k):";
		cin>>(gecicicinsiyet);

		if (gecicicinsiyet == 'e') 
		{
			//musteri[deger].cinsiyet = cinsiyet::erkek;
			musteri[deger].cinsiyet = "erkek";

		}
		else if (gecicicinsiyet == 'k')
		{
			//musteri[deger].cinsiyet = cinsiyet::kadin;
			musteri[deger].cinsiyet = "kadin";

		}
		cin.ignore();
		cout << "Dogum tarihi:";
		getline(cin, musteri[deger].dogum_tarihi);
		cout << "Telefon  numarasi:";
		getline(cin, musteri[deger].telefon);
		cout << "Eposta:";
		getline(cin, musteri[deger].eposta);
		cout << "Giris gunu:";
		cin >> gun;

		cout << "Giris ayi(ocak icin 1 aralik icin 12 giriniz.):";
		cin >> ay;

		cout << "Giris yili:";
		cin >> yil;

		girist.append(gun);
		girist.append("/");
		girist.append(ay);
		girist.append("/");
		girist.append(yil);
		musteri[deger].giris_tarihi = girist;

		musteri[deger].girisayi = ay;

		string yeniyil = to_string(stoi(yil) + 1);
		

		cikist.append(gun);
		cikist.append("/");
		cikist.append(ay);
		cikist.append("/");
		cikist.append(yeniyil);
		musteri[deger].cikis_tarihi = cikist;

		
		musteri[deger].depozito = kiracidepozito;

		kontrol[deger] = 1;
		deger++;
	}
	dosyayayazdir();
}

void sil()
{
	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	int varmi = 0;
	int id;
	cout << "Silinecek musteri id yi gir" << endl;
	cin >> id;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{
			if (musteri[i].id == id)
			{
				varmi = 1;
				kontrol[i] = 0;
				cout << "Silindi" << endl;
				dosyayayazdir();
			}
			


		}
	}
	if (varmi == 0)
	{
		cout << "Bu id ye sahip bir kiraci yok" << endl;
	}

}

void listele()
{
	int listekiraciID;
	string girisayi;
	int borcvarmi = 0;
	int kiraborcu = 0;
	int elektrikborcu = 0;

	for (int i = 0; i < deger; i++) {
		for (int j = 0; j < deger; j++)
		{
			if (kontrol[i] == 1)
			{
		
				if (musteri[i].id < musteri[j].id)
				{
					temp = musteri[i];
					musteri[i] = musteri[j];
					musteri[j] = temp;
				}
			}
		}
	}



	for (int i = 0; i < deger; i++)
	{
		
			if (kontrol[i] == 1)
			{
				cout << "------------------------------" << endl;
				cout <<"id:   "<< musteri[i].id << endl;
				cout <<"tc:   "<< musteri[i].tc << endl;
				cout <<"ad_soyad:   "<<musteri[i].ad_soyad << endl;
				cout <<"cinsiyet:   "<<musteri[i].cinsiyet << endl;
				cout <<"dogum_tarihi:   "<<musteri[i].dogum_tarihi << endl;
				cout <<"telefon:   "<< musteri[i].telefon << endl;
				cout <<"eposta:   "<< musteri[i].eposta << endl;
				cout <<"giris_tarihi:   "<< musteri[i].giris_tarihi << endl;
				cout <<"cikis_tarihi:   "<<musteri[i].cikis_tarihi << endl;
				cout <<"depozito:   "<<musteri[i].depozito << endl;

				girisayi = musteri[i].girisayi;
				kiraborcu = 0;
				elektrikborcu = 0;
				for (int j = stoi(girisayi) - 1; j < 12; j++)
				{
					if (musteri[i].kiradurumu[j] == 0)
					{
						//cout << ay[j] << " ayi: \t Odenmedi" << endl;
						kiraborcu += aylikkira;
					}
					else
					{
						//cout << ay[j] << " ayi: \t Odendi" << endl;
					}

				}

				for (int k = 0; k < stoi(girisayi) - 1; k++)
				{
					if (musteri[i].kiradurumu[k] == 0)
					{
						//cout << ay[k] << " ayi: \t Odenmedi" << endl;
						kiraborcu += aylikkira;
					}
					else
					{
						//cout << ay[k] << " ayi: \t Odendi" << endl;
					}
				}






				girisayi = musteri[i].girisayi;
			
				for (int j = stoi(girisayi) - 1; j < 12; j++)
				{
					if (musteri[i].elektrikfaturasidurumu[j] == 0)
					{
						//cout << ay[j] << " ayi: \t Odenmedi" << endl;
						elektrikborcu += musteri[i].cikanelektrikborcu[j];
					}
					else
					{
						//cout << ay[j] << " ayi: \t Odendi" << endl;
					}

				}

				for (int k = 0; k < stoi(girisayi) - 1; k++)
				{
					if (musteri[i].elektrikfaturasidurumu[k] == 0)
					{
						//cout << ay[k] << " ayi: \t Odenmedi" << endl;
						elektrikborcu += musteri[i].cikanelektrikborcu[k];
					}
					else
					{
						//cout << ay[k] << " ayi: \t Odendi" << endl;
					}
				}




				cout << "Musteri toplam kira borcu: " << kiraborcu << endl;
				cout << "Musteri toplam elektrik borcu: " << elektrikborcu << endl<<endl;
				cout << "------------------------------" << endl;

			}
		
	}


}

void borclistele()
{
	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	int listekiraciID;
	string girisayi;
	int borcvarmi = 0;
	int varmi = 0;
	cout << "Listelemek istediginiz kiracinin ID'sini girin " << endl;
	cin >> listekiraciID;
	
	
	int kiraborcu = 0;
	int elektrikborcu = 0;
	
	for (int i = 0; i < deger; i++)
	{
		if (musteri[i].id == listekiraciID)
		{
			if (kontrol[i] == 1)
			{
				varmi = 1;
				cout << "------------------------------" << endl;
				cout << "id:   " << musteri[i].id << endl;
				cout << "tc:   " << musteri[i].tc << endl;
				cout << "ad_soyad:   " << musteri[i].ad_soyad << endl;
				cout << "cinsiyet:   " << musteri[i].cinsiyet << endl;
				cout << "dogum_tarihi:   " << musteri[i].dogum_tarihi << endl;
				cout << "telefon:   " << musteri[i].telefon << endl;
				cout << "eposta:   " << musteri[i].eposta << endl;
				cout << "giris_tarihi:   " << musteri[i].giris_tarihi << endl;
				cout << "cikis_tarihi:   " << musteri[i].cikis_tarihi << endl;
				cout << "depozito:   " << musteri[i].depozito << endl;


				cout << endl << endl;

			}
		}
	}

	if (varmi == 0) {
		cout << "boyle bir kiraci bulunmamaktadir." << endl;
		return;
	}
		cout << "Kira Durumu" << endl;
		kiraborcu = 0;
		for (int i = 0; i < deger; i++)
		{
			if (kontrol[i] == 1)
			{

				if (musteri[i].id == listekiraciID)
				{
					girisayi = musteri[i].girisayi;

					for (int j = stoi(girisayi) - 1; j < 12; j++)
					{
						if (musteri[i].kiradurumu[j] == 0)
						{
							cout << ay[j] << " ayi: \t Odenmedi" << endl;
							kiraborcu += aylikkira;
						}
						else
						{
							cout << ay[j] << " ayi: \t Odendi" << endl;
						}

					}

					for (int k = 0; k < stoi(girisayi) - 1; k++)
					{
						if (musteri[i].kiradurumu[k] == 0)
						{
							cout << ay[k] << " ayi: \t Odenmedi" << endl;
							kiraborcu += aylikkira;
						}
						else
						{
							cout << ay[k] << " ayi: \t Odendi" << endl;
						}
					}

				}
				
			}
		}


		cout << "Elektrik Durumu" << endl;
		
		for (int i = 0; i < deger; i++) {
			
		if (kontrol[i] == 1)
		{

			if (musteri[i].id == listekiraciID)
			{

				girisayi = musteri[i].girisayi;
				for (int j = stoi(girisayi) - 1; j < 12; j++)
				{
					if (musteri[i].elektrikfaturasidurumu[j] == 0)
					{
						if (musteri[i].aylikendeks[j] == 0)
						{
							cout << ay[j] << " ayi: \t Endeks 0 degerinde" << endl;
						}
						else
						{
							cout << ay[j] << " ayi: \t Odenmedi" << endl;
						}			
						elektrikborcu += musteri[i].cikanelektrikborcu[j];
					}
					else
					{
						cout << ay[j] << " ayi: \t Odendi" << endl;
					}

				}

				for (int k = 0; k < stoi(girisayi) - 1; k++)
				{
					if (musteri[i].elektrikfaturasidurumu[k] == 0)
					{
						if (musteri[i].aylikendeks[k] == 0)
						{
							cout << ay[k] << " ayi: \t Endeks 0 degerinde" << endl;
						}
						else
						{
							cout << ay[k] << " ayi: \t Odenmedi" << endl;
						}						
						elektrikborcu += musteri[i].cikanelektrikborcu[k];
					}
					else
					{
						cout << ay[k] << " ayi: \t Odendi" << endl;
					}
				}


			}
			

		}
	}
	
	cout << "Musteri toplam kira borcu: " << kiraborcu<<endl;
	cout << "Musteri toplam elektrik borcu: " << elektrikborcu<<endl;
	cout << "Musteri toplam borcu: " << kiraborcu + elektrikborcu<<endl;
	cout << endl;
	cout << "------------------------------" << endl;


}

void elektrikendeksigir()
{
	int endekskiraciID;
	int hangiaydayiz;
	int endeks;
	string girisayi;
	int borcvarmi = 0;

	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	cout << "Endeks girmek istediginiz kiracinin ID'sini girin " << endl;
	cin >> endekskiraciID;

	cout << "Hangi aydayiz? Ocak icin 1 Aralik icin 12" << endl;
	cin >> hangiaydayiz;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{

			if (musteri[i].id == endekskiraciID)
			{
				girisayi = musteri[i].girisayi;

				if (stoi(girisayi) > hangiaydayiz)
				{

					for (int p = stoi(girisayi) - 1; p < 12; p++)
					{
						if (musteri[i].aylikendeks[p] == 0)
						{
							cout << ay[p] << " ayi icin endeks gir.(1000 den ve bir ay onceki aydan buyuk olmali) " << endl;
							cin >> endeks;
							musteri[i].aylikendeks[p] = endeks;
						}
							
					}

					for (int r = 0; r < hangiaydayiz; r++)
					{
						if (musteri[i].aylikendeks[r] == 0)
						{
							cout << ay[r] << " ayi icin endeks gir.(1000 den ve bir ay onceki aydan buyuk olmali) " << endl;
							cin >> endeks;
							musteri[i].aylikendeks[r] = endeks;

						}
					}
				}

				else if (stoi(girisayi) <= hangiaydayiz)
				{

					for (int o = stoi(girisayi) - 1; o < hangiaydayiz; o++)
					{
						if (musteri[i].aylikendeks[o] == 0)
						{
							cout << ay[o] << " ayi icin endeks gir. " << endl;
							cin >> endeks;
							musteri[i].aylikendeks[o] = endeks;
						}


					}

				}

			}
			dosyayayazdir();
		}
	}
}

void endeksfarki()
{
	string girisayi;

	for (int i = 0; i < deger; i++)
	{
			if (kontrol[i] == 1)
			{
				girisayi = musteri[i].girisayi;
				for (int p = 0; p < 12; p++)
				{
					if (musteri[i].aylikendeks[p]==0)
					{
						musteri[i].endeksfarki[p] = 0;
					}

					else if (p == 0)
					{
						musteri[i].endeksfarki[p] =  musteri[i].aylikendeks[p]- musteri[i].aylikendeks[11];
					}
					else if (p==stoi(girisayi)-1)
					{
						musteri[i].endeksfarki[p] = musteri[i].aylikendeks[p] - 1000;
					}
					else
					{
						musteri[i].endeksfarki[p] = musteri[i].aylikendeks[p] - musteri[i].aylikendeks[p-1];
					}
				}
				dosyayayazdir();
			}
	}

}

void tumendeksfarki()
{
	for (int p = 0; p < 12; p++)
	{
		for (int i = 0; i < deger; i++)
		{
			if (kontrol[i] == 1)
			{
				tumendeksfarklaritoplami[p] += musteri[i].endeksfarki[p];
			}
		}
	}	
}

void elektrikfaturahesapla()
{
	int musteriaylikendeks;
	int toplamaylikendeks;
	int toplamaylikfatura;
	double faturatutari;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{
			for (int p = 0; p < 12; p++)
			{
				musteriaylikendeks = musteri[i].endeksfarki[p];
				toplamaylikendeks = tumendeksfarklaritoplami[p];
				toplamaylikfatura = apartfatura[p];
				faturatutari = (musteriaylikendeks*toplamaylikfatura) / toplamaylikendeks;
				musteri[i].cikanelektrikborcu[p] = faturatutari;
			}
			dosyayayazdir();
		}
	}
}

void elektrikborcuode()
{
	cout << "Kayitli kiracilarin id leri" << endl;
	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1) {
			cout << musteri[i].id << endl;
		}
	}
	int endekskiraciID;
	int hangiaydayiz;
	char tercih;
	string girisayi;
	int borcvarmi = 0;
	cout << "Endeks girmek istediginiz kiracinin ID'sini girin " << endl;
	cin >> endekskiraciID;

	cout << "Hangi aydayiz? Ocak icin 1 Aralik icin 12" << endl;
	cin >> hangiaydayiz;

	for (int i = 0; i < deger; i++)
	{
		if (kontrol[i] == 1)
		{

			if (musteri[i].id == endekskiraciID)
			{
				girisayi = musteri[i].girisayi;

				if (stoi(girisayi) > hangiaydayiz)
				{

					for (int p = stoi(girisayi) - 1; p < 12; p++)
					{
						if (musteri[i].elektrikfaturasidurumu[p] == 0)
						{
							borcvarmi = 1;
							cout << ay[p] << " ayi icin elektrik faturasi odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].elektrikfaturasidurumu[p] = 1;
								cout << "Odeme yapildi."<<endl;
							}
						}

					}

					for (int r = 0; r < hangiaydayiz; r++)
					{
						if (musteri[i].elektrikfaturasidurumu[r] == 0)
						{
							borcvarmi = 1;
							cout << ay[r] << " ayi icin elektrik faturasi odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].elektrikfaturasidurumu[r] = 1;
								cout << "Odeme yapildi."<<endl;
							}
						}
					}
				}

				else if (stoi(girisayi) <= hangiaydayiz)
				{

					for (int o = stoi(girisayi) - 1; o < hangiaydayiz; o++)
					{
						if (musteri[i].elektrikfaturasidurumu[o] == 0)
						{
							borcvarmi = 1;
							cout << ay[o] << " ayi icin elektrik faturasi odemek icin y yaz. " << endl;
							cin >> tercih;
							if (tercih == 'y')
							{
								musteri[i].elektrikfaturasidurumu[o] = 1;
								cout << "Odeme yapildi."<<endl;
							}
						}
					}

				}

				if (borcvarmi == 0)
				{
					cout << "musteri elektrik borcu bulunmamaktadir." << endl;
				}
			}
			dosyayayazdir();
		}
	}
}

int main()
{
	dosyaoku();
	faturaoku();

	int secenek;
	int flag= 1;

	cout << "------PANSIYON YONETIM SISTEMINE HOSGELDINIZ." << endl;

	for (int i = 0;; i++)
	{
		cout << "Yeni kiraci kaydi icin 1'i seciniz." << endl;
		cout << "Kiraci kaydini silmek icin 2'i seciniz." << endl;
		cout << "Kiraci bilgilerini guncellemek icin 3'u seciniz." << endl;
		cout << "Listeleme 1 icin 4'u seciniz." << endl;
		cout << "Listeleme 2 icin icin 5'i seciniz." << endl;
		cout << "Kira borcu odemek icin 6'i seciniz." << endl;
		cout << "Elektrik borcu odemek icin 7'i seciniz." << endl;
		cout << "Kiraci Elektrik Endeks girmek icin 8'i seciniz." << endl;
		cout << "Aparta gelen elektrik faturasi girisi icin 9'u seciniz." << endl;
		cout << "Cikis yapmak icin 10'u seciniz." << endl;

		cin >> secenek;
		while (true)
		{
			switch (secenek)
			{
			case 1:
			{
				verial();

				break;
			}
			case 2:
			{
				sil();
				break;
			}
			case 3:
			{
				guncelle();
				break;
			}

			case 4:
			{

				listele();
				break;
			}

			case 5:
			{

				borclistele();
				break;
			}
			case 6:
			{
				cout << "Kira Ode "<<endl;
				kiraode();
				break;
			}

			case 7:
			{
				cout << "Elektrik Borcu ode "<<endl;
				endeksfarki();
				tumendeksfarki();
				elektrikfaturahesapla();
				elektrikborcuode();
				break;
			}

			case 8:
			{
				cout << "Elektrik Endeks gir "<<endl;
				elektrikendeksigir();
				break;
			}
			case 9:
			{
				toplamfatura();
				break;
			}
			case 10:
			{
				cout << "Cikis yapiliyor.";
				exit(0);
				flag = 1;
				break;
			}
			default:
			{
				cout << "lutfen yukardaki secenekleri giriniz." << endl;
				flag = 0;
			}
			}

					if (flag == 1)
		{
			break;
		
		}

		}
	}
	dosyayayazdir();
	system("pause");
}
