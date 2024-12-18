// bazı nitelikler artarken bazıları azalmalı bunları spesifik olarak belirtilen fonksiyonların içerisinde yap.

#include <stdio.h>
#include <stdlib.h>

void menu_yazdir();
void kamp_alani_alt_secenekler();
void sifahaneye_git_alt_secenekler();
void hana_git_alt_secenekler();
void maceraya_atil_alt_secenekler();
void durumu_goster(char* isim, char* calgi_adi, int* para, int* tecrube, int* can, int* tokluk, int* uyku, int* guc, int* ceviklik, int* dayaniklilik, int* karizma, int* toplayicilik_becerisi);
void uyu(int* uyku_seviyesi, int miktar);
void karizma(int* karizma_seviyesi);
void can(int* saglik_degeri);
void tokluk(int* aclik_seviyesi);
void su_degeri(int* su_degeri);
void hijyen(int* hijyen_seviyesi);
void para(int* para_seviyesi);
void tecrube(int* tecrube_degeri);
void guc(int* guc_degeri);
void ceviklik(int* ceviklik_degeri);
void dayaniklilik(int* dayaniklilik_degeri);
void toplayicilik_becerisi(int* toplama_becerisi);
void eglence_degeri(int* eglence_degeri);
void moral_degeri(int* moral_degeri);
void kampa_git(int* uyku_degeri, int* guc_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri);
void sifahaneye_git(int* para_degeri, int* hijyen_degeri, int* eglence_degeri, int* moral_degeri);
void hana_git(int* para_degeri, int* su_degeri, int* tokluk_degeri, int* can_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri);
void maceraya_atil(int* para_degeri, int* tecrube_degeri, int* can_degeri, int* tokluk_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri);
void oyundan_cik(int* secim);
void seviye_atla();

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
	
	int guc_degeri = 3;
	int ceviklik_degeri = 3;
	int dayaniklilik_degeri = 3;
	int karizma_degeri = 3;
} Ozan;

typedef struct Haydut {
	int guc_degeri = 3;
	int ceviklik_degeri = 3;
	int dayaniklilik_degeri = 3;
} Haydut;

