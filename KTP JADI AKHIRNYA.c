#include <stdio.h>

typedef struct{
    char nik[50];
    char nama[100];
    char tempat[100];
    char hari[20];
    char bulan[20];
    char tahun[20];
    char jenis[20];
    char agama[10];
} KTP;

KTP penduduk[100] = {};

int ind = 0;

void tambah(){
    printf("ID : ");
    scanf("%s",&penduduk[ind].nik);
    getchar();
    printf("Nama : ");
    gets(&penduduk[ind].nama);
    printf("Tempat Lahir : ");
    gets(&penduduk[ind].tempat);
    printf("Tanggal Lahir : ");
    gets(&penduduk[ind].hari);
    printf("Bulan Lahir : ");
    gets(&penduduk[ind].bulan);
    printf("Tahun Lahir : ");
    gets(&penduduk[ind].tahun);
    printf("Jenis Kelamin : ");
    gets(&penduduk[ind].jenis);
    printf("Agama : ");
    gets(&penduduk[ind].agama);
    printf("\n");
    printf("Data berhasil dibuat\n\n");
}

int search(int test){
    int i = 0;
    for (;i < ind;i++){
        if (penduduk[i].nik == test){
            return i;
        }
    }
    return -1;
}


void delete(int test){
    int i = test;
    for (;i < ind - 1;i++){
        penduduk[i] = penduduk[i+1];
    }
    ind--;
    printf("Data Penduduk berhasil dihapus\n");
}

void show(){
    if (ind == 0){
        printf("\nBelum ada data yang tersimpan\n\n");
        return;
    }
    int  i;
    for (i = 0;i < ind;i++){
        print(i);
    }
}

void print(int test){
    printf("ID : %s\n",penduduk[test].nik);
    printf("Nama : %s\n",penduduk[test].nama);
    printf("Tempat Lahir : %s\n",penduduk[test].tempat);
    printf("Tanggal Lahir : %s\n",penduduk[test].hari);
    printf("Bulan Lahir : %s\n",penduduk[test].bulan);
    printf("Tahun Lahir : %s\n",penduduk[test].tahun);
    printf("Jenis Kelamin : %s\n",penduduk[test].jenis);
    printf("Agama : %s\n",penduduk[test].agama);
    printf("\n");
}

int main (){
    
    while (!0){
        int input;
        printf("Ketik angka sesuai opsi yang ingin dilakukan :\n");
        printf("0. Keluar\n1. Tampilkan Data\n2. Tambah Data\n3. Mencari Data (Berdasarkan NIK)\n4. Menghapus Data (Berdasarkan NIK)\n==>");
        scanf("%d",&input);

        switch (input){
        	case 0 :{
            	printf("SELESAI");
            	return 0;
			}
         	case 1 :{
    	        // SHOW
	            show();
	            break;
        	} 	
			case 2 :{
        	    // TAMBAH
            	tambah();
            	ind++;
            	break;
        	} 
			case 3 :{
        	    // SEARCH
        	    printf("\nMasukkan ID yang akan dicari datanya : ");
        	    int test = 0;
        	    scanf("%d",&test);
        	    int kkk = search(test);
        	    if (kkk != -1){
	    	            printf("Penduduk telah terdaftar.\n\n");
	    	            print(kkk);
	    	        } else {
	    	            printf("Penduduk tidak ditemukan atau tidak terdaftar.\n\n");
	    	        }
	    	    break;
        	}
			case 4 :{
	            // DELETE
   	   	   		printf("Masukkan ID yang akan dihapus datanya : ");
    	        int test = 0;
   		        scanf("%d",&test);
        	    int kkk = search(test);
            	if (kkk != -1){
                	delete(kkk);
            	} else {
                	printf("Data Penduduk gagal dihapus karena id belum terdaftar\n\n");
            	}
            	break;
        }
        }
        if(input != 0 && input != 1 && input != 2 && input != 3 && input != 4)
            printf("\nCommand tidak ditemukan\n\n");
    }
}
