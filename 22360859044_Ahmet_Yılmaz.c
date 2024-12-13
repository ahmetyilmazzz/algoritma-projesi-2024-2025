#include <stdio.h>

void menu_yazdir();
void kamp_alani_alt_secenekler();
void sifahaneye_git_alt_secenekler();
void hana_git_alt_secenekler();
void maceraya_atil_alt_secenekler();
void durumu_goster(char* isim, char* calgi_adi, int* para, int* tecrube, int* can, int* tokluk, int* uyku, int* guc, int* ceviklik, int* dayanýklýlýk, int* karizma, int* toplayicilik_becerisi);
int uyu(int* uyku_seviyesi);
int karizma(int* karizma_seviyesi);


void main() {
	char ozan_adi[20];
	char calgi_adi[20];
	int para = 50;
	int tecrube = 50;
	int can_degeri = 50;					// temel nitelik
	int tokluk = 50;						// temel nitelik
	int uyku = 50;
	int guc = 3;							// beceri
	int ceviklik = 3;						// beceri
	int dayanýklýlýk = 3;					// beceri
	int karizma = 3;						// beceri
	int toplayýcýlýk_becerisi = 50;

	printf("Ozan'in adini giriniz: ");
	gets(ozan_adi);

	printf("Ozan'in caldigi calginin adi: ");
	gets(calgi_adi);


	int secim;
	while (1) {
		menu_yazdir();
		printf("menuden bir gorev seciniz");
		scanf("%d", &secim)
		
		if (secim == 1) {
			printf("Kamp alanina gidiyorsunuz...\n");
			kamp_alani_alt_secenekler();
			int alt_secim;
			printf("kamp alaninda ne yapmak istiyorsunuz? ");
			scanf("%d", &alt_secim);
			switch (alt_secim) {
			case 1:
				tecrube_arttir();
				karizma 
				break;
			case 2:
				karizma_arttir();
				break;
			case 3:
				uyu();
				break;
			case 4:
				menu_yazdir();
				break;
			}
		}
		else if (secim == 2) {
			printf("sifahaneye gidiyorsunuz...");
			sifahaneye_git_alt_secenekler();
			int alt_secim;
			printf("sifahane de ne yapmak istiyorsunuz? ");
			scanf("%d", &alt_secim);
			switch (alt_secim) {
			case 1:
				can_arttir();
				break;
			case 2:
				can_arttir();
				break;
			case 3:
				menu_yazdir();
				break;
			}
		}
		else if (secim == 3) {
			printf("hana gidiyorsunuz...");
			hana_git_alt_secenekler();
			int alt_secim;
			printf("han	da ne yapmak istiyorsunuz? ");
			scanf("%d", &alt_secim);
			switch (alt_secim) {
			case 1:
				para_azalt();
				tokluk_arttir();
				can_arttir();
				break;
			case 2:
				para_azalt();
				tokluk_arttir();
				can_arttir();
				break;
			case 3:
				tecrube_arttir();
			case 4:
				menu_yazdir();
				break;
			}
		}
		else if (secim == 4) {
			printf("maceraya katiliyorsunuz...");
			maceraya_atil_alt_secenekler();
			int alt_secim;
			printf("nasýl bir maceraya katilmak istiyorsunuz? ");
			scanf("%d", &alt_secim);
			switch (alt_secim) {
			case 1:
				tecrube_arttir();
				can_arttir();
				toplayýcýlýk_becerisi_arttir();
			case 2:
			case 3:
			case 4:
			case 5:
			}
		}
		else if (secim == 5) {
			durumu_goster();
		}
		else if (secim == 6) {

		}
		else if (secim == 7) {
			printf("Cikmak istediginizden emin misiniz? (E/H)");
			scanf("%d", &secim);
			if (secim == 7)
				break;
		}
		else{
			printf("gecersiz secim yaptiniz yeniden seciniz.\n");
			menu_yazdir();
		}
	}
}


void menu_yazdir() {
	printf("**********MENU**********\n\n1-kamp alanina git\n2-sifahaneye git\n3-hana git\n4-maceraya katil\n5-seviye atla\n6-Durumu goster\n7-oyundan cik\n");
}
void kamp_alani_alt_secenekler() {
	printf("1. Kamp ateþinin baþýnda çalgý çal/þarký söyle.\n");
	printf("2. Nehirde yýkan.\n");
	printf("3. Çadýrýna girip uyu.\n");
	printf("4. Köy meydanýna dön.\n");
}
void sifahaneye_git_alt_secenekler() {
	printf("1. Þifacýdan yaralarýný sarmasýný iste.\n");
	printf("2. Þifacýdan merhem yapýp sürmesini iste.\n");
	printf("3. Köy meydanýna dön.\n");
}
void hana_git_alt_secenekler() {
	printf("1. Yiyecek satýn al ve ye.\n");
	printf("2. Ýçecek satýn al, iç ve eðlen.\n");
	printf("3. Enstrüman çal ve þarký söyle.\n");
	printf("4. Köy meydanýna dön.\n");
}
void maceraya_atil_alt_secenekler() {
	printf("1. Yakýn çevreden þifalý bitki topla ve avlan.\n");
	printf("2. Ormaný keþfe çýk (kolay).\n");
	printf("3. Kayalýklarý keþfe çýk (orta).\n");
	printf("4. Vadiyi keþfe çýk (zor).\n");
	printf("5. Köy meydanýna dön.\n");
}
void durumu_goster(char* isim, char* calgi_adi, int* para, int* tecrube, int* can, int* tokluk, int* uyku, int* guc, int* ceviklik, int* dayanýklýlýk, int* karizma, int* toplayicilik_becerisi) {
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

int uyu(int* uyku_seviyesi) {
	return;
}
int karizma(int* karizma_seviyesi) {
	return;
}
int can(int* saglik_degeri) {
	return;
}
int tokluk(int* aclik_seviyesi) {
	return;
}
int hijyen(int* hijyen_seviyesi) {
	return;
}
int money(int* para_seviyesi) {
	return;
}
int tecrube(int* tecrube_degeri) {
	return;
}
int guc(int* guc_degeri) {
	return;
}
int ceviklik(int* ceviklik_degeri) {
	return;
}
int dayaniklilik(int* dayaniklilik_degeri) {
	return;
}
int toplayicilik_becerisi(int* toplama_becerisi) {
	return;
}