void main() {
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

	int secim;
	while (1) {
		menu_yazdir(&secim);

		kampa_git(&ozan.can_degeri, &ozan.tecrube_degeri, &ozan.karizma_degeri, &ozan.uyku_degeri, &ozan.guc_degeri, &ozan.ceviklik_degeri, &ozan.dayaniklilik_degeri, &secim);
		
		sifahaneye_git(&ozan.moral_degeri, &ozan.can_degeri, &ozan.ceviklik_degeri, &ozan.dayaniklilik_degeri, &ozan.guc_degeri, &ozan.para_degeri, &ozan.eglence_degeri, &ozan.moral_degeri, &secim);

		hana_git(&ozan.para_degeri, &ozan.tokluk_degeri, &ozan.can_degeri, &ozan.ceviklik_degeri, &ozan.dayaniklilik_degeri, &ozan.guc_degeri, &ozan.karizma_degeri, &ozan.tecrube_degeri, &secim);

		maceraya_atil(&ozan.para_degeri, &ozan.tecrube_degeri, &ozan.can_degeri, &ozan.tokluk_degeri, &ozan.ceviklik_degeri, &ozan.dayaniklilik_degeri, &ozan.toplayicilik_becerisi_degeri, &ozan.uyku_degeri, &ozan.guc_degeri, &secim);
		
		if (secim == 5) {
			durumu_goster(ozan_adi, calgi_adi, &para_degeri, &tecrube_degeri, &can_degeri, &tokluk_degeri, &uyku_degeri, &guc_degeri, &ceviklik_degeri, &dayaniklilik_degeri, &karizma_degeri, &toplayicilik_becerisi_degeri);
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
		if(tokluk_degeri == 0) {
			can_degeri -= 20;
		} 
		if(su_degeri == 0) {
			can_degeri -= 15;
		}
		if (uyku_degeri == 0) {
			can_degeri -= 10
		} 		
		// her turdan sonra temel niteliklerin azalması gerekiyor bunu burada hallet.
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
void durumu_goster(char* isim, char* calgi_adi, int* para, int* tecrube, int* can, int* tokluk, int* uyku, int* guc, int* ceviklik, int* dayaniklilik, int* karizma, int* toplayicilik_becerisi) {
	printf("isim: %s\n", *isim);
	printf("calgi adi: %s\n", *calgi_adi);
	printf("para: %d\n", *para);
	printf("tecrube: %d\n", *para);
	printf("can: %d\n", *para);
	printf("tokluk: %d\n", *para);
	printf("uyku: %d\n", *para);
	printf("guc: %d\n", *para);
	printf("ceviklik: %d\n", *para);
	printf("dayaniklilik: %d\n", *para);
	printf("karizma: %d\n", *para);
	printf("toplayicilik becerisi: %d\n", *para);

}

void uyu(int* uyku_seviyesi, int* tokluk, int* su, int saat) {
	if(*uyku_seviyesi > 100) {
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
		*uyku_seviyesi += 10 * saat;
		*tokluk -= 4 * saat;
		*su -= 3 * saat;
		if(*uyku_seviyesi > 100) {
			*uyku_seviyesi = 100;
		}
	}
	printf("uyku seviyesi: %d\n", *uyku_seviyesi);
}
void karizma(int* karizma_seviyesi, int miktar) {
	if (*karizma_seviyesi > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		*karizma_seviyesi += miktar;
		if (*karizma_seviyesi > 25) {
			*karizma_seviyesi = 25;
		}
	}
	printf("karizma seviyesi: %d", *karizma_seviyesi);
}
void can(int* saglik_degeri, int miktar) {
	if (*saglik_degeri > 100) {
		printf("saglik degeri 100'den buyuk olamaz.\n");
	}
	else {
		*saglik_degeri += miktar;
		if (*saglik_degeri > 100) {
			*saglik_degeri = 100;
		}
	}
}
void tokluk(int* aclik_seviyesi, int* para, int* uyku, int miktar) {
	int secim;
	printf("acligi nasil gidermek istersiniz?\n1. ekmek ye (2 altin, +10 tokluk)\n2. yahni ye (10 altin, +50 tokluk)\n3. elma ye (1 altin, +5 tokluk)\n");
	scanf("%d", &secim);
	switch (secim) {
		case 1:
			*para -= 2 * miktar;
			*aclik_seviyesi += 10 * miktar;
			break;
		case 2:
			*para -= 10 * miktar;
			*aclik_seviyesi += 50 * miktar;
			break;
		case 3:
			*para -= 1 * miktar;
			*aclik_seviyesi += 5 * miktar;
		default:
			printf("gecersiz islem yaptiniz.");
	}
	if (*aclik_seviyesi > 100) {
		printf("aclik degeri 100'den buyuk olamaz.\n");
	}
	else {
		*uyku -= 10 * miktar;
		if (*aclik_seviyesi > 100) {
			*aclik_seviyesi = 100;
		}
	}
}
void su_degeri(int* su_degeri, int* tokluk, int miktar) {
	if (*su_degeri > 100) {
		printf("su degeri 100'den buyuk olamaz.\n");
	}
	else {
		*su_degeri += miktar;
		*tokluk -= 10;		// su içmek acıktırır.
		if (*su_degeri > 100) {
			*su_degeri = 100;
		}
	}
}

void eglence_degeri(int* eglence_degeri, int* tokluk, int* uyku, int sure) {
	if (*eglence_degeri > 100) {
		printf("eglence degeri 100'den buyuk olamaz.\n");
	}
	else {
		*eglence_degeri += sure * 10; 
		*tokluk -= sure * 5;
		*uyku -= sure * 5;
		if (*eglence_degeri > 100) {
			*eglence_degeri = 100;
		}
	}
}

void moral_degeri(int* moral_degeri, int miktar) {
	if (*moral_degeri > 100) {
		printf("moral degeri 100'den buyuk olamaz.\n");
	}
	else {
		*moral_degeri += miktar;
		if (*moral_degeri > 100) {
			*moral_degeri = 100;
		}
	}
}

void hijyen(int* hijyen_seviyesi, int miktar) {
	if (*hijyen_seviyesi > 100) {
		printf("hijyen degeri 100'den buyuk olamaz.\n");
	}
	else {
		*hijyen_seviyesi += miktar;
		if (*hijyen_seviyesi > 100) {
			*hijyen_seviyesi = 100;
		}
	}
}
void para(int* para_seviyesi, int miktar) {
	*para_seviyesi += miktar;
}
void tecrube(int* tecrube_degeri, int miktar) {
	if (*tecrube_degeri > 100) {
		printf("tecrube degeri 100'den buyuk olamaz.\n");
	}
	else {
		*tecrube_degeri += miktar;
		if (*tecrube_degeri > 100) {
			*tecrube_degeri = 100;
		}
	}
	if (tecrube == 100) {
		seviye_atla();
	}
}
void guc(int* guc_degeri, int miktar) {
	if (*guc_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		*guc_degeri += miktar;
		if (*guc_degeri > 25) {
			*guc_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", *guc_degeri);
}
void ceviklik(int* ceviklik_degeri, int miktar) {
	if (*ceviklik_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		*ceviklik_degeri += miktar;
		if (*ceviklik_degeri > 25) {
			*ceviklik_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", *ceviklik_degeri);
}
void dayaniklilik(int* dayaniklilik_degeri, int miktar) {
	if (*dayaniklilik_degeri > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		*dayaniklilik_degeri += miktar;
		if (*dayaniklilik_degeri > 25) {
			*dayaniklilik_degeri = 25;
		}
	}
	printf("karizma seviyesi: %d", *dayaniklilik_degeri);
}
void toplayicilik_becerisi(int* toplama_becerisi, int miktar) {
	if (*toplama_becerisi > 25) {
		printf("karizma degeri 25'den buyuk olamaz.\n");
	}
	else {
		*toplama_becerisi += miktar;
		if (*toplama_becerisi > 25) {
			*toplama_becerisi = 25;
		}
	}
	printf("karizma seviyesi: %d", *toplayicilik_becerisi);

}

void kampa_git(Ozan* ozan, int* secim) {
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
		case 3:												//Çadırına girip uyu.(uyku, guc, ceviklik, dayanıklılık, tokluk, su degeri)
			uyu(&ozan->uyku_degeri, &ozan->can_degeri);
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
			can(&ozan->can_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			para(&ozan->para_degeri, 10);
			moral(&ozan->moral_degeri, 10);
			break;
		case 2:												// Şifacıdan merhem yapıp sürmesini iste.(can degeri, ceviklik, dayanıklılık, -para, guc, moral)
			can(&ozan->can_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			para(&ozan->para_degeri, 10);
			moral(&ozan->moral_degeri, 10);
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
			if (ozan->hijyen < 20) {
				printf("hijyene onem vermediginiz icin handa sarki soyleyemezsiniz.");
				break;
			}
			ozan->para_degeri = (10 + ((ozan->karizma_degeri) * (ozan->hijyen) / 100));
			tecrube(&ozan->tecrube_degeri, 20);
			karizma(&ozan->karizma_degeri, 10);
		case 4:
			menu_yazdir(&secim);
			break;
		}
	}
}	

void maceraya_atil(Ozan ozan, int* secim) {
	if (secim == 4) {
		printf("maceraya katiliyorsunuz...");
		maceraya_atil_alt_secenekler();
		int alt_secim;
		printf("nasil bir maceraya katilmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:												   	// Yakın çevreden şifalı bitki topla ve avlan. (toplayıcılık becerisi, -can degeri, tecrube, -dayanıklılık, -ceviklik, -tokluk, -uyku, -guc)
			toplayicilik_becerisi(&ozan->toplayicilik_becerisi_degeri, 10);
			can(&ozan->can_degeri, 10);
			tecrube(&ozan->tecrube_degeri, 10);
			dayaniklilik(&ozan->dayaniklilik_degeri, 10);
			ceviklik(&ozan->ceviklik_degeri, 10);
			tokluk(&ozan->tokluk_degeri, );
			uyu(&ozan->uyku_degeri, 10);
			guc(&ozan->guc_degeri, 10);
			break;
		case 2:													//  Ormanı keşfe çık (kolay). (tecrube, para)
			tecrube(&ozan->tecrube_degeri, 10);
			para(&ozan->para_degeri, 10);
			break;
		case 3:													// Kayalıkları keşfe çık (orta). (tecrube, para)
			tecrube(&ozan->tecrube_degeri, 10);
			para(&ozan->para_degeri, 10);
			break;
		case 4:													// Vadiyi keşfe çık (zor). (tecrube, para)
			tecrube(&ozan->tecrube_degeri, 10);
			para(&ozan->para_degeri, 10);
			break;
		case 5:
			menu_yazdir(&secim);
			break;
		}
	}
}

void seviye_atla(Ozan* ozan) {
	if (ozan->tecrube_degeri == 100) {
		ozan->tecrube_degeri = 0;
		ozan->dayaniklilik_degeri = 0;
		ozan->guc_degeri = 0;
		ozan->karizma_degeri = 0;
		ozan->toplayicilik_becerisi_degeri = 0;
	}
}