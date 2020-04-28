#include<stdio.h>
#include<stdlib.h>

int main()
{
	int bilangan[100]; //isi angka
	int i,j; //looping
	int cari; //letak angka
	int cek = 0; //cek ada nilainya
	int first=0; //bantu search
	int last=99; //bantu search
	int mid;	// bantu search
	
	printf("\nBilangan Acak : \n");
	// buat angka random
	for(i=0;i<100;i++)
	{
		bilangan[i]=rand()%100+3;
		printf("%d ",bilangan[i]);
	}
	
	printf("\n\nBilangan yang dicari : ");
	scanf("%d",&cari);
	
	//sorting
	for(i=0;i<100;i++){
		for(j=i+1;j<100;j++){
			if(bilangan[i]>bilangan[j]){
				int	temp=bilangan[i];
				bilangan[i]=bilangan[j];
				bilangan[j]=temp;
			}
		}
	}
	
	
	//searching
	while(cek!=1&&first<=last){
		mid = (first+last)/2;
		if(bilangan[mid]==cari){
			cek=1;
		}else if(bilangan[mid]<cari){
			first=mid+1;
		}else if(bilangan[mid]>cari){
			last=mid -1;
		}
	}
	
	if(cek==1) printf("\n\nTelah ditemukan angka %d di data", cari);
	else printf("\n\nTidak ditemukan angka %d di data", cari);
}
