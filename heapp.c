#include <stdio.h>

void insert(int array[], int size, int value);
void cetak(int array[], int size);
void buat_heap(int array[], int size, int key);
void benerin_heap(int array[], int size, int smallest);
void delete(int array[], int size, int key);
void swap(int *a, int *b);

int main()
{
    printf("=========MENU=========\n");

    int tanda, size = 0, array[20];

    while(tanda != 0)
    {
        printf("0 untuk mengakhiri program\n1 untuk insert\n2 untuk delete\n3 untuk print\n-->");
        scanf("%d", &tanda); //untuk mengetahui perintah yang akan dilakukan
        if(tanda == 1)
        {
            int key;
            printf("Angka yang ingin dimasukkan :");
            scanf("%d", &key);
            if(size == 0) //saat pertama masuk ke array langsung ditambahkan
            {
                array[0] = key;
                size++;
            }
            else
            {
                insert(array, size, key);
                size++;
            }
        }
        else if(tanda == 2) //untuk menghilangkan angka
        {
            int key;
            printf("Angka yang akan dihilangkan :");
            scanf("%d", &key);
            delete(array, size, key);
            size--;
        }
        else if (tanda == 3) cetak(array, size); //cetak angka
    }
    
    return 0;
}

void insert(int array[], int size, int value)
{
    size = size+1;
    array[size-1] = value; //angka dimasukkan ke index terakhir
    buat_heap(array, size, size-1); //heap disusun dengan benar
}

void buat_heap(int array[], int size, int key)
{
    int parent = (key-1)/2; //mencari parent dari index terakhir

    if(array[parent] > 0) //jika nilai lebih dari 0
    {
        if(array[key] < array[parent]) //jika angka yang dimasukan lebih kecil dari parentnya maka nilai akan ditukar dan dijalankan kembali fungsinya
        {
            swap(&array[key], &array[parent]);
            buat_heap(array, size, parent);
        }
    }
}

void cetak(int array[], int size)
{
    int i;
    printf("Isi heap adalah : ");
    for(i=0; i<size; i++)
    {
        printf("%d ", array[i]); //mencetak tiap isi dari heap
    }
    printf("\nPanjang heap adalah : %d\n", size); //mencetak ukuran dari heap
}

void delete(int array[], int size, int key)
{
    int i;
    for(i=0 ; i<size; i++) if(array[i] == key) break; //mencari nilai yang akan dihilangkan
    if(i == size-1) array[size-1] = '\0'; //jika nilai tersebut adalah yang terakhir maka akan dihapus
    else
    {
        int last = array[size-1]; //jika tidak maka nilai terakhir akan menggantikan yang hilang
        array[i] = last;
        size = size-1; //mengecilkan ukuran
        benerin_heap(array, size, i);
    }
    
}

void benerin_heap(int array[], int size, int i)
{
    int small = i; //mencari letak nilai terkecil
    int left = 2*i+1; //left node
    int right = 2*i+2; //right node

    if(left < size && array[left] < array[small]) small = left; //jika left node lebih kecil dari letak yang dihilangkan maka nilai ditukar
    if(right < size && array[right] < array[small]) small = right; // jika right node lebih kecil dari letak yang dihilangkan maka nilai ditukar
    if(small != i){
        swap(&array[i], &array[small]); //menukar nilai dengan left node atau right node
        benerin_heap(array, size, small); //mengulang fungsi
    }
}

void swap(int *a, int *b) //untuk menukar nilai
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}