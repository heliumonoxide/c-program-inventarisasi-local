#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct {
	char id[10];
	char name[20];
	int  quantity;
	int price;
}Product;

void tampil (Product produk1[]);
void tambah (Product produk1[]);
void ubah (Product produk1[]);
void hapus (Product produk1[]);
void jual(Product produk1[], long *penjualan);
void penghasilan(long penjualan);

int main(){
	int pilihan;
	int i;
	long penjualan = 0;
	Product produk[30];
	
	for (i = 0; i < 30; i++){
		strcpy(produk[i].id,"");
		strcpy(produk[i].name,"");
		produk[i].price = 0;
		produk[i].quantity = 0;
	}
	
	do {
		printf("=======================================\n");
		printf("      PROGRAM INVENTARIS PRODUK\n");
		printf("=======================================\n");
		printf("\nTekan:");
		printf("\n 1.) Menambah produk");
		printf("\n 2.) Mengubah produk");
		printf("\n 3.) Menghapus Produk");
		printf("\n 4.) Tampilan semua produk");
		printf("\n 5.) Pembelian Produk");
   		printf("\n 6.) Total keuntungan");
		printf("\n 7.) Exit the program\n");
		printf("\nPilihanmu --> ");
		scanf("%d", &pilihan);
		
		switch(pilihan) {
			case 1:
				tambah(produk);
				break;
			
			case 2:
        		ubah(produk);
				break;
				
			case 3:
				hapus(produk);
				break;
			
			case 4:
				tampil(produk);
				break;
        
			case 5:
				jual(produk,&penjualan);
				break;
			
			case 6:
        		penghasilan(penjualan);
				break;
		}
	}
	while (pilihan != 7);
	
	return 0;
}

void tambah (Product produk1[]){
	int i = 0, x;
	int sentinel;
	
	printf("\nBerapa produk yang ingin anda tambahkan? ");
	scanf("%d", &sentinel);
	printf("=======================================\n");
	for (x = 0; x < 30; x++){
		if (!strcmp(produk1[x].id,"")){
			for (i = x; i < x + sentinel; i++){
				printf("Masukkan kode produk ke-%d: ", i+1);
				scanf(" %255[^\n]s", produk1[i].id);
				fflush(stdin);
				printf("Masukkan nama produk ke-%d: ", i+1);
				scanf(" %255[^\n]s", produk1[i].name);
				fflush(stdin);
				printf("Masukkan harga produk ke-%d: ", i+1);
				scanf("%d", &produk1[i].price);
				printf("Masukkan jumlah produk yang ingin dimasukkan: ");
				scanf("%d", &produk1[i].quantity);
				printf("=======================================\n");
			}
			printf("Menunggu...\n");
			sleep(2);
			system("cls");
			break;
		}
	}
}

void tampil (Product produk1[]){
	int i;
	int trial;
	
	system("cls");
	printf("---------------------------------------------------------------------------------\n");
	printf("                                    STOK BARANG\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("No.   |   Kode   |   Nama Barang  |    Harga Barang    |      Jumlah Barang     |\n");
    printf("---------------------------------------------------------------------------------\n");
	for (i = 0; i < 30; i++){
		if(strcmp(produk1[i].id,"")){
			printf("%d\t  ", i+1);
			printf("%s\t  ", produk1[i].id);
			printf("\t%s\t", produk1[i].name);
			printf("\t%d\t", produk1[i].price);
			printf("\t\t%d\n", produk1[i].quantity);
		}
	}
	printf("Tekan Enter untuk kembali ke main menu!");
	getch();
	system("cls");
}

void ubah (Product produk1[]){
	int i, j;
	char temp[10];
	printf("Tuliskan ID produk yang ingin dicari: ");
	scanf(" %9[^\n]s", temp);
	fflush(stdin);
	for (i = 0; i < 30; i++){
		if (!strcmp(temp,produk1[i].id)){
			printf("Produk ditemukan!\n");
			printf("Masukkan kode produk baru: ");
			scanf(" %255[^\n]s", produk1[i].id);
			fflush(stdin);
			printf("Masukkan nama produk baru: ");
			scanf(" %255[^\n]s", produk1[i].name);
			fflush(stdin);
			printf("Masukkan harga produk baru: ");
			scanf("%d", &produk1[i].price);
			printf("Masukkan jumlah produk baru yang ingin dimasukkan: ");
			scanf("%d", &produk1[i].quantity);
			break;
		}
	}
	if (i == 30)
		printf("ID tidak ditemukan!\n");
}
void hapus (Product produk1[]){
	int i, j;
  	char pembanding[50];

  	printf("Masukkan id barang: ");
  	scanf(" %49[^\n]s", pembanding);
  
  	for (i = 0; i < 30; i++){
    	if(!strcmp(produk1[i].id, pembanding)){
			strcpy(produk1[i].id,"");
			strcpy(produk1[i].name,"");
		  	produk1[i].price = 0;
		  	produk1[i].quantity = 0;
		  	for (j = i; j < 29; j++){
		  		produk1[j]= produk1[j+1];
	  		}
	      	break;
	    }
	    else {
	    	printf("Maaf produk tidak ditemukan\n");
	     	printf("Masukkan id barang: ");
	  		scanf(" %49[^\n]s", pembanding);
		}
 	}
	strcpy(produk1[29].id,"");
	strcpy(produk1[29].name,"");
	produk1[29].price = 0;
	produk1[29].quantity = 0;

}

void jual(Product produk1[], long *penjualan){
	int i, j;
	char temp[10];
	unsigned int beli;
	printf("Tuliskan ID produk yang ingin dicari: ");
	scanf(" %9[^\n]s", temp);
	fflush(stdin);
	for (i = 0; i < 30; i++){
		if (!strcmp(temp,produk1[i].id)){
			printf("Produk ditemukan!\n");
			printf("ID: %s\n", produk1[i].id);
			printf("Nama: %s\n", produk1[i].name);
			printf("Harga: %d\n", produk1[i].price);
			printf("Jumlah: %d\n", produk1[i].quantity);
			
			do{
				printf("Masukkan jumlah barang yang ingin dibeli: ");
				scanf("%d",&beli);
				if (beli > produk1[i].quantity){
					printf("Jumlah pembelian lebih banyak daripada jumlah barang. Tidak boleh!\n");
				}
			}while(beli > produk1[i].quantity);

			*penjualan = beli * produk1[i].price;
			produk1[i].quantity -= beli;
			break;
		}
	}
	if (i == 30)
		printf("ID tidak ditemukan!\n");
}
void penghasilan(long penjualan){
	
	printf("Penghasilannya adalah: %ld\n", penjualan);
}
