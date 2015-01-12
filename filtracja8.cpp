#include "poligon.h"
#include "statystyka.h"
#include <locale.h>

//normalizacja prêdkoœci
//wszystkie prêdkoœci w kierunku przejœcia s¹ dodatnie, a w przeciwnym ujemne
//ujemne opóŸnienie oznacza faktyczne hamowanie
//pozycje te¿ s¹ normalizowane
//dla kier POW oryginalnie prêdkoœci s¹ ujemne a opóŸnienia dodatnie, powoduje to k³opoty
//dla kier RAD jest w porz¹dku, tylko pozycje s¹ ujemne, s¹ wiêc normalizowane
//normalizacja dotyczy tylko horyzontalnych danych, wertykalne s¹ ok


//znormalizowac pozycje pieszych!!





int main( int argc, char *argv[] )
{
	//SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	//SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	

	


	//vector <double> x;
	//vector <double> v;
	//x.push_back(5.);
	//x.push_back(7.);
	//x.push_back(10.);
	//v.push_back(15.);
	//v.push_back(18.);
	//v.push_back(22.);
	//vector <double> new_x;
	//new_x.push_back(8.);
	//new_x.push_back(10.);
	//new_x.push_back(10.1);

	//
	//vector <double>w=interpolate2(x,v,new_x);











	Poligon wroclawska(argv[1] );


	cout << "\nAnaliza trajektorii pieszych...";
	wroclawska.analizuj_trajektorie_pieszych();

	cout << "\nAnaliza predkosci (i przyspieszenia)...";
	wroclawska.analizuj_trajektorie_pojazdow(3,15);



	cout << "\nWyszukiwanie samochodow widocznych wraz z pieszymi...";
	wroclawska.znajdz_pojazdy_dla_pieszych();


	

	cout << "\nWyznaczania minimalnej odleglosci pieszy-samochod...";
	wroclawska.znajdz_minimalna_odleglosc_od_pojazdow();
	wroclawska.znajdz_maksymalne_opoznienie_pojazdow(3,15);


	wroclawska.zbieraj_statystyki();


	cout<<"\nZapisywanie statystyk pieszych..."<<endl;
	wroclawska.zapisz_pieszych();	
	cout<<"Zapisywanie statystyk pojazdow..."<<endl;
	wroclawska.zapisz_pojazdy();		
	cout<<"Zapisywanie pliku przegladowego wynikow filtracji..."<<endl;
	wroclawska.zapisz_wyniki_filtracji();
	cout<<"\nZrobione...nacisnij Enter by zakonczyc program"<<endl;


	//plik_wy.open(nazwa_pliku_wyjsciowego+"0.htm",ios::out);
	//if( plik_wy.good() == false )
	//	cout << "Nie moge pisac w pliku wyjsciowym!" << endl;
	//else
	//	plik_wy << "<html><body>" <<endl;

	////drugi plik z danymi o trajektoriach pieszych
	//	//fstream plik_trajektorie;




	//cout << endl << "Liczba wykrytych pieszych nieprawidlowych (duchy i na samochodzie): " << wroclawska.statystyka.calosciowe.piesi.razem_niepoprawna <<endl;
	//cout << endl << "Procent wykrytych pieszych nieprawidlowych: " << 100*wroclawska.statystyka.calosciowe.piesi.razem_niepoprawna/wroclawska.piesi.pieszy.size() <<endl;

	//cout << endl << "Liczba wykrytych pieszych bez samochodu: " << wroclawska.piesi.liczba_pieszych_bez_samochodow <<endl;
	//cout << endl << "Procent wykrytych pieszych bez samochodu: " << 100*wroclawska.piesi.liczba_pieszych_bez_samochodow/wroclawska.piesi.pieszy.size() <<endl;

	//if(plik_wy.good())
	//{
	//	plik_wy << endl << "<br>Liczba wykrytych pieszych nieprawidlowych (duchy i na samochodzie): " << wroclawska.statystyka.calosciowe.piesi.razem_niepoprawna <<"<br>"<<endl;
	//	plik_wy << endl << "<br>Procent wykrytych pieszych nieprawidlowych: " << 100*wroclawska.statystyka.calosciowe.piesi.razem_niepoprawna/wroclawska.piesi.pieszy.size() <<"<br>"<<endl;
	//	plik_wy << endl << "<br>Liczba wykrytych pieszych bez samochodu: " << wroclawska.piesi.liczba_pieszych_bez_samochodow <<endl;
	//	plik_wy << endl << "<br>Procent wykrytych pieszych bez samochodu: " << 100*wroclawska.piesi.liczba_pieszych_bez_samochodow/wroclawska.piesi.pieszy.size() <<endl;
	//}


	//int licznik=1;
	//int licznik_plikow=1;
	//int sprawdzaj_przyspieszenie=1;

	//if(false)
	//{
	//	
	//	plik_trajektorie.open(nazwa_pliku_wyjsciowego+".csv",ios::out);
	//	plik_trajektorie<<"nr; id; odl. calk.; odl. efekt.; pion; poziom; drg. pion; drg. poziom; sr predk.; xmin; xsr; xmax\n";
	//	for(int i=0;i<wroclawska.piesi.pieszy.size();i++)
	//	{
	//		//if(wroclawska.piesi.pieszy[i].trajektoria.rodzaj.dobra==true)
	//		{

	//			plik_trajektorie << i << ";" << wroclawska.piesi.pieszy[i].id;
	//			plik_trajektorie << ";"<< wroclawska.piesi.pieszy[i].trajektoria.dlugosc.calkowita << ";" << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.efektywna <<";" << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_pionie<< ";" << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_poziomie;
	//			plik_trajektorie << ";" << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_pionie<< ";" << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_poziomie <<";"<<wroclawska.piesi.pieszy[i].trajektoria.predkosc.srednia;
	//			plik_trajektorie << ";" <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.minimalna << ";" << wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.srednia << ";" <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.maksymalna <<endl;




	//			cout << "\n" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":\n  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;
	//			cout << "\n minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;

	//			plik_wy << "<br>" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba<<endl;
	//			plik_wy << "<br>przebyta odleglosc calkowita: "<< wroclawska.piesi.pieszy[i].trajektoria.dlugosc.calkowita << ", efektywna: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.efektywna <<", w pionie: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_pionie<< ", w poziomie: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_poziomie <<endl;
	//			plik_wy << " wsp. drgan w pionie: " << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_pionie<< " wsp. drgan w poziomie: " << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_poziomie <<" srednia predkosc: "<<wroclawska.piesi.pieszy[i].trajektoria.predkosc.srednia <<endl;
	//			plik_wy << " polozenie poziome min: " <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.minimalna << " polozenie poziome sr: " << wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.srednia << " max. polozenie: " <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.maksymalna <<endl;
	//			plik_wy << "<br> Minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;
	//			plik_wy << "<br>Kolejne pojazdy na prawym pasie: ";
	//			for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//			{
	//				string nazwa_wlasciwa = wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].id;
	//				plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";
	//			}
	//			plik_wy << "<br>Kolejne pojazdy na lewym pasie: ";
	//			for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//			{
	//				string nazwa_wlasciwa = wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].id;
	//				plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";
	//			}
	//			plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na prawym pasie: ";
	//			for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//				plik_wy << wroclawska.piesi.pieszy[i].pojazdy.pp.minimalna_odleglosc[k] << "  ";
	//			plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na lewym pasie: ";
	//			for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//				plik_wy << wroclawska.piesi.pieszy[i].pojazdy.lp.minimalna_odleglosc[k] << "  ";

	//			plik_wy <<"<br> <video width=\"1000\"  controls>" <<endl<< "<source src=\"" << wroclawska.piesi.pieszy[i].sciezka<< "/"<<wroclawska.piesi.pieszy[i].id <<".mkv\"></video><br>"<<endl;

	//			licznik++;
	//			if(licznik%50==0)
	//			{
	//				plik_wy << "<br><br>Nastepna czesc: <a href=\""<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm\">"<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm" <<"</a> ";
	//				plik_wy << "</body></html>";
	//				plik_wy.close();
	//				stringstream ss;
	//				ss<<nazwa_pliku_wyjsciowego<<licznik_plikow<<".htm";
	//				plik_wy.open( ss.str(),ios::out);
	//				licznik_plikow++;
	//			}
	//		}
	//	}
	//}
	//else


	//	if(wroclawska.filtry.w_wynikach_maja_byc.duchy)
	//		for(int i=0;i<wroclawska.piesi.pieszy.size();i++)
	//		{
	//			if(wroclawska.piesi.pieszy[i].trajektoria.rodzaj.duch==true)
	//			{
	//				cout << "\n" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":\n  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;
	//				cout << "\n minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;

	//				plik_wy << "<br>" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba<<endl;
	//				plik_wy << "<br>przebyta odleglosc calkowita: "<< wroclawska.piesi.pieszy[i].trajektoria.dlugosc.calkowita << ", efektywna: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.efektywna <<", w pionie: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_pionie<< ", w poziomie: " << wroclawska.piesi.pieszy[i].trajektoria.dlugosc.w_poziomie <<endl;
	//				plik_wy << " wsp. drgan w pionie: " << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_pionie<< " wsp. drgan w poziomie: " << wroclawska.piesi.pieszy[i].trajektoria.wspolczynnik_drgan_w_poziomie <<" srednia predkosc: "<<wroclawska.piesi.pieszy[i].trajektoria.predkosc.srednia <<endl;
	//				plik_wy << " polozenie poziome min: " <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.minimalna << " polozenie poziome sr: " << wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.srednia << " max. polozenie: " <<wroclawska.piesi.pieszy[i].trajektoria.pozycja.pozioma.maksymalna <<endl;
	//				plik_wy << "<br> Minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;
	//				plik_wy << "<br>Kolejne pojazdy na prawym pasie: ";
	//				for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//				{
	//					string nazwa_wlasciwa = wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].id;
	//					plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";
	//				}
	//				plik_wy << "<br>Kolejne pojazdy na lewym pasie: ";
	//				for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//				{
	//					string nazwa_wlasciwa = wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].id;
	//					plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";
	//				}
	//				plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na prawym pasie: ";
	//				for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//					plik_wy << wroclawska.piesi.pieszy[i].pojazdy.pp.minimalna_odleglosc[k] << "  ";
	//				plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na lewym pasie: ";
	//				for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//					plik_wy << wroclawska.piesi.pieszy[i].pojazdy.lp.minimalna_odleglosc[k] << "  ";

	//				plik_wy <<"<br> <video width=\"1000\"  controls>" <<endl<< "<source src=\"" << wroclawska.piesi.pieszy[i].sciezka<< "/"<<wroclawska.piesi.pieszy[i].id <<".mkv\"></video><br>"<<endl;

	//				licznik++;
	//				if(licznik%50==0)
	//				{
	//					plik_wy << "<br><br>Nastepna czesc: <a href=\""<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm\">"<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm" <<"</a> ";
	//					plik_wy << "</body></html>";
	//					plik_wy.close();
	//					stringstream ss;
	//					ss<<nazwa_pliku_wyjsciowego<<licznik_plikow<<".htm";
	//					plik_wy.open( ss.str(),ios::out);
	//					licznik_plikow++;
	//				}
	//			}
	//		}
	//	else
	//		if(wroclawska.filtry.w_wynikach_maja_byc.konflikty)
	//		{
	//			for(int i=0;i<wroclawska.piesi.pieszy.size();i++)
	//			{
	//				//pominiecie nieprawidlowo wykrytych pieszych
	//				if(wroclawska.piesi.pieszy[i].trajektoria.rodzaj.duch==true)
	//					continue;
	//				if(wroclawska.piesi.pieszy[i].trajektoria.rodzaj.pieszy_na_samochodzie==true)
	//					continue;
	//				//pominiecie pieszych bez samochodu
	//				if(wroclawska.piesi.pieszy[i].pojazdy.razem==0) continue;
	//				//sprawdzenie czy ktorykolwiek pojazd przekroczyl opoznienie
	//				float md=wroclawska.piesi.pieszy[i].maksymalne_opoznienie;
	//				float md2=wroclawska.znajdz_najwieksze_opoznienie_pojazdu_dla_pieszego(i);
	//				//maksymalne opoznienie w ogole
	//				//if(wroclawska.znajdz_najwieksze_opoznienie_pojazdu_dla_pieszego(i)>-4) continue;
	//				//maksymalne opoznienie w zakresie widocznosci pieszego
	//				if(wroclawska.piesi.pieszy[i].maksymalne_opoznienie>-4) continue;
	//				cout << "\n" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":\n  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;
	//				cout << "\n minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;


	//				if(plik_wy.good())
	//				{
	//					plik_wy << "<br>" << licznik << ". " << wroclawska.piesi.pieszy[i].id << ":  nr: " << i << " czas: " << wroclawska.piesi.pieszy[i].t1<<" razem: "<< wroclawska.piesi.pieszy[i].pojazdy.razem <<" prawy: " <<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba << " lewy: " << wroclawska.piesi.pieszy[i].pojazdy.lp.liczba<<endl;
	//					plik_wy << "<br> Minimalna odleglosc: " << wroclawska.piesi.pieszy[i].konfliktowy_pojazd.minimalna_odleglosc;
	//					plik_wy << "<br>Kolejne pojazdy na prawym pasie: ";
	//					for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//					{
	//						string nazwa_wlasciwa = wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_pp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k]].id;
	//						plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";

	//					}
	//					plik_wy << "<br>Kolejne pojazdy na lewym pasie: ";
	//					for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//					{
	//						string nazwa_wlasciwa = wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].sciezka +"/"+ wroclawska.pojazdy_lp.pojazd[wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k]].id;
	//						plik_wy << "<a href=\"" << nazwa_wlasciwa << ".xml" << "\">" << "XML" <<"</a>, " << "<a href=\"" << nazwa_wlasciwa << ".mkv" << "\">" << "MKV" <<"</a> "<< " ";
	//					}
	//					plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na prawym pasie: ";
	//					for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//						plik_wy << wroclawska.piesi.pieszy[i].pojazdy.pp.minimalna_odleglosc[k] << "  ";
	//					plik_wy << "<br>Minimalne odleglosci od kolejnych samochodow na lewym pasie: ";
	//					for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//						plik_wy << wroclawska.piesi.pieszy[i].pojazdy.lp.minimalna_odleglosc[k] << "  ";

	//					if(sprawdzaj_przyspieszenie)
	//					{
	//						plik_wy << "<br>Maksymalne opoznienia (oraz delta Vx, Vxmax-Vxmin) kolejnych samochodow na prawym pasie: ";
	//						for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.pp.liczba;k++)
	//						{
	//							int nr_pojazdu=wroclawska.piesi.pieszy[i].pojazdy.pp.nr[k];
	//							if(wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.min_x<.2)
	//								plik_wy<<"<font color=\"red\">";
	//							plik_wy << wroclawska.pojazdy_pp.pojazd[nr_pojazdu].acc.min_x << "("<< wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.max_x-wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.min_x <<", "<<wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.max_x<<"-"<<wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.min_x <<")  ";

	//							if(wroclawska.pojazdy_pp.pojazd[nr_pojazdu].vel.min_x<.2)
	//								plik_wy<<"</font>";


	//						}
	//						plik_wy << "<br>Maksymalne opoznienia (oraz delta Vx, Vxmax-Vxmin) kolejnych samochodow na lewym pasie: ";
	//						for(int k=0;k<wroclawska.piesi.pieszy[i].pojazdy.lp.liczba;k++)
	//						{
	//							int nr_pojazdu=wroclawska.piesi.pieszy[i].pojazdy.lp.nr[k];
	//							if(wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.min_x<.2)
	//								plik_wy<<"<font color=\"red\">";
	//							plik_wy << wroclawska.pojazdy_lp.pojazd[nr_pojazdu].acc.min_x << "("<< wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.max_x-wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.min_x<<", "<<wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.max_x<<"-"<<wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.min_x<<")  ";
	//							if(wroclawska.pojazdy_lp.pojazd[nr_pojazdu].vel.min_x<.2)
	//								plik_wy<<"</font>";


	//						}
	//					}

	//					plik_wy <<"<br> <video width=\"1000\"  controls>" <<endl<< "<source src=\"" << wroclawska.piesi.pieszy[i].sciezka<< "/"<<wroclawska.piesi.pieszy[i].id <<".mkv\"></video><br>"<<endl;
	//				}
	//				licznik++;
	//				if(licznik%50==0)
	//				{
	//					plik_wy << "<br><br>Nastepna czesc: <a href=\""<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm\">"<<nazwa_pliku_wyjsciowego << licznik_plikow << ".htm" <<"</a> ";
	//					plik_wy << "</body></html>";
	//					plik_wy.close();
	//					stringstream ss;
	//					ss<<nazwa_pliku_wyjsciowego<<licznik_plikow<<".htm";
	//					plik_wy.open( ss.str(),ios::out);
	//					licznik_plikow++;
	//				}
	//			}




	//		}


	//		plik_wy << "</body></html>";
	//		plik_wy.close();
	//		plik_trajektorie.close();



			if(argc>2)
				cin.ignore(1);
			cout<<"Zwalnianie pamieci....okno konsoli zaraz samo sie zamknie";
}






