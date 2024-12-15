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

void main() {
	char ozan_adi[20];
	char calgi_adi[20];
	int para_degeri = 10;
	int tecrube_degeri = 50;
	int can_degeri = 50;						
	int tokluk_degeri = 50;						
	int su_degeri = 50;							
	int uyku_degeri = 50;
	int hijyen_degeri = 50;
	int eglence_degeri = 50;
	int moral_degeri = 50;
	int guc_degeri = 3;							
	int ceviklik_degeri = 3;					
	int dayaniklilik_degeri = 3;				
	int karizma_degeri = 3;						
	int toplayicilik_becerisi_degeri = 50;

	printf("Ozan'in adini giriniz: ");
	gets(ozan_adi);

	printf("Ozan'in caldigi calginin adi: ");
	gets(calgi_adi);


	int secim;
	while (1) {
		menu_yazdir(&secim);

		kampa_git(&can_degeri, &tecrube_degeri, &karizma_degeri, &uyku_degeri, &guc_degeri, &ceviklik_degeri, &dayaniklilik_degeri, &secim);
		
		sifahaneye_git(&moral_degeri, &can_degeri, &ceviklik_degeri, &dayaniklilik_degeri, &guc_degeri, &para_degeri, &eglence_degeri, &moral_degeri, &secim);

		hana_git(&para_degeri, &tokluk_degeri, &can_degeri, &ceviklik_degeri, &dayaniklilik_degeri, &guc_degeri, &karizma_degeri, &tecrube_degeri, &secim);

		maceraya_atil(&para_degeri, &tecrube_degeri, &can_degeri, &tokluk_degeri, &ceviklik_degeri, &dayaniklilik_degeri, &toplayicilik_becerisi_degeri, &uyku_degeri, &guc_degeri, &secim);
		
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

void uyu(int* uyku_seviyesi, int miktar) {
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
		*uyku_seviyesi += miktar;
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
void tokluk(int* aclik_seviyesi, int* para, int miktar) {
	int secim;
	printf("acligi nasil gidermek istersiniz?\n1. ekmek ye (2 altin, +10 tokluk)\n2. yahni ye (10 altin, +50 tokluk)\n3. elma ye (1 altin, +5 tokluk)\n");
	scanf("%d", &secim);
	switch (secim) {
		case 1:
			*para -= 2;
			*tokluk += 10;
			break;
		case 2:
			*para -= 10;
			*tokluk += 50;
			break;
		case 3:
			*para -= 1;
			*tokluk += 5;
		default:
			printf("gecersiz islem yaptiniz.");
	}
	if (*aclik_seviyesi > 100) {
		printf("aclik degeri 100'den buyuk olamaz.\n");
	}
	else {
		*aclik_seviyesi += miktar;
		if (*aclik_seviyesi > 100) {
			*aclik_seviyesi = 100;
		}
	}
}
void su_degeri(int* su_degeri, int miktar) {
	if (*su_degeri > 100) {
		printf("su degeri 100'den buyuk olamaz.\n");
	}
	else {
		*su_degeri += miktar;
		if (*su_degeri > 100) {
			*su_degeri = 100;
		}
	}
}

void eglence_degeri(int* eglence_degeri, int miktar) {
	if (*eglence_degeri > 100) {
		printf("eglence degeri 100'den buyuk olamaz.\n");
	}
	else {
		*eglence_degeri += miktar;
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

void kampa_git(int* can_degeri, int* tecrube_degeri, int* karizma_degeri, int* uyku_degeri, int* guc_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri, int* secim) {
	if (secim == 1) {
		printf("Kamp alanina gidiyorsunuz...\n");
		kamp_alani_alt_secenekler();
		int alt_secim;
		printf("kamp alaninda ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:
			tecrube(tecrube_degeri, 10);
			karizma(karizma_degeri, 10);
			break;
		case 2:
			can(can_degeri, 10);
			tecrube(tecrube_degeri, 10);
			break;
		case 3:
			uyu(uyku_degeri, can_degeri);
			guc(guc_degeri, 10);
			ceviklik(ceviklik_degeri, 10);
			dayaniklilik(dayaniklilik_degeri, 10);
			break;
		case 4:
			menu_yazdir(secim);
			break;
		}
	}
}

void sifahaneye_git(int* moral_degeri, int* can_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri, int* guc_degeri, int* para_degeri, int* eglence_degeri, int* secim) {
	if (secim == 2) {
		printf("sifahaneye gidiyorsunuz...");
		sifahaneye_git_alt_secenekler();
		int alt_secim;
		printf("sifahane de ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:
			can(&can_degeri, 10);
			ceviklik(&ceviklik_degeri, 10);
			dayaniklilik(&dayaniklilik_degeri, 10);
			guc(&guc_degeri, 10);
			para(&para_degeri, 10);
			moral(&moral_degeri, 10);
			break;
		case 2:
			can(&can_degeri, 10);
			ceviklik(&ceviklik_degeri, 10);
			dayaniklilik(&dayaniklilik_degeri, 10);
			guc(&guc_degeri, 10);
			para(&para_degeri, 10);
			moral(&moral_degeri, 10);
			break;
		case 3:
			menu_yazdir(&secim);
			break;
		}
	}
}

void hana_git(int* para_degeri, int* tokluk_degeri, int* can_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri, int* guc_degeri, int* karizma_degeri, int* tecrube_degeri, int* secim) {
	if (secim == 3) {
		printf("hana gidiyorsunuz...");
		hana_git_alt_secenekler();
		int alt_secim;
		printf("han	da ne yapmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:
			para(&para_degeri, 10);
			tokluk(&tokluk_degeri, 10);
			can(&can_degeri, 10);
			ceviklik(&ceviklik_degeri, 10);
			dayaniklilik(&dayaniklilik_degeri, 10);
			guc(&guc_degeri, 10);
			break;
		case 2:
			para(&para_degeri, 10);
			can(&can_degeri, 10);
			ceviklik(&ceviklik_degeri, 10);
			dayaniklilik(&dayaniklilik_degeri, 10);
			tokluk(&tokluk_degeri, 10);
			guc(&guc_degeri, 10);
			karizma(&karizma_degeri, 10);
			break;
		case 3:
			tecrube(&tecrube_degeri, 10);
			karizma(&karizma_degeri, 10);
		case 4:
			menu_yazdir(&secim);
			break;
		}
	}
}	

void maceraya_atil(int* para_degeri, int* tecrube_degeri, int* can_degeri, int* tokluk_degeri, int* ceviklik_degeri, int* dayaniklilik_degeri, int* toplayicilik_becerisi_degeri, int* uyku_degeri, int* guc_degeri, int* secim) {
	if (secim == 4) {
		printf("maceraya katiliyorsunuz...");
		maceraya_atil_alt_secenekler();
		int alt_secim;
		printf("nasil bir maceraya katilmak istiyorsunuz? ");
		scanf("%d", &alt_secim);
		switch (alt_secim) {
		case 1:
			toplayicilik_becerisi(&toplayicilik_becerisi_degeri, 10);
			can(&can_degeri, 10);
			tecrube(&tecrube_degeri, 10);
			dayaniklilik(&dayaniklilik_degeri, 10);
			ceviklik(&ceviklik_degeri, 10);
			tokluk(&tokluk_degeri, 10);
			uyu(&uyku_degeri, 10);
			guc(&guc_degeri, 10);
			break;
		case 2:
			tecrube(&tecrube_degeri, 10);
			para(&para_degeri, 10);
			break;
		case 3:
			tecrube(&tecrube_degeri, 10);
			para(&para_degeri, 10);
			break;
		case 4:
			tecrube(&tecrube_degeri, 10);
			para(&para_degeri, 10);
			break;
		case 5:
			menu_yazdir(&secim);
			break;
		}
	}
}

void seviye_atla() {

}