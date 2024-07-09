//lokantasubesi adlı bir struct tanımlayın. 
//short personel sayısı
//long müşteri sayısı
//char[30] şube adı
//float günlük ciro olsun. Sonrasında 
//lokanta subesi türünde bir struct dizisi tanımlayın. (3 elemanlı)
//Dizi elemanlarının değerlerini kullanıcıdan isteyin

//Bir tane fonksiyon tanımlayın. Fonksiyon parametre olarak Lokantasubesi struct
//türünde bir eleman alsın. Sonra bu subenin ciro/personelsayisi degerini
//hesaplayıp döndürsün. Yukarıda tanımlanan diziye ilişkin elemanları
//bu fonksiyona sunun. Ve her bir dizi elemanı için dönen değeri
//ekrana basın.

//Struct Lokantasubesi türünde tanımlanmış bir diziyi fonksiyona parametre olarak girin.
//İŞARETÇİDEN YARARLANIN. Fonksiyon ciro/personelsayisi değeri en yüksek olan dizi elemanını döndürsün.
#include <stdio.h>
#define SUBESAY 3
struct Lokantasubesi{
	short personelsayisi;
	long musterisayisi;
	char subeadi[30];
	float gunlukciro;
};
struct Lokantasubesi personelalimi(struct Lokantasubesi sube);
struct Lokantasubesi enverimli(struct Lokantasubesi *sptr);
void calisanarttir(struct Lokantasubesi *sptr);
float oran(struct Lokantasubesi sube){
	float donen=0.0;
	donen=sube.gunlukciro/sube.personelsayisi;
	return donen;
}
void main(){
	struct Lokantasubesi subeler[SUBESAY];
	struct Lokantasubesi yenielemanlisubeler[SUBESAY];
	struct Lokantasubesi enverimlisube;
	short sayac=0;
	for(sayac=0;sayac<SUBESAY;sayac++){
		printf("%d Sira Nolu Subeye Iliskin Bilgiler",sayac);
		printf("\n Sube Adini Girin");
		scanf("%s",subeler[sayac].subeadi);
		printf("Personel Sayisini Girin");	
		scanf("%d",&subeler[sayac].personelsayisi);
		printf("Gunluk Musteri Sayisini Girin");	
		scanf("%d",&subeler[sayac].musterisayisi);	
		printf("Gunluk Ciroyu Girin");	
		scanf("%f",&subeler[sayac].gunlukciro);
		printf("gunlukciro/personelsayisi=%.2f\n",oran(subeler[sayac]));
		//yenielemanlisubeler[sayac]=personelalimi(subeler[sayac]);
	    //printf("Eski PersonelSayisi=%d Yeni Personel Sayisi=%d \n",subeler[sayac].personelsayisi,yenielemanlisubeler[sayac].personelsayisi);
	}
	enverimlisube=enverimli(subeler);
	printf("\n En Verimli Sube: %s subesidir",enverimlisube.subeadi);
	calisanarttir(subeler);
	for(sayac=0;sayac<SUBESAY;sayac++){
		printf("\n %s Subesi Eleman Sayisi=%d",subeler[sayac].subeadi,subeler[sayac].personelsayisi);
	}
}
void calisanarttir(struct Lokantasubesi *sptr){
	short sayac=0;
	for(sayac=0;sayac<SUBESAY;sayac++){
		(sptr+sayac)->personelsayisi++;
	}
}
struct Lokantasubesi personelalimi(struct Lokantasubesi sube){
	sube.personelsayisi++;
	return sube;
}

struct Lokantasubesi enverimli(struct Lokantasubesi *sptr){
	struct Lokantasubesi envesube;
	short sayac=0;
	envesube=*sptr;
	for(sayac=1;sayac<SUBESAY;sayac++){
		if(((sptr+sayac)->gunlukciro/(sptr+sayac)->personelsayisi)>(envesube.gunlukciro/envesube.personelsayisi))
		envesube=*(sptr+sayac);
	}
	return envesube;
}
