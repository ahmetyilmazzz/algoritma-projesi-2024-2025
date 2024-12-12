#include <stdio.h>

void menu_yazdir() {
	printf("**********MENU**********\n\n1-kamp alanina git\n2-sifahaneye git\n3-hana git\n4-maceraya katil\n5-seviye atla\n6-Durumu goster\n7-oyundan cik\n");
}
void kamp_alani_alt_secenekler() {
	printf("1. Kamp ate�inin ba��nda �alg� �al/�ark� s�yle.\n");
	printf("2. Nehirde y�kan.\n");
	printf("3. �ad�r�na girip uyu.\n");
	printf("4. K�y meydan�na d�n.\n");
}
void sifahaneye_git_alt_secenekler() {
	printf("1. �ifac�dan yaralar�n� sarmas�n� iste.\n");
	printf("2. �ifac�dan merhem yap�p s�rmesini iste.\n");
	printf("3. K�y meydan�na d�n.\n");
}
void hana_git_alt_secenekler() {
	printf("1. Yiyecek sat�n al ve ye.\n");
	printf("2. ��ecek sat�n al, i� ve e�len.\n");
	printf("3. Enstr�man �al ve �ark� s�yle.\n");
	printf("4. K�y meydan�na d�n.\n");
}
void maceraya_atil_alt_secenekler() {
	printf("1. Yak�n �evreden �ifal� bitki topla ve avlan.\n");
	printf("2. Orman� ke�fe ��k (kolay).\n");
	printf("3. Kayal�klar� ke�fe ��k (orta).\n");
	printf("4. Vadiyi ke�fe ��k (zor).\n");
	printf("5. K�y meydan�na d�n.\n");
}
void durumu_goster(char *isim, char *calgi_adi, int *para, int *tecrube, int *can, int *tokluk, int *uyku, int* guc, int *ceviklik, int *dayan�kl�l�k, int *karizma, int *toplayicilik_becerisi) {
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

}

void main() {
	char ozan_adi[20];
	char calgi_adi[20];
	int para = 50;
	int tecrube = 50;
	int can_degeri = 50;					// temel nitelik
	int tokluk = 50;						// temel nitelik
	int uyku = 50;
	int guc = 50;							// beceri
	int ceviklik = 50;						// beceri
	int dayan�kl�l�k = 50;					// beceri
	int karizma = 50;						// beceri
	int toplay�c�l�k_becerisi = 50;

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
				tecrube_arttir();z
			case 4:
				menu_yazdir();
				break;
			}
		}
		else if (secim == 4) {
			printf("maceraya katiliyorsunuz...");
			maceraya_atil_alt_secenekler();
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