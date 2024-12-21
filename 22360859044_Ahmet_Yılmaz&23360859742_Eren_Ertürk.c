#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu_yazdir();
void kamp_alani_alt_secenekler();
void sifahaneye_git_alt_secenekler();
void hana_git_alt_secenekler();
void maceraya_atil_alt_secenekler();
void durumu_goster(Ozan* ozan);
void uyu(Ozan* ozan, int saat);
void karizma(Ozan* ozan, int miktar);
void can(Ozan* ozan, int miktar);
void tokluk(Ozan* ozan, int miktar);
void su_degeri(Ozan* ozan, int miktar);
void hijyen(Ozan* ozan, int miktar);
void para(Ozan* ozan, int miktar);
void tecrube(Ozan* ozan, int miktar);
void guc(Ozan* ozan, int miktar);
void ceviklik(Ozan* ozan, int miktar);
void dayaniklilik(Ozan* ozan, int miktar);
void toplayicilik_becerisi(Ozan* ozan, int miktar);
void eglence_degeri(Ozan* ozan, int sure);
void moral_degeri(Ozan* ozan, int miktar);
void kampa_git(Ozan* ozan, int* secim);
void sifahaneye_git(Ozan* ozan, int* secim);
void hana_git(Ozan* ozan, int* secim);
void maceraya_atil(Ozan* ozan, int* secim);
//void oyundan_cik(int* secim);
void seviye_atla(Ozan* ozan);
void savas_becerileri(Ozan* ozan, Haydut* haydut);
void savas(Ozan* ozan, Haydut* haydut);
void ozanin_savas_secimi(Ozan* ozan, Haydut* Haydut);

typedef struct Ozan {
	char ozan_adi[20];
	char calgi_adi[20];
	int para_degeri;
	int tecrube_degeri;
	int can_degeri;
	int tokluk_degeri;
	int su_degeri;
	int uyku_degeri;
	int hijyen_degeri;
	int eglence_degeri;
	int moral_deger;
	int toplayicilik_becerisi_degeri;
	
	int guc_degeri;
	int ceviklik_degeri;
	int dayaniklilik_degeri;
	int karizma_degeri;
} Ozan;

typedef struct Haydut {
	int can_degeri;
	int guc_degeri;
	int ceviklik_degeri;
	int dayaniklilik_degeri;
} Haydut;

