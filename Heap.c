#include<stdio.h>

void menu(int array[], int size);
int find(int array[], int size, int value);
void start();
void insert(int array[], int size);
void delete(int array[], int size);
void cetak(int array[], int size);
void swap(int *a, int *b);
void bubbleSort(int arr[], int size);

int main()
{
    printf("Program starting...\n");
    start();
    printf("Program terminated\n");
    return 0;
}

void start() // untuk mengisi heap pertama kali
{
    int size,i;

    printf("Type how long is you heap:");
    scanf("%d", &size); // untuk mendapatkan size heap yang ingin dibuat
    int array[size];

    printf("Insert the heap:\n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]); // mengisi heap
    }

    bubbleSort(array, size); // untuk mengurutkan heap secara ascending

    menu(array, size); //untuk ke menu user yang terdapat pilihan kegiatan
}

void menu(int array[], int size)
{
    printf("===================MENU===================\n");
    printf("Choose what to do:\n");
    printf("1 for insert\n2 for delete\n3 for print\n4 to end the program\n->");
    int menu;
    scanf("%d", &menu);

    if(menu == 1) insert(array, size);
    else if(menu == 2) delete(array, size);
    else if(menu == 3) cetak(array, size);
    else if(menu == 4) return;
}

int find(int array[], int size, int value) // mencari apakah angka tersebut sudah ada di dalam heap
{
    int flag = 0;
    for(int i=0; i<size; i++)
    {
        if(array[i] == value) flag = 1; //jika terdapat maka tanda yaitu flag akan bernilai 1
    }
    return flag;
}

void insert(int array[], int size)
{
    int number, i, flag = 0;
    printf("Type in the number to insert:");
    scanf("%d", &number);
    
    if(find(array, size, number) == 0) // jika pada find hasilnya 0, dalam artian belum ada angka tersebut maka program jalan
    {
        int arr[size+1]; //membuat array untuk mengisi heap yang baru
    
        for(i=0; i<size; i++)
        {
            if(array[i] < number) arr[i] = array[i]; //jika isi array lebih kecil maka akan di copy ke array yang baru
            else // jika angka lebih kecil maka akan dimasukan ke array yang baru
            {
                arr[i] = number;
                flag = 1; //flag sebagai penanda bahwa angka baru sudah dimasukan
                break;
            }
        }

        if(flag == 1) //jika angka baru sudah masuk maka lanjut dalam mengisi array baru
        {
          for(; i<size; i++) arr[i+1] = array[i];
        }
        else arr[size] = number; //jika angka baru belum dimasukan, yang artinya memiliki angka terbesar maka akan diisi sebagai angka terakhir
        menu(arr, size+1);
    }
    else //jika tidak maka lanjut ke menu kembali
    {
        printf("Sorry the number you are trying to insert is already in the heap\n");
        menu(array, size);
    }
}

void delete(int array[], int size)
{
    int number, i, flag=0;
    printf("Type in the number you want to delete:");
    scanf("%d", &number);
    if(find(array, size, number)) //mencari apakah angka yang ingin di hilangkan ada di heap atau tidak
    {
        int arr[size-1]; //untuk heap yang baru
        for(i=0; i<size-1; i++)
        {
            if(array[i] != number) arr[i] = array[i]; //jika isi array bukan angka yang akan dihilangkan maka array akan di copy
            else{
                i++;
                flag=1; //jika angka ditemukan maka akan ditandai dengan flag dan akan di skip dalam pengisian array
                break;
            }
        }
        if(flag == 1) for(;i<size; i++) arr[i-1] = array[i]; //jika angka sudah dihilangkan maka dilanjutkan pengisiannya

        menu(arr, size-1);
    }
    else
    {
        printf("The number you're trying to delete isn't in the heap\n");
        menu(array, size);
    }
    
}

void cetak(int array[], int size) //untuk mencetak isi heap
{
    int i;

    printf("The heap is : ");
    for(i=0; i<size; i++) printf("%d ", array[i]); //mencetak isi dari heap
    printf("\n");
    printf("The heap size is : %d\n", size); //mencetak ukuran dari heap
    menu(array, size);
}

void swap(int *a, int *b) //untuk menukar nilai
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void bubbleSort(int arr[], int size) //untuk sorting secara ascending
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)       
        for (j = 0; j < size-i-1; j++)  
            if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