void main() {
	Haydut* haydut;
	Ozan ozan;
	printf("Ozan'in adini giriniz: ");
	gets(ozan.ozan_adi);

	printf("Ozan'in caldigi calginin adi: ");
	gets(ozan.calgi_adi);
	ozan.para_degeri = 10;
	ozan.tecrube_degeri = 50;
	ozan.can_degeri = 100;
	ozan.tokluk_degeri = 50;
	ozan.su_degeri = 50;
	ozan.uyku_degeri = 50;
	ozan.hijyen_degeri = 50;
	ozan.eglence_degeri = 50;
	ozan.moral_deger = 50;
	ozan.toplayicilik_becerisi_degeri = 50;

	ozan.guc_degeri = 3;
	ozan.ceviklik_degeri = 3;
	ozan.dayaniklilik_degeri = 3;
	ozan.karizma_degeri = 3;

	srand(time(NULL));
	int secim;
	while (1) {
		menu_yazdir(&secim);

		kampa_git(&ozan, &secim);
		
		sifahaneye_git(&ozan, &secim);

		hana_git(&ozan, &secim);

		maceraya_atil(&ozan, &haydut, &secim);
		
		if (secim == 5) {
			durumu_goster(&ozan);
		}
		// else if (secim == 6) {

		// }
		else if (secim == 7) {
			printf("Cikmak istediginizden emin misiniz? (E/H)");
			scanf("%d", &secim);
			if (secim == 7)
				break;
		}
		else{
			printf("gecersiz secim yaptiniz yeniden seciniz.\n");
			menu_yazdir(&secim);
		}
		if(ozan.tokluk_degeri == 0) {
			ozan.can_degeri -= 20;
		} 
		if(ozan.su_degeri == 0) {
			ozan.can_degeri -= 15;
		}
		if (ozan.uyku_degeri == 0) {
			ozan.can_degeri -= 10;
		} 		
		// her turdan sonra temel niteliklerin azalması gerekiyor bunu burada hallet.
	}
}
void kampa_git(Ozan* ozan, int* secim) {
	int uyku_miktari;
	if (secim == 1) {
		printf("Kamp alanina gidiyorsunuz...\n");
		kamp_alani_alt_secenekler();
		int alt_secim;
		printf("kamp alaninda ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:												//Kamp ateşinin başında çalgı çal/şarkı söyle.(tecrube, karizma, tokluk, susuzluk, eglence, moral)
			tecrube(&ozan->tecrube_degeri, 10);
			karizma(&ozan->karizma_degeri, 10);
			break;
		case 2:												//Nehirde yıkan.(can degeri, tecrube, hijyen, eglence, moral)
			can(&ozan->can_degeri, 10);
			tecrube(&ozan->tecrube_degeri, 10);
			break;
		case 3:		
			printf("ozan ne kadar uyusun: ");										//Çadırına girip uyu.(uyku, guc, ceviklik, dayanıklılık, tokluk, su degeri)
			scanf("%d", &uyku_miktari);
			uyu(&ozan->uyku_degeri, uyku_miktari);
			guc(&ozan->guc_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			break;
		case 4:
			menu_yazdir(secim);
			break;
		}
	}
}

void sifahaneye_git(Ozan* ozan, int* secim) {
	if (secim == 2) {
		printf("sifahaneye gidiyorsunuz...");
		sifahaneye_git_alt_secenekler();
		int alt_secim;
		printf("sifahane de ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:												// Şifacıdan yaralarını sarmasını iste.(can degeri, ceviklik, dayanıklılık, -para, guc, moral)
			can(&ozan->can_degeri, 14);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			para(&ozan->para_degeri, 10);
			moral(&ozan->moral_deger, 10);
			break;
		case 2:												// Şifacıdan merhem yapıp sürmesini iste.(can degeri, ceviklik, dayanıklılık, -para, guc, moral)
			can(&ozan->can_degeri, 21);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			para(&ozan->para_degeri, 10);
			moral(&ozan->moral_deger, 10);
			break;
		case 3:
			menu_yazdir(&secim);
			break;
		}
	}
}

void hana_git(Ozan* ozan, int* secim) {
	if (secim == 3) {
		printf("hana gidiyorsunuz...");
		hana_git_alt_secenekler();
		int alt_secim;
		printf("han	da ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:								//Yiyecek satın al ve ye. (-para, can degeri, ceviklik, dayanıklılık, tokluk, guc, su degeri, eglence, moral)
			para(&ozan->para_degeri, 10);
			tokluk(&ozan->tokluk_degeri, 10);
			can(&ozan->can_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			break;
		case 2:								//İçecek satın al, iç ve eğlen. (-para, can degeri, ceviklik, dayanıklılık, guc, karizma, su degeri, eglence, moral)
			para(&ozan->para_degeri, 10);
			can(&ozan->can_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			tokluk(&ozan->tokluk_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			karizma(&ozan->karizma_degeri, 10);
			break;
		case 3:								//Enstrüman çal ve şarkı söyle. (karizma, tecrube, su degeri, tokluk, eglence, moral)
			if (ozan->hijyen_degeri < 20) {
				printf("hijyene onem vermediginiz icin handa sarki soyleyemezsiniz.");
				break;
			}
			ozan->para_degeri = (10 + ((ozan->karizma_degeri) * (ozan->hijyen_degeri) / 100));
			tecrube(&ozan->tecrube_degeri, 20);
			karizma(&ozan->karizma_degeri, 10);
		case 4:
			menu_yazdir(&secim);
			break;
		}
	}
}	

void maceraya_atil(Ozan* ozan, Haydut* haydut, int* secim) {
	double kolay_haydut_ganimeti = 15 + (rand() % 10);
	double orta_haydut_ganimeti = 30 + (rand() % 20);
	double zor_haydut_ganimeti = 55 + (rand() % 20);
	int random_sayi_sifali_bitki = rand() % 100;		// bu sayı şifalı bitki bulma şansını kontrol etmek için var 
	int random_sayi_meyve = rand() % 100;		// bu sayı meyve bulma şansını kontrol etmek için var 
	int random_hayvan_bulma = rand() % 100;
	double sifali_bitki_bulma_sansi = (ozan->toplayicilik_becerisi_degeri * 4) / 100;
	if (secim == 4) {
		printf("maceraya katiliyorsunuz...");
		maceraya_atil_alt_secenekler();
		int alt_secim;
		printf("nasil bir maceraya katilmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:												   	// Yakın çevreden şifalı bitki topla ve avlan. (toplayıcılık becerisi, -can degeri, tecrube, -dayanıklılık, -ceviklik, -tokluk, -uyku, -guc)
			if((sifali_bitki_bulma_sansi * 100) > random_sayi_sifali_bitki)
				ozan->can_degeri += 10;
				
			if((sifali_bitki_bulma_sansi * 100) > random_sayi_meyve)
				ozan->tokluk_degeri += 10;
			
			if((sifali_bitki_bulma_sansi * 100 / 2) > random_hayvan_bulma)
				ozan->tokluk_degeri += 50;

			toplayicilik_becerisi(&ozan->toplayicilik_becerisi_degeri, 10);
			can(&ozan->can_degeri, 10);
			tecrube(&ozan->tecrube_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			tokluk(&ozan->tokluk_degeri, 10);
			uyu(&ozan->uyku_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			break;
		case 2:													//  Ormanı keşfe çık (kolay). (tecrube, para)
			haydut->guc_degeri = (rand() % 2) + 1;
			haydut->dayaniklilik_degeri = (rand() % 2) + 4;
			haydut->ceviklik_degeri = (rand() % 2) + 4;
			savas_becerileri(ozan, haydut);
			ozanin_savas_secimi(ozan, haydut);
			tecrube(&ozan->tecrube_degeri, 30);
			para(&ozan->para_degeri, kolay_haydut_ganimeti);
			break;
		case 3:													// Kayalıkları keşfe çık (orta). (tecrube, para)
			haydut->guc_degeri = (rand() % 2) + 4;
			haydut->dayaniklilik_degeri = (rand() % 2) + 4;
			haydut->ceviklik_degeri = (rand() % 2) + 4;
			savas_becerileri(ozan, haydut);
			ozanin_savas_secimi(ozan, haydut);
			tecrube(&ozan->tecrube_degeri, 60);
			para(&ozan->para_degeri, orta_haydut_ganimeti);
			break;
		case 4:													// Vadiyi keşfe çık (zor). (tecrube, para)
			haydut->guc_degeri = (rand() % 3) + 7;
			haydut->dayaniklilik_degeri = (rand() % 3) + 7;
			haydut->ceviklik_degeri = (rand() % 3) + 7;
			savas_becerileri(ozan, haydut);
			ozanin_savas_secimi(ozan, haydut);
			tecrube(&ozan->tecrube_degeri, 90);
			para(&ozan->para_degeri, zor_haydut_ganimeti);
			break;
		case 5:
			menu_yazdir(&secim);
			break;
		}
	}
}

void seviye_atla(Ozan* ozan) {
	if (ozan->tecrube_degeri == 100) {
		ozan->tecrube_degeri = 3;
		ozan->dayaniklilik_degeri = 3;
		ozan->guc_degeri = 3;
		ozan->karizma_degeri = 3;
		ozan->toplayicilik_becerisi_degeri = 3;
	}
	int secim, miktar, toplam_puan;
	while (toplam_puan != 0){
		printf("-----SEVIYE ATLAMA MENUSU-----\n\n");
		printf("seviye atladiniz tebrikler! 5 puan kazandiniz. Puanlarinizi hangi becerilerde kullanmak istersiniz? (once artirmak istediginiz becerinin numarasini yazin sonra artirmak istediginiz miktari girin.)\n");
		printf("1- tecrube\n2- dayaniklilik\n3- guc\n4- karizma\n5- toplayicilik becerisi\n");
		scanf("%d", &secim);
		switch(secim) {
			case 1:
				scanf("%d", &miktar);
				if((miktar >= 0) && (miktar <= 5)){
					ozan->tecrube_degeri += miktar;
					toplam_puan -= miktar;
				}
				else 
					printf("gecersiz deger girdiniz.");
				break;
			case 2:
				scanf("%d", &miktar);
				if((miktar >= 0) && (miktar <= 5)){
					ozan->tecrube_degeri += miktar;
					toplam_puan -= miktar;
				}
				else 
					printf("gecersiz deger girdiniz.");
				break;
			case 3:
				scanf("%d", &miktar);
				if((miktar >= 0) && (miktar <= 5)){
					ozan->tecrube_degeri += miktar;
					toplam_puan -= miktar;
				}
				else 
					printf("gecersiz deger girdiniz.");
				break;
			case 4:
				scanf("%d", &miktar);
				if((miktar >= 0) && (miktar <= 5)){
					ozan->tecrube_degeri += miktar;
					toplam_puan -= miktar;
				}
				else 
					printf("gecersiz deger girdiniz.");
				break;
			case 5:
				scanf("%d", &miktar);
				if((miktar >= 0) && (miktar <= 5)){
					ozan->tecrube_degeri += miktar;
					toplam_puan -= miktar;
				}
				else 
					printf("gecersiz deger girdiniz.");
				break;
			default:
				printf("gecersiz islem yaptiniz.");
				break;
		}
	}
}

void menu_yazdir(int* secim) {
	printf("**********MENU**********\n\n1-kamp alanina git\n2-sifahaneye git\n3-hana git\n4-maceraya katil\n5-seviye atla\n6-Durumu goster\n7-oyundan cik\n");
	printf("menuden bir gorev seciniz");
	scanf("%d", &secim);
}
void kamp_alani_alt_secenekler() {
	printf("1. Kamp atesinin basinda calgi cal/sarki soyle.\n");
	printf("2. Nehirde yikan.\n");
	printf("3. cadirina girip uyu.\n");
	printf("4. Koy meydanina don.\n");
}
void sifahaneye_git_alt_secenekler() {
	printf("1. sifacidan yaralarini sarmasini iste.\n");
	printf("2. sifacidan merhem yapip surmesini iste.\n");
	printf("3. Koy meydanina don.\n");
}
void hana_git_alt_secenekler() {
	printf("1. Yiyecek satin al ve ye.\n");
	printf("2. icecek satin al, ic ve eglen.\n");
	printf("3. Enstruman cal ve sarki soyle.\n");
	printf("4. Koy meydanina don.\n");
}
void maceraya_atil_alt_secenekler() {
	printf("1. Yakin cevreden sifali bitki topla ve avlan.\n");
	printf("2. Ormani kesfe cik (kolay).\n");
	printf("3. Kayaliklari kesfe cik (orta).\n");
	printf("4. Vadiyi kesfe cik (zor).\n");
	printf("5. Koy meydanina don.\n");
}
void durumu_goster(Ozan* ozan) {
	printf("isim: %s\n", ozan->ozan_adi);
	printf("calgi adi: %s\n", ozan->calgi_adi);
	printf("para: %d\n", ozan->para_degeri);
	printf("tecrube: %d\n", ozan->tecrube_degeri);
	printf("can: %d\n", ozan->can_degeri);
	printf("tokluk: %d\n", ozan->tokluk_degeri);
	printf("su: %d\n", ozan->su_degeri);
	printf("hijyen: %d\n", ozan->hijyen_degeri);
	printf("uyku: %d\n", ozan->uyku_degeri);
	printf("eglence: %d\n", ozan->eglence_degeri);
	printf("moral: %d\n", ozan->moral_deger);
	printf("guc: %d\n", ozan->guc_degeri);
	printf("ceviklik: %d\n", ozan->ceviklik_degeri);
	printf("dayaniklilik: %d\n", ozan->dayaniklilik_degeri);
	printf("karizma: %d\n", ozan->karizma_degeri);
	printf("toplayicilik becerisi: %d\n", ozan->toplayicilik_becerisi_degeri);
}

void uyu(Ozan* ozan, int saat) {
	if(ozan->uyku_degeri > 100) {
		printf("uyku seviyesi 100'den buyuk olamaz.\n");
	}
	/*else if (*uyku_seviyesi <= 20) {
		printf("uyku seviyesi 20'nin altina düstü.\n");
	}
	else if (*uyku_seviyesi < 0) {
		*uyku_seviyesi = 0;
	}
	else if (*uyku_seviyesi == 0) {
		*can_degeri -= 10;
	}*/											// bunları burada kontrol etmek mantıksız.
	else {
		ozan->uyku_degeri += 10 * saat;
		ozan->tokluk_degeri -= 4 * saat;
		ozan->su_degeri -= 3 * saat;
		if(ozan->uyku_degeri > 100) {
			ozan->uyku_degeri = 100;
		}
	}
	printf("uyku seviyesi: %d\n", ozan->uyku_degeri);
}
void karizma(Ozan* ozan, int miktar) {
	if (ozan->karizma_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		ozan->karizma_degeri += miktar;
		if (ozan->karizma_degeri > 25) {
			ozan->karizma_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", ozan->karizma_degeri);
}
void can(Ozan* ozan, int miktar) {
	if (ozan->can_degeri > 100) {
		printf("saglik degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->can_degeri += miktar;
		if (ozan->can_degeri > 100) {
			ozan->can_degeri = 100;
		}
	}
}
void tokluk(Ozan* ozan, int miktar) {
	int secim;
	printf("acligi nasil gidermek istersiniz?\n1. ekmek ye (2 altin, +10 tokluk)\n2. yahni ye (10 altin, +50 tokluk)\n3. elma ye (1 altin, +5 tokluk)\n");
	scanf("%d", &secim);
	switch (secim) {
		case 1:
			ozan->para_degeri -= 2 * miktar;
			ozan->tokluk_degeri += 10 * miktar;
			break;
		case 2:
			ozan->para_degeri -= 10 * miktar;
			ozan->tokluk_degeri += 50 * miktar;
			break;
		case 3:
			ozan->para_degeri -= 1 * miktar;
			ozan->tokluk_degeri += 5 * miktar;
		default:
			printf("gecersiz islem yaptiniz.");
	}
	if (ozan->tokluk_degeri > 100) {
		printf("aclik degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->uyku_degeri -= 10 * miktar;
		if (ozan->tokluk_degeri > 100) {
			ozan->tokluk_degeri = 100;
		}
	}
}
void su_degeri(Ozan* ozan, int miktar) {
	if (ozan->su_degeri > 100) {
		printf("su degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->su_degeri += miktar;
		ozan->tokluk_degeri -= 10;		// su içmek acıktırır.
		if (ozan->su_degeri > 100) {
			ozan->su_degeri = 100;
		}
	}
}

void eglence_degeri(Ozan* ozan, int sure) {
	if (ozan->eglence_degeri > 100) {
		printf("eglence degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->eglence_degeri += sure * 10; 
		ozan->tokluk_degeri -= sure * 5;
		ozan->uyku_degeri -= sure * 5;
		if (ozan->eglence_degeri > 100) {
			ozan->eglence_degeri = 100;
		}
	}
}

void moral_degeri(Ozan* ozan, int miktar) {
	if (ozan->moral_deger > 100) {
		printf("moral degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->moral_deger += miktar;
		if (ozan->moral_deger > 100) {
			ozan->moral_deger = 100;
		}
	}
}

void hijyen(Ozan* ozan, int miktar) {
	if (ozan->hijyen_degeri > 100) {
		printf("hijyen degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->hijyen_degeri += miktar;
		if (ozan->hijyen_degeri > 100) {
			ozan->hijyen_degeri = 100;
		}
	}
}
void para(Ozan* ozan, int miktar) {
	ozan->para_degeri += miktar;
}
void tecrube(Ozan* ozan, int miktar) {
	if (ozan->tecrube_degeri > 100) {
		printf("tecrube degeri 100'den buyuk olamaz.\n");
	}
	else {
		ozan->tecrube_degeri += miktar;
		if (ozan->tecrube_degeri > 100) {
			ozan->tecrube_degeri = 100;
		}
	}
	if (tecrube == 100) {
		seviye_atla(ozan);
	}
}
void guc(Ozan* ozan, int miktar) {
	if (ozan->guc_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		ozan->guc_degeri += miktar;
		if (ozan->guc_degeri > 25) {
			ozan->guc_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", ozan->guc_degeri);
}
void ceviklik(Ozan* ozan, int miktar) {
	if (ozan->ceviklik_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		ozan->ceviklik_degeri += miktar;
		if (ozan->ceviklik_degeri > 25) {
			ozan->ceviklik_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", ozan->ceviklik_degeri);
}
void dayaniklilik(Ozan* ozan, int miktar) {
	if (ozan->dayaniklilik_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		ozan->dayaniklilik_degeri += miktar;
		if (ozan->dayaniklilik_degeri > 25) {
			ozan->dayaniklilik_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", ozan->dayaniklilik_degeri);
}
void toplayicilik_becerisi(Ozan* ozan, int miktar) {
	if (ozan->toplayicilik_becerisi_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		ozan->toplayicilik_becerisi_degeri += miktar;
		if (ozan->toplayicilik_becerisi_degeri > 25) {
			ozan->toplayicilik_becerisi_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", ozan->toplayicilik_becerisi_degeri);
}

void savas_becerileri(Ozan* ozan, Haydut* haydut) {
	printf("%s'in savas becerileri\n", ozan->ozan_adi);
	printf("guc degeri: %d\ndayaniklilik degeri: %d\nceviklik degeri: %d\n\n", ozan->guc_degeri, ozan->dayaniklilik_degeri, ozan->ceviklik_degeri);
	printf("haydutun savas becerileri\n");
	printf("guc degeri: %d\ndayaniklilik degeri: %d\nceviklik degeri: %d", haydut->guc_degeri, haydut->dayaniklilik_degeri, haydut->ceviklik_degeri);
}

void savas(Ozan* ozan, Haydut* haydut, int* ozanin_verdigi_hasar, int* ozanin_aldigi_hasar) {
	while((ozan->can_degeri > 0) || (haydut->can_degeri > 0)) {
		if(ozan->ceviklik_degeri > haydut->ceviklik_degeri) {
			*ozanin_verdigi_hasar = ozan->guc_degeri * 4;
		} else if(ozan->ceviklik_degeri < haydut->ceviklik_degeri) {
			*ozanin_aldigi_hasar = (haydut->guc_degeri * 4) - (haydut->guc_degeri * 4 * 4 * ozan->dayaniklilik_degeri / 100 - 1);
			ozan->can_degeri -= *ozanin_aldigi_hasar;
		}
	}
}

void ozanin_savas_secimi(Ozan* ozan, Haydut* haydut) {
	int savasma_secimi;
	int ozanin_aldigi_hasar;
	int ozanin_verdigi_hasar;
	int ozanin_kacma_ihtimali;
	int random_ozanin_kacma_ihtimali;	// bu sayi ozanin kacabilme ihtimali için random oluşturulacaktır.
	printf("1-savas\n2-kac\n");
	scanf("%d", &savasma_secimi);
	switch(savasma_secimi) {
		case 1:
			savas(ozan, haydut, &ozanin_verdigi_hasar, &ozanin_aldigi_hasar);
			break;
		case 2:
			ozanin_kacma_ihtimali = 4 * ozan->ceviklik_degeri / 100;
			random_ozanin_kacma_ihtimali = rand() % 100;
			if((ozanin_kacma_ihtimali * 100) > random_ozanin_kacma_ihtimali) {
				printf("ozan basariyl kacti");
			} else {
				savas(ozan, haydut, &ozanin_verdigi_hasar, &ozanin_aldigi_hasar);
			}
			break;
		if(ozan->can_degeri == 0 || ozan->can_degeri < 0) {
			printf("%s yenildi! Savas bitti.", ozan->ozan_adi);
		}
		if(haydut->can_degeri == 0 || haydut->can_degeri < 0) {
			printf("haydut yenildi! Savas bitti");
		}
	}	
}